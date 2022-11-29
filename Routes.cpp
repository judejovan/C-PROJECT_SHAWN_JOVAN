#include <iostream>
#include <string>
#include <any>
using namespace std;

class Routes{

    //  Routes class  instance variables
protected:
    string airlineCode;
    string airlineID;
    string destinationAirportCode;
    int Stops;

public :
    // instance variables  constructor method
    Routes(string airlineCode, string airlineID, string destinationAirportCode, int Stops)
    {
        this->airlineCode = airlineCode;
        this->airlineID = airlineID;
        this->destinationAirportCode = destinationAirportCode;
        this->Stops = Stops;
    }

    string getAirlineCode()
    {
        return airlineCode;
    }

    void setAirlineCode(string airlineCode)
    {
        this->airlineCode = airlineCode;
    }

    string getAirlineID()
    {
        return airlineID;
    }

    void setAirlineID(string airlineID)
    {
        this->airlineID = airlineID;
    }

    string getDestinationAirportCode()
    {
        return destinationAirportCode;
    }

    void setDestinationAirportCode(string destinationAirportCode)
    {
        this->destinationAirportCode = destinationAirportCode;
    }

    int getStops()
    {
        return Stops;
    }

    void setStops(int Stops)
    {
        this->Stops = Stops;
    }

    //  toString method overridden in this class.
    string toString()
    {
        return "Routes{airlineCode= " + airlineCode + ", airlineID= " + airlineID + ", destinationAirportCode= " + destinationAirportCode + ", stops= " + to_string(Stops) + "})";
    }
};


