#include <iostream>
#include <vector>
#include <algorithm>
#include "Routes.cpp"
#include <string>
using namespace std;

class NodeClass{

private:
    NodeClass *parentNode;
    string airportCode;
    string airlineCode;
    int Stops;
    vector<Routes>successors;

public:

    NodeClass(NodeClass *parentNode, string airportCode, string airlineCode, int Stops, vector<Routes>successors){
        this->parentNode = parentNode;
        this->airportCode = airportCode;
        this->airlineCode = airlineCode;
        this->Stops = Stops;
        this->successors = successors;
    }

    string to_string();
    bool operator==(const NodeClass &obj);
    int hashCode();

    NodeClass getParentNode();
    void setParentNode(NodeClass *parentNode);

    string getAirportCode();
    void setAirportCode(string airportCode);

    string getAirlineCode();
    void setAirlineCode(string airlineCode);

    int getStops();
    void setStops(int Stops);

    vector<Routes> getSuccessors();
    void setSuccessors(vector<Routes> successors);


    vector<string> solutionPath();
};

string NodeClass:: to_string(){
    return "Node{parentNode= ", *parentNode,
            ", airportCode='" + airportCode + '\'' +
            ", airlineCode='" + airlineCode + '\'' +
            ", stops=", Stops,
            ", successors=", successors,
            "}";
}

bool NodeClass:: operator==(const NodeClass&obj){

    if (*this == obj) {
        return true;
    }
    if (&obj == NULL || typeid(obj) != typeid(this)){
        return false;
    }
    NodeClass node = (NodeClass) obj;
    return  airportCode==node.airportCode;
}

//int NodeClass:: hashCode(){
//    return hash(*parentNode, airportCode, airlineCode, Stops, successors);
//}

NodeClass NodeClass:: getParentNode() {
    return *parentNode;
}

void NodeClass:: setParentNode(NodeClass *parentNode) {
    this->parentNode = parentNode;
}

string NodeClass:: getAirportCode() {
    return airportCode;
}

void NodeClass:: setAirportCode(string airportCode) {
    this->airportCode = airportCode;
}

string NodeClass:: getAirlineCode() {
    return airlineCode;
}

void NodeClass:: setAirlineCode(string airlineCode) {
    this->airlineCode = airlineCode;
}

int NodeClass:: getStops() {
    return Stops;
}

void NodeClass:: setStops(int stops) {
    this->Stops = stops;
}

vector<Routes> NodeClass:: getSuccessors() {
    return successors;
}

void NodeClass:: setSuccessors(vector<Routes> successors) {
    this->successors = successors;
}



vector<string> NodeClass:: solutionPath(){
    vector<string> airportCodes;
    vector<string> airlineCodes;
    vector<string> solution;
    vector<int> stops;
    NodeClass thisNode = *this;

    while(&thisNode != NULL){
        airlineCodes.push_back(thisNode.getAirlineCode());
        airportCodes.push_back(thisNode.getAirportCode());
        stops.push_back(thisNode.getStops());
        thisNode = *thisNode.parentNode;
    }
    reverse(airlineCodes.begin(), airlineCodes.end());
    reverse(airportCodes.begin(), airportCodes.end());

    for (int i = 0;i < airlineCodes.size()-1;i++){
        string result = airlineCodes.at(i+1) + " from " + airportCodes.at(i) + " to " +
                        airportCodes.at(i+1) + " " + std::to_string(stops.at(i)) + " stops.";
        solution.push_back(result);
    }

    return solution;

}

