#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <map>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;
const char CH = 178, SB = 219;
string choice;

class Design
{

public:
//	Display first line of header & footer (before text)
    void drawFirstLine(int x, int y)
    {

        for (int i = 0; i < x; i++)
        {
//        	usleep(): Suspends the execution of the program for a specified number of microseconds using unistd.h headerfile.
            usleep(10000);
            cout << SB;
        }
        for (int i = 0; i < y; i++)
        {
            usleep(10000);
            cout << CH;
        }
    }
    
    
//		Display 2nd line of header & footer (After text)
	void draw2ndLine(int x, int y)
    {

        for (int i = 0; i < y; i++)
        {
            usleep(10000);
            cout << CH;
        }
        for (int i = 0; i < x; i++)
        {
            usleep(10000);
            cout << SB;
        }
    }
    
//    Display Header bar
    void drawHeader(const string &header)
    {
        cout << endl;
        drawFirstLine(10, 40);
        cout << " Modern Electronic Voting Machine ";
        draw2ndLine(10, 40);
        cout << endl
             << endl;
        drawFirstLine(5, 10);
        cout << header;
        draw2ndLine(5, 10);
    }
    
    //Display footer bar
    void drawFooter(const string &footer)
    {
        cout << endl
             << endl;
        drawFirstLine(10, 35);
        cout << footer;
        draw2ndLine(10, 35);
    }

    // Display a loading bar
    void displayLoadingBar(const string &loading)
    {
        cout << endl
             << endl
             << endl
             << loading;
        cout << endl
             << endl
             << "                  ";
        for (int i = 0; i <= 80; i++)
        {
            usleep(150000);
            cout << SB;
        }
        cout << endl
             << endl;
    }
};

//class for display group information and front page of Applacation
class Group
{
public:
    Group()
   {   
//    for system color
        system("color A");
        
        // Display a loading screen
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n                                 System Starting Please Wait";
        for (int i = 0; i < 30; i++)
        {
            usleep(150000);
            cout << ".";
        }
        system("cls");
        // Clear the console and display the introduction screen
        
        Design obj;
        string header = "   Introduction   ";
        obj.drawHeader(header);
        cout << endl
             << endl
             << SB << CH << CH << " Submitted to:    <=>     Mr. Fayez Afzaal ";
        cout << endl
             << endl
             << SB << CH << CH << " created by "
             << "      <=>    "
             << " Registration No " << CH << CH << SB;
        cout << "\n_________________";
        cout << "\n\n"
             << SB << CH << " Mohsin Haider           =>  SP22-BCS-136" << endl;
        cout << "\n"
             << SB << CH << " Muhammad Shoaib         =>  SP22-BCS-109" << endl;
        cout << "\n"
             << SB << CH << " Kashif Shazad           =>  SP22-BCS-134" << endl;
        cout << "\n"
             << SB << CH << " Sajil Rana              =>  SP21-BBI-007" << endl;
        cout << "\n"
             << SB << CH << " Malaika Rehman          =>  SP21-BBI-011\n"
             << endl;
        string y = " COMSATS University Islamabad Sahiwal ";

        obj.drawFooter(y);

        string Loding = "                                              Loading Please wait..............";
        obj.displayLoadingBar(Loding);
    }
};

class Candidate
{
private:
    string name;
    string party;
    int votes;

public:
    Candidate(const string &candidateName, const string &candidateParty)
        : name(candidateName), party(candidateParty), votes(0) {}

    string getName() const
    {
        return name;
    }

    string getParty() const
    {
        return party;
    }

    int getVotes() const
    {
        return votes;
    }

    void incrementVotes()
    {
        votes++;
    }
};

class EVM
{
private:
    vector<Candidate> candidates;
    map<string, bool> voterRecords;
    string adminName;
    string adminPassword;

public:
    EVM()
    {
        candidates.push_back(Candidate("Imran khan     ", " =>    PTI "));
        candidates.push_back(Candidate("Maryam Nawaz   ", " =>    PMLN"));
        candidates.push_back(Candidate("Bilawal Bhutto ", " =>    PPP "));
        candidates.push_back(Candidate("Khalid Maqbool ", " =>    MQM "));
        candidates.push_back(Candidate("Saad Rizvi     ", " =>    TLP "));

        adminName = "admin";
        adminPassword = "admin123";
    }

    void displayCandidates() const
    {
        Design obj;
        string header = "  List of Candidates   ";
        obj.drawHeader(header);
        cout << endl
             << endl
             << SB << CH << CH << " Leader "
             << "     <=>    "
             << " Political Party " << CH << CH << SB;
        for (const Candidate &candidate : candidates)
        {
            cout << "\n\n"
                 << SB << CH << " " << candidate.getName() << "  " << candidate.getParty();
        }
        string y = " Thank You For using This menu ";
        obj.drawFooter(y);
        cout << "\n\n"
             << SB << CH << " Press Any key To Go Back ";
        cin >> choice;
        system("cls");
    }

    void displayWinner() const
    {
        int maxVotes = 0;
        string winnerName;

        for (const Candidate &candidate : candidates)
        {
            if (candidate.getVotes() > maxVotes)
            {
                maxVotes = candidate.getVotes();
                winnerName = candidate.getName();
            }
        }

        Design obj;
        string s = " Winner Candidate ";
        obj.drawHeader(s);

        cout << "\n\n"
             << SB << CH << SB << CH << " Winner: " << winnerName << " With => " << maxVotes << " Votes. ";

        string y = " Thank You For using This menu ";

        obj.drawFooter(y);
        cout << "\n\n"
             << SB << CH << " Press Any key To Go Back ";
        cin >> choice;
        system("cls");
    }

    void displayCandidatesWithVotes() const
    {
        Design obj;
        string header = " Candidates and Votes ";
        obj.drawHeader(header);
        cout << endl
             << endl
             << SB << CH << CH << " Leader "
             << "   <=>  "
             << " Political Party "
             << "  <=>  "
             << " Total Vote " << CH << CH << SB;
        for (const Candidate &candidate : candidates)
        {
            cout << "\n\n"
                 << SB << CH << " " << candidate.getName() << "      " << candidate.getParty() << "   -    " << candidate.getVotes() << " votes\n";
        }

        string y = " Thank You For using This menu ";
        obj.drawFooter(y);
        cout << "\n\n"
             << SB << CH << " Press Any key To Go Back ";
        cin >> choice;
        system("cls");
    }

    bool authenticateAdmin(const string &name, const string &password) const
    {
        return (name == adminName && password == adminPassword);
    }

    bool hasVoterVoted(const string &name, const string &idCardNumber) const
    {
        string voterKey = name + idCardNumber;
        return (voterRecords.find(voterKey) != voterRecords.end());
    }

    void castVote(const string &name, const string &idCardNumber)
    {
        if (hasVoterVoted(name, idCardNumber))
        {
            string y = " Your vote has already been cast ";
            Design obj;
            obj.drawFooter(y);
            cout << "\n\n"
                 << SB << CH << " Press Any key To Go Back ";
            cin >> choice;
            system("cls");
        }

        else
        {
            Design obj;
            string header = "    List of Candidates    ";
            obj.drawHeader(header);
            cout << endl
                 << endl
                 << SB << CH << CH << "  Leader "
                 << "      <=>    "
                 << " Political Party "
                 << CH << CH << SB;
            string voterKey = name + idCardNumber;
            voterRecords[voterKey] = true;
            for (int i = 0; i < candidates.size(); i++)
            {
                cout << "\n\n"
                     << SB << CH << " " << (i + 1) << "." << candidates[i].getName() << " From   " << candidates[i].getParty() << endl;
            }

            int choice;
            cout << "\n\n"
                 << SB << CH << " Enter the candidate number to cast your vote: ";
            cin >> choice;

            if (choice >= 1 && choice <= candidates.size())
            {
                candidates[choice - 1].incrementVotes();
                string y = " Your vote has been cast Sucessfully ";
                obj.drawFooter(y);
            }
            else
            {
                string y = " Invalid candidate number. ";
                obj.drawFooter(y);
                cout << "\n\n"
                     << SB << CH << " Press Any key To Go Back ";
                cin >> choice;
                system("cls");
            }
        }
        cout << "\n\n"
             << SB << CH << " Press Any key To Go Back ";
        cin >> choice;
        system("cls");
    }
};

int main()
{
    Group obj;
    system("cls");
    EVM evm;

    int userChoice;

    while (true)
    {
        Design obj;
        string s = " User Menu ";
        obj.drawHeader(s);
        cout << "\n\n"
             << SB << CH << " 1. Admin ";
        cout << "\n\n"
             << SB << CH << " 2. Voter ";
        cout << "\n\n"
             << SB << CH << " 3. Exit ";
        cout << "\n\n"
             << SB << CH << " Enter your choice: ";
        cin >> userChoice;
        system("cls");

        if (userChoice == 1)
        {
            string s = " logIn menu ";
            obj.drawHeader(s);
            string adminName, adminPassword;
            cout << "\n\n"
                 << SB << CH << " Enter admin name: ";
            cin >> adminName;
            cout << "\n\n"
                 << SB << CH << " Enter admin password: ";
            cin >> adminPassword;
//            system("cls");

            if (evm.authenticateAdmin(adminName, adminPassword))
            {   obj.drawFooter(" login sucessful ");
                sleep(1);
                system("cls");
                int adminChoice;
                while (true)
                {
                    string s = " Admin Menu ";
                    obj.drawHeader(s);
                    cout << "\n\n"
                         << SB << CH << " 1. List of Candidates";
                    cout << "\n\n"
                         << SB << CH << " 2. Display Winner";
                    cout << "\n\n"
                         << SB << CH << " 3. Candidates and Votes";
                    cout << "\n\n"
                         << SB << CH << " 4. Go back to User Menu";
                    cout << "\n\n"
                         << SB << CH << " Enter your choice: ";
                    cin >> adminChoice;
                    system("cls");

                    switch (adminChoice)
                    {
                    case 1:
                        evm.displayCandidates();
                        break;
                    case 2:
                        evm.displayWinner();
                        break;
                    case 3:
                        evm.displayCandidatesWithVotes();
                        break;
                    case 4:
                        break;
                    default:
                        string s = " check validation ";
                        obj.drawHeader(s);
                        string y = " Invalid choice. Try again. ";
                        obj.drawFooter(y);
                        cout << "\n\n"
                             << SB << CH << " Press Any key To Go Back ";
                        cin >> choice;
                        system("cls");

                        break;
                    }

                    if (adminChoice == 4)
                    {
                        break;
                    }
                }
            }
            else
            {
                string s = " check validation ";
                obj.drawHeader(s);
                cout << "\n\n"
                     << SB << SB << CH << CH << "Invalid admin credentials.\n\n";
                string y = " Thanks For using This menu ";
                obj.drawFooter(y);
                cout << "\n\n"
                     << SB << CH << " Press Any key To Go Back ";
                cin >> choice;
                system("cls");
            }
        }
        else if (userChoice == 2)
        {
            string s = " voter Login ";
            obj.drawHeader(s);
            string voterName, voterId;
            cout << "\n\n"
                 << SB << CH << " Enter your name: ";
            cin >> voterName;
            cout << "\n\n"
                 << SB << CH << " Enter your ID card number: ";
            cin >> voterId;
            system("cls");

            evm.castVote(voterName, voterId);
        }
        else if (userChoice == 3)
        {
            string s = " Feedback ";
            obj.drawHeader(s);
            cout << "\n\n"
                 << SB << CH << " Please Give a Feedback  ";
            cin >> choice;
            cout << endl
                 << endl
                 << endl;
            string y = " Thanks For Feedback and using  Our Applacation ";
            obj.drawFooter(y);
            exit(0);
        }

        else
        {
            string s = " check validation ";
            obj.drawHeader(s);
            cout << "\n\n"
                 << SB << SB << CH << CH << " Invalid choice. Try again.";
            string y = "  Thanks For using This menu ";
            obj.drawFooter(y);
            cout << "\n\n"
                 << SB << CH << " Press Any key To Go Back ";
            cin >> choice;
            system("cls");
        }
    }

    return 0;
}