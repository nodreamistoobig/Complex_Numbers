#include <iostream>
#include <iomanip>
#include <cmath>
#define PI 3.14159265358979323846 
#define E 2.71828182845904523536

using namespace std;

template <class T> class Complex
{
public:
	T real;	//real part
	T img;	//imaginary part
	Complex(T r, T i) { real = r; img = i; };
	Complex() {
		real = 1;
		img = 1;
	};

	Complex& operator +=(const Complex& c) {
		real = real + c.real;
		img = img + c.img;
		return *this;
	};

	Complex operator +(const Complex& c) const {
		Complex res(*this);
		res += c;
		return res;
	};

	Complex operator -() const {
		Complex c(-real, -img);
		return c;
	};

	Complex operator -(const Complex& c) const {
		return (*this + (-c));
	};

	Complex& operator -=(const Complex& c) {
		return (*this += (-c));
	};

	Complex operator *(const Complex& c) const {
		Complex res(*this);
		res.real = real * c.real - img * c.img;
		res.img = real * c.img + c.real * img;
		return res;
	};

	Complex& operator *=(const Complex& c) {
		Complex res(*this);
		res = *this * c;
		real = res.real;
		img = res.img;
		return *this;
	};

	Complex operator /(const Complex& c) const {
		Complex res(*this);
		res.real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
		res.img = (c.real * img + real * c.img) / (c.real * c.real + c.img * c.img);
		return res;
	};

	Complex& operator /=(const Complex& c) {
		Complex res(*this);
		res = *this / c;
		real = res.real;
		img = res.img;
		return *this;
	};

	double Module() { 
		return sqrt(real * real + img * img); 
	};

	double Phase() { 
		return 180 * atan(img / real) / PI; 
	};

	Complex Power(int p) {
		Complex res(*this);
		double m = this->Module();
		double f = this->Phase() * PI / 180;
		double mInPow = 1;
		for (int i = 0; i < p; i++) {
			mInPow *= m;
		}
		res.real = mInPow * cos(p * f);
		res.img = mInPow * sin(p * f);
		return res;
	};

	Complex Power(Complex p) {
		Complex c(0,0), res(0,0);						//формула логарифма из комплексного числа
		double m = this->Module();
		c.real = log(m);			              //ln(complex) = ln(real + i*img) = ln(Module) + i*Phase => complex number
		c.img = this->Phase() * PI / 180;		//формула Эйлера e^(i*x) = cos x + i sin x
		c = p * c;								
		double r = pow(E,c.real);				
		res.real = r*cos(c.img);			      //complex1^complex2 = e ^ (complex2 * ln(comlex1)) = e ^ (complex2 * comlex3) = e ^ complex4 = 						
		res.img  = r*sin(c.img);			      // = e^(real + i*img) = e^real * e^(i*img) = e^real * cos(img) + e^real * i * sin(img)
		return res;
	};

	friend istream& operator >>(istream& in, Complex& c) {
		in >> c.real >> c.img;
		return in;
	};

	friend ostream& operator <<(ostream& out, const Complex& c) {
		if (c.real)
			out << setprecision(3) << c.real;
		if (c.img > 0) {
			cout << "+";
			if (c.img != 1)
				cout << setprecision(3) << c.img;
			cout << "i";
		}
		else if (c.img < 0) {
			if (c.img != -1)
				cout << setprecision(3) << c.img << "i";
			else
				cout << "-i";
		}
		return out;
	};
};
