#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>

using namespace std;

struct Thesis
{
    string thesisID;
    string studentName;
    string title;
    string adviserName;
    string status;
    string comments;
};
vector<Thesis> theses;
int nextThesisNumber = 1;

string generateThesisID()
{
    ostringstream ss;
    ss << "TH-" << setfill('0') << setw(3) << nextThesisNumber++;
    return ss.str();
}

// first commit features.
void submitProposal();
void viewProposal();

//2nd commit 
void checkStatus();

//1st commit - gila
void reviewTheses();
//2nd commit - gila
void approveThesis();
//3rd commit - gila
void rejectThesis();
//4th commit - gila
void addComment();

//1st commit - valencia
void viewAcceptedTheses();
void viewRejectedTheses();
//2nd commit - valencia
void searchThesis();
void sortByTitle();
//3rd commit - valencia
void displayStatistics();

void studentMenu()
{
    int choice;

    do
    {
        cout << "\n\n STUDENT MENU ";
        cout << "\n1. Submit Proposal";
        cout << "\n2. View Proposal";
        cout << "\n3. Edit Proposal";
        cout << "\n4. Delete Proposal";
        cout << "\n5. Submit Revision";
        cout << "\n6. Check Status";
        cout << "\n7. Back";

        cout << "\nChoice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: submitProposal(); 
            break;
            case 2: viewProposal();
            break;
            case 3: editProposal();
            break;
            //just add more cases here
            case 6: checkStatus();
            break;

        }

    } while(choice != 7);
    
}

void submitProposal()
{
    Thesis t;

    t.thesisID = generateThesisID();

    cin.ignore();  

    cout << "\nStudent Name: ";
    getline(cin, t.studentName);

    cout << "Thesis Title: ";
    getline(cin, t.title);

    cout << "Adviser Name: ";
    getline(cin, t.adviserName);

    t.status = "Pending";
    t.comments = "No comments yet";

    theses.push_back(t);
    cout << "\nYour Thesis ID is: " << t.thesisID << "\n";
    cout << "\nProposal submitted successfully!";
}

void viewProposal()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(const auto& t : theses)
    {
        if(t.thesisID == id)
        {
            cout << "\n--------------------------";
            cout << "\nThesis ID: " << t.thesisID;
            cout << "\nStudent: " << t.studentName;
            cout << "\nTitle: " << t.title;
            cout << "\nAdviser: " << t.adviserName;
            cout << "\nStatus: " << t.status;
            cout << "\nComments: " << t.comments;
            cout << "\n--------------------------\n";

            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

void checkStatus()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(const auto& t : theses)
    {
        if(t.thesisID == id)
        {
            cout << "\nCurrent Status: " << t.status << endl;
            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

// MEMBER 2 (Maintenance Module)

// 1st commit
void editProposal()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    cin.ignore();

    bool found = false;

    for(auto& t : theses)
    {
        if(t.thesisID == id)
        {
            cout << "\nEnter New Thesis Title: ";
            getline(cin, t.title);

            cout << "\nUpdated Successfully!\n";
            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

//2nd commit - gila
void approveThesis()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(auto& t : theses)
    {
        if(t.thesisID == id)
        {
            t.status = "Approved";

            cout << "\nThesis Approved!\n";
            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

//3rd commit - gila
void rejectThesis()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(auto& t : theses)
    {
        if(t.thesisID == id)
        {
            t.status = "Rejected";

            cout << "\nThesis Rejected!\n";
            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

//4th commit - gila
void addComment()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    cin.ignore();

    bool found = false;

    for(auto& t : theses)
    {
        if(t.thesisID == id)
        {
            cout << "Enter Adviser Comment: ";
            getline(cin, t.comments);

            cout << "\nComment Added!\n";
            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

//1st commit - valencia
void viewAcceptedTheses()
{
    cout << "\n===== ACCEPTED THESES =====\n";

    bool found = false;

    for(const auto& t : theses)
    {
        if(t.status == "Approved")
        {
            cout << "\nID: " << t.thesisID;
            cout << "\nTitle: " << t.title;
            cout << "\nStudent: " << t.studentName;
            cout << "\n---------------------";

            found = true;
        }
    }

    if(!found)
        cout << "\nNo accepted theses.\n";
}

void viewRejectedTheses()
{
    cout << "\n===== REJECTED THESES =====\n";

    bool found = false;

    for(const auto& t : theses)
    {
        if(t.status == "Rejected")
        {
            cout << "\nID: " << t.thesisID;
            cout << "\nTitle: " << t.title;
            cout << "\nStudent: " << t.studentName;
            cout << "\n---------------------";

            found = true;
        }
    }

    if(!found)
        cout << "\nNo rejected theses.\n";
}

//2nd commit - valencia
void searchThesis()
{
    cin.ignore();

    string keyword;

    cout << "\nEnter Keyword: ";
    getline(cin, keyword);

    bool found = false;

    for(const auto& t : theses)
    {
        if(t.title.find(keyword) != string::npos)
        {
            cout << "\nFound Thesis:";
            cout << "\nID: " << t.thesisID;
            cout << "\nTitle: " << t.title;
            cout << "\nStudent: " << t.studentName;

            found = true;
        }
    }

    if(!found)
        cout << "\nNo matching thesis found.\n";
}

void sortByTitle()
{
    sort(theses.begin(), theses.end(),
        [](const Thesis& a, const Thesis& b)
        {
            return a.title < b.title;
        });

    cout << "\nSuccessfully Sorted By Title.\n";
}

//3rd commit - valencia
void displayStatistics()
{
    int approved = 0;
    int rejected = 0;
    int pending = 0;

    for(const auto& t : theses)
    {
        if(t.status == "Approved")
            approved++;
        else if(t.status == "Rejected")
            rejected++;
        else
            pending++;
    }

    cout << "\n===== STATISTICS =====";
    cout << "\nApproved : " << approved;
    cout << "\nRejected : " << rejected;
    cout << "\nPending  : " << pending;
    cout << "\nTotal    : " << theses.size() << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n   THESIS MANAGEMENT SYSTEM";
        cout << "\n1. Student";
        cout << "\n2. Adviser";
        cout << "\n3. Thesis Repository";
        cout << "\n4. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                studentMenu();
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                cout << "\nThank you for using the system.\n";
                break;

            default:
                cout << "\nInvalid choice.\n";
        }

    } while(choice != 4);

    return 0;
}

