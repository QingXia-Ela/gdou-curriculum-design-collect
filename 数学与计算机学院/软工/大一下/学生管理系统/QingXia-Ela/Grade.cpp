#include "Grade.h"
#include "Utils.h"

Grade::Grade(string data)
{
  vector<string> arr = Utils::StringSplit(data, spliter);

  this->id = atoll(arr[0].c_str());
  this->course = arr[1];
  this->grade = arr[2];
}

string Grade::ToString()
{
  return to_string(this->id) + spliter + this->course + spliter + this->grade;
}