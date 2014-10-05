/*****************************************************
 *                                                   *
 *   validator.cpp                                   *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include "validator.h"

Validator::Validator()
{
   allTrue = true;
   allFalse = false;
}

void Validator::assertTrue(bool trueValue)
{
   allTrue &= trueValue;
}

void Validator::assertFalse(bool falseValue)
{
   allFalse |= falseValue;
}

bool Validator::satisfied() const
{
   return allTrue && !allFalse;
}

