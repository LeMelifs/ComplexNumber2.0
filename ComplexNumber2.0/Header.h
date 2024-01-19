#pragma once
#include <iostream>

class Real {
private:
    double real;

public:
    Real();
    Real(double value);
    double GetValue() const;
    void SetValue(const double value);
    operator double() const;
};

class Imaginary {
private:
    double imaginary;

public:
    Imaginary();
    Imaginary(double value);
    double GetValue() const;
    void SetValue(const double value);
    operator double() const;
};

class ComplexNumber {

private:
    Real real;
    Imaginary imaginary;

public:
    friend std::ostream& operator <<(std::ostream&, const ComplexNumber&);
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    double GetReal() const;
    Real& GetRealObj();
    const Real& GetRealObj() const;
    Imaginary& GetImaginaryObj();
    const Imaginary& GetImaginaryObj() const;
    double GetImaginary() const;
    void SetReal(const double value);
    void SetImaginary(const double value);
    virtual ~ComplexNumber();
    ComplexNumber operator +(const ComplexNumber& other);
    ComplexNumber operator -(const ComplexNumber& other);
    ComplexNumber operator *(const ComplexNumber& other);
    ComplexNumber operator /(const ComplexNumber& other);
    ComplexNumber& operator +=(const ComplexNumber& other);
    ComplexNumber& operator -=(const ComplexNumber& other);
    ComplexNumber& operator *=(const ComplexNumber& other);
    ComplexNumber& operator /=(const ComplexNumber& other);
    bool operator ==(const ComplexNumber& other);
    bool operator ==(const double& other);
    double Abs() const;
    ComplexNumber Pow(int degree) const;
};

std::ostream& operator << (std::ostream& out, const ComplexNumber& num);

class DerivedComplexNumber : public ComplexNumber {
public:
    DerivedComplexNumber(double real, double imaginary);
    void derivedFunction();
};