#include "Gyro.h"

void setup()
{
    Gyro::Init();
    Serial.begin(115200);
}

void loop()
{
    Gyro::Update();
    Vector3 rotation = Gyro::RetrieveRotation();
    Vector3 acceleration = Gyro::RetrieveAcceleration();

    Serial.print("Rotation -> ");
    Serial.print(rotation.GetX());
    Serial.print(" ");
    Serial.print(rotation.GetY());
    Serial.print(" ");
    Serial.print(rotation.GetZ());

    Serial.print(" Acceleration -> ");
    Serial.print(acceleration.GetX());
    Serial.print(" ");
    Serial.print(acceleration.GetY());
    Serial.print(" ");
    Serial.println(acceleration.GetZ());
}