#include "Account.h"

/**
  * Rights index:
  * 0 - Add Hatchback
  * 1 - Add Limousine
  * 2 - Add Sport Vehicle
  * 3 - Show Details
  * 4 - Add Engine Package
  * 5 - Delete Vehicle
  * 6 - Load Database
  * 7 - Save to Database
*/

/**
 * constructor - create Account with default value
 */
Account::Account() {
  apRights = nullptr;
  aRightsNumber = 0;
}

/**
 * constructor - create Account with default value
 * @param amount - amount of rights to be assigned
 */
Account::Account(unsigned int amount) {
  if (amount < 8)
	throw MyException("warning",
					  "Not Enough Rights",
					  "Account.cpp",
					  "Account",
					  "17");
  aRightsNumber = amount;
  apRights = new bool[aRightsNumber];
  for (int i = 0; i < aRightsNumber; ++i)
	apRights[i] = false;
}

/**
  * @brief destructor - deletes dynamic array of rights
  */
Account::~Account() {
  if (apRights != nullptr)
	delete[] apRights;
}

/**
  * @brief returns a pointer with rights array
  */
bool *Account::getAllRight() {
  return apRights;
}

/**
  * @param position - position of rights in array
  * @return a boolean value of right at a given position in rights array
*/
bool Account::getRightOnPosition(unsigned int position) {
  if (position > (this->aRightsNumber - 1))
	throw MyException("warning",
					  "There is no such right",
					  "Account.cpp",
					  "getRightOnPosition",
					  "38");
  else
	return apRights[position];
}

/**
  * @brief sets a boolean value of right at a given position in rights array
  * @param position - position of rights in array
  * @param value - boolean value to be set
*/
void Account::setRightOnPosition(unsigned int position, bool value) {
  if (position > (this->aRightsNumber - 1))
	throw MyException("warning",
					  "There is no such right",
					  "Account.cpp",
					  "setRightOnPosition",
					  "38");
  else
	apRights[position] = value;
}

/**
  * @brief sets an administrator rights (all rights are set to true)
*/
void Account::setAdmin() {
  aRightsNumber = 8;
  apRights = new bool[aRightsNumber];
  for (int i = 0; i < aRightsNumber; ++i)
	apRights[i] = true;
  aUsername = "admin";
  aPassword = "admin";
}

/**
  * @brief sets a normal user rights (all rights are set to true except for the 5)
*/
void Account::setNormalUser() {
  aRightsNumber = 8;
  apRights = new bool[aRightsNumber];
  for (int i = 0; i < aRightsNumber; ++i)
	apRights[i] = true;
  apRights[5] = false;
  aUsername = "user";
  aPassword = "user";
}

/**
  * @brief copy constructor
*/
Account::Account(Account &obj) {
  aRightsNumber = obj.aRightsNumber;
  apRights = obj.apRights;
  aUsername = obj.aUsername;
  aUsername = obj.aPassword;
}
