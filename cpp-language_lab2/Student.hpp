#pragma once

#include "Equation.hpp"
#include "Teacher.hpp"
#include "Homework.hpp"

using namespace std;

class student {
public:
	student(string _name) : name(_name), t(NULL), hw(NULL) {};
	string getName() { return name; };
	homework* getHomework() { return hw; };
	void setTeacher(teacher* _teacher) { t = _teacher; };
	void setHomework(ifstream* streamIn);
	void doHomework();
	virtual equation::solution solveEq(equation eq) { return { equation::rootsCount::ZERO, 0, 0 }; };

private:
	string name;
	teacher* t;
	homework* hw;
};

class goodStudent : public student {
public:
	goodStudent(string _name) : student(_name) {};
	equation::solution solveEq(equation eq);
};

class normStudent : public student {
public:
	normStudent(string _name) : student(_name) {};
	equation::solution solveEq(equation eq);
};

class badStudent : public student {
public:
	badStudent(string _name) : student(_name) {};
	equation::solution solveEq(equation eq);
};