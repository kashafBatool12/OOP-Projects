#ifndef ADMIN_H
#define ADMIN_H

#include <string>
using namespace std;

class Admin {
private:
    string username;
    string password;

public:
    Admin(string uname, string pass);
    bool login(string uname, string pass);
};

#endif
