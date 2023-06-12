#include "Menu.h"
#include "Utils.h"
#include <iostream>
using namespace std;

bool JudgeContains(string s)
{
  return s.length() == 1 && s.find_first_not_of("01234") == string::npos;
}

void Menu::gotoCourseMenu()
{
  string choose;
  do
  {
    cout << "------课程管理------" << endl;
    cout << "1. 添加课程" << endl;
    cout << "2. 删除课程" << endl;
    cout << "3. 修改课程" << endl;
    cout << "4. 查询课程" << endl;
    cout << "0. 返回上级菜单" << endl;
    choose = Utils::GetValidInput("请输入选项:", JudgeContains);
    system("cls");

    switch (choose[0])
    {
    case '1':
      courseManager.add();
      break;
    case '2':
      courseManager.del();
      break;
    case '3':
      courseManager.modify();
      break;
    case '4':
      courseManager.query();
      break;
    }
  } while (choose != "0");
}

bool JudgeStudentContains(string s)
{
  return s.length() == 1 && s.find_first_not_of("012345") == string::npos;
}
void Menu::gotoStudentMenu()
{
  string choose;
  do
  {
    cout << "------学生管理------" << endl;
    cout << "1. 添加学生" << endl;
    cout << "2. 删除学生" << endl;
    cout << "3. 修改学生" << endl;
    cout << "4. 查询学生" << endl;
    cout << "5. 按条件查询学生" << endl;
    cout << "0. 返回上级菜单" << endl;
    choose = Utils::GetValidInput("请输入选项:", JudgeStudentContains);
    system("cls");

    switch (choose[0])
    {
    case '1':
      studentManager.add();
      break;
    case '2':
      studentManager.del();
      break;
    case '3':
      studentManager.modify();
      break;
    case '4':
      studentManager.query();
      break;
    case '5':
      studentManager.queryWithCondition();
    }
  } while (choose != "0");
}

bool JudgeGradeMenuContains(string s)
{
  return s.length() == 1 && s.find_first_not_of("012345678") == string::npos;
}
void Menu::gotoGradeMenu()
{
  string choose;
  do
  {
    cout << "------成绩管理------" << endl;
    cout << "1. 添加成绩" << endl;
    cout << "2. 删除成绩" << endl;
    cout << "3. 修改成绩" << endl;
    cout << "4. 查询成绩" << endl;
    cout << "5. 根据学号查询某个学生的各门课程的成绩" << endl;
    cout << "6. 根据课程号查询某门课程的成绩情况" << endl;
    cout << "7. 查询某班级不及格学生名单" << endl;
    cout << "8. 统计某门课程各成绩段人数及其百分比" << endl;
    cout << "0. 返回上级菜单" << endl;
    choose = Utils::GetValidInput("请输入选项:", JudgeGradeMenuContains);
    system("cls");

    switch (choose[0])
    {
    case '1':
      gradeManager.add();
      break;
    case '2':
      gradeManager.del();
      break;
    case '3':
      gradeManager.modify();
      break;
    case '4':
      gradeManager.query();
      break;
    case '5':
      gradeManager.queryByStudentId();
      break;
    case '6':
      gradeManager.queryByCourseId();
      break;
    case '7':
      gradeManager.queryClassFailStudent();
      break;
    case '8':
      gradeManager.queryGradeStudentCountByCourseId();
      break;
    }
  } while (choose != "0");
}

void Menu::gotoMainMenu()
{
  string choose;
  do
  {
    cout << "------欢迎使用学生成绩管理系统------" << endl;
    cout << "1. 课程管理" << endl;
    cout << "2. 学生管理" << endl;
    cout << "3. 成绩管理" << endl;
    cout << "4. 退出系统" << endl;
    choose = Utils::GetValidInput("请输入选项:", JudgeContains);
    system("cls");

    switch (choose[0])
    {
    case '1':
      gotoCourseMenu();
      break;
    case '2':
      gotoStudentMenu();
      break;
    case '3':
      gotoGradeMenu();
      break;
    case '4':
      gotoExitMenu();
      break;
    default:
      break;
    }
  } while (true);
}

void Menu::gotoExitMenu()
{
  if (Utils::JudgeChoose("确认退出系统?"))
    exit(0);
  system("cls");
}

void Menu::StartMenu()
{
  gotoMainMenu();
}