#include <string>
using namespace std;
struct student{
int id;
string name;
string surname;
int age;
int classNum;


    student() {

    }
    student(int id, string name, string surname, int age, int classNum) {
        this->id = id;
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->classNum = classNum;
    }
};
