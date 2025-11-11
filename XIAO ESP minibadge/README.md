## Seeed XIAO ESP32 Minibadge
### Images
<img height="200" alt="image" src="https://github.com/user-attachments/assets/56bc166a-cdfb-4ba8-b20b-36bac40fdcd9" /> <img height="200" alt="image" src="https://github.com/user-attachments/assets/4d7cbb31-693a-40bc-a030-e4964991c0f7" /> <img height="200" alt="image" src="https://github.com/user-attachments/assets/ea113d91-fde4-4b09-8662-196e06823c00" />

## Description
A Minibadge that can hold and power the Seeed XIAO ESP32 modules. It features 1206 diodes to prevent the XIAO from backfeeding power to the main badge, should you plug USB in at the same time. The Minibadge has solderable jumper pads to connect 3.3v, 5v, SDA, and SCL to your ESP. This is untested, and will be updated, but I recommend just soldering the 3.3V pad. I would like to see if it's at all possible for the badge next year to work with this badge over I2C.

Supports:
* [XIAO ESP32-S3 + Wio-SX1262 (Meshtastic)](https://www.seeedstudio.com/Wio-SX1262-with-XIAO-ESP32S3-p-5982.html)
* [XIAO ESP32-C6 (Thread/Zigbee)](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C6-p-5884.html)
* [XIAO ESP32-S3 Sense (Camera/SD card)](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html)
* Other XIAO ESPs are untested, but if the pinout is the same, it will work.

Possible projects:
* [Meshtastic node minibadge](https://www.seeedstudio.com/Wio-SX1262-with-XIAO-ESP32S3-p-5982.html)
* [Zigbee node minibadge](https://www.seeedstudio.com/Seeed-Studio-XIAO-ESP32C6-p-5884.html)
* [Picture/video recorder minibadge](https://www.seeedstudio.com/XIAO-ESP32S3-Sense-p-5639.html)
* [LED matrix minibadge](https://www.seeedstudio.com/6x10-RGB-MATRIX-for-XIAO-p-5771.html)
* [GNSS minibadge](https://www.seeedstudio.com/L76K-GNSS-Module-for-Seeed-Studio-XIAO-p-5864.html)
* [Temp/humidity/light sensor minibadge](https://www.seeedstudio.com/XIAO-LOG-p-6341.html)
* [mmWave sensor minibadge](https://www.seeedstudio.com/Seeed-Studio-XIAO-24Ghz-mmwave-Human-Static-Presence-Module-p-6266.html)

## Flashing The XIAO ESP32S3
Flashing the XIAO ESP32S3 is incredibly straightforward, following the standard procedure for ESP32 devices:

* Connect the Device: Use a USB Type-C cable that supports data transfer to connect the device to your computer.
* Visit the Flasher Tool: Open [Meshtastic Flasher](https://flasher.meshtastic.org/).
* Select Your Device: From the device list, choose Seeed Xiao ESP32-S3.
* hoose Firmware: Select your preferred firmware version and click on Flash.
* Review Changelog: The tool will display a changelog—click Continue.
* Perform Full Erase: For the best results, select Full Erase and Install, then click Update.
* Reboot: Once the device reboots, it’s ready to pair.

## Pairing the Device
Pairing the XIAO ESP32S3 with the Meshtastic app is as simple as with any other Meshtastic device:

* Download the Meshtastic App: Available on both the App Store (iOS) and Google Play (Android).
* Bluetooth Pairing: Open the Meshtastic app and navigate to the Bluetooth page. Wait a moment for your XIAO ESP32S3 to appear in the list of available devices. It will display a Node ID and additional details in the app.
* Enter Pairing Code: Select the XIAO ESP32S3 from the list and enter the pairing code 123456 when prompted. If it’s not 123456, check the terminal output after flashing to find the correct pairing code.
* Set Region: After pairing, you’ll be prompted to select your region. Choose the appropriate setting for your location. The device will restart to apply the region settings.
