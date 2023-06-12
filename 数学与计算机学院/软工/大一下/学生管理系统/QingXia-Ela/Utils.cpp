#include "Utils.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * 字符串分割
 * @param str 字符串
 * @param ch 分割符
 * @return 分割后的字符串，返回一个字符串向量组
 */
vector<string> Utils::StringSplit(const string str, const char ch)
{
	vector<string> res;

	stringstream ss(str);
	string temp;
	while (getline(ss, temp, ch))
	{
		res.push_back(temp);
	}

	return res;
}

string Utils::ReadFile(const char *filename)
{
	ifstream ifile(filename);
	stringstream ss;
	ss << ifile.rdbuf();
	ifile.close();
	return ss.str();
}

void Utils::WriteFile(const char *filename, string data)
{
	ofstream ofile(filename);
	// https://blog.csdn.net/xw20084898/article/details/21374433
	ofile << data;
	ofile.close();
}

/**
 * 用于获取用户输入选择
 * @param title 标题
 * @return true:确认  false:拒绝
 */
bool Utils::JudgeChoose(const char *title)
{
	cout << title << "(y/n): ";
	char c;
	cin >> c;
	return c == 'y' || c == 'Y';
}

/**
 * 暂停程序和清空屏幕
 */
void Utils::PauseAndCls()
{
	system("pause");
	system("cls");
}

string Utils::GetValidInput(const char *title, bool (*p)(string))
{
	string res;
	cout << title;
	cin >> res;
	do
	{
		if (p(res))
			return res;
		cout << "输入有误,请重新输入: ";
		cin >> res;
	} while (true);
	return res;
}