#pragma once
#include <iostream>
#include <cmath>

using namespace std;

enum class Result {
	SUCC,
	FAIL
};

double Discriminant(double a, double b, double c);
Result Roots(pair<double, double>& x, double a, double b, double c);
Result Input(double& a, double& b, double& c);
void Output(pair<double, double> roots, Result flag);