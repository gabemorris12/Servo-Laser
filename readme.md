# Purpose

***
In this project, a ClearPath servo from Teknic is programmed via Arduino Mega. The system takes in a distance input in
inches, then moves a laser to that distance (tolerance is within a 1/16th of an inch). The system is belt driven. Here
are the required components used for this project:

* [Arduino Mega](https://www.amazon.com/gp/product/B01EWNUUUA/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)
* [Keypad](https://www.amazon.com/outstanding-Adhesive-Membrane-Keyboard-Prototyping/dp/B08JYNM8D9/ref=sr_1_8?dchild=1&keywords=Arduino+keypad&qid=1627044087&s=industrial&sr=1-8)
* [Liquid Crystal I2C](https://www.amazon.com/gp/product/B0711WLVP9/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1)
* ClearPath Servo (SDSK model). Accessories can be
  found [here](https://www.teknic.com/clearpath-accessories-guide/accessories-guide-sd-dc/).
    * Power Supply (IPC-5)
    * Power Cables (IPC to ClearPath)
    * Controller Cable (8-pin molex mini)
    * Micro USB for ClearPath Setup
* DC to Dc Converter. This is used to step down the 75V power supply to 12V. One can be
  found [here](https://www.amazon.com/SMAKN-Converter-20V-75V-Module-96W-Waterproof/dp/B0711R5ZDR).
* Arduino Shield (optional). One was
  found [here](https://www.amazon.com/Electronics-Salon-Prototype-Terminal-Arduino-MEGA-2560/dp/B00UT13YXA/ref=sr_1_2_sspa?dchild=1&keywords=arduino+mega+shield&qid=1625768587&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzNzBHT04yNDNJTjRGJmVuY3J5cHRlZElkPUEwMzU1Mjg5MkVEUVdPNDFTREFFMiZlbmNyeXB0ZWRBZElkPUEwMDMyOTI5M0FWOFBRNTU1SUpXViZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=)
* Belt Components:
    * Tensioner (see parts folder)
    * Lase Mount (see parts folder)
    * [Aluminum Extrusion](https://www.grainger.com/product/80-20-Framing-Extrusion-16U249)
    * [GT2 Timing Pulley](https://www.amazon.com/gp/product/B077P8PQHK/ref=ppx_yo_dt_b_asin_title_o02_s00?ie=UTF8&psc=1)
    * [GT2 Timing Belt](https://www.amazon.com/gp/product/B07MF6TDHF/ref=ppx_yo_dt_b_asin_title_o03_s00?ie=UTF8&psc=1)
    * [Laser](https://www.amazon.com/gp/product/B07CGG8LDX/ref=ppx_yo_dt_b_asin_title_o08_s00?ie=UTF8&psc=1)
    * [Plate Kit](https://www.amazon.com/gp/product/B08B65GKRD/ref=ppx_yo_dt_b_asin_title_o09_s01?ie=UTF8&psc=1) (for
      mounting laser)

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
* See more examples on using the ClearPath package under the example folder in the ClearPathStepGen package.
    