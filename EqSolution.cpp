#include "QuadraticEq.hpp"

double Discriminant(double a, double b, double c) {
	return b * b - 4 * a * c;
}

Result Roots(pair<double, double> &x, double a, double b, double c) {
	double tmp = Discriminant(a, b, c);
	if (tmp < 0)
		return Result::FAIL;
	else {
		x.first = (-b + sqrt(tmp)) / (2 * a);
		x.second = (-b - sqrt(tmp)) / (2 * a);
		return Result::SUCC;
	}
}

Result Input(double& a, double& b, double& c) {
	cout << "Input the coefficients of equation of the form ax^2 + bx + c = 0: ";
	cin >> a >> b >> c;
	if (a == 0) {
		cout << "It's not the equation of the form above!" << endl;
		return Result::FAIL;
	}
	return Result::SUCC;
}

void Output(pair<double, double> roots, Result flag) {	
	if (flag == Result::FAIL) 
		cout << "There are no real roots of this equation!" << endl;
	else {
		if (roots.first == roots.second)
			cout << "The root is " << roots.first << "." << endl;
		else
			cout << "The roots are " << roots.first << " and " << roots.second << "." << endl;
	}
	return;
}

int main(void) {
	double a, b, c;
	double& ref_a = a, & ref_b = b, & ref_c = c;
	pair<double, double> roots;
	pair<double, double>& ref = roots;
	if (Input(ref_a, ref_b, ref_c) == Result::SUCC)
		Output(roots, Roots(ref, a, b, c));
	return 0;
}