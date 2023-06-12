#pragma once
#include <string>
#include <vector>
using namespace std;
class Utils
{
public:
	static vector<string> StringSplit(const string str, const char ch);
	static string ReadFile(const char *filename);
	static void WriteFile(const char *filename, string data);
	static bool JudgeChoose(const char *title);
	static void PauseAndCls();
	static string GetValidInput(const char *title, bool (*p)(string));
};
