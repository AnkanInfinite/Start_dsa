/*
Enter a positive Number : 5
ABCDE
ABCD
ABC
AB
A
*/
#include<iostream>
using namespace std;
void print15(int n){
    for(int rows=0;rows<n;rows++){
        //column n,n-1,n-2...
        for(int columns=0;columns<n-rows;columns++){
            cout << char('A' + columns);
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
    print15(x);
    return 0;
}
