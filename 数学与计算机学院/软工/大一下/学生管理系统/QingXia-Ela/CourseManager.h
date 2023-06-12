#pragma once
#include <string>
#include <unordered_map>
#include "Course.h"
using namespace std;

class CourseManager
{
private:
	unordered_map<string, Course> Map;

	string ReadDB();
	void WriteDB(string str);

	string ParseMap2DBString(unordered_map<string, Course> Map);
	unordered_map<string, Course> ParseString2Map(string data);

	void AddCourse(string id, string name, string score, string money);
	void DeleteCourse(string id);
	void ModifyCourse(string id, string name, string score, string money);
	void PrintCourseInfo(string id);

public:
	CourseManager();

	void add();

	void del();

	void modify();

	void query();

	Course *QueryCourse(string id);
	Course *QueryCourseByName(string name);
};
