#ifndef TERM_CLASS_H
#define TERM_CLASS_H
class Term
{
	float coef;
	int exp;
public:
	Term();

	Term(float c, int e);

	void setExponent(int e);

	int getExponent();

	void setCoefficient(float c);

	float getCoefficient();

};
#endif TERM_CLASS_H

