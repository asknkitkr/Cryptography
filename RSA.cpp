#include<iostream>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main() { 
    int msg_data;
    cout << "Enter Message data: ";
    cin >> msg_data;

    int p, q;
    cout << "Enter two primes (p and q): ";
    cin >> p >> q;

    int n = p*q;
    int phi = (p-1)*(q-1);

    int e;
    cout << "Enter public key -> e: ";
    cin >> e; 

    while(e < phi) {
        if(gcd(e, phi) == 1) {
            break;
        }
        e++;
    }

    int enc = pow(msg_data, e);
    enc = enc%n;

    cout << "\nMESSAGE DATA: " << msg_data << endl;
    cout << "PUBLIC KEY: " << e << endl;
    cout << "ENCRYPTED DATA: " <<  enc << endl;
    cout << "------------------------------------" << endl;

    int d, k;
    cout << "Enter arbitary value: ";
    cin >> k;

    d = (1+(k*phi))/e;
    int c = pow(msg_data, e);
    c = c%n;
    int m = pow(enc, d);
    m = m%n;

    cout << "DECRYPTED DATA: " << m << endl;
    return 0;
}