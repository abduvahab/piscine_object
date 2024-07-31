#include "parsing.hpp" 

Parsing::Parsing(const std::string& railsFileName, const std::string& trainsFileName):
        railsFileName(railsFileName),
        trainsFileName(trainsFileName),
        nodeLines(),
        railLines(),
        eventLines(),
        trainLines(),
        nodeNames()
        {

}

Parsing::Parsing(const Parsing& obj){
    *this = obj;
}

Parsing& Parsing::operator=(const Parsing& obj){
    if(this == &obj){
        return *this;
    }
    railsFileName = obj.railsFileName;
    trainsFileName = obj.trainsFileName;
    nodeLines = obj.nodeLines;
    eventLines = obj.eventLines;
    railLines = obj.railLines;
    trainLines = obj.trainLines;
    nodeNames = obj.nodeNames;
    return *this;
}


std::string      Parsing::getRailsFileName(){
    return railsFileName;
}

std::string      Parsing::getTrainsFileName(){
    return trainsFileName;
}


void             Parsing::setRailsFileName(const std::string &filename){
    railsFileName = filename;
}

void             Parsing::setTrainsFileName(const std::string &filename){
    trainsFileName = filename;
}

void      Parsing::readRailsFile(){
    if(railsFileName == "" ){
        throw ParsingException("the rails network file is not provided");
    }
    std::ifstream railsFile(railsFileName.c_str());
    if(!railsFile.is_open()){
        throw ParsingException("the rails network file can't be open");
    }

    std::string line;
    int i = 1;
    while(std::getline(railsFile, line)){
        std::istringstream iss(line);
        std::string type;
        iss>>type;
        if(type == "Node"){
           nodeLines.push_back(line); 
        }
        else if(type == "Event"){
            eventLines.push_back(line);
        }
        else if(type == "Rail"){
            railLines.push_back(line);
        }
        else if(type == ""){
            i++;
            continue;
            // std::cout<<"continue--------------------"<<std::endl;
        }
        else{
            std::stringstream ss;
            ss<<i;
            throw ParsingException("rail description file, Unknown Line "+ ss.str() + ": "+line);
        }
        i++;
    }

    railsFile.close();
}
void             Parsing::readTrainssFile(){
    if(trainsFileName == ""){
        throw ParsingException("the train file is not provided");
    }
    std::ifstream trainFile(trainsFileName.c_str());
    if(!trainFile.is_open()){
        throw ParsingException("the train file can't be open");
    }

    std::string line;
    while(std::getline(trainFile, line)){
        trainLines.push_back(line);   
    }

    trainFile.close();
}
void             Parsing::addNodesName(const std::string name){
    for(std::vector<std::string>::iterator it=nodeNames.begin(); it!=nodeNames.end(); it++){
        if(*it == name){
            return ;
        }
    }
    nodeNames.push_back(name);
}

void         Parsing::checkAllTokens(){

}

std::vector<std::string> Parsing::splitString(std::string line){
    line.find()
}

void             Parsing::checkNodes(){
    for(std::vector<std::string>::iterator it=nodeLines.begin(); it!=nodeLines.end(); it++){
        std::istringstream iss(*it);
        std::string node;
        iss>>node;
        std::string nodeName;
        iss>>nodeName;
        std::string other;
        iss>>other;
        if(other !=""){
            throw ParsingException("rail description file, Unknown Line -: " + *it);
        }
        addNodesName(nodeName);
    }
}

void             Parsing::checkEvents(){

}

void             Parsing::checkRails(){

}

void             Parsing::checkTrains(){

}


