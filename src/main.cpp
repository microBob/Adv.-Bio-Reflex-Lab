#include "../include/main.h"

long startTime;

void setup()
{
  //stop();
  // pinModes
  pinMode(led_pin, OUTPUT);
  pinMode(piezo_pin, OUTPUT);
  pinMode(motor_pin, OUTPUT);

  pinMode(button_pin, INPUT);
  pinMode(light_pin, INPUT);

  // Test outputs
  //testOutputs();

  // Serial
  Serial.begin(9600);
  while (!Serial)
    ;

  // Wait for user to press start
  digitalWrite(led_pin, HIGH);
  Serial.println("Press to start...");
  while (!digitalRead(button_pin))
    ;
  digitalWrite(led_pin, LOW);
  startTime = millis();

  // Set random seed
  randomSeed(analogRead(A1));
}

void loop()
{
  delay(random(1000, 5000)); // wait 1-5 seconds per round

  switch (1) // #### SELECT TEST WITH THIS VALUE ####
  {
  case 1:
    lightReactionTest();
    break;
  case 2:
    soundReactionTest();
    break;
  case 3:
    touchReactionTest();
    break;
  case 4:
    lightAndSoundReactionTest();
    break;
  case 5:
    lightAndTouchReactionTest();
    break;
  case 6:
    touchAndSoundReactionTest();
    break;
  default:
    break;
  }

  // End Test after 2 minutes
  if ((millis() - startTime) >= 120000)
  {
    digitalWrite(led_pin, HIGH);
    Serial.println("TEST COMPLETE");
    stop();
  }
}