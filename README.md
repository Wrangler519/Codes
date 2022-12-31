# Codes


### System diagram:

<img width="367" alt="sys" src="https://user-images.githubusercontent.com/84453030/210120114-0bd35e84-de26-4f22-a690-558a5f8d9eec.png">

### Our final deliverable codes logic

use APDS sensor(proxomity) to control/switch between 2 modes: 1. sound mode, 2. joystick mode. Waving the hand at the apds will switch one mode to another.
```mermaid
graph TD;
    A[Get distance data from ADPS 9960] --> B{< 200}
    B -->|Yes| C[Switch Mode]
    C --> D[Sound Mode] --> A
    C --> E[Joystick Mode] --> A
    B ---->|No| A
```

### Codes Development Process
Attached below is the proposed idea of Wrangler(which is a bit different from the final deliverable). The proposed model is cute and interesting. We were thinking using a motion sensor APDS9960 to control the Wrangler to move in different directions. 

![image](https://user-images.githubusercontent.com/84453030/209241315-e3d71c71-575d-415a-b744-bcac83668311.png)

First thing we did was to plan the use of the pins of the QT PY 2040 board. We read through the datasheet and allocated the pins and memories for different uses. The pins are assigned as below:

<img width="429" alt="Screenshot 2022-12-22 at 6 27 30 PM" src="https://user-images.githubusercontent.com/84453030/209897570-e8ad2b4f-622c-4f0a-a5f1-6b90ff40baee.jpeg"> <img width="429" alt="Screenshot 2022-12-22 at 6 27 30 PM" src="https://user-images.githubusercontent.com/84453030/209241916-03a30a64-1e45-40bc-acb7-b7f7aba44143.png">

We started from making each small module work and then combined them altogether. They can be summarized as 
```mermaid
graph LR;
    QT_PY-->motion_sensor-->motor_driver-->2_DC_motors;   
```
```mermaid
graph LR;
    QT_PY --> joystick --> motor_driver --> 2_DC_motors ;
```
```mermaid
graph LR;
    QT_PY --> sound_sensor --> servo_motor & motor_driver;
```
After coding, configuring, testing all the broke-down functions mentioned, we mounted them onto the chassis. The breadboard was secured on the first layer of acylic board on the chassis, the wires were carefully arranged for clarity and ease of debugging. The second layer of acrylic board was used hold the "wrangler" toy for a better visual prospective.

<img width="329" alt="Screenshot 2022-12-22 at 6 27 30 PM" src="https://user-images.githubusercontent.com/84453030/209898140-7996e309-d591-415a-a19e-065560bb61e1.jpg"> <img width="329" alt="Screenshot 2022-12-22 at" src="https://user-images.githubusercontent.com/84453030/209898345-888ee383-af6d-402c-8cb5-d80cd5f6b820.jpg"> 

Then we tried to test the functions in an integrated manner by redesigning the C file, Cmake files and code structures. After failing due to a few bugs, we managed to get functions working. However, there are still structural problems that we found out during the process. The wrangler was placed too high and when the motors drive the chassis to move, especially forward,  the Wrangler loss balance. Thus, we decided to implement some weights at the bottom layer to lower the center of gravity and adjusting the running interval of motor for a smoother movement. 

The final deliverable looks like this: 

<img width="229" alt="Screenshot 2022-12-22 at 6 27 30 PM" src="https://user-images.githubusercontent.com/84453030/209244690-b042743f-b8d5-4b7b-85bc-d5e7fa7b8b83.jpg"> <img width="229" alt="Screenshot 2022-30 PM" src="https://user-images.githubusercontent.com/84453030/209897828-662b3cfe-c631-4b5c-af62-9ba5810232ae.jpg"> <img width="229" alt="Screenshot 2022-12-2 PM" src="https://user-images.githubusercontent.com/84453030/209898459-58e787cb-3f0b-4564-a662-14d6d60ff8f2.jpg"> 

**So, the final deliverable codes logic is:**

use APDS sensor(proxomity) to control/switch between 2 modes: 1. sound mode, 2. joystick mode. Waving the hand at the apds will switch one mode to another.
```mermaid
graph TD;
    A[Get distance data from ADPS 9960] --> B{< 200}
    B -->|Yes| C[Switch Mode]
    C --> D[Sound Mode] --> A
    C --> E[Joystick Mode] --> A
    B ---->|No| A
```


### Check here to download all the codes in .zip:

https://github.com/skyfall88888/ESE519-FinalProj/blob/main/Wrangler.zip

