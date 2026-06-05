#include "ElectionSystem.h"

ElectionSystem::ElectionSystem() : admin("admin", "1234") {
    candidateCount = 3;
    voterCount = 0;

    candidates[0] = Candidate("Amina");
    candidates[1] = Candidate("Zara");
    candidates[2] = Candidate("Irha");
}

void ElectionSystem::displayMenu() {
    cout << "WELCOME TO DIGITAL VOTING SYSTEM"<<endl;
    cout << "1. Register as Voter"<<endl;
    cout << "2. Vote"<<endl;
    cout << "3. Show Candidates"<<endl;
    cout << "4. Admin Panel (Results)"<<endl;
    cout << "5. Exit"<<endl;
    cout << "Enter your choice:";
}

void ElectionSystem::registerVoter() {
    if (voterCount >= MAX_VOTERS) {
        cout << "Maximum number of voters reached"<<endl;
        return;
    }

    string id, name;
    cout << "Enter Voter ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin >> name;

    for (int i = 0; i < voterCount; i++) {
        if (voters[i].getVoterID() == id) {
            cout << "Voter already registered"<<endl;
            return;
        }
    }

    voters[voterCount] = Voter(id, name);
    voterCount++;
    cout << "Voter registered successfully"<<endl;
}

void ElectionSystem::showCandidates() {
    cout << "Candidates:"<<endl;
    for (int i = 0; i < candidateCount; i++) {
        cout << i + 1 << ". " << candidates[i].getName() << endl;
    }
}

void ElectionSystem::vote() {
    string id;
    cout << "Enter your Voter ID: ";
    cin >> id;

    for (int i = 0; i < voterCount; i++) {
        if (voters[i].getVoterID() == id) {
            if (voters[i].getHasVoted()) {
                cout << "You have already voted"<<endl;
                return;
            }

            showCandidates();
            int choice;
            cout << "Enter candidate number: ";
            cin >> choice;

            if (choice < 1 || choice > candidateCount) {
                cout << "Invalid candidate choice"<<endl;
                return;
            }

            candidates[choice - 1].addVote();
            voters[i].setHasVoted(true);
            cout << "Vote casted successfully"<<endl;
            return;
        }
    }

    cout << "Voter not found. Please register first.\n";
}

void ElectionSystem::showResults() {
    cout << "Election Results"<<endl;
    for (int i = 0; i < candidateCount; i++) {
        cout << candidates[i].getName() << ": " << candidates[i].getVotes() << " votes"<<endl;
    }
}

void ElectionSystem::adminPanel() {
    string uname, pass;
    cout << "Enter admin username: ";
    cin >> uname;
    cout << "Enter admin password: ";
    cin >> pass;

    if (admin.login(uname, pass)) {
        showResults();
    } else {
        cout << "Access denied. Invalid credentials"<<endl;
    }
}

void ElectionSystem::start() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1: registerVoter();
			 break;
            case 2: vote();
			 break;
            case 3: showCandidates();
			 break;
            case 4: adminPanel();
			 break;
            case 5: cout << "Exiting"<<endl;
			 break;
            default: cout << "Invalid choice"<<endl;
			 break;
        }
    } while (choice != 5);
}
