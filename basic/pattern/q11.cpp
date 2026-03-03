/*
Enter Numebr of rows : 5
1 
0 1
1 0 1
0 1 0 1
1 0 1 0 1
*/

#include<iostream>
using namespace std;
void print11(int n){
    for(int rows=0;rows<n;rows++){
        if(rows%2==0){
            for(int column=0;column<=rows;column++){
                if(column%2==0){
                    cout << "1 ";
                }
                else{
                    cout << "0 ";
                }
            }
        }
        else{
            for(int column=0;column<=rows;column++){
                if(column%2==0){
                    cout << "0 ";
                }
                else{
                    cout << "1 ";
                }
            }
        }
        cout << endl;
    }
}
//Try after a chat with gimini helped in identifying another pattern output = (rows+columns+1)%2
void print11a(int n){
    for(int rows=0;rows<n;rows++){
        for(int columns=0;columns<=rows;columns++){
            cout << "" << (rows+columns+1)%2 << " ";
        }
        cout << endl;
    }
}

int main(){
    int x;
    cout << "Enter Numebr of rows : ";
    cin >> x;
    print11a(x);
    return 0;
}