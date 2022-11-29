#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <unordered_map>
#include "Routes.cpp"
#include "Objects.cpp"


class BFS
{
protected:
    string initialLoc;
    string destinationLoc;
    queue<NodeClass> frontier;
    set<string> exploredSet;
    vector<string> airports;


    unordered_map<string, string> airportsToPlaces;
    unordered_map<string, vector<string>> locationToAirportsMap;
    unordered_map<string, vector<Routes>> routesMap;

public:
    BFS(unordered_map<string, string> airportsMap, unordered_map<string, vector<string>> locationsMap, unordered_map<string, vector<Routes>> routesMap);

    bool contains(queue<NodeClass> aQueue, NodeClass aNode);

    bool contains(set<string> aSet, string aString);

    bool equals(NodeClass node1, NodeClass node2);

    bool equals(string firstString, string secondString);

    bool equals(vector<Routes> firstList, any secondItem);

    vector<string> algSearch(string initialLoc, string destinationLoc);

};


BFS::BFS (unordered_map<string, string> airportsMap, unordered_map<string, vector<string>> locationsMap, unordered_map<string, vector<Routes>> routesMap)
{
    this-> airportsToPlaces = airportsMap;
    this->locationToAirportsMap = locationsMap;
    this->routesMap = routesMap;
}

bool BFS::contains(queue<NodeClass> aQueue, NodeClass aNode)
{
    bool check;
    queue<NodeClass> newQueueCopy = aQueue;
    while(!newQueueCopy.empty())
    {
        NodeClass item = newQueueCopy.front();
        check = equals(item, aNode);
    }
    return check;
}


bool BFS::contains(set<string> aSet, string aString)
{
    bool check;
    for(auto item : aSet)
    {
        check = (item == aString);
        if(check == true)
            break;
    }
    return check;
}


bool BFS::equals(NodeClass firstNode, NodeClass secNode)
{
    return (typeid(firstNode) == typeid(secNode));
}

bool BFS::equals(string firstString, string secondString)
{
    return (firstString == secondString);
}

bool BFS::equals(vector<Routes> firstList, any secondItem)
{
    return (typeid(firstList) == typeid(secondItem));
}


vector<string> BFS::algSearch(string initialLoc, string destinationLoc){
    airports = locationToAirportsMap.at(initialLoc);

    for(string airport:airports)
    {
        NodeClass airportNode(NULL, airport, NULL, 0, NULL);
        frontier.push(airportNode);
    }




    while(frontier.size() != 0){
        NodeClass currentNode = frontier.pop();

        exploredSet.insert(currentNode.getAirportCode());
        vector<Routes> successorStates = routesMap.at(currentNode.getAirportCode());

        if (equals(successorStates, NULL) == false)
        {
            for(Routes successorState: successorStates)
            {
                NodeClass child(currentNode, successorState.getDestinationAirportCode(), successorState.getAirlineCode(), successorState.getStops(), NULL);

                if (!(contains(frontier, child)) && !(contains(exploredSet, child.getAirportCode()))){
                    string destinationName = airportsToPlaces.at(child.getAirportCode());
                    if((equals(destinationName, NULL) == false) && (equals(destinationName, destinationLoc) == true))
                    {
                        return child.solutionPath();
                    }
                }
                frontier.push(child);
            }
        }
    }
}
