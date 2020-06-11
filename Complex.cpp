#include <iostream>
#include "Complex.h"

using namespace std;

double isDouble(double& x);

int main()
{
	setlocale(LC_ALL, "Russian");
	double A, B, C;
	cout << "Квадратное уравнение" << endl << "Введите коэффициент а в формате double" << endl;
	isDouble(A);
	cout << "Введите коэффициент b в формате double" << endl;
	isDouble(B);
	cout << "Введите коэффициент c в формате double" << endl;
	isDouble(C);

	double D = B * B - 4 * A * C;

	if (D > 0) {
		double X1 = (-B + sqrt(D)) / (2 * A);
		double X2 = (-B - sqrt(D)) / (2 * A);
		cout << "x1 = " << X1 << " x2 = " << X2;
	}
	else if (D == 0) {
		double x1 = -B / (2 * A);
	}
	else {
		Complex<double> sqrt_d(0, sqrt(abs(D)));
		Complex<double> a(A, 0), b(B, 0), c(C, 0);
		Complex<double> t(2, 0);
		Complex<double> x1 = (-b + sqrt_d) / (t * a);
		Complex<double> x2 = (-b - sqrt_d) / (t * a);
		cout << "x1 = " << x1 << " x2 = " << x2 << endl;
		cout << x1.Power(x2);
	}
}

double isDouble(double& x)
{
	bool rightCin = false;
	while (!rightCin)
	{
		cin >> x;
		if (cin.fail())
		{
			cout << "Введите ЧИСЛО в формате double" << endl;
			cin.clear();
			cin.ignore(10, '\n');
		}
		else
			rightCin = true;
	}
	return x;
}
