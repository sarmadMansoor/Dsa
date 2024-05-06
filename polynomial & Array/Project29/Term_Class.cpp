#include "Term_Class.h"

Term::Term()
{
	coef = 0;
	exp = 0;
}
Term::Term(float c, int e)
{
	coef = c;
	exp = e;
}
void Term::setExponent(int e)
{
	exp = e;
}
int Term::getExponent()
{
	return exp;
}
void Term::setCoefficient(float c)
{
	coef = c;
}
float Term::getCoefficient()
{
	return coef;
}