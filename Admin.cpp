#include "Admin.h"

Admin::Admin(string uname, string pass) {
    username = uname;
    password = pass;
}

bool Admin::login(string uname, string pass) {
    return (uname == username && pass == password);
}
