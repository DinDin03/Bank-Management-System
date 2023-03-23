#include <iostream>
#include <fstream>
#include <string>
#include "student.h"
using namespace std;

class Classroom
{
private:
    int class_size;
    Student* student_records;
public:
    Classroom(){
        class_size = 0;
        student_records = new Student[class_size];
        };
    Classroom(int a_class_size){
        class_size = a_class_size;
        student_records = new Student[class_size];
        
    }
    ~Classroom(){
        delete [] student_records; 
    }
    void read_students_records(string filesname){
        ifstream student_records_file;
        student_records_file.open(filesname);
        for (size_t i = 0; i < class_size; i++)
        {
            string name;
            int ID;
            double grade;
        }
        
     }
};


int main(){
    Classroom oop20239(50);
    return 0;

}