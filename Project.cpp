#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class LogIn { // To get admin access | username: Admin | password: admin123
private:
    string userName;
    string password;
    bool isAdmin;

public:
    // Constructor
    LogIn() : userName(""), password(""), isAdmin(false) {}

    // Getters
    string getUserName() {
        return userName;
    }
    
    string getPassword() {
        return password;
    }
    
    bool getIsAdmin() {
        return isAdmin;
    }

    void logIn() {
        cout << "----------[Log in]----------\n";
        cout << "Username: ";
        cin >> userName;

        if (userName == "Admin") {
            string inputPassword;
            bool temp = false;

            while (!temp) {
                cout << "Password: ";
                cin >> inputPassword;

                if (inputPassword == "admin123") {
                    isAdmin = true;
                    temp = true;
                    cout << "Login successful! You are now logged in as Admin.\n";
                } else {
                    cout << "\nIncorrect password. Try again.\n";
                }
            }
        } else {
            cout << "Welcome " << userName << endl;
        }
    }
};

class ScreenMenu {
public:
    void mainMenuAdmin() {
        cout << "==========[Admin Menu]==========\n";
        cout << "[1 - Add event]\n[2 - Display events]\n[3 - Edit event]\n[4 - Delete event]\n[5 - Sort]\n[6 - Events to confirm]\n[7 - Log out]\n[8 - Close program]\n";
    }

    void mainMenuUser() {
        cout << "==========[User Menu]==========\n";
        cout << "[1 - View events]\n[2 - Search events]\n";
    }
};

//=================================================================// Data

struct Event {
    string name;
    string month;
    int day;
    int year;
    string eventName;

    Event(string n, string m, int d, int y, string evName)
        : name(n), month(m), day(d), year(y), eventName(evName) {}
};

// Singleton class to manage events
class EventManager {
private:
    static EventManager* instance;
    vector<Event> events;

    EventManager() {
		events.emplace_back("Nathan", "Feb", 12, 2005, "Birthday Celebration");	
	}

public:
    EventManager(const EventManager&) = delete;
    EventManager& operator=(const EventManager&) = delete;

    static EventManager& getInstance() {
        if (!instance) {
            instance = new EventManager();
        }
        return *instance;
    }

    void addEvent(const Event& event) {
        events.push_back(event);
    }

    // Display all events
    void displayEvents() const {
    	cout << setw(20) << left << "Name" << setw(20) << left << "Month" << setw(10) << left << "Day" << setw(10) << left << "Year" << setw(10) << left << "Event" << endl;
    	
        for (const auto& event : events) {
			cout << setw(20) << left << event.name << setw(10) << left << event.month << setw(10) << left << event.day << setw(10) << left << event.year << setw(10) << left << event.eventName << endl;
        }
    cout << endl << endl;
    system("pause");
    system("cls");
	}
    
};

// Initialize static member
EventManager* EventManager::instance = nullptr;

//=================================================================// Main

int main() {
    LogIn login; // Create an instance of LogIn
    ScreenMenu SM;
    
    login.logIn(); // Call the logIn method
    
    
    
    int option; // Menu option
    
    if (login.getIsAdmin()) {
        bool tempo = false;
        while (!tempo) {
            SM.mainMenuAdmin();
            cout << "\nChoose an option: ";
            cin >> option;

            switch (option) {
            case 1: {
            	// Add event						[Validation]
                string name, month, eventName;
                int day, year;
                cout << "Enter name: ";
                cin.ignore(10000, '\n');
				getline(cin,name);
                
				cout << "Enter month: ";
                cin >> month;
                cout << "Enter day: ";
                cin >> day;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter event name: ";
                cin.ignore(10000, '\n');
				getline(cin, eventName);

                Event newEvent(name, month, day, year, eventName);
                EventManager::getInstance().addEvent(newEvent);
                cout << "Event added successfully.\n";
                break;
            }
            case 2: {
                // Display Events					[Done]
                EventManager::getInstance().displayEvents();
                
                break;
            }
            case 3: {
            	//Edit Event						[Missing]
				break;
			}
			case 4: {
				//Delete Event						[Missing]
				break;
			}
			case 5: {
				//Sort								[Missing]
				break;
			}
			case 6: {
				//Events to Confirm					[Missing]
				break;
			}
			case 7: {
				//Log out							[Missing]
				break;
			}
			case 8: {
				//Close Program						[Missing]
				break;
			}
			
            default:
                cout << "Invalid input\n";
                break;
            }
        }
    } else {
        SM.mainMenuUser();//Still empty (Missing all user prompts || PLease follow flow chart on process)
    }

    return 0;
}
