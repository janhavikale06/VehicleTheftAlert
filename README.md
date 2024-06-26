# VEHICLE THEFT ALERT AND ENGINE LOCK SYSTEM USING ARM7

## Overview:

1. A system designed to prevent vehicle theft using advanced technology.
2. Combines PIR Motion Sensor, GSM technology, and ARM7 microcontroller for efficient theft detection and prevention.

## Components:

1. PIR Motion Sensor: Detects motion around the vehicle. Triggers alert upon detecting unauthorized movement.
2. GSM Module: Facilitates communication between the vehicle and the owner's mobile phone via SMS.
3. ARM7 Microcontroller: A central processing unit that integrates all system components.
4. LCD Display: Displays theft detection messages.
5. Alarm System: Emits a beep sound to alert of unauthorized access.
6. Two Keys:
   a) Owner's Key: Authorized key for legitimate vehicle access.
   b) Direct Key: Unauthorized key triggering the alarm and theft detection mechanism.

## System Functionality:

1. Theft Detection:
   a) PIR Motion Sensor detects unauthorized motion near the vehicle.
   b) LCDs "Theft Detection!" message.
2. Alarm Activation:
   a) When the direct key is used, the alarm system is activated.
   b) A beep sound alerts surrounding individuals of potential theft.
3. SMS Communication:
   a) The GSM module sends an SMS to the vehicle owner's mobile phone upon detection of theft.
   b) Provides real-time information about the vehicle's status.
4. Engine Lock Mechanism:
   a) Upon receiving the alert, the vehicle owner sends an SMS command to lock the vehicle’s engine remotely.
   b) Ensures the thief cannot drive away with the vehicle.

## Communication Process:

1. Theft Detection Alert: PIR Motion Sensor detects movement. The GSM module sends an alert SMS to the registered mobile number.
2. Owner Response: The owner receives the theft alert message. Sends a command SMS back to the GSM module to lock the engine.

## Interfacing of the overall system:

<img width="775" alt="vehicleTheft" src="https://github.com/janhavikale06/VehicleTheftAlert/assets/81229872/e4974a0d-dbdf-439b-96e0-3d49a026ab04">

## Advantages:

1. Real-time theft detection and alert system.
2. Remote engine lock capability enhances vehicle security.
3. Immediate response mechanism reduces the risk of vehicle theft.
4. Audible alarm deters thieves and attracts attention from bystanders.

## Conclusion:

1. The Vehicle Theft Alert and Engine Lock System utilizing ARM7 is an effective solution to prevent vehicle theft.
2. By integrating motion detection, GSM communication, and remote engine control, the system ensures enhanced security and quick response to potential theft attempts.

## References:

1. https://www.academia.edu/63372516/Detection_of_Automobile_Theft_and_Engine_Locking_Using_Arduino?from_sitemaps=true&version=2
2. https://www.researchgate.net/publication/328293746_Anti-theft_Security_System_for_Vehicles
3. http://www.ijirset.com/upload/2019/march/117_REMOTE_RMK.pdf
4. http://proceeding.conferenceworld.in/BIT_30_Mar_2019/14BvDayVXaGB337.pd
5. https://www.ijrpr.com/uploads/V2ISSUE3/IJRPR289.pdf
