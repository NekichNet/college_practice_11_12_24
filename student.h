#pragma once

#include <iostream>
#include <Windows.h>
#include <limits>
#include <string>

struct Student {
private:
	bool is_student;
	std::string name, surname, otchestvo, group, kafedra;
	static unsigned const short marks_quantity = 4;
	unsigned short marks[marks_quantity];
public:
	std::string GetFullname();
	std::string GetName();
	std::string GetSurname();
	std::string GetOtchestvo();
	std::string GetGroup();
	std::string GetKafedra();
	bool IsStudent();
	unsigned short* GetMarks();

	void SetName(std::string value);
	void SetSurname(std::string value);
	void SetOtchestvo(std::string value);
	void SetGroup(std::string value);
	void SetKafedra(std::string value);
	void SetStudentStatus(bool value = true);
	void SetMarks(unsigned short mark, unsigned short index);

	void SetFullname(std::string values[3]);
	void SetMarks(unsigned short values[marks_quantity]);

	void PrintName();
	void PrintSurname();
	void PrintOtchestvo();
	void PrintGroup();
	void PrintStudentStatus();

	void PrintMarks();
	void PrintFullname();

	void PrintAll();

	void SetAll(std::string surname, std::string name, std::string otchestvo,
		std::string group, std::string kafedra, unsigned short marks[marks_quantity]);

	void SetAll(std::string fullname[3], std::string group,
		std::string kafedra, unsigned short marks[marks_quantity]);

	void FillAll();

	bool CheckAverageMark();

	Student(bool fill_in = true);
	Student(std::string surname, std::string name, std::string otchestvo,
		std::string group, std::string kafedra, unsigned short marks[marks_quantity]);
	Student(std::string fullname[3], std::string group,
		std::string kafedra, unsigned short marks[marks_quantity]);
};