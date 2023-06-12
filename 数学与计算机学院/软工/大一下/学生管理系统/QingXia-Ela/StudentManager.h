#pragma once
#include "Student.h"

class StudentManager
{
private:
  vector<Student> StudentList;

  string ReadDB();
  void WriteDB(string str);

  string ParseStudentList2DBString(vector<Student> StudentList);
  vector<Student> ParseString2StudentList(string data);

  bool JudgeExist(long long id);

  void AddStudent(string data);
  void AddStudent(long long id, string name, string gender, string age, string province, string major);
  void DeleteStudent(long long id);
  void ModifyStudent(Student stu);
  void PrintStudentInfo(long long id);
  void PrintStudentInfoWithLine(Student &stu, const char *spliter);

  /** 判断条件是否符合学生 */
  vector<Student> JudgeStudent(string subName, string gender, string age, string subProvince, string subMajor);

public:
  StudentManager();

  void add();

  void del();

  void modify();

  void query();

  /** 多条件、模糊查询 */
  void queryWithCondition();

  Student *query(long long id);
};
