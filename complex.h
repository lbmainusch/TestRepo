// Complex.h
#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

class Complex 
{

	friend int returnCount(void);

public:
   Complex( double = 0.0, double = 0.0 ); // default constructor
   ~Complex();
   Complex( const Complex& rhs );   //copy constructor
   Complex& add( const Complex&  );	     // function add
   Complex& subtract( const Complex&  ); // function subtract
   std::string toString() const;
   void setComplexNumber( double, double ); // set complex number 
   
private:
   double realPart_;
   double imaginaryPart_;
   static int count_;
}; // end class Complex 

#endif

/**************************************************************************
 * (C) Copyright 1992-2014 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 **************************************************************************/


