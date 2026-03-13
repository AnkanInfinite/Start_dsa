/*
Enter a positive Number : 5
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
#include<iostream>
using namespace std;
void print17(int n){
    int t;
    for(int rows=0;rows<n;rows++){
        //leading spaces
        for(int lspace=0;lspace<n-rows-1;lspace++){
            cout << " ";
        }
        //Middle Characters
        for(t=0;t<=rows;t++){
            cout << char('A'+t);
        }
        t-=2;
        while(t>=0){
            cout << char('A'+t);
            t--;
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
    print17(x);
    return 0;
}