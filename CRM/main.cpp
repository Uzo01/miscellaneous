#include <iostream>
#include <string>
#include <vector>

using namespace std;

// User class
class User {
public:
    string name, password;

    // Constructor
    User(string userName, string userPassword) {
        name = userName;
        password = userPassword;
    }

    // Login method
    bool login(string inputName, string inputPass) {
        return inputName == name && inputPass == password;
    }

    // Display method (for future use)
    void displayInfo() {
        cout << "Name: " << name << endl;
    }
};

int main() {
    vector<User> users;
    int choice;
    bool running = true;

    while (running) {
        cout << "\n===== CRM MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        // REGISTER
        if (choice == 1) {
            string newName, newPass;

            cout << "Enter your username: ";
            cin >> newName;

            cout << "Enter your password: ";
            cin >> newPass;

            User newUser(newName, newPass);
            users.push_back(newUser);

            cout << "✅ Registration successful!\n";
        }

        // LOGIN
        else if (choice == 2) {
            if (users.empty()) {
                cout << "⚠️ No users registered yet. Please register first.\n";
                continue;
            }

            string loginName, loginPass;
            cout << "Username: ";
            cin >> loginName;

            cout << "Password: ";
            cin >> loginPass;

            bool found = false;

            for (User u : users) {
                if (u.login(loginName, loginPass)) {
                    cout << "✅ Login successful. Welcome back, " << loginName << "!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "❌ Login failed. Invalid username or password.\n";
            }
        }

        // EXIT
        else if (choice == 3) {
            running = false;
            cout << "👋 Goodbye!\n";
        }

        // INVALID INPUT
        else {
            cout << "❗ Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
