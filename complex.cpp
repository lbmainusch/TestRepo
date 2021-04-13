// complex.cpp
// Member-function definitions for class Complex.
#include <iostream> 
#include <sstream>
#include "complex.h"
using namespace std;

Complex::Complex( double real, double imaginary )
   : realPart_( real ), imaginaryPart_( imaginary )
{ 
	count_++;
	cout << "\nconstructor at work - count: " << count_ << endl;
} // end Complex constructor


Complex::~Complex()
{
	cout << "\ndestructor at work... " << endl;
} // end Complex constructor

//Complex::Complex( const Complex& rhs)

Complex::Complex( const Complex& rhs )
{
	 count_++;
	 cout << "\n copy constructor at work - count: " << count_ << endl;
	 realPart_ = rhs.realPart_;
     imaginaryPart_ = rhs.imaginaryPart_;
}


Complex& Complex::add( const Complex& right )
{
   
   realPart_      += right.realPart_;
   imaginaryPart_ += right.imaginaryPart_;
   
   return *this;
   
} // end function add


Complex& Complex::subtract( const Complex& right ) 
{
	realPart_     -= right.realPart_;
	imaginaryPart_ -= right.imaginaryPart_;

	return *this;

} // end function subtract



string Complex::toString() const
{
	ostringstream buffer;
	buffer << '(' << realPart_ << ", " << imaginaryPart_ << ')';
	return buffer.str();
} // end function printComplex

void Complex::setComplexNumber( double rp, double ip ) 
{
   realPart_ = rp;
   imaginaryPart_ = ip;
} // end function setComplexNumber 





/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 **************************************************************************/


