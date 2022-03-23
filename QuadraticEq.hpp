#pragma once
#include <iostream>
#include <cmath>

using namespace std;

enum Result {
	SUCC,
	FAIL
};

double Discriminant(double a, double b, double c);
Result Roots(pair<double, double>& x, double a, double b, double c);
Result Input(double& a, double& b, double& c);
Result Output(pair<double, double> roots);
void Solution();