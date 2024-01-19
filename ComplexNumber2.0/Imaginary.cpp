#include "Header.h"

Imaginary::Imaginary() : imaginary(0) {}

Imaginary::Imaginary(double value) : imaginary(value) {}

double Imaginary::GetValue() const {
	return imaginary;
}

void Imaginary::SetValue(const double value) {
	imaginary = value;
}

Imaginary::operator double() const {
	return imaginary;
}