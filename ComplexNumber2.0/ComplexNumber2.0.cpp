#include <iostream>
#include "Header.h"

ComplexNumber::ComplexNumber() : real(Real(0)), imaginary(Imaginary(0)) {}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(Real(real)), imaginary(Imaginary(imaginary)) {}


double ComplexNumber::GetReal() const {
    return real.GetValue();
}

double ComplexNumber::GetImaginary() const {
    return imaginary.GetValue();
}

void ComplexNumber::SetReal(const double value) {
    real.SetValue(value);
}

void ComplexNumber::SetImaginary(const double value) {
    imaginary.SetValue(value);
}

Real& ComplexNumber::GetRealObj() {
    return real;
}

const Real& ComplexNumber::GetRealObj() const {
    return real;
}

Imaginary& ComplexNumber::GetImaginaryObj() {
    return imaginary;
}

const Imaginary& ComplexNumber::GetImaginaryObj() const {
    return imaginary;
}

ComplexNumber::~ComplexNumber() = default;

ComplexNumber ComplexNumber::operator +(const ComplexNumber& other) {
    double this_real = real.GetValue();
    double other_real = other.real.GetValue();

    double this_imaginary = imaginary.GetValue();
    double other_imaginary = other.imaginary.GetValue();

    double new_real = this_real + other_real;
    double new_imaginary = this_imaginary + other_imaginary;

    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber ComplexNumber::operator -(const ComplexNumber& other) {
    double this_real = real.GetValue();
    double other_real = other.real.GetValue();

    double this_imaginary = imaginary.GetValue();
    double other_imaginary = other.imaginary.GetValue();

    double new_real = this_real - other_real;
    double new_imaginary = this_imaginary - other_imaginary;

    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber ComplexNumber::operator *(const ComplexNumber& other) {
    double this_real = real.GetValue();
    double other_real = other.real.GetValue();

    double this_imaginary = imaginary.GetValue();
    double other_imaginary = other.imaginary.GetValue();

    double new_real = this_real * other_real - this_imaginary * other_imaginary;
    double new_imaginary = this_real * other_imaginary + other_real * this_imaginary;

    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber ComplexNumber::operator /(const ComplexNumber& other) {
    double this_real = real.GetValue();
    double other_real = other.real.GetValue();

    double this_imaginary = imaginary.GetValue();
    double other_imaginary = other.imaginary.GetValue();

    double denominator = other_real * other_real + other_imaginary * other_imaginary;
    double eps = 1e-5;
    if (std::fabs(denominator) < eps) {
        throw std::overflow_error("Divide by zero exception");
    }
    double new_real = (this_real * other_real + this_imaginary * other_imaginary) / denominator;
    double new_imaginary = (other_real * this_imaginary - this_real * other_imaginary) / denominator;

    return ComplexNumber(new_real, new_imaginary);
}

ComplexNumber& ComplexNumber::operator +=(const ComplexNumber& other) {
    real = (*this + other).real;
    imaginary = (*this + other).imaginary;
    return *this;
}

ComplexNumber& ComplexNumber::operator -=(const ComplexNumber& other) {
    real = (*this - other).real;
    imaginary = (*this - other).imaginary;
    return *this;
}

ComplexNumber& ComplexNumber::operator *=(const ComplexNumber& other) {
    real = (*this * other).real;
    imaginary = (*this * other).imaginary;
    return *this;
}

ComplexNumber& ComplexNumber::operator /=(const ComplexNumber& other) {
    real = (*this / other).real;
    imaginary = (*this / other).imaginary;
    return *this;
}

bool ComplexNumber::operator ==(const ComplexNumber& other) {
    return (real.GetValue() == other.real.GetValue() && imaginary.GetValue() == other.imaginary.GetValue());
}

bool ComplexNumber::operator ==(const double& other) {
    double eps = 1e-5;
    return (real.GetValue() == other && std::fabs(imaginary) < eps);
}

double ComplexNumber::Abs() const {
    return std::sqrt(real.GetValue() * real.GetValue() + imaginary.GetValue() * imaginary.GetValue());
}

ComplexNumber ComplexNumber::Pow(int degree) const {
    double r = std::pow(this->Abs(), degree);
    double phi = std::atan2(imaginary.GetValue(), real.GetValue());
    double new_real = r * std::cos(degree * phi);
    double new_imaginary = r * std::sin(degree * phi);
    return ComplexNumber(new_real, new_imaginary);
}

std::ostream& operator << (std::ostream& out, const ComplexNumber& num)
{
    if (num.imaginary < 0) {
        out << num.real.GetValue() << num.imaginary.GetValue() << "i\n";
    }
    else {
        out << num.real.GetValue() << "+" << num.imaginary.GetValue() << "i\n";
    }
    return out;
}