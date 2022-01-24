#include "Account.h"
/*
  Rights index:
  0 - Add Hatchback
  1 - Add Limousine
  2 - Add Sport Vehicle
  3 - Show Details
  4 - Add Engine Package
  5 - Delete Vehicle
  6 - Load Database
  7 - Save to Database
*/
Account::Account() {
    apRights = nullptr;
    aRightsNumber = 0;
}

Account::Account(unsigned int amount)
{
  if(amount < 8)
      throw MyException("warning",
                        "Not Enough Rights",
                        "Account.cpp",
                        "Account",
                        "17");
  aRightsNumber = amount;
  apRights = new bool [aRightsNumber];
  for(int i = 0; i < aRightsNumber; ++i)
    apRights[i] = 0;
}

Account::~Account() {
  if(apRights != nullptr)
    delete [] apRights;
}

bool* Account::getAllRight() {
    return apRights;
}

bool Account::getRightOnPosition(unsigned int position) {
    if(position > (this->aRightsNumber - 1))
        throw MyException("warning",
                          "There is no such right",
                          "Account.cpp",
                          "getRightOnPosition",
                          "38");
    else
        return apRights[position];
}

void Account::setRightOnPosition(unsigned int position, bool value) {
    if(position > (this->aRightsNumber - 1))
        throw MyException("warning",
                          "There is no such right",
                          "Account.cpp",
                          "setRightOnPosition",
                          "38");
    else
        apRights[position] = value;
}

void Account::setAdmin() {
    aRightsNumber = 8;
    apRights = new bool [aRightsNumber];
    for(int i = 0; i < aRightsNumber; ++i)
      apRights[i] = 1;
    aUsername = "admin";
    aPassword = "admin";
}

void Account::setNormalUser() {
    aRightsNumber = 8;
    apRights = new bool [aRightsNumber];
    for(int i = 0; i < aRightsNumber; ++i)
      apRights[i] = 1;
    apRights[5] = 0;
    aUsername = "user";
    aPassword = "user";
}

Account::Account(Account &obj) {
    aRightsNumber = obj.aRightsNumber;
    apRights = obj.apRights;
    aUsername = obj.aUsername;
    aUsername = obj.aPassword;
}
