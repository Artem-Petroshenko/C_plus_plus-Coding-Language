#include "Teacher.hpp"
#include "Student.hpp"

bool teacher::isSolutionCorrect(equation::solution eqSol, equation::solution stSol) {
	if (stSol.count != eqSol.count)
		return false;
	else if (stSol.count == equation::rootsCount::ZERO)
		return true;
	else if (stSol.x1 == eqSol.x1 && stSol.x2 == eqSol.x2)
		return true;
	else
		return false;
}

void teacher::checkHomework() {
	map<student*, int> res;
	while (!toCheck.empty()) {
		res[toCheck.front()->getStudent()] = 0;
		for (int i = 0; i < toCheck.front()->getEquations().size(); i++)
			if (isSolutionCorrect(toCheck.front()->getEquations().at(i).getSolution(), toCheck.front()->getStudentAnswers().at(i)))
				res[toCheck.front()->getStudent()]++;
		toCheck.pop();
	}
	resultTable = res;
	return;
}

void teacher::publishTable(ofstream* streamOut) {
	for (auto& item : resultTable)
		*streamOut << item.first->getName() << ';' << item.second << endl;
	return;
}