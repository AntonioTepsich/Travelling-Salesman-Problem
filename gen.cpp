#include "clases.hpp"

Gen::Gen(size_t i) : id_(i) {}

size_t Gen::GetId() const
{
    return id_;
}

City::City(double x, double y, size_t i) : Gen(i), x_(x), y_(y) {}
double City::GetX() const
{
    return x_;
}

double City::GetY() const
{
    return y_;
}