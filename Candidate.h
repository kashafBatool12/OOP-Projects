#ifndef CANDIDATE_H
#define CANDIDATE_H

#include <string>
using namespace std;

class Candidate {
private:
    string name;
    int votes;

public:
    Candidate();
    Candidate(string name);
    string getName() const;
    void addVote();
    int getVotes() const;
};

#endif
