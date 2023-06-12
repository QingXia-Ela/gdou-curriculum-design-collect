#include "Utils.h"
#include "Student.h"
#include <string>
#include <vector>
using namespace std;

Student::Student(string data)
{
	vector<string> arr = Utils::StringSplit(data, ',');
	this->id = atoll(arr[0].c_str());
	this->name = arr[1];
	this->gender = arr[2];
	this->age = arr[3];
	this->province = arr[4];
	this->major = arr[5];
}

bool Student::validateId(long long id)
{
	return to_string(id).length() == 12;
}

bool Student::validateId(string id)
{
	// 12 位长 + 开头不为 0
	return id.length() == 12 && id[0] != '0';
}

bool Student::validateName(string name)
{
	return name.length() > 0 && name.length() < 20;
}

bool Student::validateGender(string gender)
{
	return gender == "男" || gender == "女" || gender == "M" || gender == "F";
}

bool Student::validateAge(string age)
{
	return age.length() == 2;
}

bool Student::validateProvince(string province)
{
	return true;
}

bool Student::validateMajor(string major)
{
	return major.length() > 0 && major.length() <= 8;
}

string Student::ToString()
{
	return to_string(this->id) + Student_Spliter + this->name + Student_Spliter + this->gender + Student_Spliter + this->age + Student_Spliter + this->province + Student_Spliter + this->major;
}