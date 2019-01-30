#include <Servo.h> // bibliotheque du servo moteur
Servo servoMotor;  // déclarer le servo moteur
#include <HCSR04.h>  // bibliotheque du capteur a distance
UltraSonicDistanceSensor distanceSensor(7, 8);  // déclarer le capteur a distance 

void setup() {
  Serial.begin(9600); // regler la vitesse de transmission d'affichage
  
  servoMotor.attach(10);  // le pin du servo moteur
  servoMotor.write(80);  // valeur en degré sur servo moteur
}

void loop() {
  double distance = distanceSensor.measureDistanceCm();  // activer le capteur de distance en boucle
Serial.println (distance); // affichage en boucle des valeurs du capteur a distance sur le moniteur

if(distance< 29 && distance>0 ) {  // double condition sur la distance du capteur
  servoMotor.write(80); // couvercle poubelle ouvert
  delay(5000);

} else {
  servoMotor.write(10); // couvercle poubelle fermé
  
}
}
