#pragma once
#include <string>
#include <vector>
using namespace std;

const char Student_Spliter = ',';
class Student
{
public:
	long long id;
	string name;
	string gender;
	string age;
	string province;
	string major;

	Student(string data);
	Student(long long id, string name, string gender, string age, string province, string major) : id(id), name(name), gender(gender), age(age), province(province), major(major){};
	static bool validate(Student &stu);
	static bool validate(string data);
	static bool validateId(long long id);
	static bool validateId(string id);
	static bool validateName(string name);
	static bool validateGender(string gender);
	static bool validateAge(string age);
	static bool validateProvince(string province);
	static bool validateMajor(string major);

	string ToString();
};
