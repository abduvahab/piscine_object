#include "./bell.hpp"
#include "./professor.hpp"
#include "./student.hpp"


void Bell::addlistener(BellListener* listener){
    for(std::vector<BellListener*>::iterator it=bellListeners.begin(); it!=bellListeners.end(); it++){
        if(*it == listener){
            return;
        }
    }
    bellListeners.push_back(listener);

}
void Bell::ringBell(){
    onBreak = !onBreak;
    Event event= RingBell;
     
    for(std::vector<BellListener*>::iterator it=bellListeners.begin(); it!=bellListeners.end(); it++){
        
        (*it)->oneBellRing(event, onBreak);
    }
}