#include "Equation.hpp"
#include "Homework.hpp"
#include "Student.hpp"
#include "Teacher.hpp"

using namespace std;

const vector<string> name = { "Valeriya", "Olga", "Vera", "Ekaterina", "Artem", "Vadim", "Alexander", "Ivan" };
const vector<string> surname = { "Rubanich", "Embekich", "Fich", "Zinchenko", "Petroshenko", "Tugay", "Sorokich", "Eroshkich" };

string createName();
vector<student*> createStudents(int stAmount, teacher* teacher);
teacher* createTeacher(string teacherName);
void FreeMemory(vector<student*> students, teacher* teacher);

string createName() {
	return (surname.at(rand() % 8) + " " + name.at(rand() % 8));
}

vector<student*> createStudents(int stAmount, teacher* teacher) {
	int stType;
	vector<student*> students;
	for (int i = 0; i < stAmount; i++) {
		stType = rand() % 3;
		student* newStudent = NULL;
		if (stType == 0)
			newStudent = new badStudent(createName());
		else if (stType == 1)
			newStudent = new normStudent(createName());
		else if (stType == 2)
			newStudent = new goodStudent(createName());
		newStudent->setTeacher(teacher);
		students.push_back(newStudent);
	}
	return students;
}

teacher* createTeacher(string teacherName) {
	return new teacher(teacherName);
}

void FreeMemory(vector<student*> students, teacher* teacher) {
	for (int i = 0; i < students.size(); i++) {
		delete students.at(i)->getHomework();
		delete students.at(i);
	}
	delete teacher;
}

int main(void) {
	srand(time(0));
	remove("results.csv");
	ofstream F2("results.csv");
	if (!F2.is_open()) 
		cout << "error in file";
	int numberStudents = 8;
	string teacherName = "Vyacheslav Chukanov";
	teacher* t = createTeacher(teacherName);
	vector<student*> st = createStudents(numberStudents, t);
	for (int i = 0; i < numberStudents; i++) {
		ifstream F1("test.txt");
		if (!F1.is_open()) {
			F2.close();
			cout << "error in file";
		}
		st.at(i)->setHomework(&F1);
		st.at(i)->doHomework();
		F1.close();
	}
	t->checkHomework();
	t->publishTable(&F2);
	F2.close();
	return 0;
}