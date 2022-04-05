#include<iostream>
#include<vector>
using namespace std;

int modInverse(int a, int m) {
    a %= m;
    for (int x = -m; x < m; x++)
        if ((a * x) % m == 1)
            return x;
}

int coFactor(int a[2][2], int temp[2][2], int p, int q, int n) {
    int i = 0, j = 0;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(r != p && c != q) {
                temp[i][j++] = a[r][c];
                if(j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int a[2][2], int n, int N) {
    int D = 0, sign = 1;
    if(n == 1)
        return a[0][0];
    int temp[2][2];
    for(int f = 0; f < n; f++) {        
        coFactor(a, temp, 0, f, n);
        D += sign * a[0][f] * determinant(temp, n - 1, N);
        sign = -sign;
    }
    return D;
}

void adjoint(int a[2][2], int adj[2][2], int N) {
    if(N == 1) {
        adj[0][0] = 1;
        return;
    }
    int temp[2][2], sign = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            coFactor(a, temp, i, j, N);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (determinant(temp, N - 1, N) * sign);
        }
    }
}

bool inverse(int a[2][2], int inv[2][2], int N) {
    int det = determinant(a, N, N);
    if(det == 0) {
        return false;
    }
    int invDet = modInverse(det, 26);
    int adj[2][2];
    adjoint(a, adj, N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            inv[i][j] = (adj[i][j] * invDet) % 26;
        }
    }
    return true;
}

int main() {
    int mat[2][2],inv[2][2], i, j, t, k, f, temp, sum = 0;
    string encrypted = "", decrypted = "";

    cout << "Enter 2x2 key matrix: ";
    for(i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter your text: ";
    string text; cin >> text;
    int len = text.size();

    

    cout << "\nSELECT CHOICE:\n[1] Encrypt your text\n[2] Decrypt your text\n";
    cout << "Enter choice: ";
    int c; cin >> c;

    switch(c) {
        case 1:
            temp = (2-text.length()%2)%2;
            for(i = 0; i < temp; i++) {
                text += 'x';
            }
            k = 0;
            while(k < len) {
                for(i = 0; i < 2; i++) {
                    sum = 0;
                    temp = k;
                    for(int j = 0; j < 2; j++) {
                        sum += ((mat[i][j] + 26)%26*(text[temp++]-'a')%26)%26;
                        sum %= 26;
                    }
                    encrypted += (sum + 'a');
                }
                k += 2;
            }
            cout << "Cipher: " << encrypted << endl;
            break;
        case 2:      
            inverse(mat, inv, 2);      
            k = 0;
            while(k < len) {
                for(i = 0; i < 2; i++) {
                    sum = 0;
                    temp = k;
                    for(j = 0; j < 2; j++) {
                        sum += ((inv[i][j] + 26)%26*(text[temp++]-'a')%26)%26;
                        sum %= 26;
                    }
                    decrypted += (sum + 'a');
                }
                k += 2;
            }

            f = decrypted.size() - 1;
            while(decrypted[f] == 'x') {
                f--;
            }

            cout << "Plaintext: ";
            for(i = 0; i <= f; i++) {
                cout << decrypted[i];
            }
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }

    cout << endl <<1561;
    return 0;
}