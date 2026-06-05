#ifndef ELECTIONSYSTEM_H
#define ELECTIONSYSTEM_H

#include "Voter.h"
#include "Candidate.h"
#include "Admin.h"
#include <iostream>
using namespace std;

class ElectionSystem {
private:
    static const int MAX_VOTERS = 100;
    static const int MAX_CANDIDATES = 10;

    Voter voters[MAX_VOTERS];
    int voterCount;

    Candidate candidates[MAX_CANDIDATES];
    int candidateCount;

    Admin admin;

public:
    ElectionSystem();
    void displayMenu();
    void registerVoter();
    void showCandidates();
    void vote();
    void showResults();
    void adminPanel();
    void start();
};

#endif
