
# **Starwheel Indexing Stepper Controller**

This Arduino sketch drives a stepper motor used in a **starwheel / indexing mechanism**.
The system rotates the wheel a fixed number of degrees, pauses, and repeats — ideal for simple indexing mechanism.

---

## **Features**

* Fixed-angle indexing (default: **45° per cycle**)
* Adjustable motor RPM
* Adjustable pause time between movements
* Simple serial interface: **pause** and **resume** commands
* Built-in optional coil-release logic to reduce motor/driver heat
* Uses the Arduino **Stepper** library (included by default — no extra libraries required)

---

## **Hardware Setup**

| Component     | Notes                                                |
| ------------- | ---------------------------------------------------- |
| Stepper Motor | 200 steps/rev (1.8°/step typical NEMA 17 or similar) |
| Driver        | L298N or similar H-bridge driver                     |
| Arduino Pins  | 8, 9, 10, 11 → connected to motor driver inputs      |

Modify these if your wiring differs:

```cpp
const int motorPins[4] = {8, 9, 10, 11};
```

---

## **Configurable Parameters**

You can tune the motor motion by editing these values:

```cpp
const float moveDegrees = 45.0;   // degrees per indexing cycle
const int pauseTime = 5*1000;     // milliseconds between movements
const int motorSpeed = 10;        // RPM
```

**Typical use-cases:**

* Increase `motorSpeed` → faster rotation
* Increase `pauseTime` → longer dwell time
* Adjust `moveDegrees` → change indexing angle

---

## **Serial Control**

To control the motor, open the Serial Monitor.

Send:

| Command | Function         |
| ------- | ---------------- |
| `p`     | Pause the motor  |
| `r`     | Resume operation |

Messages will print confirming each action.

---

## **How to Upload**

1. Open the `.ino` file in **Arduino IDE** or VS Code with the Arduino extension.
2. Select the correct **board** and **port**.
3. Click **Upload**.

No external libraries needed — `Stepper.h` comes bundled with Arduino IDE (Just assure you include it at the beginning of the sketch).

---

## **Folder Structure**

```
software/
  code/
    StepMotorCode.ino
```

---

## **Notes**

* Coils auto-release after each movement to reduce heat.
  If you need holding torque, comment out the coil-release section.
* If direction is reversed, switch:

```cpp
motor.step(+stepsToMove);
```

to

```cpp
motor.step(-stepsToMove);
```

---
