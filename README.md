---

# Arduino IR and Bluetooth Control System

This repository contains the Arduino sketch and necessary data definitions for controlling various devices via infrared (IR) signals. The system also optionally supports Bluetooth commands for remote control functionalities.

## Overview

The project consists of two main components:
1. **IR Control:** Send and receive IR signals to/from devices like fans or air conditioners to control operations such as power state and fan speed.
2. **Bluetooth Control:** (Optional) Use Bluetooth for remote command input via a connected Bluetooth module.

The included Arduino sketch (`sketch_mainIR.ino`) sets up the hardware interfaces and controls the device behavior based on IR or Bluetooth inputs. Definitions for IR signal patterns are stored in `data.h`.

## Hardware Requirements

- Arduino Uno or compatible board
- IR LED for sending IR signals
- IR Receiver Module (e.g., TSOP4838)
- Bluetooth Module (HC-05 or HC-06) for Bluetooth capabilities (optional)
- Connecting wires
- Breadboard

## Software Dependencies

- [IRLibRecvPCI](https://github.com/cyborg5/IRLib2): For receiving IR signals.
- [IRLibSendBase](https://github.com/cyborg5/IRLib2): For sending IR signals.
- [IRLib_HashRaw](https://github.com/cyborg5/IRLib2): For handling raw IR data.
- [SoftwareSerial](https://www.arduino.cc/en/Reference/softwareSerial): For Bluetooth communication (if used).

## Installation

1. **Setup Arduino Environment:**
   - Download and install the Arduino IDE from [Arduino Software](https://www.arduino.cc/en/software).
2. **Library Installation:**
   - Open the Arduino IDE, go to Sketch > Include Library > Manage Libraries.
   - Search for "IRLib2" and install it for handling IR signals.
   - If using Bluetooth, ensure the `SoftwareSerial` library is installed (included with Arduino IDE).
3. **Clone the Repository:**
   - Use `git clone https://github.com/yourusername/yourprojectname.git` or download the ZIP file and extract it in your Arduino projects directory.

## Configuration

- **Pin Configuration:**
  - Define the pins used for IR transmission and reception in the Arduino sketch. The default is pin 2 for IR receive.
  - If using Bluetooth, set the TX and RX pins appropriately, as defined in the sketch.
- **IR Patterns:**
  - Modify the `data.h` file if different IR codes are required. This file contains the raw IR data for various commands.

## Usage

1. **Upload the Sketch:**
   - Open `sketch_mainIR.ino` in the Arduino IDE.
   - Connect your Arduino board to your computer.
   - Select the correct board type and port in Tools menu.
   - Click on Upload.
2. **Testing:**
   - Point an IR remote at the receiver to test receiving capabilities.
   - Use the serial monitor to view output and debug.
   - If using Bluetooth, pair the module with a smartphone and send commands via a terminal app.

## Functionality

- **IR Receiving and Sending:**
  - The system can receive IR signals, decode them, and print the decoded information to the serial monitor.
  - It can send pre-defined IR signals stored in `data.h` in response to Bluetooth commands or internal logic.
- **Bluetooth Integration:**
  - If enabled, commands can be received through Bluetooth to trigger specific actions (like changing fan speed or turning a device on/off).

## Customization

- Developers can add additional commands and modify existing IR patterns in the `data.h` file.
- Modify the main sketch to handle additional functionality such as more complex command sequences or integration with other sensors and inputs.

## Contributing

Contributions are welcome. Please fork the repository and submit pull requests with your enhancements.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE) file for details.

## Acknowledgments

- Thanks to the IRLib2 library maintainers for providing robust tools for IR signal processing.

---
