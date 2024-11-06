#include <iostream>
#include <string>
using namespace std;

class LogIn{
	private:
		string username;
		string password;
		
		//For admin access | Password is admin123 | login is admin | 
		
	public:
	
	void userLogin(){
		cout << "[]-------[Event Management System]-------[]\n";
		cout << "Enter user name: ";
		getline(cin,username);
		cin.ignore();
		
		cout << "Enter password: ";
		getline(cin,password);
		cin.ignore();
	}
		
		string getUsername() {	//Getters
			return username;
		}
		
		string getPassword() {
			return password;
		}
	
};

class MainMenu : public LogIn{
	private:
		LogIn login;		// Call functions in LogIn class
	public:
		//Admin
		
		
		void adminOptions(){
			cout << "[]-------[Event Management System]-------[]\n";
			cout << "1 - Create an event \n2 - List of Events \n3 - View Sort \n4 - Delte event \n5 - Edit Event \n6 - Log out";
		}
		
		void userOptions(){
			cout << "[]-------[Event Management System]-------[]\n";
			cout << "User options\n";
		}
		void displayMenu(){
		string username, password;
			
		login.userLogin();
		username = login.getUsername();
		password = login.getPassword();
		
		if (username == "admin" && password == "admin123"){
			cout << "Admin Menu\n";
			adminOptions();
		}
		else{
			cout << "Welcome user " << username << endl;
			userOptions();
		}
		
		}

};




int main(){
	MainMenu menu;
	
	menu.displayMenu();
}