#pragma once

struct Vector
{
    float a;
    float b;
    float c;
    Vector(){};
    Vector(float a, float b, float c) : a(a), b(b), c(c) {}
};

class Triangle
{
public:
    void SetLength(const Vector& V) { vector = V; }
    Vector GetLength() const { return vector; };
    virtual bool IsValid() const;
    Vector GetAngle() const;
    float GetPerimeter() const;
    float GetSquare() const;
    void PrintTriangle() const;

private:
    Vector vector;
    static float CalculateAngle(float a, float b, float c);
};

class EquipotentialTriangle : public Triangle
{
public:
    bool IsValid() const override;
};
