# FUCK M5-NEMO

![Fuck-Nemo Matrix Logo](https://github.com/Niximkk/fuck-nemo/blob/main/NEMOMatrix.png) Ubisoft, unkill watchdogs.

![M5-Nemo on M5StickC family and M5Cardputer](https://github.com/n0xa/m5stick-nemo/blob/main/M5-Nemo.jpg)

## My Fucking Changelog
* New bootscreen - [@gustavocelani](https://github.com/gustavocelani)
* Starting the process to save IR codes at SPIFFS/SD Card.
* Minor fixes and changes (no one cares).

## My Fucking ToDo list
* DESTROY THE FUCKING 7 SEGMENT CLOCK!!!!
* Fix bad PRs (by waiting the fix of course).

## Read this fucking FAQ
* Q: Will you publish it on M5burner?
  * Hell nah, compile it yourself. (And customize the code)
* Q: Will you create releases with .bin's?
  * Nuh uh.
* Q: Why is your code shitty?
  * Cuz its my personal version of nemo, just dont use it.
* Q: What if i dont know how to compile it?
  * [Youtube](https://www.youtube.com/), [Fucking Readme](https://github.com/Niximkk/fuck-nemo#building-from-source) etc... You will figure it out.
* Q: I cant compile it! :(
  * Womp womp.

## Features
[❕] No changes [❗] Changes
* ❕ [TV B-Gone](http://www.righto.com/2010/11/improved-arduino-tv-b-gone.html) Shut off many infrared-controlled TVs, projectors and other devices.
* ❗ [IR_Replay](https://github.com/FlasherTwelve/IR_Replay) Copy and send IR Codes (Need an [external module](https://github.com/Arduino-IRremote/Arduino-IRremote/blob/master/pictures/IRReceiverPinout.jpg)).
* ❗ [Flipper IR File](https://github.com/Lucaslhm/Flipper-IRDB) Flipper IR File support (sd card needed).
* ❕ [AppleJuice](https://github.com/ECTO-1A/AppleJuice) iOS Bluetooth device pairing spam
* ❗ Bluetooth device notification spamming for SwiftPair (Windows), Android and Samsung (With random MAC Address)
* ❕ WiFi Spam - Funny SSIDs, WiFi Rickrolling, and a Random mode that creates hundreds of randomly-named SSIDs per minute
* ❕ WiFi NEMO Portal - A captive portal that tries to social engineer email credentials - saves usernames and passwords to SD Card (if inserted into a supported reader)
* ❕ WiFi SSID Scanner - Display 2.4 GHz SSIDs nearby, get information about them, and even clone the SSIDs in NEMO Portal
* ❕ User-adjustable 24 Hour digital clock backed by the M5 Stick RTC so it holds relatively stable time even in deep sleep and low battery mode
* ❕ EEPROM-backed Settings for rotation, brightness, automatic dimming and NEMO Portal SSID
* ❗ Battery level and Clock at the main menu.
* ❕ Credits in settings menu

## ⚠️ How to use Flipper IR codes
- Go to the Flipper-IRDB repo and get your codes.
- Rename the file to IR_Codes.txt
- Put it in the root of the SD card.
- WAIT UNTIL ALL THE FUCKING CODES HAVE BEEN SENT. (otherwise it will stop working)

(No fucking idea if it works, waiting for the fix.)

## User Interface
There are three main controls:
* Home - Stops the current process and returns you to the menu from almost anywhere in NEMO
* Next - Moves the cursor to the next menu option. In function modes, this usually stops the process and returns you to the previous menu.
* Select - Activates the currently-selected menu option, and wakes up the dimmed screen in function modes  

* StickC and StickC-Plus
  * Power: Long-press the power button for 6 seconds to turn off the unit
  * Home: Tap the power button (closest to the USB port)
  * Next: Tap the side button
  * Select: Tap the M5 button on the front of the unit  

* Cardputer
  * Home: Tap the Esc/~/` key or the Left-Arrow/, key
  * Next/Prev: Tap the Down-Arrow/. key and Up-Arrow/; keys to navigate
  * Select: Tap the OK/Enter key or Right-Arrow/? key  

## Evil Portal
In Evil Portal mode, NEMO activates an open WiFi Hotspot named "Nemo Free WiFi" (configurable in portal.h) with DNS, DHCP and Web servers activated. 
* Evil Portal serves a fake login page that claims to provide internet access if you log in.
* This is a social engineering attack, and will log the username and passwords entered on the page. 
* From the Wifi Scan details, you can clone an existing SSID from the scan list. Exiting Evil Portal will clear the Evil Twin SSID
* You can view captured credentials by connecting to the portal from your own device and browsing to http://172.0.0.1/creds
* You can set a custom SSID by connecting to the portal from your own device and browsing to http://172.0.0.1/ssid
* If your device supports EEPROM for settings, the custom SSID you enter will be saved as the default, even if powered off.
* If your device has an SD Card reader with a FAT filesystem formatted card inserted, the usernames and passwords will be logged to nemo-portal-creds.txt on the SD Card for you to peruse later. 
* SD Card support is only enabled by default on the M5Stack Cardputer platform. It can be enabled on M5Stick devices but an SD Card reader must be built and attached to the front panel pin header.
* Evil Portal is only for use on professional engagements with a valid scope of work, educational or demonstration purposes. Storage, sale, or use of personal information without consent is against the law. 🤓

## Install .bin files manually with esptool.py
* Install ESP-IDF tools per the [Espressif Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/)
* Open the esp-idf CMD tool (on Windows) - on Mac or Linux, esp-idf.py and esptool.py should be in the system path.
* esptool.py --port COMPORT -b 115200 write_flash -z 0x0 M5Nemo-VERSION.bin
  * port may be a COM port e.g. COM4, COM11 on Windows. On Mac and Linux it will usually be in /dev such as /dev/ttyUSB0, /dev/ttyACM0 or /dev/cu.usbserial-3
  * M5Nemo-VERSION.bin should be a version you downloaded from a GitHub Release -- preferably the latest available.

## Building from Source
If you want to customize NEMO or contribute to the project, you should be familiar with building NEMO from source.
* Install Arduino IDE. I've used Arduino 1.8 on Linux and Windows, and Arduino 2.2 on Windows successfully.
* Install the M5Stack boards for Arduino IDE: In File -> Preferences, paste this URL into the "Boards Manager URLs" text box. Use commas between URLs if there are already URLs present.  https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
* If M5Stack -> M5Stick-C-Plus doesn't show up under Tools -> Boards, then use Tools -> Boards -> Boards Manager and search for M5Stack. This will install support for most of the M5Stack boards including the Stick C Plus.
* Ensure the correct device model (e.g. M5Stick-C, M5Stick-C-Plus or M5Cardputer) is selected in the boards menu.
* Install necessary libraries. In Sketch -> Include Library -> Library Manager, search for and install the following libraries and any dependencies they require:
  * M5StickCPlus, M5StickC or M5Cardputer
  * IRRemoteESP8266
* Un-comment the appropriate `#define` line near the top for your platform (STICK_C, STICK_C_PLUS or CARDPUTER)
* Switch partition schemes. `Tools` -> `Partition Scheme` -> `No OTA (Large APP)` - sometimes this option is labeled `Huge APP` 
* Configuration
  * The code should compile cleanly and work on an M5Stick C Plus out of the box from the master branch or a release tag.
  * Uncomment only the one appropriate `#define` option or compiler errors will occur. 
  * If for some reason the screen jumps from very dim at level 0 to almost fully bright at level 1 and further brightness levels don't affect anything, set the pct_brightness variable to false.
* Compile and upload the project

## Building from Source (with Arduino CLI)

- Install Arduino CLI
- Add M5Stack Index to Arduino Core
- Add M5Stack Libraries

```bash

# Install m5stack boards
arduino-cli core install m5stack:esp32  --additional-urls https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json --log-level warn --verbose

# Install required library
arduino-cli lib install M5Cardputer --log-level warn --verbose
arduino-cli lib install IRRemoteESP8266 --log-level warn --verbose

# Compile sketch
arduino-cli compile --fqbn m5stack:esp32:m5stack_cardputer -e --build-property build.partitions=huge_app --build-property upload.maximum_size=3145728 ./fuck-nemo.ino

```

- This will create multiple binaries based on partition sketch, you can merge a single binary using `esptool`
- Install esptool - `pip install -U esptool`

```bash

esptool.py --chip esp32s3 merge_bin --output FuckNemo.bin 0x0000 fuck-nemo.ino.bootloader.bin 0x8000 fuck-nemo.ino.partitions.bin 0x10000 fuck-nemo.ino.bin
```

- You can now flash the merged binary firmware using `esptool`

```bash

esptool.exe write_flash -z 0 FuckNemo.bin
```

## Building from Source (Docker)

- Install Docker
- Run `./scripts/docker-build.sh <configs/.env.>`
- Run `./scripts/flash.sh --device=<your-device-port>`

```sh
# This will build an image will all required libraries based on the configured platform, and it will compile, output and merge binaries
# By default this will compile for the M5Cardputer in en-us locale, ./config/.env.M5Cardputer
./scripts/docker-build.sh 

# If you want to select a different build config you can pass it as a parameter. See ./configs/ for various configurations
./scripts/docker-build.sh ./config/.env.M5Cardputer

# Binary files will be output to ./build
ls ./build

# This will flash the build output from the build step, it reuses the container image from the previous step.
# By default this will compile for the M5Cardputer in en-us locale, ./config/.env.M5Cardputer
./scripts/flash.sh --device=/dev/ttyusb0 

# If you passed a different build config make sure to pass it along to the flash script
./scipts/flash.sh --device=/dev/ttyusb0 --build-config=./config/.env.M5Cardputer
```
Things I probably won't merge in:
* My credit card info.
