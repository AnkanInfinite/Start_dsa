#include<iostream>
using namespace std;
//to print upper part
void uppart(int n){
    for(int rows=0;rows<n;rows++){
        for(int stars=0;stars<=rows;stars++){
            cout << "*";
        }
        cout << endl;
    }
}
//to print lower part
void lowerpart(int n){
    for(int rows=n;rows>0;rows--){
        
        for(int stars=rows;stars>0;stars--){
            cout << "*";
        }
        cout << endl;
    }
}
//Auxilary function to distribute number of rows
void print10(int t){
    uppart(t/2+t%2);
    lowerpart(t/2);
}

int main(){
    print10(9);
    return 0;
}