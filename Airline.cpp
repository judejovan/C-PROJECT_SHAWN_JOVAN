#include <iostream>
#include <string>
using namespace std;

class Airlines
{
protected:
    string airlineID;
    string airlineName;
    string IATA_code;
    string IACO_code;
    string Country;


public:
    string getAirlineID()
    {
        return airlineID;
    }

    void setAirlineID(string airlineID)
    {
        this->airlineID = airlineID;
    }

    string getAirlineName()
    {
        return airlineName;
    }

    void setAirlineName(string airlineName)
    {
        this->airlineName = airlineName;
    }

    string getIATA_code()
    {
        return IATA_code;
    }

    void setIATA_code(string IATA_code)
    {
        this->IATA_code = IATA_code;
    }

    string getIACO_code()
    {
        return IACO_code;
    }

    void setIACO_code(string IACO_code)
    {
        this->IACO_code = IACO_code;
    }

    string getCountry()
    {
        return Country;
    }

    void setCountry(string Country)
    {
        this->Country = Country;
    }
};