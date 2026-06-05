#include "Voter.h"

Voter::Voter() {
    voterID ;
    name ;
    hasVoted = false;
}

Voter::Voter(string id, string name) {
    voterID = id;
    name = name;
    hasVoted = false;
}

string Voter::getVoterID() const {
    return voterID;
}

string Voter::getName() const {
    return name;
}

bool Voter::getHasVoted() const {
    return hasVoted;
}

void Voter::setHasVoted(bool status) {
    hasVoted = status;
}
