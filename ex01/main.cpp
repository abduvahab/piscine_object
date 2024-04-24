
#include "./Graphic.hpp"
#include "./Vector2.hpp"


int main(){
    try{
        Graphic graph;
        graph.addPoint(0, 0);
        graph.addPoint(2, 2);
        graph.addPoint(4, 2);
        graph.addPoint(2, 4);
        // graph.addPoint(-2, -4);
        graph.addPoint(9.2, 9.3);
        graph.addPoint(12.6, 15.3);
        // graph.addPoint(99.4, 99.3);
        // graph.addPoint(99.6, 99.3);

        graph.drawGraphic();

    }
    catch(std::exception &e){
        std::cout<<e.what()<<std::endl;
    }

}