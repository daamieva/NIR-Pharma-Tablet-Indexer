# NIR Tablet Indexer for Continuous Manufacturing

System designed to automatically move pharmaceutical tablets onto and off of a near-infrared (NIR) sensor. The NIR sensor allows for measuring tablet strength in a nondestructive manner. <mark>work</mark>

---
## Preface
In Pharmaceuticals, there are two main types of manufacturing strategies: batch manufacturing, which is the more traditional approach, and now continuous manufacturing, which has recently been adopted. As the name states, batch manufacturing completes the manufacturing process of a drug in batches, while continuous manufactures from 0 to 100% without stop. An advantage of continuous manufacturing is that, if there is any mishap or deviation detected downstream, engineers can alter parameters upstream during manufacturing so that loss of product is minimized.

Currently, the lab is exploring new technologies to aid in the the viability of testing the strength of tablets composed of granular material in a nondestructive manner. Normally, when something like a pill is tested for tensile strength, it is put under load in something like a compression test to find out the strength, (in other words the failure stength). after this, the pill is destroyed. For our case, we do not want to destroy the tablet, because we just want to test it to see if it is up to par with the threshold strength levels. Previous lab experiments have yielded that the tensile strength can be deduced by measuring the absorption of the tablets using Near-infrared scanner. 

After the lab determined that this can be done, I was brought onto the team to explore the possibility of making this nondestructive testing method also “in-line”, meaning it can occur in the continuous manufacturing line without any intervention.

## 🚀 Overview
The system I created moves tablets along a controlled conveyor belt using a motor-driven mechanism with guides, rollers, and optional counting/sorting sensors. Built to mimic small-scale industrial automation used in pharmaceutical production.
My design features a starwheel, which was inspired by the starwheels I worked with in filling lines of manufacturing bottled pharmaceuticals. The starwheel is used to move bottles using a vacuum to


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
