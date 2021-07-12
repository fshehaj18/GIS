#include "sll.h"
#include <bits/stdc++.h> 
using namespace std;
enum TeacherButtons{
    teacherViewStudents=1,
    teacherViewArithmeticSubjectMean=2,
    teacherViewStudentMean=3,
    teacherInsertGrade=4,
    teacherExit
    };
    //void teacherViewStudents();

void addGrade(List<Grade> &GradeDB){
 
int id;
double grade;
int studentId;
int classNum;
cout<<endl<<"Enter subject ID:";
cin>>id;cout<<endl<<"Enter student ID:";
cin>>studentId;
cout<<endl<<"Enter grade";
cin>>grade;
cout<<endl<<"Enter classNum";
cin>>classNum;
Grade *t=new Grade(id,studentId,grade,classNum);
push_back(GradeDB,t);
ofstream fout;
fout.open("grades.txt", std::ios_base::app); 
fout<<endl;
fout<<t->studentId<<" "<<t->subjectId<<" "<<t->grade<<" "<<t->classNum;
}
void append(int *arr,int &n,int val)
{
   int newArr[n+1];
   for(int i = 0; i < n; i++)
        newArr[i] = arr[i];

   n+=1;
   arr = newArr;
   
}

int* TeacherViewCourses(List<subject> &s,int teacherID){
//List<subject> courses;
Node<subject> *temp=s.head;
int n=0;
int * courses=new int(n);
while(temp!=nullptr){
  subject* add_course=new subject(temp->data->id,temp->data->name,temp->data->teacherId);
  if(temp->data->teacherId==teacherID){
  append(courses,n,temp->data->id);courses[n-1]=temp->data->id;}
  temp=temp->next;
}
//viewSubjects(courses);
return courses;
}
void display(int* arr){
  int n=sizeof(arr)/sizeof(arr[0]);
  for(int i=0;i<n;i++)
  cout<<arr[i]<<" ";
  cout<<endl;
}
bool checkSubject(int * arr,int teacherId){
  for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
    if(arr[i]==teacherId)
    return true;
  }
  return false;
}
List<Grade> TeacherViewGrades(List<Grade> &s,int subjectId){
List<Grade> courses;
Node<Grade> *temp=s.head;
while(temp!=nullptr){
  Grade* add_course=new Grade(temp->data->studentId,temp->data->subjectId,temp->data->grade,temp->data->classNum);
  if(temp->data->subjectId==subjectId)
  push_back(courses,add_course);
  temp=temp->next;
}
return courses;
}
string searchSubject(List<subject> &s,int id){
  Node<subject> *temp=s.head;
  while(temp!=nullptr){
if(temp->data->id==id)
return temp->data->name;
    temp=temp->next;
  }
  return NULL;
}
double subjectAvg(List<subject> &s,List<Grade> &g){
  cout<<"Enter the subject id: ";
  int subjectId;cin>>subjectId;
  cout<<endl;
  List<Grade> subjectGrades=TeacherViewGrades(g,subjectId);
  int size=subjectGrades.size;
  if(size==0) return 0;
  double arr[size];double avg=0;
  string name=searchSubject(s,subjectId);
  Node<Grade>*temp=g.head;
  for(int i=0;i<size;i++){
if(temp->data->subjectId==subjectId)
arr[i]=temp->data->grade;
temp=temp->next;
  }
  for(int i=0;i<size;i++)
  avg+=arr[i];
  
  cout<<"The average grade of subject "<<name<<" is: ";
  return (avg/size);
  
}
