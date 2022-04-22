#pragma once
#include <map>

#include "Homework.hpp"
#include "Equation.hpp"

using namespace std;

class student;

class teacher {
public:
	teacher(string _name) : name(_name) {};
	void pushQueue(homework* _hw) { toCheck.push(_hw); };
	void checkHomework();
	void publishTable(ofstream* streamOut);

private:
	string name;
	queue<homework*> toCheck;
	map<student*, int> resultTable;
	bool isSolutionCorrect(equation::solution eqSol, equation::solution stSol);
};