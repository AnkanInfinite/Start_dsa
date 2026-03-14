/*
Enter a positive Number : 5
E 
D E 
C D E 
B C D E 
A B C D E 
*/

#include<iostream>
using namespace std;
void print18(int n){
    char ch='A' + n-1;//Calculates from which character to start 5->E , 4 -> D ...
    for(int rows=0;rows<n;rows++){
        for(int columns=0;columns<=rows;columns++){
            cout << char(ch- rows + columns) << ' '; //ch - rows determines first letter of each row and + columns moves froward as we go forward through row
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
    print18(x);
    return 0;
}