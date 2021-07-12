
#include <iostream>
#include <fstream>
#include "RWfiles.h"
#include "AdminOptions.h"
#include "TeacherVIew.h"
//#include "TeacherOptions.h"
using namespace std;




int main() {

  string user,pass; AdminButtons admChoice;
  TeacherButtons teacherSelect;
  while(true){
  cout<<"WELCOME TO GIS-GRADING INTERACTIVE SYSTEM"<<endl;
  cout<<"Please login"<<endl;
  cout<<"Username: ";
  cin>>user;
  cout<<"Password: ";cin>>pass; 
  List<student> s=readStudents(); 
    List<teacher> t=readTeachers(); 
    List<subject> c=readSubjects(); 
    List<Grade> g=readGrades(); 
  if(user=="admin"&&pass=="admin"){
   
    while(true){
    
  int cmd=AdminView();admChoice=choice(cmd);
  
  switch(admChoice){
case adminViewStudents:
viewStudents(readStudents());break;
case adminViewTeachers:
viewTeachers(readTeachers());break;
case adminViewSubjects:
viewSubjects(readSubjects());break;
case adminAddStudent:
addStudent(s);break;
case adminAddTeacher:
addTeacher(t);break;
case adminAddSubject:
addSubject(c);break;
case adminUpdateStudent:
updateStudent(s);break;
case adminUpdateTeacher:
updateTeacher(t);break;
case adminUpdateCourse:
updateSubject(c);break;
default:
break;
  }
  if (cmd>9) break;}}
  else {
    while(true){
  Node<teacher>* teacherInfo=TeacherExists(user,pass,t);
  if(teacherInfo==nullptr)  break;
int cmd=TeacherView(); teacherSelect=teacherChoice(cmd);

switch(teacherSelect){
  case teacherViewStudents:{
  int *arr=TeacherViewCourses(c,teacherInfo->data->id);
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
  cout<<arr[i]<<" ";
  cout<<endl; break;}
   case teacherViewArithmeticSubjectMean:
   if(subjectAvg(c,g)>0)
  cout<<subjectAvg(c,g)<<endl;
  else cout<<"ID does not exist or there are no grades to show!"<<endl; break;
   
  case teacherInsertGrade:
  addGrade(g);break; 
  default:
  break;
}
if(cmd>4) break;}
  }
  }
 return 0;
}
