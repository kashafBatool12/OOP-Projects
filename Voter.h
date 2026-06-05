#ifndef VOTER_H
#define VOTER_H

#include <string>
using namespace std;

class Voter {
private:
    string voterID;
    string name;
    bool hasVoted;

public:
    Voter();
    Voter(string id, string name);
    string getVoterID() const;
    string getName() const;
    bool getHasVoted() const;
    void setHasVoted(bool status);
};

#endif
