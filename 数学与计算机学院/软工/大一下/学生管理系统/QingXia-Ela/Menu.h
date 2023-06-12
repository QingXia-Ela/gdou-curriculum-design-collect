#pragma once
#include "GradeManager.h"

class Menu
{
private:
  GradeManager gradeManager;
  CourseManager courseManager;
  StudentManager studentManager;

  void gotoCourseMenu();
  void gotoStudentMenu();
  void gotoGradeMenu();
  void gotoMainMenu();
  void gotoExitMenu();

public:
  Menu(CourseManager &C, StudentManager &S, GradeManager &G) : courseManager(C), studentManager(S), gradeManager(G){};
  void StartMenu();
};
