#include <iostream>

using namespace std;

int findInverse(int a){
    int aInverse = 0;
    for (int i = 0; i < 26; i++) {
        int temp = (a * i) % 26;
        if (temp == 1) {
            aInverse = i;
            break;
        }
    }
    return aInverse;
}

// Function to encrypt the plaintext
string encrypt(string plaintext, int a, int b) {
    string ciphertext = "";

    for (char c : plaintext) {
        if (isalpha(c)) {
            char encryptedChar = (a * (c - 'A') + b) % 26 + 'A';
            ciphertext += encryptedChar;
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

// Function to decrypt the ciphertext
string decrypt(string ciphertext, int a, int b) {
    string plaintext = "";

    // Calculate the modular inverse of 'a'
    // int aInverse = 0;
    // for (int i = 0; i < 26; i++) {
    //     int temp = (a * i) % 26;
    //     if (temp == 1) {
    //         aInverse = i;
    //         break;
    //     }
    // }

    int aInverse = findInverse(a);
    
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char decryptedChar = (aInverse * (c - 'A' - b + 26)) % 26 + 'A';
            plaintext += decryptedChar;
        } else {
            plaintext += c;
        }
    }

    return plaintext;
}

int main() {
    string plaintext;
    int a, b;

    // Get user input
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the value of 'a' (must be coprime with 26): ";
    cin >> a;

    cout << "Enter the value of 'b': ";
    cin >> b;

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, a, b);
    cout << "Encrypted ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = decrypt(ciphertext, a, b);
    cout << "Decrypted plaintext: " << decryptedText << endl;

    return 0;
}
