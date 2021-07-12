#include <string>
using namespace std;
struct subject{
int id;
string name;
int teacherId;


    subject(){
    }
    subject(int id, string name, int teacherId) {
        this->id = id;
        this->name = name;
        this->teacherId = teacherId;
    }
};
