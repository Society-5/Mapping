# Mapping

QR-code-guided navigation for the Robosapien X. It extends [Vision-Control](https://github.com/Society-5/Vision-Control) to decide the robot's movement from where QR codes appear in the camera frame.

## How it works

QR codes placed on the floor mark walls or obstacles. For every code detected in a frame (OpenCV + ZBar):

- If one of its corners is within **30 px of the bottom edge** of the image, the code counts as directly in front of the robot.
  - If that corner is in the **left quarter** of the frame, the robot turns left for 3 s.
  - If that corner is in the **right quarter** of the frame, it turns for 4 s (the code currently calls `turn_left` here as well).
  - After a turn, the robot moves forward for 1.5 s.
- Otherwise the path is clear and the robot keeps going.

Every movement is a timed, open-loop action. `action.hpp` defines an `action_t` enum (`go_straight`, `turn_left`, `go_back`, `turn_right`) with a duration in seconds. It was intended for turning the text in a QR code into a command, but that isn't wired up yet.

## Files

| File | Purpose |
|---|---|
| `main.cpp` | Capture loop and steering logic |
| `decode.hpp`, `decode_object.hpp`, `cover_to_display.hpp` | QR detection and display, shared with Vision-Control |
| `action.hpp` | Action type and duration |
| `robot/controllers.cpp` | `robosapien::interface`. Currently a debug stub that prints each move and waits for a key press instead of sending infrared commands |

## Build and run

```bash
make
./main
```

The phone's camera-stream URL is hardcoded in `main.cpp`. Commands for the real robot are sent by [robot-controller](https://github.com/Society-5/robot-controller).

---

Part of **[Society-5](https://github.com/Society-5)**: a WowWee Robosapien X that explores a floor on its own, using a phone camera and QR codes as markers, with a mixed-reality (VR) interface for remote control. See [Introduction](https://github.com/Society-5/Introduction) for the project overview.
