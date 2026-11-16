#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <sstream>
#include <cstdlib>

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

int readInt(const string& prompt)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        if (cin.eof()) exit(0);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number.\n";
    }
}

string readLine(const string& prompt)
{
    string text;
    while (true)
    {
        cout << prompt;
        getline(cin, text);
        if (!text.empty()) return text;
        cout << "This field cannot be empty.\n";
    }
}
Thesis* findThesis(const string& id)
{
    for (auto& t : theses)
        if (t.thesisID == id)
            return &t;
    return nullptr;
}
// first commit features.
void submitProposal();
void viewProposal();

//2nd commit
void checkStatus();

// Ibana (Maintenance Module)
void editProposal(); // 1st commit
void deleteProposal(); // 2nd commit
void submitRevision(); // 3rd commit

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
        cout << "\n7. Back\n";

        choice = readInt("Choice: ");

        switch (choice)
        {
            case 1: submitProposal(); break;
            case 2: viewProposal();   break;
            case 3: editProposal();   break;
            case 4: deleteProposal(); break;
            case 5: submitRevision(); break;
            case 6: checkStatus();    break;
            case 7: break;
            default: cout << "\nInvalid or not yet available.\n";
        }
    } while (choice != 7);
}

void adviserMenu()
{
    int choice;

    do
    {
        cout << "\n\n===== ADVISER MENU =====";
        cout << "\n1. Review Theses";
        cout << "\n2. Approve Thesis";
        cout << "\n3. Reject Thesis";
        cout << "\n4. Add Comment";
        cout << "\n5. Back\n";

        choice = readInt("Choice: ");

        switch (choice)
        {
            case 1: reviewTheses();  break;
            case 2: approveThesis(); break;
            case 3: rejectThesis();  break;
            case 4: addComment();    break;
            case 5: break;
            default: cout << "\nInvalid choice.\n";
        }
    } while (choice != 5);
}

void submitProposal()
{
    Thesis t;

    t.studentName = readLine("\nStudent Name: ");
    t.title       = readLine("Thesis Title: ");
    t.adviserName = readLine("Adviser Name: ");

    t.thesisID = generateThesisID();   // generate only after input succeeds
    t.status   = "Pending";
    t.comments = "No comments yet";

    theses.push_back(t);
    cout << "\nYour Thesis ID is: " << t.thesisID << "\n";
    cout << "\nProposal submitted successfully!\n";
}

void viewProposal()
{
    string id = readLine("\nEnter Thesis ID: ");

    if (Thesis* t = findThesis(id))
    {
        cout << "\n--------------------------";
        cout << "\nThesis ID: " << t->thesisID;
        cout << "\nStudent: "   << t->studentName;
        cout << "\nTitle: "     << t->title;
        cout << "\nAdviser: "   << t->adviserName;
        cout << "\nStatus: "    << t->status;
        cout << "\nComments: "  << t->comments;
        cout << "\n--------------------------\n";
    }
    else
        cout << "\nThesis not found.\n";
}

void checkStatus()
{
    string id = readLine("\nEnter Thesis ID: ");

    if (Thesis* t = findThesis(id))
        cout << "\nCurrent Status: " << t->status << endl;
    else
        cout << "\nThesis not found.\n";
}

// 1st commit - Ibana
void editProposal()
{
    string id = readLine("\nEnter Thesis ID: ");

    if (Thesis* t = findThesis(id))
    {
        t->title = readLine("\nEnter New Thesis Title: ");
        cout << "\nUpdated Successfully!\n";
    }
    else
        cout << "\nThesis not found.\n";
}

// 2nd commit - Ibana
void deleteProposal()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(int i = 0; i < theses.size(); i++)
    {
        if(theses[i].thesisID == id)
        {
            theses.erase(theses.begin() + i);

            found = true;
            cout << "\nProposal deleted successfully!\n";
            break;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

// 3rd commit - Ibana
void submitRevision()
{
    string id;

    cout << "\nEnter Thesis ID: ";
    cin >> id;

    bool found = false;

    for(auto& t : theses)
    {
        if(t.thesisID == id)
        {
            t.status = "Pending";

            cout << "\nRevision submitted successfully.\n";
            found = true;
        }
    }

    if(!found)
        cout << "\nThesis not found.\n";
}

//4th commit - gila
void addComment()
//1st commit - gila
void reviewTheses()
{
    if (theses.empty())
    {
        cout << "\nNo thesis records available.\n";
        return;
    }

    cout << "\n===== THESIS LIST =====\n";

    for (const auto& t : theses)
    {
        cout << "\nID: "      << t.thesisID;
        cout << "\nStudent: " << t.studentName;
        cout << "\nTitle: "   << t.title;
        cout << "\nStatus: "  << t.status;
        cout << "\n----------------------\n";
    }
}

//2nd commit - gila
void approveThesis()
{
    string id = readLine("\nEnter Thesis ID: ");

    if (Thesis* t = findThesis(id))
    {
        t->status = "Approved";
        cout << "\nThesis Approved!\n";
    }
    else
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
    string id = readLine("\nEnter Thesis ID: ");

    if (Thesis* t = findThesis(id))
    {
        t->status = "Rejected";
        cout << "\nThesis Rejected!\n";
    }
    else
        cout << "\nThesis not found.\n";
}

//4th commit - gila
void addComment()
{
    string id = readLine("\nEnter Thesis ID: ");

    if (Thesis* t = findThesis(id))
    {
        t->comments = readLine("Enter Adviser Comment: ");
        cout << "\nComment Added!\n";
    }
    else
        cout << "\nThesis not found.\n";
}


///lagay lang ako dito for remember