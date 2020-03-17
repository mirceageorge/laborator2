//Aiordachioaei Andrei

#include "complex.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <cassert>
using namespace std;

//Tests
void tests()
{
	Complex z1(2,4);
	Complex z2(6,3);

	Complex result1 = z1.add(z2);
	assert(result1.getReal() == 8);
	assert(result1.getImaginary() == 7);

	Complex result2 = z1.mul(z2);
	assert(result2.getReal() == 0);
	assert(result2.getImaginary() == 18);

	Complex result3 = z1.quot(z2);
	assert(result3.getReal() == 0.96);
	assert(result3.getImaginary() == 0.72);
	  
	z1.setReal(3);
	z1.setImaginary(4);
	assert(z1.abs()==5);

}

//Sort function
bool sort_function(Complex z1, Complex z2) 
{
	return (z1.abs() < z2.abs());
}

int main() 
{
	tests();
	
	Complex v0, v1(2, 2), v2(3, 6), v3, v4, v5(1, 2); //We do not use v0, but it helps because now the vector starts from 1, instead of 0.
	Complex vector[]={v0, v1, v2, v3, v4, v5};
	Complex vector_sum;
	double vector_real, vector_imaginary;

	for (int i=1;i<=5;i++) 
	{
	    cout << "The " << i << " complex number is: ";
        vector[i].show_compl();
        cout << "With the exponential form: ";
        vector[i].show_exp();
        cout << "With the polar form: " << vector[i].compute_polar();
		cout << "With the abs: " << vector[i].abs();

        //Here we calculate the sum so we do not have to iterate again
		vector_real += vector[i].getReal(); 
		vector_imaginary += vector[i].getImaginary();
		
		cout << endl;
	}

	vector_sum.setReal(vector_real);
	vector_sum.setImaginary(vector_imaginary);
	cout << endl << "Sum of the vector elements: ";
	vector_sum.show_compl();

	cout << endl << "Sum v1+v2: ";
	Complex sum = v1.add(v2);
	sum.show_compl();

	cout << endl << "Multiplication v1*v2: ";
	Complex mul = v1.mul(v2);
	mul.show_compl();

	cout << endl << "Division v1/v2: ";
	Complex quot = v1.quot(v2);
	quot.show_compl();
	
	cout << endl << "Unsorted vectors: " << endl;
	for(int i=1;i<=5;i++)
		vector[i].show_compl();
	
	cout << endl << "Sorted vectors: " << endl;//Sorted by the complex number modulus
	sort(vector+1, vector+6,sort_function);
	for(int i=1;i<=5;i++)
		vector[i].show_compl();

	return 0;
}