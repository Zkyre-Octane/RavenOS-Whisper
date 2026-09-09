# RavenOS-Whisper

RavenOS Whisper is a minimal controller-oriented variant of RavenOS Umbra.
This build extracts core functions, libraries, and hardware abstractions from Umbra
and adapts them for an ESP-NOW based transmission system.

Whisper retains the original SSD1306 graphics driver but removes menus, buttons,
and higher-level UI layers to provide a lightweight, low-latency control interface.

The controller uses:
  - SSD1306 OLED display for telemetry output
  - Joystick input for directional and speed control
  - ESP-NOW for wireless command transmission

Whisper is designed to operate the Wraith, an experimental UGV platform that does
not yet have an official name. It serves as the communication and control layer
within the RavenOS ecosystem, focusing on reliability, simplicity, and a gothic
thematic identity.

References:
  - RavenOS Umbra .......... core architecture and libraries
  - ESP-NOW ................ wireless protocol for command transmission
  - SSD1306 ................ display driver for telemetry
  - Wraith UGV ............. current working name of the vehicle
