#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

class equation {
public:
	enum class rootsCount {  //we suggest that a,b,c != 0, so there cant be infinity of roots
		ZERO,
		ONE,
		TWO
	};
	struct solution {
		rootsCount count;
		double x1;
		double x2;
	};
	equation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { solveEq(); };
	double getA() { return a; };
	double getB() { return b; };
	double getC() { return c; }; 
	solution getSolution() { return eqRoots; };

private:
	double a;
	double b;
	double c;
	double discriminant();
	solution eqRoots;
	void solveEq();
};