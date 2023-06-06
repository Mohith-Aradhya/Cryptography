#include<bits/stdc++.h>
using namespace std;

string applyHash(string str){
    hash<string> hasher;
    
    size_t hash = hasher(str);
    
    return to_string(hash);
}

int main(){
    string senderMsg, receiverMsg;
    string senderHashedVal, ReceiverHashedVal;
    
    cout<<"Sender"<<endl;
    cout<<"Enter message: ";
    cin>>senderMsg;
    
    senderHashedVal = applyHash(senderMsg);
    cout<<"Sender hashed val: "<<senderHashedVal;
    
    cout<<"\nReceiver"<<endl;
    cout<<"Enter message: ";
    cin>>receiverMsg;
    
    ReceiverHashedVal = applyHash(receiverMsg);
    cout<<"Receiver hashed val: "<<ReceiverHashedVal<<endl;
    
    if(senderHashedVal == ReceiverHashedVal){
        cout<<"Message has not been modified";
    }else{
        cout<<"Message has been modified";
    }
    return 0;
}