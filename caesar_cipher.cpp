#include<iostream>
using namespace std;

string caesarCipherEncrypt(string msg, int key) {
    string cipher = "";
    
    for(int i = 0; i < msg.length(); i++) {
        if(msg[i] >= 'a' && msg[i] <= 'z') {
            cipher +=  + (msg[i]+key - 'a') % 26 + 'a';
        } 
        else if(msg[i] >= 'A' && msg[i] <= 'Z') {
            cipher += (msg[i] + key - 'A') % 26 + 'A';
        }
    }
    return cipher;
}

string decrypt(string msg, int key) {
    string decrypt = "";

    for(int i = 0; i < msg.length(); i++) {
        if(msg[i] >= 'a' && msg[i] <= 'z') {
            decrypt += (msg[i] - key - 'a') % 26 + 'a';
        } 
        else if(msg[i] >= 'A' && msg[i] <= 'Z') {
            decrypt += (msg[i] - key - 'A') % 26 + 'A';
        }
    }
    return decrypt;
}

int main() {
    string msg;
    int key;

    int c;
    cout << "1. Encrypt the message\n2. Decrypt the message" << endl;
    cout << "Enter your choice: ";
    cin >> c;

    switch(c) {
        case 1:
            cout << "\nEnter the message: ";
            cin >> msg;
            cout << "Enter the key: ";
            cin >> key;
            cout << caesarCipherEncrypt(msg, key) << endl;
            break;
        case 2:
            cout << "\nEnter the encrypted message: ";
            cin >> msg;
            cout << "Enter the key: ";
            cin >> key;
            cout << decrypt(msg, key) << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}