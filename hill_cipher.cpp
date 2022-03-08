#include<iostream>
using namespace std;

#define N 2

void hill_encryption(string msg, int mat[][2]) {
    int t = (2-msg.length()%2)%2;
    for (int i = 0; i < t; i++) {
        msg += 'x'; 
    }

    int len = msg.length();
    string cipher = "";
    int k = 0;

    while(k < len) {
        int x = msg[k] - 'a';
        int y = msg[k+1] - 'a';
        int x1 = mat[0][0] * x + mat[0][1] * y;
        int y1 = mat[1][0] * x + mat[1][1] * y;
        cipher += (char)((x1 % 26) + 'a');
        cipher += (char)((y1 % 26) + 'a');
        k += 2;
    }
    cout << "Cipher Text: " << cipher << endl;
}

void hill_decryption(string msg, int mat[][2]) {
    int len = msg.length();
    int inv[2][2];
    string plaintext = "";
    int k = 0;

    while(k < len) {
        for(int i = 0; i < len; i++) {
            int sum = 0, temp = k;
            for(int j = 0; j < len; j++) {
                sum += ((inv[i][j] + 26)%26*(msg[temp++]-'a')%26)%26;
                sum %= 26;
            }
            plaintext += (char)(sum + 'a');
        }
        k += n;
    }
    
    int t = plaintext.size() - 1;
    while(plaintext[t] == 'x') 
        t--;

    cout << "Plaintext: ";
    for(int i = 0; i <= t; i++) {
        cout << plaintext[i];
    }
}

int main() {
    int m[2][2];
    cout << "Enter 2x2 key matrix: ";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> m[i][j];
        }
    }
    string msg;
    cout << "Enter message: ";
    cin >> msg;

    hill_decryption(msg, m);
    return 0;
}