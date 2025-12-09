#include <Stepper.h> // Stepper library for stepper motors

// --- Motor Setup ---
const int stepsPerRevolution = 200;      // 1.8° per step → 200 steps = 360°
const int motorPins[4] = {8, 9, 10, 11}; // Pins connected to L298N inputs IN1–IN4

// Create Stepper motor object
Stepper motor(stepsPerRevolution, motorPins[0], motorPins[1], motorPins[2], motorPins[3]);

// --- User Settings ---
const float moveDegrees = 45.0;          // Rotation per cycle
const int pauseTime = 5 * 1000;          // Pause between moves (ms)
const int motorSpeed = 10;               // RPM

// Pause flag
bool paused = false;

void setup() {
  motor.setSpeed(motorSpeed);

  // Configure coil control pins (required for manual de-energizing)
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);
  Serial.println("Stepper 45-degree indexing started...");
  Serial.println("Press 'p' to PAUSE, 'r' to RESUME.");
  Serial.println("Motor holding torque ENABLED by default.");
  Serial.println("To ENABLE coil de-energizing, uncomment the block at the bottom of loop().");
}

void loop() {

  // --- SERIAL PAUSE / RESUME ---
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == 'p') {
      paused = true;
      Serial.println("Motor PAUSED.");

      // OPTIONAL: De-energize while paused
      // Uncomment next 4 lines to disable torque when paused
      /*
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(11, LOW);
      */
    }

    if (cmd == 'r') {
      paused = false;
      Serial.println("Motor RESUMED.");
    }
  }

  // If paused → stop movement loop
  if (paused) {
    delay(100);
    return;
  }

  // --- MOTOR MOVEMENT ---
  int stepsToMove = (moveDegrees / 360.0) * stepsPerRevolution;

  Serial.print("Moving ");
  Serial.print(moveDegrees);
  Serial.println(" degrees...");

  motor.step(+stepsToMove);   // Change to -stepsToMove for CCW

  // --- PAUSE BETWEEN MOVEMENTS ---
  Serial.print("Pausing for ");
  Serial.print(pauseTime);
  Serial.println(" ms...");
  delay(pauseTime);

  // -------------------------------------------------------------------
  // OPTIONAL: DE-ENERGIZE MOTOR COILS AFTER EACH MOVE TO SAVE POWER AND REDUCE HEAT
  //
  // ENABLE THIS BLOCK *ONLY IF YOU WANT*:
  //  - Lower heat
  //  - Lower power usage
  //  - No holding torque between steps
  //  - Shaft can spin freely if pushed
  //
  // !!! DEFAULT: DISABLED (motor stays energized to hold position)
  //
  // To enable, remove the /* */ around this block:
  /*
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  Serial.println("Coils de-energized.");
  */
  // -------------------------------------------------------------------
}