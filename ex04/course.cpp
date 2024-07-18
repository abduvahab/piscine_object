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
std::vector<Student*>::iterator Course::removeStudent(Student* p_student){
        std::vector<Student*>::iterator it=_students.begin();
        for (; it!=_students.end(); it++){
            if(*it == p_student){
                return _students.erase(it);
            }
        }
        return _students.end();
}

void Course::printStudent(){
    std::cout<<"list of the studentd for "<<_name<<" course: ";
    for(std::vector<Student*>::iterator it=_students.begin(); it!=_students.end(); it++){
        std::cout<<(*it)->getName()<<",";
    }
    std::cout<<std::endl;
}
