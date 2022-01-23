#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "MyException.h"

class Account
{
public:
    Account();
    Account(unsigned int amount);
    ~Account();
    bool getAllRight();
    bool getRightOnPosition(unsigned int position);
    void setRightOnPosition(unsigned int position, bool value);
    void setAdmin();
    void setNormalUser();
    std::string getUsername();
    void setUsername(std::string username);
    std::string getPassword();
    void setPassword(std::string password);
    Account(Account &obj);

private:
    unsigned int aRightsNumber = 0;
    bool *apRights;
    std::string aUsername;
    std::string aPassword;
};

#endif // ACCOUNT_H
