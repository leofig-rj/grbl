![GitHub Logo](https://github.com/gnea/gnea-Media/blob/master/Grbl%20Logo/Grbl%20Logo%20250px.png?raw=true)

Grbl is a no-compromise, high performance, low cost alternative to parallel-port-based motion control for CNC milling. This version of Grbl runs on an Arduino with a 328p processor (Uno, Duemilanove, Nano, Micro, etc).

The controller is written in highly optimized C utilizing every clever feature of the AVR-chips to achieve precise timing and asynchronous operation. It is able to maintain up to 30kHz of stable, jitter free control pulses.

It accepts standards-compliant g-code and has been tested with the output of several CAM tools with no problems. Arcs, circles and helical motion are fully supported, as well as, all other primary g-code commands. Macro functions, variables, and most canned cycles are not supported, but we think GUIs can do a much better job at translating them into straight g-code anyhow.

Grbl includes full acceleration management with look ahead. That means the controller will look up to 16 motions into the future and plan its velocities ahead to deliver smooth acceleration and jerk-free cornering.

* This version of Grbl is based on the wonderful Grbl version v1.1h.20190825 from https://github.com/gnea/grbl.
The objective was to create a command for another discreet output and allow the adaptation of an Anet A8 3D printer to OpenPnP.
In this way we can control the Vacuum Pump, the LED of the Upper Camera, the LED of the Lower Camera and the Angle of the Head, with M03/M04, M08/M09, M106/M107 and X Axis, respectively.
Cooling Fan ON (M106) and Cooling Fan OFF (M107) commands were created, acting on port A4. For this, the option M7_COOLANT_MIST was removed.

* For installation see https://github.com/gnea/grbl.

```
List of Supported G-Codes in Grbl v1.1:
  - Non-Modal Commands: G4, G10L2, G10L20, G28, G30, G28.1, G30.1, G53, G92, G92.1
  - Motion Modes: G0, G1, G2, G3, G38.2, G38.3, G38.4, G38.5, G80
  - Feed Rate Modes: G93, G94
  - Unit Modes: G20, G21
  - Distance Modes: G90, G91
  - Arc IJK Distance Modes: G91.1
  - Plane Select Modes: G17, G18, G19
  - Tool Length Offset Modes: G43.1, G49
  - Cutter Compensation Modes: G40
  - Coordinate System Modes: G54, G55, G56, G57, G58, G59
  - Control Modes: G61
  - Program Flow: M0, M1, M2, M30*
  - Coolant Control: M8, M9
  - Fan Control: M106, M107
  - Spindle Control: M3, M4, M5 (In our case, we only use M03 and M04.)
  - Valid Non-Command Words: F, I, J, K, L, N, P, R, S, T, X, Y, Z
```
