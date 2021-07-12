
#ifndef RWfiles_H
#define RWfiles_H
#include"student.h"
#include"teacher.h"
#include"subject.h"
#include"grade.h"
#include "sll.h"
#include <fstream>


List<student> readStudents()
{
 ifstream fin("students.txt");
 List<student> StudentDB;
 while(!fin.eof()){
   student* std=new student();
   fin>>std->id>>std->name>>std->surname>>std->age>>std->classNum;
   push_back(StudentDB,std);
 }
 return StudentDB;
}

List<teacher> readTeachers()
{
 ifstream fin("teachers.txt");
 string s;
 List<teacher> TeacherDB;
 while(!fin.eof()){
  
   teacher* std=new teacher();
   fin>>std->id>>std->user>>std->pass>>std->name>>std->surname>>std->age>>std->salary;
   push_back(TeacherDB,std); 
   if(fin.eof())
   break;
 }
 return TeacherDB;
}

/**/

List<subject> readSubjects()
{
 ifstream fin("subjects.txt");
 List<subject> SubjectDB;
 while(!fin.eof()){
   subject* std=new subject();
   fin>>std->id>>std->name>>std->teacherId;
   push_back(SubjectDB,std);
 }
 return SubjectDB;
}
List<Grade> readGrades()
{
 ifstream fin("grades.txt");
 List<Grade> GradeDB;
 while(!fin.eof()){
   Grade* std=new Grade();
   fin>>std->subjectId>>std->studentId>>std->grade>>std->classNum;
   push_back(GradeDB,std);
 }
return GradeDB;}
void writeStudents(Node<student> *s);
void writeStudents(List<student> StudentDB);

void writeTeachers(Node<teacher> *s);
void writeTeachers(List<teacher> StudentDB);

void writeSubjects(Node<subject> *s);
void writeSubjects(List<subject> StudentDB);

void writeGrades(Node<Grade> *s);
void writeGrades(List<Grade> StudentDB);

void writeStudents(Node<student> *s)
{
 ofstream fout;
fout.open("students.txt", std::ios_base::app); 
if(s==nullptr)
return;
fout<<s->data->id<<" "<<s->data->name<<" "<<s->data->surname<<" "<<s->data->age<<" "<<s->data->classNum<<" ";

writeStudents(s->next);
}
void writeStudents(List<student> StudentDB){
  
  writeStudents(StudentDB.head);
}
void writeTeachers(Node<teacher> *s)
{
 ofstream fout;
fout.open("teachers.txt", std::ios_base::app); 
if(s==nullptr)
return;

fout<<s->data->id<<" "<<s->data->user<<" "<<s->data->pass<<" "<<s->data->name<<" "<<s->data->surname<<" "<<s->data->age<<" "<<s->data->salary;
fout<<endl;
writeTeachers(s->next);
}
void writeTeachers(List<teacher> TeacherDB){
  
  writeTeachers(TeacherDB.head);
}

void writeSubjects(Node<subject> *s)
{
 ofstream fout;
fout.open("subjects.txt", std::ios_base::app); 
if(s==nullptr)
return;

fout<<s->data->id<<" "<<s->data->name<<" "<<s->data->teacherId;
fout<<endl;
writeSubjects(s->next);
}
void writeSubjects(List<subject> SubjectDB){
  
  writeSubjects(SubjectDB.head);
}
void writeGrades(Node<Grade> *s)
{
 ofstream fout;
fout.open("grades.txt", std::ios_base::app); 
if(s==nullptr)
return;

fout<<s->data->subjectId<<" "<<s->data->studentId<<" "<<s->data->grade<<" "<<s->data->classNum;
fout<<endl;
writeGrades(s->next);
}
void writeGrades(List<Grade> GradeDB){
  
  writeGrades(GradeDB.head);
}
#endif