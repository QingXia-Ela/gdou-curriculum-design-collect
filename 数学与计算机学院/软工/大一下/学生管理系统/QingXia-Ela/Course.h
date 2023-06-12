#pragma once
#include <string>
using namespace std;
const char Course_Spliter = ',';

class Course
{
public:
	string id;
	string name;
	string score;
	string money;

	Course(string data);
	Course(string id, string name, string score, string money) : id(id), name(name), score(score), money(money){};

	string ToString();
};
