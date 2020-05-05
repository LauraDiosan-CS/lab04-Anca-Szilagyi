#pragma once
#include<string>
#include "User.h"
#include<vector>
using namespace std;
class LoginManager {

public:
	string username;
	string password;
	vector<User> users;
	LoginManager();
	~LoginManager() {};
	bool login(string, string);
};
LoginManager::LoginManager() {

	username = "\0";
	password = "\0";
	User u1("Ana", "123");
	User u2("Sorina", "1234");
	users.push_back(u1);
	users.push_back(u2);
}
bool LoginManager::login(string username, string password) {


	for (User x : users) {

		string ch_username = x.getUsername();
		string ch_password = x.getPassword();

		if (username.compare(ch_username) == 0 && password.compare(ch_password) == 0) {

			cout << "Bine ai venit," << " " << username << "!\n";
			return true;

		}
		else {
			cout << "Autentificare esuata. Incercati din nou.\n" << "\n";
			return false;
		}
	}

	return true;

}