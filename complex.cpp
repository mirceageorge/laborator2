//Basulescu Mircea

#include "complex.h"
#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>
using namespace std;


//If the we do not give a value to the objects, it will be by default 0
Complex::Complex() {
	real = 0;
	imaginary = 0;
}

//The object attributes are initiated with re, for real, and im, for imaginary
Complex::Complex(double re, double im) {
	real = re;
	imaginary = im;
}

//Destructor function
Complex::~Complex() {
}

//The implementation of the get and set methods
double Complex::getReal() const {
	return real;
}

double Complex::getImaginary() const {
	return imaginary;
}

void Complex::setReal(double re) {
	real = re;
}

void Complex::setImaginary(double im) {
	imaginary = im;
}

//Funtion that prints the normal form of a complex number -> a + bi
void Complex::show_compl() {
	double re, im;

	re = this->getReal();
	im = this->getImaginary();
	if (im < 0) {
		cout << re << "" << im << "i" << endl;
	} 
	else 
    {
		cout << setprecision(3) << re << "+" <<setprecision(3) << im << "i" << endl;
	}
}

//Funtion that prints the exponential form of a complex number -> r*e^i*theta
void Complex::show_exp() {
	double theta, r;

	r = sqrt(
		this->getReal() * this->getReal() +
		this->getImaginary() * this->getImaginary());
	theta = atan2(this->getImaginary(), this->getReal());

	cout << "(" << setprecision(3) <<r << "e)^" << setprecision(3) <<theta << "i" << endl;
}

//Function that adds two complex numbers and return a complex number -> a + c + (b + d)i
Complex Complex::add(Complex nr) {
	Complex result;

	result.setReal(this->getReal() + nr.getReal());
	result.setImaginary(this->getImaginary() + nr.getImaginary());

	return result;
}

//Function that multiplies two complex numbers and returns a complex number -> (ac-bd) + (bc + ad)i
Complex Complex::mul(Complex nr) {
	Complex result;

	result.setReal(
		this->getReal() * nr.getReal() -
		this->getImaginary() * nr.getImaginary());
	result.setImaginary(
		this->getImaginary() * nr.getImaginary() +
		this->getReal() * nr.getImaginary());

	return result;
}

//Fnction that divides two complex numbers and return a complex number
Complex Complex::quot(Complex nr) {
	Complex result;
	double denom = this->getImaginary() * this->getImaginary() +
		nr.getImaginary() * nr.getImaginary();
	result.setReal(
		(this->getReal() * nr.getReal() +
		 this->getImaginary() * nr.getImaginary()) /
		denom);
	result.setImaginary(
		(this->getImaginary() * nr.getReal() -
		 this->getReal() * nr.getImaginary()) /
		denom);
	return result;
}

//Funtion that calculates the module of a complex number -> radical(a^2 + b^2)
double Complex::abs() {
	double result;

	result = sqrt(
		this->getReal() * this->getReal() +
		this->getImaginary() * this->getImaginary());

	return result;
}

//Funtion that computes the polar form of a complex number -> r(cos theta + i sin theta)
string Complex::compute_polar() {
	double theta, r;
	string result;

	r = sqrt(
		this->getReal() * this->getReal() +
		this->getImaginary() * this->getImaginary());
	theta = atan2(this->getImaginary(), this->getReal());
	result = to_string(r) + "(cos(" + to_string(theta) + ") + isin(" +
		to_string(theta) + "))\n";
	return result;
}