
#include <iostream>
//#include "sll.h"
#include<fstream>
#include"RWfiles.h"
using namespace std;
enum AdminButtons {
    adminViewStudents = 1,
    adminViewTeachers = 2,
    adminViewSubjects = 3,
    adminAddStudent = 4,
    adminAddTeacher = 5,
    adminAddSubject = 6,
    adminUpdateStudent = 7,
    adminUpdateTeacher = 8,
    adminUpdateCourse = 9,
    adminExit
};
//admin functionalities:update and add

void addStudent();
void addTeacher();
void addSubject();
bool checkStudent();
bool checkTeacher();
bool checkSubject();
void updateStudent();
void updateTeacher();
void updateSubject();
void viewTeachers();
void viewSubjects();
void viewStudents();

void viewStudents(Node<student> *s){
  if(s==nullptr)
return;

cout<<s->data->id<<" "<<s->data->name<<" "<<s->data->surname<<" "<<s->data->age<<" "<<s->data->classNum;
cout<<endl;
viewStudents(s->next);
}
void viewStudents(List<student> StudentDB){
  cout<<"ID Name Surname age classNum" <<endl;
  viewStudents(StudentDB.head);
}

void viewTeachers(Node<teacher> *s)
{

if(s==nullptr)
return;

cout<<s->data->id<<" "<<s->data->user<<" "<<s->data->pass<<" "<<s->data->name<<" "<<s->data->surname<<" "<<s->data->age<<" "<<s->data->salary;
cout<<endl;
viewTeachers(s->next);
}
void viewTeachers(List<teacher> TeacherDB){
  
  viewTeachers(TeacherDB.head);
}
void viewSubjects(Node<subject> *s)
{

if(s==nullptr)
return;

cout<<s->data->id<<" "<<s->data->name<<" "<<s->data->teacherId;
cout<<endl;
viewSubjects(s->next);
}
void viewSubjects(List<subject> SubjectDB){
  
  viewSubjects(SubjectDB.head);
}
void viewGrades(Node<Grade> *s)
{

if(s==nullptr)
return;

cout<<s->data->subjectId<<" "<<s->data->studentId<<" "<<s->data->grade<<" "<<s->data->classNum;
cout<<endl;
viewGrades(s->next);
}
void viewGrades(List<Grade> GradeDB){
  
  viewGrades(GradeDB.head);
}
void addStudent(List<student> &StudentDB){
 
int id;
string name;
string surname;
int age;
int classNum;
cout<<endl<<"Enter student ID: ";
cin>>id;
cout<<endl<<"Enter student name: ";
cin>>name;
cout<<endl<<"Enter student surname: ";
cin>>surname;
cout<<endl<<"Enter student age: ";
cin>>age;
cout<<endl<<"Enter student classNum: ";
cin>>classNum;
student *s=new student(id,name,surname,age,classNum);
ofstream fout;
fout.open("students.txt", std::ios_base::app); 
fout<<endl;
fout<<s->id<<" "<<s->name<<" "<<s->surname<<" "<<s->age<<" "<<s->classNum;
push_back(StudentDB,s);
}
void addTeacher(List<teacher> &TeacherDB){
  int id;
string user;
string pass;
string name;
string surname;
int age;
int salary;
cout<<endl<<"Enter teacher ID: ";
cin>>id;
cout<<endl<<"Enter teacher username: ";
cin>>user;
cout<<endl<<"Enter teacher password: ";
cin>>pass;
cout<<endl<<"Enter teacher name: ";
cin>>name;
cout<<endl<<"Enter teacher surname: ";
cin>>surname;
cout<<endl<<"Enter teacher age: ";
cin>>age;
cout<<endl<<"Enter teacher salary: ";
cin>>salary;
teacher *s=new teacher(id,user,pass,name,surname,age,salary)
;
ofstream fout;
fout.open("teachers.txt", std::ios_base::app); 
push_back(TeacherDB,s);
fout<<endl;
fout<<s->id<<" "<<s->user<<" "<<s->pass<<" "<<s->name<<" "<<s->surname<<" "<<s->age<<" "<<s->salary;
}
void addSubject(List<subject> &SubjectDB){
 
int id;
string name;
int teacherId;
cout<<endl<<"Enter subject ID:";
cin>>id;cout<<endl<<"Enter subject name:";
cin>>name;
cout<<endl<<"Enter teacher ID:";
cin>>teacherId;
subject *t=new subject(id,name,teacherId);
push_back(SubjectDB,t);
ofstream fout;
fout.open("subjects.txt", std::ios_base::app); 
fout<<endl;
fout<<t->id<<" "<<t->name<<" "<<t->teacherId;
}

AdminButtons choice(int cmd){
  AdminButtons c;
  switch(cmd){
  case 1:
  c=adminViewStudents;
  break;
  case 2:
  c=adminViewTeachers;
  break;
  case 3:
  c=adminViewSubjects;
  break;
  case 4:
  c=adminAddStudent;
  break;
  case 5:
  c=adminAddTeacher;
  break;
case 6:
  c=adminAddSubject;
  break;
  case 7:
  c=adminUpdateStudent;
  break;
  case 8:
  c=adminUpdateTeacher;
  break;
  case 9:
  c=adminUpdateCourse;
  break;
  default:
  c=adminExit;
  }return c;
}
void updateStudent(List<student> &StudentDB){
 
int id;
string name;
string surname;
int age;
int classNum;

cout<<endl<<"Enter student ID: ";
cin>>id;
cout<<endl<<"Enter student name: ";
cin>>name;
cout<<endl<<"Enter student surname: ";
cin>>surname;
cout<<endl<<"Enter student age: ";
cin>>age;
cout<<endl<<"Enter student classNum: ";
cin>>classNum;
//Node<student> s=new student(id,name,surname,age,classNum);
Node<student> *temp=StudentDB.head;
while(temp!=nullptr){
if(temp->data->id==id){
temp->data->name=name;
temp->data->surname=surname;
temp->data->age=age;
temp->data->classNum=classNum;
break;
}
  temp=temp->next;
}
if(temp==nullptr)
cout<<endl<<endl<<"ID does not exist!!"<<endl<<endl<<endl;
else{
ofstream fout("students.txt");
writeStudents(StudentDB);}
}
void updateTeacher(List<teacher> &TeacherDB){
  int id;
string user;
string pass;
string name;
string surname;
int age;
int salary;
cout<<endl<<"Enter teacher ID: ";
cin>>id;
cout<<endl<<"Enter teacher username: ";
cin>>user;
cout<<endl<<"Enter teacher password: ";
cin>>pass;
cout<<endl<<"Enter teacher name: ";
cin>>name;
cout<<endl<<"Enter teacher surname: ";
cin>>surname;
cout<<endl<<"Enter teacher age: ";
cin>>age;
cout<<endl<<"Enter teacher salary: ";
cin>>salary;
Node<teacher> *temp=TeacherDB.head;
while(temp!=nullptr){
if(temp->data->id==id){
  temp->data->user=user;
  temp->data->pass=pass;
temp->data->name=name;
temp->data->surname=surname;
temp->data->age=age;
temp->data->salary=salary;
break;
}
  temp=temp->next;
}
if(temp==nullptr)
cout<<endl<<endl<<"ID does not exist!!"<<endl<<endl<<endl;
else{
ofstream fout("teachers.txt");
writeTeachers(TeacherDB);}
}

void updateSubject(List<subject> &SubjectDB){
 int id;
string name;
int teacherId;
cout<<endl<<"Enter subject ID:";
cin>>id;cout<<endl<<"Enter subject name:";
cin>>name;
cout<<endl<<"Enter teacher ID:";
cin>>teacherId;
Node<subject> *temp=SubjectDB.head;
while(temp!=nullptr){
if(temp->data->id==id){
  temp->data->name=name;
  temp->data->teacherId=teacherId;
break;
}
  temp=temp->next;
}
if(temp==nullptr)
cout<<endl<<endl<<"ID does not exist!!"<<endl<<endl<<endl;
else{
ofstream fout("subjects.txt");
writeSubjects(SubjectDB);}
}
int AdminView(){
  cout<<"Welcome Admin"<<endl;
  cout<<"Please select one of the options:"<<endl;
  
  cout<<"Press 1 to view students:"<<endl;
  cout<<"Press 2 to view teachers:"<<endl;
  cout<<"Press 3 to view subjects:"<<endl;
  cout<<"Press 4 to add students:"<<endl;
  cout<<"Press 5 to add teachers :"<<endl;
  cout<<"Press 6 to add subjects"<<endl;
  cout<<"Press 7 to update students"<<endl;
   cout<<"Press 8 to update teachers"<<endl;
    cout<<"Press 9 to update subjects"<<endl;
     cout<<"Press any other button to exit"<<endl;
  int cmd;cin>>cmd;
  
return cmd;
}