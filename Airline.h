#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Airlines {
private:
    int airline_id;
    string name;
    string alias;
    string iatacode;
    string icaocode;
    string callsign;
    string country;
    string active;

public:
    Airlines(int airline_id, string name, string  alias, string iatacode, string icaocode, string callsign, string country, string active);

    const int& getAirlineId()const;
    string& getAirlineName();
    string& getAlias();
    string& getIataCode();
    string& IcaoCode();
    string& getCallsign();
    string& getCountry();
    string& getActive();

};


int main()
{
    ifstream airlineFile;
    airlineFile.open("C:/Users/user/Desktop/C++ Project/airlines.csv");

    while (airlineFile.good()) {
        string line;
        getline(airlineFile, line, ',');
        cout << line << endl;
    }
    airlineFile.close();

}