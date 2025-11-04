## 👀 arduino-uno_home-assistant Overview  
<h1 align="center">A handmade photo camera</h1>  


## 🚀 Features  
<h1 align="center">This a portable mini photo camera.It has also a flash.Every photo saved with unique name in a sd card storage.</h1>  


## 🔎 Preparation
<details>
<summary>1. Components</summary>
'1' Arduino Uno<br>
'1' 16×2 LCD Screen<br>
'1' Flammable Gas Sensor (MQ-2)<br>
'1' Temperature and Humidity Sensor (DHT11)<br>
'1' Real-Time Clock Module (DS1302)<br>
'1' Flame Detection Sensor (IR Flame Sensor)<br>
'1' 5V Active Buzzer
</details>

2. `Use an SD card with a minimum capacity of 4 GB, formatted as FAT32 with a 32 KB allocation unit size.`
3. `Then insert this SD card into your ESP32-CAM board.`
4. `Connect your 'OV2640' camera to your ESP32-CAM board.`


## 📦 Setup 
1. `Refer to the 'circuit_camera-programming.png' diagram`
2. `Install the 'Arduino IDE' software and open 'esp32-cam_camera.ino' with 5 other file`
3. `File>Preferences>Additional Boards Manager URLs:(Click the double window button)`
>Paste this code  
```bash
https://dl.espressif.com/dl/package_esp32_index.json
```
4. `Click 'OK'`  
5. `Tools>Board>Boards Manager...`  
6. `Search 'esp32' by Espressif Systems, and install it` 
> ⚠️ **Warning:** Make sure you have installed the correct USB driver (CH340, CH341, FT232R / FTDI Driver, CP2102) before connecting the ESP32CAM to your computer.
7. `Plug the ESP32CAM into your computer`
8. `Tools>Board>esp32>'AI Thinker ESP32-CAM'`
9. `Tools>Port>'Select the esp's port'`



10. `Tools>Manage Libraries...>Install the libraries used in the code`
11. `Click the 'upload ➡️' button`  
✅ **To make sure it has been uploaded successfully, you should see the message 'Done uploading'** 
> ⚠️ **Advisory for Developers:** If you want to try this project in the future with new generation boards and you want to add new features like using 'DS1302 real time module', you must have 3 unused pins.

## 🎉 Run  
1. `Refer to the 'circuit_camera.png' diagram`  
2. `Let the electricity pass through the switch`  
3. `Press the reset button on the esp32cam`  
4. `You are ready to use your mini camera`  


## 🔒 License  
<h1 align="center">📜 GPL-3.0 License</h1>
