# Voice-Controlled-Home-assistant--a-prototype
This project was created using arduino uno, esp 8286 and python . It also uses google's speech recognition services. It can convert voice commands to text and wirelessly send the command to  esp 8286, which sends this command to arduino. Arduino can trun the specified LED on or off. requires a internet connection to work.

Clone the repository to run the project. The code inside the folder "esp_ardionp_code" needs to be sent to the arduino board. Please make sure the esp 8286 is up and running.

Ensure you have python 3 installed in your PC. Turn the WiFi of your computer on. 

Opem a command prompt and run the following code 

` 
python driver.py
`

If this is the first time the program is running, it will search for the IP address of the esp 8286 to connect. After successfully connecting, you will be prompted to to either press 'T' to type in a command, or to type in 'S' to speak. You can now speak/ type specific commands on the screen to turn specific LEDs on and off on the arduino board

While developing this project, I only gave support for LED pins 1,2,3,4  on the arduino board. You need to connect LED lights with these pins.

Pin 2 & 3 of Arduino ar denoted as RX and TX. Connect TX and RX of ESP8266 respectively
