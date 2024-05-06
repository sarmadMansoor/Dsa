#include "complexNumber.cpp"
template class Complex<double>;
template class Complex<float>;
template class Complex<int>;
template ostream& operator<< (ostream& out, Complex <double>& ref);
template ostream& operator<< (ostream& out, Complex <float>& ref);
template ostream& operator<< (ostream& out, Complex <int>& ref);
