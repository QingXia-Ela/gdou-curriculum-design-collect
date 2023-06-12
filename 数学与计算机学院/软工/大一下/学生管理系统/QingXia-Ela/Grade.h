#pragma once
#include <string>
using namespace std;
const char spliter = '\t';

class Grade
{
public:
	/** Ñ§ºÅ */
	long long id;
	/** ¿Î³ÌºÅ */
	string course;
	/** ³É¼¨ */
	string grade;

	Grade(string data);
	Grade(long long id, string course, string grade) : id(id), grade(grade), course(course){};

	string ToString();
};
