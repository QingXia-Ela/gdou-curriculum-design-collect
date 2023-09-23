#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Score
{
public:
    int studentId;
    int courseId;
    int score;
};

class Student
{
public:
    int id;
    string name;
    int classId;
    vector<Score> scores;
};

class Course
{
public:
    int id;
    string name;
};

vector<Student> StudentData;
vector<Course> CourseData;

string getCourseNameFromId(int id)
{
    for (auto &c : CourseData)
    {
        if (c.id == id)
            return c.name;
    }
    return "";
}

int main()
{
    ifstream file("./xyz4.in");

    if (file.is_open())
    {
        string line;
        int n;
        file >> n;

        for (int i = 0; i < n; i++)
        {
            auto stu = new Student();
            file >> stu->id >> stu->name >> stu->classId;
            StudentData.push_back(*stu);
        }
        file >> n;

        for (int i = 0; i < n; i++)
        {
            auto c = new Course();
            file >> c->id >> c->name;
            CourseData.push_back(*c);
        }
        file >> n;

        for (int i = 0; i < n; i++)
        {
            auto s = new Score();
            file >> s->studentId >> s->courseId >> s->score;
            for (auto &stu : StudentData)
            {
                if (stu.id == s->studentId)
                {
                    stu.scores.push_back(*s);
                    break;
                }
            }
        }
        for (auto &stu : StudentData)
        {
            auto &arr = stu.scores;
            sort(arr.begin(), arr.end(), [](Score &s1, Score &s2)
                 { return s1.courseId < s2.courseId; });
        }

        vector<Student> FirstClass;
        vector<Student> SecondClass;

        for (auto &s : StudentData)
        {
            if (s.classId == 101)
                FirstClass.push_back(s);
            else
                SecondClass.push_back(s);
        }

        sort(FirstClass.begin(), FirstClass.end(), [](Student &s1, Student &s2)
             { return s1.id < s2.id; });

        sort(SecondClass.begin(), SecondClass.end(), [](Student &s1, Student &s2)
             { return s1.id < s2.id; });
        cout << "===============°àºÅ£º101===============" << endl;
        for (auto &s : FirstClass)
        {
            for (int i = 0; i < s.scores.size(); i++)
            {
                if (i == 0)
                    cout << s.id << " " << s.name << "  ";
                else
                    cout << "\t";

                cout << getCourseNameFromId(s.scores[i].courseId) << "\t" << s.scores[i].score << endl;
            }
        }
        cout << "===============°àºÅ£º102===============" << endl;
        for (auto &s : SecondClass)
        {
            for (int i = 0; i < s.scores.size(); i++)
            {
                if (i == 0)
                    cout << s.id << " " << s.name << "  ";
                else
                    cout << "\t";

                cout << getCourseNameFromId(s.scores[i].courseId) << "\t" << s.scores[i].score << endl;
            }
        }

        file.close();
    }
    system("pause");
    return 0;
}
