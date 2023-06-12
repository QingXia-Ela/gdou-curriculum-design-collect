#include "StudentManager.h"
#include "Utils.h"
#include <iostream>

string StudentManager::ReadDB()
{
  return Utils::ReadFile("StudentInfo.txt");
}

void StudentManager::WriteDB(string data)
{
  Utils::WriteFile("StudentInfo.txt", data);
}

string StudentManager::ParseStudentList2DBString(vector<Student> StudentList)
{
  string res;
  for (Student &stu : StudentList)
  {
    res += stu.ToString() + '\n';
  }
  return res;
}

vector<Student> StudentManager::ParseString2StudentList(string data)
{
  vector<Student> res;
  vector<string> arr = Utils::StringSplit(data, '\n');
  for (string &str : arr)
  {
    Student stu(str);
    res.push_back(stu);
  }
  return res;
}

bool StudentManager::JudgeExist(long long id)
{
  for (Student stu : this->StudentList)
    if (stu.id == id)
      return true;
  return false;
}

Student *StudentManager::query(long long id)
{
  for (Student &stu : this->StudentList)
    if (stu.id == id)
      return &stu;
  return nullptr;
}

void StudentManager::AddStudent(string data)
{
  Student stu(data);
  if (!JudgeExist(stu.id))
    this->StudentList.push_back(stu);
}

void StudentManager::AddStudent(long long id, string name, string gender, string age, string province, string major)
{
  Student stu(id, name, gender, age, province, major);
  if (!JudgeExist(stu.id))
  {
    this->StudentList.push_back(stu);
    this->WriteDB(this->ParseStudentList2DBString(this->StudentList));
  }
};

void StudentManager::DeleteStudent(long long id)
{
  for (int i = 0; i < this->StudentList.size(); i++)
    if (this->StudentList[i].id == id)
    {
      this->StudentList.erase(this->StudentList.begin() + i);
      this->WriteDB(this->ParseStudentList2DBString(this->StudentList));
      return;
    }
}

void StudentManager::ModifyStudent(Student stu)
{
  for (int i = 0; i < this->StudentList.size(); i++)
    if (this->StudentList[i].id == stu.id)
    {
      this->StudentList[i] = stu;
      this->WriteDB(this->ParseStudentList2DBString(this->StudentList));
      return;
    }
}

void StudentManager::PrintStudentInfo(long long id)
{
  bool exist = false;
  for (Student stu : this->StudentList)
    if (stu.id == id)
    {
      exist = true;
      cout << "ID为" << stu.id << "的学生信息如下: " << endl;
      cout << "姓名:" << stu.name << endl;
      cout << "性别:" << stu.gender << endl;
      cout << "年龄:" << stu.age << endl;
      cout << "省份:" << stu.province << endl;
      cout << "专业:" << stu.major << endl;
      return;
    }

  if (!exist)
    cout << "不存在ID为" << id << "的学生!" << endl;
}

void StudentManager::PrintStudentInfoWithLine(Student &stu, const char *spliter)
{
  cout << stu.id << spliter << stu.name << spliter << stu.gender << spliter << stu.age << spliter << stu.province << spliter << stu.major << endl;
}

vector<Student> StudentManager::JudgeStudent(string subName, string gender, string age, string subProvince, string subMajor)
{
  vector<Student> res;

  for (Student stu : this->StudentList)
  {
    if (stu.name.find(subName) != string::npos)
    {
      if (stu.gender.find(gender) != string::npos)
      {
        if (stu.age.find(age) != string::npos)
        {
          if (stu.province.find(subProvince) != string::npos)
          {
            if (stu.major.find(subMajor) != string::npos)
            {
              res.push_back(stu);
            }
          }
        }
      }
    }
  }

  return res;
}

void StudentManager::add()
{
  long long id;
  string name;
  string gender;
  string age;
  string province;
  string major;
  cout << "-----添加学生信息-----" << endl;
  id = stoll(Utils::GetValidInput("请输入学生ID(12位数字): ", Student::validateId));
  if (JudgeExist(id))
  {
    cout << "该学生已存在!" << endl;
    Utils::PauseAndCls();
    return;
  }
  name = Utils::GetValidInput("请输入学生姓名(不超过20个字符): ", Student::validateName);
  gender = Utils::GetValidInput("请输入学生性别(男/女/M/F): ", Student::validateGender);
  age = Utils::GetValidInput("请输入学生年龄(2位数字): ", Student::validateAge);
  province = Utils::GetValidInput("请输入学生省份: ", Student::validateProvince);
  major = Utils::GetValidInput("请输入学生专业(不超过8个字符): ", Student::validateMajor);

  AddStudent(id, name, gender, age, province, major);
  cout << "添加成功!" << endl;
  Utils::PauseAndCls();
}

void StudentManager::del()
{
  cout << "-----删除学生信息-----" << endl;
  long long id;
  id = stoll(Utils::GetValidInput("请输入要删除的学生ID: ", Student::validateId));
  if (JudgeExist(id))
  {
    PrintStudentInfo(id);
    if (Utils::JudgeChoose("是否删除学生信息?"))
    {
      DeleteStudent(id);
      cout << "删除成功!" << endl;
    }
    else
      cout << "已取消删除操作" << endl;
  }
  else
    cout << "不存在ID为" << id << "的学生!" << endl;
  Utils::PauseAndCls();
}

void StudentManager::modify()
{
  cout << "-----修改学生信息-----" << endl;
  long long id;
  string name;
  string gender;
  string age;
  string province;
  string major;

  id = stoll(Utils::GetValidInput("请输入要修改的学生ID: ", Student::validateId));

  if (JudgeExist(id))
  {
    PrintStudentInfo(id);
    if (Utils::JudgeChoose("是否修改学生信息?"))
    {
      name = Utils::GetValidInput("请输入学生姓名(不超过20个字符): ", Student::validateName);
      gender = Utils::GetValidInput("请输入学生性别(男/女/M/F): ", Student::validateGender);
      age = Utils::GetValidInput("请输入学生年龄(2位数字): ", Student::validateAge);
      province = Utils::GetValidInput("请输入学生省份: ", Student::validateProvince);
      major = Utils::GetValidInput("请输入学生专业(不超过8个字符): ", Student::validateMajor);

      Student stu(id, name, gender, age, province, major);
      ModifyStudent(stu);
      cout << "修改成功!" << endl;
    }
    else
      cout << "已取消修改" << endl;
  }
  else
    cout << "不存在ID为" << id << "的学生!" << endl;
  Utils::PauseAndCls();
}

void StudentManager::query()
{
  cout << "-----查询学生信息-----" << endl;
  long long id;
  id = stoll(Utils::GetValidInput("请输入要查询的学生ID: ", Student::validateId));
  PrintStudentInfo(id);
  Utils::PauseAndCls();
}

void StudentManager::queryWithCondition()
{
  cout << "------按条件查询学生信息------" << endl;

  string subName;
  string gender;
  string age;
  string subMajor;
  string subProvince;

  string temp;

  cout << "请输入以下所有信息，输入#表示不将其作为查询条件: \n\n";

  cout << "请输入学生姓名(子串即可): ";
  cin >> temp;
  if (temp != "#")
    subName = temp;

  cout << "请输入学生性别: ";
  cin >> temp;
  if (temp != "#")
    gender = temp;

  cout << "请输入学生年龄: ";
  cin >> temp;
  if (temp != "#")
    age = temp;

  cout << "请输入学生专业(子串即可): ";
  cin >> temp;
  if (temp != "#")
    subMajor = temp;

  cout << "请输入学生省份(子串即可): ";
  cin >> temp;
  if (temp != "#")
    subProvince = temp;

  vector<Student> res = this->JudgeStudent(subName, gender, age, subProvince, subMajor);

  if (res.empty())
  {
    cout << "没有查询到符合条件的学生信息!" << endl;
    Utils::PauseAndCls();
    return;
  }

  cout << "共查询到" << res.size() << "条符合条件的学生信息!\n"
       << endl;

  cout << "学生ID\t\t姓名\t性别\t年龄\t省份\t专业" << endl;
  for (auto stu : res)
    PrintStudentInfoWithLine(stu, "\t");

  Utils::PauseAndCls();
}

StudentManager::StudentManager()
{
  this->StudentList = ParseString2StudentList(ReadDB());
}