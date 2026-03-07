#include<iostream>
using namespace std;
void print14(int n){
    for(int rows=0;rows<n;rows++){
        for(char column='A';column<='A'+rows;column++){
            cout << column;
        }
        cout << endl;
    }
}

int main(){
    int x=0;
    do{
        cout << "Enter a positive Number : ";
        cin >> x;
    }while(x<0);
    print14(x);
    return 0;
}