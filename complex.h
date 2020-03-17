//Basulescu Mircea

#include <iostream>
#include <string>
using namespace std;

class Complex{
public:
	Complex();//default constructor
	Complex(double re, double im);//constructor
	~Complex();//destructor

	//get method
	double getReal() const;
	double getImaginary() const;
	//set methods
	void setReal(double value);
	void setImaginary(double value);
	
	void show_compl();
	void show_exp();
	
	Complex add(Complex nr);
	Complex mul(Complex nr);
	Complex quot(Complex nr);
	
    string compute_polar();
	
	double abs();

private:
	double real;
	double imaginary;
};