#include "Course.h"
#include "Utils.h"
#include <vector>

Course::Course(string data)
{
	vector<string> arr = Utils::StringSplit(data, Course_Spliter);

	this->id = arr[0];
	this->name = arr[1];
	this->score = arr[2];
	this->money = arr[3];
}

string Course::ToString()
{
	return this->id + Course_Spliter + this->name + Course_Spliter + this->score + Course_Spliter + this->money;
}