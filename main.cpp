#include <decode_object.hpp>

#include <decode.hpp>

#include <cover_to_display.hpp>

#include <action.hpp>

#define debug
#include <robot/controllers.cpp>

int main (int argc, char* argv[])
{
	VideoCapture cap;

	if (!cap.open ("http://172.16.0.60:8080/video"))
        return 0;

	robosapien::interface robot;

	for (;;) {

		Mat im;

		// Read image
		cap >> im;

		if (im.empty ()) break; // end of video stream

		// Variable for decoded objects 
		vector <decodedObject> decodedObjects;

		// Find and decode barcodes and QR codes
		decode (im, decodedObjects, [&robot, &im](const decodedObject& obj)
				{
					// Print type and data
					cout << "Type : " << obj.type << endl;
					cout << "Data : " << obj.data << endl << endl;
					bool problem_detected = false;
					for (auto& point : obj.location) 
					{ 
						cout << "   X : " << point.x << endl << endl;
						cout << "   Y : " << point.y << endl << endl;
						if (point.y >= im.rows - 30) // 30px between the robot and the QR code (our wall)
						{
							if (point.x <= im.cols / 4)
							{
								// turn left
								robot.turn_left (3);
								problem_detected = true;
								break;
							}
							else if (point.x >= 3 * im.cols / 4)
							{
								// turn right
								robot.turn_left (4);
								problem_detected = true;
								break;
							}
							else
							{
								continue;
							}
						}
						else // no problems in front of me
						{
							continue;
						}
					}
					if (problem_detected)
						robot.go_forward (1.5); // go ahead more
				});

		// Display location 
		display (im, decodedObjects);
	}

	return EXIT_SUCCESS;
}

