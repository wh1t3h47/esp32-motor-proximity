#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper myStepper(stepsPerRevolution, 19, 18, 5, 17);

const int sensorPin = 22;

bool motorLigado = false;
bool ultimoEstadoSensor = LOW;

void setup() {
  pinMode(sensorPin, INPUT);
  myStepper.setSpeed(10);
}

void loop() {
  bool estadoAtualSensor = digitalRead(sensorPin);

  if (estadoAtualSensor == HIGH && ultimoEstadoSensor == LOW) {
    motorLigado = !motorLigado;
  }

  if (motorLigado) {
    myStepper.step(10);
  }

  ultimoEstadoSensor = estadoAtualSensor;
}
