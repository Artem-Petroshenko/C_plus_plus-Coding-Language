#include "Student.hpp"

equation::solution goodStudent::solveEq(equation eq) {
	return eq.getSolution();
}

equation::solution badStudent::solveEq(equation eq) {
	return { equation::rootsCount::ONE, 0, 0 };
}

equation::solution normStudent::solveEq(equation eq) {
	if (rand() % 2)
		return eq.getSolution();
	else 
		return { equation::rootsCount::ONE, 0, 0 };
}

void student::doHomework() {
	vector<equation> eqs = hw->getEquations();
	vector<equation::solution> answers;
	for (int i = 0; i < eqs.size(); i++)
		answers.push_back(solveEq(eqs.at(i)));
	hw->setStudentAnswers(answers);
	t->pushQueue(hw);
}

void student::setHomework(ifstream* streamIn) {
	homework* hw = new homework;
	vector<equation> eqs;
	int a, b, c;
	while (!(*streamIn).eof()) {
		*streamIn >> a;
		*streamIn >> b;
		*streamIn >> c;
		equation eq(a, b, c);
		eqs.push_back(eq);
	}
	hw->setStudent(this);
	hw->setEquations(eqs);
	this->hw = hw;
	return;
}