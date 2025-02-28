//
// Created by Nadav Suliman on 10/1/20.
//

#include "Account.h"

///Constructors & Destructors--------------------------------------------------------------
Account::Account(const string& username, const string& password, const string& fname, const string& lname,
    const Address& address) : address(address), username(username), password(password), fname(fname),
    lname(lname) {
}

Account::~Account() {

}

Account::Account(ifstream& in): address(in) {
    in >> *this;
}

ifstream& operator>>(ifstream& in, Account& base) {
    if (typeid(in) == typeid(ifstream)) {               //checking if the input stream is file input stream
        char trash;
        //in.getline(&trash, 1);
        getline(in, base.username);
        getline(in, base.password);
        getline(in, base.fname);
        getline(in, base.lname);
        return in;
    }
}
///Operators----------------------------------------------------------------------
ostream& operator<<(ostream& os, Account& base) {
    if (typeid(os) == typeid(ofstream)) {                       //if the output stream is output file stream
        string TypeName = typeid(base).name();                  //writing the tye of the account
        os << TypeName <<endl<< base.address << endl << base.username << endl << base.password << endl      //writing the data
            << base.fname << endl << base.lname <<  endl;
        base.toOs(os);                                      //Calling relevant toOs function in children classes.
    }
    else {
        os << "Username: " << base.username << endl;            //Printing to console
        os << "Name: " << base.fname << " " << base.lname << endl;
        os << "Address: " << base.address << endl;
        base.toOs(os);
    }
    return os;
}

void Account::toOs(ostream &os) const {

}

///Getters and setters---------------------------------------------------------------------
const string& Account::getUsername() const {
    return username;
}

const string&Account::getPassword() const {
    return password;
}

const string& Account::getLName() const {
    return lname;
}

const string& Account::getFName() const {
    return fname;
}

const Address &Account::getAddress() const {
    return address;
}

bool Account::setFName(const string& new_fname) {
    if (new_fname.length() <= FNAME_MAX_LEN) {
        this->fname = new_fname;
        return true;
    }
    return false;
}

bool Account::setLName(const string& new_lname) {
    if (new_lname.length() <= LNAME_MAX_LEN) {
        this->lname = new_lname;
        return true;
    }
    return false;
}


bool Account::setUsername(const string& new_username) {
    if (new_username.length() <= USERNAME_MAX_LEN) {
        this->username = new_username;
        return true;
    }
    return false;
}

bool Account::setPassword(const string& new_password) {
    if (new_password.length() <= PASSWORD_MAX_LEN && new_password.length() >=PASSWORD_MIN_LEN) {
        this->password = new_password;
        return true;
    }
    return false;
}

void Account::setAddress(const Address &new_address) {
    address.setHomeNumber(new_address.getHomeNumber());
    address.setStreet(new_address.getStreet());
    address.setCity(new_address.getCity());
}
