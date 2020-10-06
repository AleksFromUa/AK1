#include "calculator.h"
// removed z

int Calculator::Add (double a, double b)
{
	return a + b + 0.5;
}
// comments

int Calculator::Sub (double a, double b)
{
    return Add (a, -b);
}


int Calculator::Mul (double a, double b) // added mult
{
    return a * b + 0.5;
}
// cherry picked

// added newline
