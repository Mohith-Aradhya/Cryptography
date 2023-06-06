#include<iostream>
using namespace std;

int gcd(int b, int a){
    int r1 = a;
    int r2 = b;
    int t1 = 0;
    int t2 = 1;
    int inv = 0;
    
    while(r2 > 0){
        int q = r1/r2;
        int r = r1-(q*r2);
        r1 = r2;
        r2 = r;
        int t = t1-(q*t2);
        t1 = t2;
        t2 = t;
    }
    
    if(t1 < 0) return (t1+t2)%a;
    else return t1%a;
}

int main(){
    int a, b, inverse;
    
    cout<<"**********   Extended Euclidean Algorithm    **********"<<endl<<endl;
    cout<<"Finds the multiplicate inverse of 'a' in 'Zb'"<<endl<<endl;
    cout<<"Enter numbers a and b: "<<endl;
    cin>>a>>b;
    
    inverse = gcd(a, b);
    
    cout<<"Multiplicative inverse of "<<a<<" is: "<<inverse;
    
    return 0;
}