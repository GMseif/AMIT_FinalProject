Electric Heater Controller (ATmega32)
== Overview ==
This project implements a simple electric heater controller using the ATmega32 microcontroller.
The system measures temperature using an LM35 sensor and controls the heater based on a user-defined temperature setting.

== Features ==
Temperature measurement using LM35 sensor
Display temperature on a 7-segment display
Ability to set the desired temperature
Heater turns ON or OFF automatically depending on temperature
Temperature readings averaged for more stable results
Settings saved using EEPROM

== Hardware Components ==
ATmega32 Microcontroller
LM35 Temperature Sensor
Seven Segment Display
Push Buttons
Heater (simulated with LED)

== How the System Works ==
The LM35 sensor reads the current temperature.
The value is converted using the ADC.
The temperature is displayed on the seven segment display.
The user can set the desired temperature.
The heater turns:
ON if the temperature is lower than the set value
OFF if the temperature is higher than the set value
To improve stability, the system calculates the average of multiple readings.
