#include <string>
using namespace std;
struct teacher{
int id;
string user;
string pass;
string name;
string surname;
int age;
int salary;

    teacher(){
    }
    teacher(int id, string user, string pass, string name, string surname, int age, double salary) {
        this->id = id;
        this->user = user;
        this->pass = pass;
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->salary = salary;
    }
};
