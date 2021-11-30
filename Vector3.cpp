#include "Vector3.h"

Vector3::Vector3()
{
    m_x = m_y = m_z = 0.0f;

    m_vec[0] = m_vec[1] = m_vec[2] = 0.0f;
}

Vector3::Vector3(double x, double y, double z)
{
    m_vec[0] = m_x = x;
    m_vec[1] = m_y = y;
    m_vec[2] = m_z = z;
}

Vector3::Vector3(double *vec)
{
    m_x = m_vec[0] = vec[0];
    m_y = m_vec[1] = vec[1];
    m_z = m_vec[2] = vec[2];
}

const double *Vector3::Get() const
{
    return m_vec;
}

double Vector3::GetX() const
{
    return m_x;
}

double Vector3::GetY() const
{
    return m_y;
}

double Vector3::GetZ() const
{
    return m_z;
}

double Vector3::Magnitude() const
{
    return sqrt(m_x * m_x + m_y * m_y + m_z * m_z);
}

void Vector3::Add(double val)
{
    m_vec[0] = m_x += val;
    m_vec[1] = m_y += val;
    m_vec[2] = m_z += val;
}

void Vector3::AddX(double val)
{
    m_vec[0] = m_x += val;
}

void Vector3::AddY(double val)
{
    m_vec[1] = m_y += val;
}

void Vector3::AddZ(double val)
{
    m_vec[2] = m_z += val;
}

void Vector3::Add(double *val)
{
    m_x = m_vec[0] += val[0];
    m_y = m_vec[1] += val[1];
    m_z = m_vec[2] += val[2];
}

void Vector3::Add(Vector3 other)
{
    m_x = m_vec[0] += other.GetX();
    m_y = m_vec[1] += other.GetY();
    m_z = m_vec[2] += other.GetZ();
}

void Vector3::Divide(double val)
{
    m_vec[0] = m_x /= val;
    m_vec[1] = m_y /= val;
    m_vec[2] = m_z /= val;
}

void Vector3::DivideX(double val)
{
    m_vec[0] = m_x /= val;
}

void Vector3::DivideY(double val)
{
    m_vec[1] = m_y /= val;
}

void Vector3::DivideZ(double val)
{
    m_vec[2] = m_z /= val;
}

void Vector3::Divide(double *val)
{
    m_x = m_vec[0] /= val[0];
    m_y = m_vec[1] /= val[1];
    m_z = m_vec[2] /= val[2];
}

void Vector3::Divide(Vector3 other)
{
    m_x = m_vec[0] /= other.GetX();
    m_y = m_vec[1] /= other.GetY();
    m_z = m_vec[2] /= other.GetZ();
}

void Vector3::Multiply(double val)
{
    m_vec[0] = m_x *= val;
    m_vec[1] = m_y *= val;
    m_vec[2] = m_z *= val;
}

void Vector3::MultiplyX(double val)
{
    m_vec[0] = m_x *= val;
}

void Vector3::MultiplyY(double val)
{
    m_vec[1] = m_y *= val;
}

void Vector3::MultiplyZ(double val)
{
    m_vec[2] = m_z *= val;
}

void Vector3::Multiply(double *val)
{
    m_x = m_vec[0] *= val[0];
    m_y = m_vec[1] *= val[1];
    m_z = m_vec[2] *= val[2];
}

void Vector3::Multiply(Vector3 other)
{
    m_x = m_vec[0] *= other.GetX();
    m_y = m_vec[1] *= other.GetY();
    m_z = m_vec[2] *= other.GetZ();
}

void Vector3::Set(double *vec)
{
    m_x = m_vec[0] = vec[0];
    m_y = m_vec[1] = vec[1];
    m_z = m_vec[2] = vec[2];
}

void Vector3::SetX(double x)
{
    m_vec[0] = m_x = x;
}

void Vector3::SetY(double y)
{
    m_vec[1] = m_y = y;
}

void Vector3::SetZ(double z)
{
    m_vec[2] = m_z = z;
}

void Vector3::Subtract(double val)
{
    m_vec[0] = m_x -= val;
    m_vec[1] = m_y -= val;
    m_vec[2] = m_z -= val;
}

void Vector3::SubtractX(double val)
{
    m_vec[0] = m_x -= val;
}

void Vector3::SubtractY(double val)
{
    m_vec[1] = m_y -= val;
}

void Vector3::SubtractZ(double val)
{
    m_vec[2] = m_z -= val;
}

void Vector3::Subtract(double *val)
{
    m_x = m_vec[0] -= val[0];
    m_y = m_vec[1] -= val[1];
    m_z = m_vec[2] -= val[2];
}

void Vector3::Subtract(Vector3 other)
{
    m_x = m_vec[0] -= other.GetX();
    m_y = m_vec[1] -= other.GetY();
    m_z = m_vec[2] -= other.GetZ();
}