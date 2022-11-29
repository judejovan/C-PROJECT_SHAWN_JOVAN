#include <iostream>
#include <string>
using namespace std;

class Airports
{
protected:
    string airportID;
    string airportName;
    string City;
    string Country;
    string IACO_code;


public :
    Airports(string airportID, string airportName, string City, string Country, string IACO_code)
    {
        this->airportID = airportID;
        this->airportName = airportName;
        this->City = City;
        this->Country = Country;
        this->IACO_code = IACO_code;
    }

    string getAirportID()
    {
        return airportID;
    }

    void setAirportID(string airportID)
    {
        this->airportID = airportID;
    }

    string getAirportName()
    {
        return airportName;
    }

    void setAirportName(string airportName)
    {
        this->airportName = airportName;
    }

    string getCity()
    {
        return City;
    }

    void setCity(string City)
    {
        this->City = City;
    }

    string getCountry()
    {
        return Country;
    }

    void setCountry(string Country)
    {
        this->Country = Country;
    }

    string getIACO_code()
    {
        return IACO_code;
    }

    void setIACO_code(string IACO_code)
    {
        this->IACO_code = IACO_code;
    }

    string toString()
    {
        return "Airports{airportID= " + airportID + ", airportName= " + airportName + ", city= " + City + ", country= " + Country + ", IACOCode= " + IACO_code + "}";
    }
};