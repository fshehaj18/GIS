#include <string>
using namespace std;
struct Grade{
int subjectId;
int studentId;
double grade;
int classNum;

Grade(){}
Grade(int subjectId, int studentId, double grade,int classId) {
        this->subjectId = subjectId;
        this->studentId = studentId;
        this->grade = grade;
        this->classNum = classId;

    }
};
