# NIR Pharmaceutical Tablet Indexer for Continuous Manufacturing

---
## Preface
In Pharmaceuticals, there are two main types of manufacturing strategies: 
* **Batch manufacturing**: Material is made in discrete lots, with defined pauses in-between. The pauses allow for quality control, but at the cost of production time and potentially not realizing an error until an entire batch is done.
* **Continuous manufacturing**: Material flows nonstop from raw ingredients to finished product. Quality is monitored and can be altered automatically in real time using process analytical technology (PAT) tools. The main advantage here is that by improving the mechanisms of monitoring the product, product waste can be reduced.
<!-- include GROUP name -->
I am part of [`Purdue University’s Continuous Solids Processing Pilot Plant`](https://engineering.purdue.edu/CP3) at FLEX Lab, which does reasearch in the realm of continuous manufacturing for granular materials. The group has recently come up with a way to deduce the tensile strength of a tablet in a non-destructive manner by correlating it to the size distribution of granules using a near-infrared (NIR) sensor. The NIR sensor measures the NIR spectra of each tablet to essentially see how dense each tablet is. This density is critical for tablet manufacturing. if the tablet is not dense enough, it is succeptible to breaking in transport. If it is too dense, it can have problems with taking too long to dissolve once ingested. If the tablet density is determined to be undesireable by the NIR sensor, feedback can be sent upstream to the tablet press, which can then change the pressure at which it presses tablets. This can be another way to reduce material in a continuous manufacturing line, if we can implement the technology properly. This is where my prototype comes in to the picture.

I was brought onto the team to explore the possibility of making this nondestructive testing method also “in-line”, meaning it can occur in the continuous manufacturing line automatically without slowing down the flow of production.

## Overview
The system I created moves the tablets onto and off of the NIR sensor using a starwheel device. I was inspired to make this design "revolve" (no pun intended) around the starwheel technology after seeing it used to move bottled pharmaceuticals and other objects within assembly lines. The starwheel is powered by a stepper motor and arduino. 
This is the first prototype, so the goal here was to just prove that a tablet could be indexed onto and off of the sensor in a quick and controlled manner, all while displaying a consistent measurement of the light distribution for each tablet. Check out how it works in [`media/`](/media/)

*The following document regarding IP [`Purdue Research IP`](https://www.purdue.edu/research/oevprp/regulatory-affairs/intellectual-property-faq.php) shows that since I was an unpaid undergraduate researcher and did not use Purdue funds or grants to complete my work, this project is my intellectual property.*

---

### Hardware Components
* Stepper Motor: NEMA17
* Motor driver: L298N
* Microcontroller: Arduino UNO (any similar microcontroller can be used)
* Frame: 3D-printed parts
* Sensor: NIR Sensor
* Power: 12V supply

---

### CAD Files & Engineering Drawings
All custom-designed components are in [`hardware/mechanical/cad/`](hardware/mechanical/cad/).

Include:
* NIR Tablet Indexer Stand   
* NIR Tablet Indexer Stator
* NIR Tablet Indexer Rotor
* NIR sensor dummy representation for testing

Engineering drawings are in [`hardware/mechanica/drawings/](hardware/mechanical/drawings/)

---

### Wiring Diagram
Schematic for electronical components is in [`hardware/electronics/`](hardware/electronics/)

---

### Software: Arduino Stepper Indexer
A simple, configurable 45° indexing mechanism controlled by an Arduino + L298N driver.

Code and documentation here: [`software/`](software/)

---

## Future Improvements
The NIR sensor used needed to be shipped back to the company which lent it. Therefore, we were unable to capture as much data as desired. However, when the project resumes, I have the following improvements in mind:
* Alter base leg height to match sensor height.
* Add ramp to use gravity to feed tablets from hopper to the starwheel one at a time. This will eliminate the need for me to place tablets onto the base, and allow integration into continuous manufacturing line.
* Add pathway for tablets to go after being measured. Currently there is just a hole in the base where they drop out from, but the next iteration will include a ramp to guide them through the process. 
* Create closed loop in some manner to be able to feed signal upstream and alter tablet composition parameters as needed.
