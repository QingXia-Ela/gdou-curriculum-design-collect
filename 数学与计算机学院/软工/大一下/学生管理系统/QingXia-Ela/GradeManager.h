#pragma once
#include <string>
#include <vector>
#include "Grade.h"
#include "CourseManager.h"
#include "StudentManager.h"
using namespace std;

class GradeManager
{
private:
  vector<Grade> grades;
  CourseManager courseManager;
  StudentManager studentManager;

  string ReadDB();
  void WriteDB(string str);

  string ParseVector2DBString(vector<Grade> grades);
  vector<Grade> ParseString2Vector(string data);

  bool JudgeExist(long long id, string courseId);
  bool JudgeGrade(string grade);
  bool JudgeStudentIdExist(long long id);
  bool JudgeCourseIdExist(string courseId);

  void AddGrade(long long id, string courseId, string grade);
  void DeleteGrade(long long id, string courseId);
  void ModifyGrade(long long id, string courseId, string grade);
  void PrintGradeInfo(long long id, string courseId);

public:
  GradeManager(CourseManager &C, StudentManager &S);

  void add();

  void del();

  void modify();

  void query();

  /** 根据学号查询某个学生的各门课程的成绩 */
  void queryByStudentId();

  /** 根据课程号查询某门课程的成绩情况 */
  void queryByCourseId();

  /** 统计某班级不及格名单 */
  void queryClassFailStudent();

  /** 统计某门课程各成绩段人数及其百分比 */
  void queryGradeStudentCountByCourseId();

  vector<Grade> QueryGrade(long long id, string courseId);
  vector<Grade> QueryGrade(long long id);
  vector<Grade> QueryGrade(string courseId);
  vector<Grade> QueryFailStudentByClassName(string name);
};
