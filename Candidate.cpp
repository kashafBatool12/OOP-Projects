#include "Candidate.h"

Candidate::Candidate() {
    name = "";
    votes = 0;
}

Candidate::Candidate(string name) {
    name = name;
    votes = 0;
}

string Candidate::getName() const {
    return name;
}

void Candidate::addVote() {
    votes++;
}

int Candidate::getVotes() const {
    return votes;
}
