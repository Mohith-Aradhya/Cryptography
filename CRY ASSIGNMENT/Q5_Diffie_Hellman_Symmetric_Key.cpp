#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int num){
    if(num < 2) return false;
    else if(num == 2) return true;
    else if(num > 2){
        bool prime = true;
        for(int i=2; i<num/2; i++){
            if(num % i == 0 && num != i){
                prime = false;
            } 
        }
        return prime;
    }
}

bool checkPrimitive(int publicKeyG, int publicKeyP){
    vector<double> vec;
    
    for(int i=1; i<publicKeyP; i++){
        vec.push_back(fmod((double) (pow(publicKeyG, i)), (double) publicKeyP));    
    }
    
    for(int i=1; i<publicKeyP; i++){
        if(count(vec.begin(), vec.end(), i) > 1){
            return false;
        }
        return true;
    }
}

int generate_symmetric_key(int publicKeyG, int pubicKeyP, int privateKeyAlice, int privateKeyBob) {
    
    int A = fmod(pow(publicKeyG, privateKeyAlice), pubicKeyP);
    int B = fmod(pow(publicKeyG, privateKeyBob), pubicKeyP);

    // Calculate symmetric key
    int keyA = fmod(pow(B, privateKeyAlice), pubicKeyP);
    int keyB = fmod(pow(A, privateKeyBob), pubicKeyP);

  
    if (keyA == keyB) {
        cout<<"Keys exchanged successfully"<<endl;
        return keyA;
    } else {
        return -1;
    }
}

int main() {
    // default values just in case
    int pubicKeyP = 23;
    int publicKeyG = 9;  
    int privateKeyAlice = 4;  //x : Private key for Alice
    int privateKeyBob = 3;  //y : Private key for bob
    
    while(1){ 
        
        cout<<"Enter public key P (prime number): ";
        cin>>pubicKeyP;
        
        if(checkPrime(pubicKeyP) == false){
            cout<<"Public key P should be a prime number!";
        }else break;
        
    };
    
    while(1){
        cout<<"Enter public key G (primitive root of P): ";
        cin>>publicKeyG;
        
        if(checkPrimitive(publicKeyG, pubicKeyP) == false){
            cout<<"Public key G should be a primitive root of P!";
        }else break;
    }
    
    cout<<"Enter private key of Alice: ";
    cin>>privateKeyAlice;
    
    cout<<"Enter private key Bob: ";
    cin>>privateKeyBob;

  
    int SymmetricKey = generate_symmetric_key(publicKeyG, pubicKeyP, privateKeyAlice, privateKeyBob);


    if (SymmetricKey != -1) {
        cout<<"Symmetric Key generated: "<<SymmetricKey;
    } else {
        cout<<"Symmetric key could not be generated";
    }

    return 0;
}