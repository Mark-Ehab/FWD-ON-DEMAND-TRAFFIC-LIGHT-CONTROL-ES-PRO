# FWD-ON-DEMAND-TRAFFIC-LIGHT-CONTROL-ES-PRO
This is the sescond project for FWD Embedded Systems Professional Track that tries to simulate an on-demand traffic light
## Hardware requirements:
- ATmega32 microcontroller
- One push button connected to INT0 pin for pedestrian
- Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
- Three LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
## Mechanism
### In normal mode:
Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
### In pedestrian mode:
1. Change from normal mode to pedestrian mode when the pedestrian button is pressed.
2. If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
3. If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both 4.Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
4. At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
5. After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
6. Traffic lights signals are going to the normal mode again.

## System flowchart 
![OnDemandTrafficLightFlowChart](https://user-images.githubusercontent.com/72959499/193889037-dfa1ee15-72df-4e7f-92c0-7203217c0352.png)
## Clarifing videos and documentation 
### [Click Here For Videos and Documentaion](https://drive.google.com/drive/folders/1r5-yCQkoHnk9iywSS6tAkT0hyzMqenp8?usp=sharing)