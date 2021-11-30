#pragma once
#include "Arduino.h"
#include <Wire.h>
#include "Vector3.h"

namespace Gyro
{
    class Handler
    {
        static constexpr int CALIBS = 1000;
        static constexpr int MAX_BYTES = 14;
        static constexpr int MAX_UPDATE_PERIOD = 4;

        static bool m_Initialised;
        static bool m_GyroInitialised;

        static Vector3 m_Gyro;
        static Vector3 m_CalibratedGyro;
        static Vector3 m_Accelerometer;
        static Vector3 m_GyroAcceleration;
        static Vector3 m_RawRotation;
        static Vector3 m_Rotation;
        static Vector3 m_Offset;

        static long m_Timer;

        static void InitialiseRegisters();
        static void ProcessMovement();
        static void ReadRegisters();

    public:
        Handler() = delete;
        Handler &operator=(const Handler &) = delete;
        Handler(const Handler &) = delete;

        static Vector3 GetRotation();
        static Vector3 GetAcceleration();

        static void Calibrate();
        static void Init();
        static void SetXOffset(double val);
        static void SetYOffset(double val);
        static void SetZOffset(double val);
        static void Update();
    };

    void Init();
    void SetPitchOffset(double val);
    void SetRollOffset(double val);
    void SetYawOffset(double val);
    void Update();

    Vector3 RetrieveAcceleration();
    Vector3 RetrieveRotation();
}