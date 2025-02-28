//
// Created by Nadav Suliman on 24/11/19.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Address.h"
using namespace std;

///Constructors------------------------------------------------------------------------------------
Address::Address(const string&  city, const string&  street, int home_number) : city(city), street(street), home_number(home_number) {

}

//Constructor from file input.
Address::Address(ifstream& in) {
    in >> *this;
}

//Operator << for printing and writing to file.
ostream& operator<<(ostream& os, const Address& address) {
    os << address.street << endl << address.home_number << endl << address.city;
    return os;
}

//Operator >> for reading from a file.
ifstream& operator>>(ifstream& in, Address& address) {
    if (typeid(in) == typeid(ifstream)) {
        char trash;
        getline(in, address.street);
        in >> address.home_number;
        in.getline(&trash, 1);
        getline(in, address.city);
        return in;
    }
}


///Setters and Getters----------------------------------------------------------------------------
bool Address::setCity(const string& city) {
    if(city.length() <= CITY_NAME_LEN) {
        this->city = city;
        return true;
    }
        return false;
}

bool Address::setStreet(const string& street) {
    if(street.length() <= STREET_NAME_LEN){
        this->street = street;
        return true;
    }
    return false;
}

bool Address::setHomeNumber(int home_number) {
    if(home_number > 0) {
        this->home_number = home_number;
        return true;
    }
    return false;
}

const string& Address::getCity() const{
    return city;
}

const string& Address::getStreet() const{
    return street;
}

int Address::getHomeNumber() const{
    return home_number;
}