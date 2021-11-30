#pragma once
#include <math.h>

class Vector3
{
    double m_x, m_y, m_z;
    double m_vec[3];

public:
    Vector3();
    Vector3(double x, double y, double z);
    Vector3(double *vec);

    const double *Get() const;

    double GetX() const;
    double GetY() const;
    double GetZ() const;
    double Magnitude() const;

    void Add(double val);
    void AddX(double val);
    void AddY(double val);
    void AddZ(double val);
    void Add(double *val);
    void Add(Vector3 other);
    void Divide(double val);
    void DivideX(double val);
    void DivideY(double val);
    void DivideZ(double val);
    void Divide(double *val);
    void Divide(Vector3 other);
    void Multiply(double val);
    void MultiplyX(double val);
    void MultiplyY(double val);
    void MultiplyZ(double val);
    void Multiply(double *val);
    void Multiply(Vector3 other);
    void Set(double *vec);
    void SetX(double x);
    void SetY(double y);
    void SetZ(double z);
    void Subtract(double val);
    void SubtractX(double val);
    void SubtractY(double val);
    void SubtractZ(double val);
    void Subtract(double *val);
    void Subtract(Vector3 other);
};