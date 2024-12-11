#include "student.h"

std::string Student::GetFullname() {
	return surname + ' ' + name + ' ' + otchestvo;
}
std::string Student::GetName() { return name; }
std::string Student::GetSurname() { return surname; }
std::string Student::GetOtchestvo() { return otchestvo; }
std::string Student::GetGroup() { return group; }
std::string Student::GetKafedra() { return kafedra; }
bool Student::IsStudent() { return is_student; }
unsigned short* Student::GetMarks() { return marks; }

void Student::SetName(std::string value) { name = value; }
void Student::SetSurname(std::string value) { surname = value; }
void Student::SetOtchestvo(std::string value) { otchestvo = value; }
void Student::SetGroup(std::string value) { group = value; }
void Student::SetKafedra(std::string value) { kafedra = value; }
void Student::SetStudentStatus(bool value = true) { is_student = value; }
void Student::SetMarks(unsigned short mark, unsigned short index) {
	if (index < marks_quantity && index > 0) { marks[index] = mark; }
	CheckAverageMark();
}

void Student::SetFullname(std::string values[3]) {
	name = values[0]; surname = values[1]; otchestvo = values[2];
}
void Student::SetMarks(unsigned short values[marks_quantity]) {
	for (unsigned short i = 0; i < marks_quantity; i++) { marks[i] = values[i]; }
	CheckAverageMark();
}

void Student::PrintName() { std::cout << name << std::endl; }
void Student::PrintSurname() { std::cout << surname << std::endl; }
void Student::PrintOtchestvo() { std::cout << otchestvo << std::endl; }
void Student::PrintGroup() { std::cout << group << std::endl; }
void Student::PrintStudentStatus() { std::cout << "Is student: " << is_student << std::endl; }

void Student::PrintMarks() {
	for (unsigned short i = 0; i < marks_quantity; i++) { std::cout << marks[i] << ' '; }
	std::cout << std::endl;
}
void Student::PrintFullname() {
	std::cout << GetFullname() << std::endl;
}

void Student::PrintAll() {
	PrintFullname();
	PrintGroup();
	PrintStudentStatus();
	PrintMarks();
}

void Student::SetAll(std::string surname, std::string name, std::string otchestvo,
	std::string group, std::string kafedra, unsigned short marks[marks_quantity]) {
	SetSurname(surname);
	SetName(name);
	SetOtchestvo(otchestvo);
	SetGroup(group);
	SetKafedra(kafedra);
	SetMarks(marks);
}

void Student::SetAll(std::string fullname[3], std::string group,
	std::string kafedra, unsigned short marks[marks_quantity]) {
	SetFullname(fullname);
	SetGroup(group);
	SetKafedra(kafedra);
	SetMarks(marks);
}

void Student::FillAll() {
	std::cout << "Enter surname: ";
	getline(std::cin, surname, '\n');
	std::cout << "Enter name: ";
	getline(std::cin, name, '\n');
	std::cout << "Enter otchestvo: ";
	getline(std::cin, otchestvo, '\n');
	std::cout << "Enter group: ";
	getline(std::cin, group, '\n');
	std::cout << "Enter kafedra: ";
	getline(std::cin, kafedra, '\n');
	std::cout << "Is this person a student? (y/n) ";
	char new_is_student;
	std::cin >> new_is_student;
	is_student = new_is_student == 'y' || new_is_student == 'Y';
	for (short i = 0; i < marks_quantity; i++) {
		std::cout << "Enter mark ¹" << i + 1 << " for " << name << ": ";
		std::cin >> marks[i];
	}
}

bool Student::CheckAverageMark() {
	unsigned int marks_sum = 0;
	for (unsigned short i = 0; i < marks_quantity; i++) { marks_sum += marks[i]; }
	if (marks_sum / marks_quantity < 3.5) { is_student = false; return false; }
	return true;
}

Student::Student(bool fill_in = true) { if (fill_in) { FillAll(); } }
Student::Student(std::string surname, std::string name, std::string otchestvo,
	std::string group, std::string kafedra, unsigned short marks[marks_quantity]) {
	SetAll(surname, name, otchestvo, group, kafedra, marks);
}
Student::Student(std::string fullname[3], std::string group,
	std::string kafedra, unsigned short marks[marks_quantity]) {
	SetAll(fullname, group, kafedra, marks);
}