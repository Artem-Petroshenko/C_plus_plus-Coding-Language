#include "QuadraticEq.hpp"

double Discriminant(double a, double b, double c) {
	return b * b - 4 * a * c;
}

int Roots(pair<double, double> &x, double a, double b, double c) {
	double tmp = Discriminant(a, b, c);
	if (tmp < 0)
		return -1;
	else {
		x.first = (-b + sqrt(tmp)) / (2 * a);
		x.second = (-b - sqrt(tmp)) / (2 * a);
		return 0;
	}
}

int main(void) {
	double a, b, c;
	cout << "Input the coefficients of equation of the form ax^2 + bx + c = 0: ";
	cin >> a >> b >> c;
	if (a == 0)
		cout << "It's not equation of the form above!" << endl;
	else {
		pair<double, double> roots;
		pair<double, double>& ref = roots;
		if (Roots(ref, a, b, c) == -1)
			cout << "There are no real roots of this equation!" << endl;
		else if (ref.first == ref.second)
			cout << "The root is " << ref.first << "." << endl;
		else
			cout << "The roots are " << ref.first << " and " << ref.second << "." << endl;
	}
	return 0;
}