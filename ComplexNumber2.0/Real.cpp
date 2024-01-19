#include "Header.h"

Real::Real() : real(0) {}

Real::Real(double value) : real(value) {}

double Real::GetValue() const {
	return real;
}

void Real::SetValue(const double value) {
	real = value;
}

Real::operator double() const {
	return real;
}