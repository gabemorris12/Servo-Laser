# Purpose
***
In this project, a ClearPath servo from Teknic is programmed via Arduino Mega. The system takes in a distance input in 
inches, then moves a laser to that distance (tolerance is within a 1/16th of an inch). The system is belt driven. Here
are the required components used for this project: 
* Arduino Mega
* Keypad
* Liquid Crystal I2C  
* ClearPath Servo (SDSK model). Accessories can be found [here](https://www.teknic.com/clearpath-accessories-guide/accessories-guide-sd-dc/).
    * Power Supply (IPC-5)
    * Power Cables (IPC to ClearPath)
    * Controller Cable (8-pin molex mini)
    * Micro USB for ClearPath Setup
* DC to Dc Converter. This is used to step down the 75V power supply to 12V. One can be found [here](https://www.amazon.com/SMAKN-Converter-20V-75V-Module-96W-Waterproof/dp/B0711R5ZDR).
* Arduino Shield (optional). One was found [here](https://www.amazon.com/Electronics-Salon-Prototype-Terminal-Arduino-MEGA-2560/dp/B00UT13YXA/ref=sr_1_2_sspa?dchild=1&keywords=arduino+mega+shield&qid=1625768587&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzNzBHT04yNDNJTjRGJmVuY3J5cHRlZElkPUEwMzU1Mjg5MkVEUVdPNDFTREFFMiZlbmNyeXB0ZWRBZElkPUEwMDMyOTI5M0FWOFBRNTU1SUpXViZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
* *Add belt components here*

# Environment
***
Here are the libraries that are not standard:
* [LiquidCrystal_I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
* Keypad ([Download Here](https://playground.arduino.cc/uploads/Code/keypad/index.zip))
* [ClearPathStepGen](https://github.com/Teknic-ClearPath/ClearPath-Arduino-Step-And-Direction/tree/master/Arduino%20Uno/ClearPathStepGen)

*Libraries are installed in "C:\Users\username\OneDrive\Documents\Arduino\libraries"*

If there are libraries missing, then troubleshoot at runtime.

# Additional References
***
## NYC CNC
* Good examples for using the ClearPath classes and move method are found [here](https://youtu.be/ZRURwDFvdAs?t=225).
* See more examples on using the ClearPath package under the example folder in the package.
    