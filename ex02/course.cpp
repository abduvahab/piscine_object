#include "./course.hpp"
#include "./student.hpp"

void Course::subscribe(Student* p_student){
    if(_students.size() < size_t(_maximumNumberOfStudent)){
        for (std::vector<Student*>::iterator it=_students.begin(); it!=_students.end(); it++){
            if(*it == p_student){
                return ;
            }
        }
        _students.push_back(p_student);
    }
}
