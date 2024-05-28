#include <iostream>
#include <string>

using namespace std;

struct User {
    string username;
    string password;
    string role; // bisa berupa "admin" atau "user"
    User* next; // pointer to the next user in case of a collision
};

const int MAX_SIZE = 100;
User* users[MAX_SIZE] = {nullptr}; // initialize array of pointers to nullptr

int hashFunction(const string& str) {
    int hash = 0;
    for (char c : str) {
        hash += c;
    }
    return hash % MAX_SIZE;
}

void addUser(const User& user) {
    int index = hashFunction(user.username);
    User* newUser = new User{user.username, user.password, user.role, nullptr};

    if (users[index] == nullptr) {
        users[index] = newUser;
    } else {
        User* current = users[index];
        while (current->next != nullptr) {
            if (current->username == user.username) {
                delete newUser; // clean up the allocated memory
                return; // user already exists, do nothing
            }
            current = current->next;
        }
        if (current->username == user.username) {
            delete newUser; // clean up the allocated memory
            return; // user already exists, do nothing
        }
        current->next = newUser;
    }
}

bool checkLogin(const string& username, const string& password) {
    int index = hashFunction(username);
    User* current = users[index];
    while (current != nullptr) {
        if (current->username == username && current->password == password) {
            return true;
        }
        current = current->next;
    }
    return false;
}