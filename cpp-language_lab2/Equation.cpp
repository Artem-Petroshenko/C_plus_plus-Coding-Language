#include "Equation.hpp"

double equation::discriminant() {
	return b * b - 4 * a * c;
}

void equation::solveEq() {
	double d = equation::discriminant();
	if (d < 0) {
		eqRoots.count = rootsCount::ZERO;
		return;
	}
	else if (d == 0) {
		eqRoots.count = rootsCount::ONE;
		eqRoots.x1 = eqRoots.x2 = -b / (2 * a);
		return;
	}
	else {
		eqRoots.count = rootsCount::TWO;
		eqRoots.x1 = (-b + sqrt(d)) / (2 * a);
		eqRoots.x2 = (-b - sqrt(d)) / (2 * a);
		return;
	}
}