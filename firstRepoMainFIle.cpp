#include <iostream>
#include <cmath>

struct Z {
	double a;
	double b;
	Z ();
	Z (double x, double y);
	Z (Z const& other);
	~Z ();
	Z& operator= (Z const& other);
	Z operator+ (Z const& other);
	Z operator- (Z const& other);
	Z operator/ (Z const& other);
	Z operator* (Z const& other);
	double getModule () const;
	double getPhi () const;
	void set (double x,double y);
};

Z::Z (): a(0), b(0) {

}

Z::Z (double x, double y): a(x), b(y) {

}

Z::Z(Z const& other) {
	*this = other;
}

Z::~Z() {

}

Z& Z::operator= (Z const& other) {
	a = other.a;
	b = other.b;
	return *this;
}

Z Z::operator+ (Z const& other) {
	Z t = *this;
	t.a = t.a + other.a;
	t.b = t.b + other.b;
	return t;
}

Z Z::operator- (Z const& other) {
	Z t = *this;
	t.a = t.a - other.a;
	t.b = t.b - other.b;
	return t;
}

Z Z::operator* (Z const& other) {
	Z t;
	double r = getModule () * other.getModule ();
	double phi = getPhi () + other.getPhi ();
	t.set (r,phi);
	return t;
}

Z Z::operator/ (Z const& other) {
	Z t;
	double r = getModule () / other.getModule ();
	double phi = getPhi () - other.getPhi ();
	t.set (r,phi);
	return t;
}

double Z::getModule () const {
	return sqrt (a*a + b*b);
}

double Z::getPhi () const {
	return atan (b/a);
}

void Z::set (double r, double phi) {
	a = r*cos(phi);
	b = r*sin(phi);
}

void VASILIY (Z zzz) {
	std::cout << "a = " << zzz.a << std::endl;
	std::cout <<"b = " << zzz.b << std::endl;
}




int main(int argc, char** argv) {
	Z z1(1,2);
	std::cout << "z1" << std::endl;
	VASILIY (z1);

	Z z2(3,4);
	std::cout << "z2" << std::endl;
	VASILIY (z2);

	Z z3;
	z3 = z1+z2;
	std::cout << "z3+" << std::endl;
	VASILIY (z3);

	z3 = z1-z2;
	std::cout << "z3-" << std::endl;
	VASILIY (z3);

	z3 = z1*z2;
	std::cout << "z3*" << std::endl;
	VASILIY (z3);

	z3 = z1/z2;
	std::cout << "z3/ " << std::endl;
	VASILIY (z3);
	return 0;
}

