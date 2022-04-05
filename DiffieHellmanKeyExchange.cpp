#include<iostream>
#include<cmath>
using namespace std;
#define lli long long int

int main() {
    int a, n;
    cout << "Enter the primitive root: ";
    cin >> a;
    cout << "Enter the value of modulus: ";
    cin >> n;

    int Xa, Xb;
    cout << "\nEnter the value of Xa: ";
    cin >> Xa;
    cout << "Enter the value of Xb: ";
    cin >> Xb;

    lli pA = pow(a, Xa);
    lli pB = pow(a, Xb);

    int keyA = pow(pB, Xa);
    int keyB = pow(pA, Xb);
    cout << "\nSecret key for A: " << (keyA%n)%n << endl;
    cout << "Secret key for B: " << (keyB%n)%n << endl;

    return 0;
}