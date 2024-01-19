#include "Header.h"

DerivedComplexNumber::DerivedComplexNumber(double real, double imaginary) : ComplexNumber(real, imaginary) {}

void DerivedComplexNumber::derivedFunction() {
	std::cout << "Я производный класс от класса комплексных чисел!";
}