#include "GradeManager.h"
#include "Utils.h"
#include <iostream>

string GradeManager::ReadDB()
{
  return Utils::ReadFile("Grade.txt");
}

void GradeManager::WriteDB(string str)
{
  Utils::WriteFile("Grade.txt", str);
}

string GradeManager::ParseVector2DBString(vector<Grade> grades)
{
  string str = "";
  for (Grade grade : grades)
  {
    str += grade.ToString() + "\n";
  }
  return str;
}

vector<Grade> GradeManager::ParseString2Vector(string data)
{
  vector<Grade> grades;
  vector<string> arr = Utils::StringSplit(data, '\n');
  for (string str : arr)
  {
    Grade grade(str);
    grades.push_back(grade);
  }
  return grades;
}

bool GradeManager::JudgeExist(long long id, string courseId)
{
  for (Grade grade : this->grades)
    if (grade.id == id && grade.course == courseId)
      return true;
  return false;
}

bool GradeManager::JudgeGrade(string grade)
{
  vector<string> arr({"优秀", "良好", "中等", "及格", "不及格"});
  for (string str : arr)
  {
    if (grade == str)
    {
      return true;
    }
  }
  try
  {
    int gradeNum = stoi(grade.c_str());
    return gradeNum >= 0 && gradeNum <= 100;
  }
  catch (const std::exception &e)
  {
    return false;
  }
  return false;
}

vector<Grade> GradeManager::QueryGrade(long long id, string courseId)
{
  vector<Grade> grades;
  for (Grade grade : this->grades)
  {
    if (grade.id == id && grade.course == courseId)
    {
      grades.push_back(grade);
      break;
    }
  }
  return grades;
}

vector<Grade> GradeManager::QueryGrade(long long id)
{
  vector<Grade> grades;
  for (Grade grade : this->grades)
  {
    if (grade.id == id)
    {
      grades.push_back(grade);
    }
  }
  return grades;
}

/**
 * 查询该课程下所有成绩
 */
vector<Grade> GradeManager::QueryGrade(string courseId)
{
  vector<Grade> grades;
  for (Grade grade : this->grades)
  {
    if (grade.course == courseId)
    {
      grades.push_back(grade);
    }
  }
  return grades;
}

vector<Grade> GradeManager::QueryFailStudentByClassName(string name)
{
  vector<Grade> grades;
  for (Grade grade : this->grades)
  {
    try
    {
      if (grade.grade == "不及格" || stoi(grade.grade) < 60)
      {
        Student *stu = this->studentManager.query(grade.id);
        if (stu != nullptr && stu->major == name)
          grades.push_back(grade);
      }
    }
    catch (const std::exception &e)
    {
      continue;
    }
  }
  return grades;
}

bool GradeManager::JudgeCourseIdExist(string courseId)
{
  return this->courseManager.QueryCourse(courseId) != nullptr;
}

bool GradeManager::JudgeStudentIdExist(long long id)
{
  Student *stu = this->studentManager.query(id);

  return stu != nullptr;
}

/**
 * 添加成绩（附带检验，不提示是否存在）
 */
void GradeManager::AddGrade(long long id, string courseId, string grade)
{
  if (!JudgeGrade(grade))
    return;
  Grade gradeObj(id, courseId, grade);
  this->grades.push_back(gradeObj);
  this->WriteDB(this->ParseVector2DBString(this->grades));
}

void GradeManager::DeleteGrade(long long id, string courseId)
{
  for (Grade &grade : this->grades)
  {
    if (grade.id == id && grade.course == courseId)
    {
      this->grades.erase(this->grades.begin() + this->grades.size() - 1);
      this->WriteDB(this->ParseVector2DBString(this->grades));
      return;
    }
  }
}

void GradeManager::ModifyGrade(long long id, string courseId, string grade)
{
  for (Grade &gradeObj : this->grades)
  {
    if (gradeObj.id == id && gradeObj.course == courseId)
    {
      if (!JudgeGrade(grade))
      {
        cout << "成绩不合法" << endl;
        return;
      }
      gradeObj.grade = grade;
      this->WriteDB(this->ParseVector2DBString(this->grades));
      return;
    }
  }
}

void GradeManager::PrintGradeInfo(long long id, string courseId)
{
  vector<Grade> grades = this->QueryGrade(id, courseId);

  if (grades.empty())
  {
    cout << "没有该学生与其对应课程号的成绩" << endl;
    return;
  }
  cout << "共查询到" << grades.size() << "条成绩:" << endl;
  cout << "学号\t\t课程号\t\t成绩" << endl;

  for (Grade &grade : grades)
  {
    cout << grade.ToString() << endl;
  }
}

/**
 * Visual Utils
 */

/** 添加成绩 */
void GradeManager::add()
{
  long long id;
  string courseId;
  string grade;
  cout << "------添加成绩------" << endl;
  cout << "请输入学生ID:";
  cin >> id;
  if (!JudgeStudentIdExist(id))
  {
    cout << "该学生不存在" << endl;
    Utils::PauseAndCls();
    return;
  }
  cout << "请输入课程ID:";
  cin >> courseId;
  if (!JudgeCourseIdExist(courseId))
  {
    cout << "该课程不存在" << endl;
    Utils::PauseAndCls();
    return;
  }

  /**
   * 检查是否已有该学生与该课程的成绩，输入成绩的逻辑进行复用
   */

  bool exist = JudgeExist(id, courseId);

  if (exist)
  {
    this->PrintGradeInfo(id, courseId);
    if (!Utils::JudgeChoose("该操作将覆盖这条数据，是否继续?"))
      return;
  }

  cout << "请输入成绩:";
  cin >> grade;
  if (JudgeGrade(grade))
  {
    exist ? this->ModifyGrade(id, courseId, grade) : this->AddGrade(id, courseId, grade);
    cout << (exist ? "修改成功" : "添加成功") << endl;
  }
  else
    cout << "请输入正确的成绩" << endl;

  Utils::PauseAndCls();
}

/** 删除成绩 */
void GradeManager::del()
{
  cout << "------删除成绩------" << endl;
  long long id;
  string courseId;
  cout << "请输入学生ID:";
  cin >> id;
  cout << "请输入课程ID:";
  cin >> courseId;
  if (JudgeExist(id, courseId))
  {
    cout << endl;
    this->PrintGradeInfo(id, courseId);
    if (Utils::JudgeChoose("该操作将删除这条数据，是否继续?"))
    {
      this->DeleteGrade(id, courseId);
      cout << "删除成功" << endl;
    }
    else
      cout << "已取消删除操作" << endl;
  }
  else
    cout << "该条件下没有查询到任何成绩" << endl;

  Utils::PauseAndCls();
}

void GradeManager::modify()
{
  long long id;
  string courseId;
  string grade;
  cout << "------修改成绩------" << endl;
  cout << "请输入学生ID:";
  cin >> id;
  cout << "请输入课程ID:";
  cin >> courseId;

  if (JudgeExist(id, courseId))
  {
    cout << endl;
    this->PrintGradeInfo(id, courseId);
    if (Utils::JudgeChoose("该操作将进行修改数据，是否继续?"))
    {
      cout << "请输入新的成绩:";
      cin >> grade;
      if (JudgeGrade(grade))
      {
        this->ModifyGrade(id, courseId, grade);
        cout << "修改成功" << endl;
      }
      else
        cout << "请输入正确的成绩" << endl;
    }
    else
      cout << "已取消修改操作" << endl;
  }
  else
    cout << "该条件下没有查询到任何成绩" << endl;

  Utils::PauseAndCls();
}

/** 查询成绩 */
void GradeManager::query()
{
  long long id;
  string courseId;
  cout << "------查询成绩------" << endl;
  cout << "请输入学生ID:";
  cin >> id;
  cout << "请输入课程ID:";
  cin >> courseId;
  if (JudgeExist(id, courseId))
    this->PrintGradeInfo(id, courseId);
  else
    cout << "该条件下没有查询到任何成绩" << endl;

  Utils::PauseAndCls();
}

void GradeManager::queryByStudentId()
{
  cout << "------查询学生各门课程成绩------" << endl;
  long long id;
  id = stoll(Utils::GetValidInput("请输入学生ID:", Student::validateId));

  if (JudgeStudentIdExist(id))
  {
    vector<Grade> grades = this->QueryGrade(id);
    if (grades.empty())
      cout << "该学生不包含任何成绩" << endl;
    else
    {
      cout << "ID为" << id << "的学生各课程成绩如下:" << endl;
      cout << "课程ID\t\t成绩" << endl;
      for (Grade &grade : grades)
        cout << grade.course << "\t" << grade.grade << endl;
    }
  }
  else
    cout << "该学生不存在" << endl;

  Utils::PauseAndCls();
}

void GradeManager::queryByCourseId()
{
  cout << "------查询课程成绩成绩情况------" << endl;
  string courseId;
  cout << "请输入课程ID:";
  cin >> courseId;
  if (JudgeCourseIdExist(courseId))
  {
    vector<Grade> grades = this->QueryGrade(courseId);
    if (grades.empty())
      cout << "该课程不包含任何成绩" << endl;
    else
    {
      cout << "ID为" << courseId << "的课程中各成绩段人数如下:" << endl;
      unordered_map<string, int> GradeMap;
      for (Grade &grade : grades)
        GradeMap[grade.grade]++;
      cout << "成绩\t\t人数" << endl;
      for (auto it = GradeMap.begin(); it != GradeMap.end(); it++)
        cout << it->first << "\t\t" << it->second << endl;
    }
  }
  else
    cout << "该课程不存在" << endl;

  Utils::PauseAndCls();
}

void GradeManager::queryClassFailStudent()
{
  cout << "------查询课程不及格学生的成绩情况------" << endl;
  string className;
  cout << "请输入班级名称:";
  cin >> className;
  vector<Grade> grades = this->QueryFailStudentByClassName(className);
  if (grades.empty())
    cout << "该班级不包含任何学生或该班级没有不合格者或不存在该班级" << endl;
  else
  {
    cout << "班级名称为 " << className << " 中不及格学生的成绩段如下:" << endl;
    cout << "学生ID\t\t课程ID\t\t成绩" << endl;
    for (Grade &grade : grades)
      cout << grade.id << "\t" << grade.course << "\t" << grade.grade << endl;
  }
  Utils::PauseAndCls();
}

void GradeManager::queryGradeStudentCountByCourseId()
{
  cout << "------查询课程成绩情况------" << endl;
  string courseId;
  cout << "请输入课程ID:";
  cin >> courseId;
  if (JudgeCourseIdExist(courseId))
  {
    vector<Grade> grades = this->QueryGrade(courseId);
    if (grades.empty())
      cout << "该课程不包含任何成绩" << endl;
    else
    {
      cout << "课程ID为 " << courseId << " 的课程中各成绩段人数与百分比如下:" << endl;
      unordered_map<string, int> GradeMap;
      int count = 0;
      for (Grade &grade : grades)
      {
        GradeMap[grade.grade]++;
        count++;
      }
      cout << "成绩\t\t人数\t\t百分比" << endl;
      for (auto it = GradeMap.begin(); it != GradeMap.end(); it++)
        cout << it->first << "\t\t" << it->second << "\t\t" << (it->second * 1.0 / count * 100) << "%" << endl;
    }
  }
  else
    cout << "该课程不存在" << endl;

  Utils::PauseAndCls();
}

GradeManager::GradeManager(CourseManager &C, StudentManager &S) : courseManager(C), studentManager(S)
{
  this->grades = ParseString2Vector(this->ReadDB());
}
