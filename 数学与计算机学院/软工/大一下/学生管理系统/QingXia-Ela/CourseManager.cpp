#include "CourseManager.h"
#include "Utils.h"
#include <fstream>
#include <vector>
#include <iostream>

string CourseManager::ReadDB()
{
	return Utils::ReadFile("CourseInfo.txt");
}

void CourseManager::WriteDB(string data)
{
	Utils::WriteFile("CourseInfo.txt", data);
}

unordered_map<string, Course> CourseManager::ParseString2Map(string data)
{
	unordered_map<string, Course> Map;
	vector<string> dataArr = Utils::StringSplit(data, '\n');

	for (string i : dataArr)
	{
		Course CourseObj(i);
		Map.insert(pair<string, Course>(CourseObj.id, CourseObj));
	}

	return Map;
}

string CourseManager::ParseMap2DBString(unordered_map<string, Course> Map)
{
	string res;
	for (auto i : Map)
		res += i.second.id + Course_Spliter + i.second.name + Course_Spliter + i.second.score + Course_Spliter + i.second.money + '\n';

	return res;
}

/** normal utils */
void CourseManager::AddCourse(string id, string name, string score, string money)
{
	Course CourseObj(id, name, score, money);
	if (this->Map.find(id) != this->Map.end()) // 如果课程已经存在
	{
		if (Utils::JudgeChoose("该课程已经存在,是否要覆盖?"))
		{
			this->Map.find(id)->second.name = name;
			this->Map.find(id)->second.score = score;
			this->Map.find(id)->second.money = money;
		}
	}
	this->Map.insert(pair<string, Course>(id, CourseObj));
	this->WriteDB(this->ParseMap2DBString(this->Map));
}

void CourseManager::DeleteCourse(string id)
{
	this->Map.erase(id);
	this->WriteDB(this->ParseMap2DBString(this->Map));
}

void CourseManager::ModifyCourse(string id, string name, string score, string money)
{
	this->Map.find(id)->second.name = name;
	this->Map.find(id)->second.score = score;
	this->Map.find(id)->second.money = money;
	this->WriteDB(this->ParseMap2DBString(this->Map));
}

Course *CourseManager::QueryCourse(string id)
{
	if (this->Map.find(id) == this->Map.end())
		return nullptr;
	else
		return &this->Map.find(id)->second;
}

Course *CourseManager::QueryCourseByName(string name)
{
	for (auto i : this->Map)
		if (i.second.name == name)
			return &i.second;
	return nullptr;
}

void CourseManager::PrintCourseInfo(string id)
{
	Course *course = this->QueryCourse(id);
	if (course == nullptr)
	{
		cout << "该课程不存在!" << endl;
		return;
	}
	cout << "课程信息如下:" << endl;
	cout << "课程号:" << course->id << endl;
	cout << "课程名:" << course->name << endl;
	cout << "课程学分:" << course->score << endl;
	cout << "课程学财:" << course->money << endl;
}

/**
 * Add Course
 */
void CourseManager::add()
{
	cout << "------添加课程信息------" << endl;
	string id, name, score, money;
	cout << "请输入课程号:";
	cin >> id;
	cout << "请输入课程名:";
	cin >> name;
	cout << "请输入课程学分:";
	cin >> score;
	cout << "请输入课程学财:";
	cin >> money;
	this->AddCourse(id, name, score, money);
	cout << "添加成功!" << endl;

	Utils::PauseAndCls();
}

/**
 * Delete Course
 */
void CourseManager::del()
{
	cout << "------删除课程信息------" << endl;
	string id;
	cout << "请输入课程号:";
	cin >> id;
	Course *course = this->QueryCourse(id);
	if (course == nullptr)
	{
		cout << "该课程不存在!" << endl;
	}
	else
	{
		/**
		 * show course info and confirm delete
		 */
		this->PrintCourseInfo(id);
		if (Utils::JudgeChoose("确定要删除该课程吗?"))
		{
			this->DeleteCourse(id);
			cout << "删除成功!" << endl;
		}
		else
			cout << "已取消删除!" << endl;
	}

	Utils::PauseAndCls();
}

/**
 * Modify Course
 */
void CourseManager::modify()
{
	cout << "------修改课程信息------" << endl;
	string id, name, score, money;
	cout << "请输入要修改课程的课程号:";
	cin >> id;

	Course *course = this->QueryCourse(id);
	if (course == nullptr)
	{
		cout << "该课程不存在!" << endl;
	}
	else
	{
		this->PrintCourseInfo(id);
		if (Utils::JudgeChoose("确定要修改该课程吗?"))
		{
			cout << "请输入课程名:";
			cin >> name;
			cout << "请输入课程学分:";
			cin >> score;
			cout << "请输入课程学财:";
			cin >> money;
			this->ModifyCourse(id, name, score, money);
			cout << "修改成功!" << endl;
		}
		else
			cout << "已取消修改!" << endl;
	}

	Utils::PauseAndCls();
}

void CourseManager::query()
{
	cout << "------查询课程信息------" << endl;
	string id;
	cout << "请输入要查询课程的课程号:";
	cin >> id;
	Course *course = this->QueryCourse(id);
	if (course == nullptr)
	{
		cout << "该课程不存在!" << endl;
	}
	else
		this->PrintCourseInfo(id);

	Utils::PauseAndCls();
}

CourseManager::CourseManager()
{
	this->Map = this->ParseString2Map(this->ReadDB());
}
