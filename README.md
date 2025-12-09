# NIR Tablet Indexer for Continuous Manufacturing

System designed to automatically move pharmaceutical tablets onto and off of a near-infrared (NIR) sensor. The NIR sensor allows for measuring tablet strength in a nondestructive manner. <mark>work</mark>

---
## Preface
In Pharmaceuticals, there are two main types of manufacturing strategies: 
* **Batch manufacturing**: Material is made in discrete lots, with defined pauses in-between. The pauses allow for quality control, but at the cost of production time, and not realizing an error until an entire batch is done.
* **Continuous manufacturing**: Material flows nonstop from raw ingredients to finished product. Quality is monitored and can be altered automatically in real time using PAT tools. The main advantage here is that by improving the mechanisms of monitoring the product, product waste can be reduced.
<!-- include group name -->
The lab I am working at, FLEX Lab, has come up with a way to measure tensile strength of a tablet in a non-destructive manner by correlating it to the size distribution of granules using a near-infrared (NIR) sensor.

Normally, when something like a tablet is tested for tensile strength, it is put under load until failure to determine its strength. After this, the tablet is destroyed and no longer product. So, this advancement will unlock a new way to measure the tablets as they are manufactured - if it can be integrated into the continuous manufacturing line. Which is where I come in.

I was brought onto the team to explore the possibility of making this nondestructive testing method also “in-line”, meaning it can occur in the continuous manufacturing line automatically without slowing down the flow of production.

## Overview
The system I created moves the tablets onto and off of the NIR sensor using a starwheel device. I was inspired to make this design "revolve" (no pun intended) around the starwheel technology after seeing it used to move bottled pharmaceuticals and other objects within assembly lines. The starwheel is powered by a stepper motor and arduino. 
This is the first prototype, so the goal here was to prove that a tablet could be indexed onto and off of the sensor in a quick and controlled manner, all while measuing the tablets. 


---

## 🎥 Demo
(Add GIF or link to your demo video here)

---

## 🛠️ Hardware Components
- Motor: (NEMA17)
- Motor driver: L298N
- Microcontroller: Arduino UNO (any similar microcontroller can be used)
- Frame: 3D-printed parts
- Sensor: NIR Sensor
- Power: 12V supply

Full Bill of Materials in `/hardware/BOM.csv`.

---

## 📐 CAD Files
All custom-designed components are in `/cad`.

Include:
- NIR Tablet Indexer Stand   
- NIR Tablet Indexer Stator
- NIR Tablet Indexer Rotor

---

## 🔌 Wiring Diagram
![Wiring Diagram](docs/wiring-diagram.png)

---

## Software: Arduino Stepper Indexer
A simple, configurable 45° indexing mechanism controlled by an Arduino + L298N driver.

👉 See the full documentation here:  
[`/software/Arduino/README.md`](software/Arduino/README.md)


---

## 🧪 Testing & Results
See `/results` for:
- Speed measurements  
- Stability tests  
- Counting accuracy (if applicable)  

---

## 📚 Future Improvements
- Add camera-based tablet detection
- Add sorting mechanism
- Add hopper feeder
- Add adjustable speed control via UI

---
