#include "Gyro.h"

bool Gyro::Handler::m_Initialised = false;
bool Gyro::Handler::m_GyroInitialised = false;

Vector3 Gyro::Handler::m_Gyro;
Vector3 Gyro::Handler::m_CalibratedGyro;
Vector3 Gyro::Handler::m_Accelerometer;
Vector3 Gyro::Handler::m_GyroAcceleration;
Vector3 Gyro::Handler::m_RawRotation;
Vector3 Gyro::Handler::m_Rotation;
Vector3 Gyro::Handler::m_Offset;

long Gyro::Handler::m_Timer = 0;

void Gyro::Handler::InitialiseRegisters()
{
    Wire.beginTransmission(0x68);
    Wire.write(0x6B);
    Wire.write(0x00);
    Wire.endTransmission();

    Wire.beginTransmission(0x68);
    Wire.write(0x1C);
    Wire.write(0x10);
    Wire.endTransmission();

    Wire.beginTransmission(0x68);
    Wire.write(0x1B);
    Wire.write(0x08);
    Wire.endTransmission();
}

void Gyro::Handler::ProcessMovement()
{
    m_Gyro.Subtract(m_CalibratedGyro);

    m_RawRotation.AddY(m_Gyro.GetX() * 0.0000611);

    m_RawRotation.AddX(m_Gyro.GetY() * 0.0000611);

    m_RawRotation.AddY(m_RawRotation.GetX() * sin(m_Gyro.GetZ() * 0.000001066));
    m_RawRotation.SubtractX(m_RawRotation.GetY() * sin(m_Gyro.GetZ() * 0.000001066));

    double magnitude = m_Accelerometer.Magnitude();

    m_GyroAcceleration.SetY(asin(m_Accelerometer.GetY() / magnitude) * 57.296);

    m_GyroAcceleration.SetX(asin(m_Accelerometer.GetX() / magnitude) * -57.296);

    if (m_GyroInitialised)
    {
        m_RawRotation.SetY(m_RawRotation.GetY() * 0.9996 + m_GyroAcceleration.GetY() * 0.0004);

        m_RawRotation.SetX(m_RawRotation.GetX() * 0.9996 + m_GyroAcceleration.GetX() * 0.0004);
    }
    else
    {
        m_RawRotation.SetY(m_GyroAcceleration.GetY());
        m_RawRotation.SetX(m_GyroAcceleration.GetX());
        m_GyroInitialised = true;
    }

    m_Rotation.SetX(m_Rotation.GetX() * 0.9 + m_RawRotation.GetX() * 0.1 + m_Offset.GetX());
    m_Rotation.SetY(m_Rotation.GetY() * 0.9 + m_RawRotation.GetY() * 0.1 + m_Offset.GetY());
    m_Rotation.SetZ(m_Rotation.GetZ() * 0.9 + m_RawRotation.GetZ() * 0.1 + m_Offset.GetZ());
}

void Gyro::Handler::ReadRegisters()
{
    Wire.beginTransmission(0x68);
    Wire.write(0x3B);
    Wire.endTransmission();
    Wire.requestFrom(0x68, MAX_BYTES);

    while (Wire.available() < MAX_BYTES)
    {
    }

    m_Accelerometer.SetX(Wire.read() << 8 | Wire.read());
    m_Accelerometer.SetY(Wire.read() << 8 | Wire.read());
    m_Accelerometer.SetZ(Wire.read() << 8 | Wire.read());

    int temp = Wire.read() << 8 | Wire.read();

    m_Gyro.SetX(Wire.read() << 8 | Wire.read());
    m_Gyro.SetY(Wire.read() << 8 | Wire.read());
    m_Gyro.SetZ(Wire.read() << 8 | Wire.read());
}

Vector3 Gyro::Handler::GetAcceleration()
{
    return m_Accelerometer;
}

Vector3 Gyro::Handler::GetRotation()
{
    return m_Rotation;
}

void Gyro::Handler::Calibrate()
{
    int i;
    for (i = 0; i < CALIBS; ++i)
    {
        ReadRegisters();
        m_CalibratedGyro.Add(m_Gyro);
        delay(3);
    }

    m_CalibratedGyro.Divide(CALIBS);
}

void Gyro::Handler::Init()
{
    if (!m_Initialised)
    {
        m_Initialised = true;

        Wire.begin();
        InitialiseRegisters();

        m_Timer = millis();
    }
}

void Gyro::Handler::SetXOffset(double val)
{
    m_Offset.SetX(val);
}

void Gyro::Handler::SetYOffset(double val)
{
    m_Offset.SetY(val);
}

void Gyro::Handler::SetZOffset(double val)
{
    m_Offset.SetZ(val);
}

void Gyro::Handler::Update()
{
    if (millis() - m_Timer > MAX_UPDATE_PERIOD)
    {
        ReadRegisters();
        ProcessMovement();

        m_Timer = millis();
    }
}

void Gyro::Init()
{
    Handler::Init();
}

void Gyro::SetPitchOffset(double val)
{
    Handler::SetYOffset(val);
}

void Gyro::SetRollOffset(double val)
{
    Handler::SetXOffset(val);
}

void Gyro::SetYawOffset(double val)
{
    Handler::SetZOffset(val);
}

void Gyro::Update()
{
    Handler::Update();
}

Vector3 Gyro::RetrieveAcceleration()
{
    return Handler::GetAcceleration();
}

Vector3 Gyro::RetrieveRotation()
{
    return Handler::GetRotation();
}