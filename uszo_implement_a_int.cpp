#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Data model for chatbot monitor
class User {
public:
    string username;
    string message;
};

class ChatbotMonitor {
private:
    map<string, vector<User>> conversations;
public:
    void recordMessage(string username, string message) {
        conversations[username].push_back(User{username, message});
    }

    void displayConversation(string username) {
        if (conversations.find(username) != conversations.end()) {
            for (const User& user : conversations[username]) {
                cout << user.username << ": " << user.message << endl;
            }
        } else {
            cout << "No conversation found for " << username << endl;
        }
    }
};

int main() {
    ChatbotMonitor monitor;

    while (true) {
        string username, message;
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter message: ";
        getline(cin, message);

        monitor.recordMessage(username, message);

        cout << "Display conversation for " << username << "? (y/n): ";
        char response;
        cin >> response;
        if (response == 'y') {
            monitor.displayConversation(username);
        }
    }

    return 0;
}