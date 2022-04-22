#pragma once
#include <vector>

#include "Equation.hpp"

class student;

class homework {
public:
	student* getStudent() { return st; };
	vector<equation> getEquations() { return equations; };
	vector<equation::solution> getStudentAnswers() { return studentAnswers; };
	void setStudent(student* _student) { st = _student; };
	void setEquations(vector<equation> _equations) { equations = _equations; };
	void setStudentAnswers(vector<equation::solution> _studentAnswers) { studentAnswers = _studentAnswers; };

private:
	vector<equation> equations;
	vector<equation::solution> studentAnswers;
	student* st;
};