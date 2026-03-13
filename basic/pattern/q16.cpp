/*
Enter a positive Number : 5
A
BB
CCC
DDDD
EEEEE
*/
#include<iostream>
using namespace std;
void print16(int n){
    for(int rows=0;rows<n;rows++){
        for(int columns=0;columns<=rows;columns++){
            cout << char('A' + rows);
        }
        //newline
        cout << endl;
    }
}

int main(){
    int x=0;
    do{
        cout << "Enter a positive Number : ";
        cin >> x;
    }while(x<0);
    print16(x);
    return 0;
}
