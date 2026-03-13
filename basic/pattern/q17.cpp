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
    for(int rows=0;rows<n;rows++){
        //leading spaces
        for(int lspace=0;lspace<n-rows-1;lspace++){
            cout << " ";
        }
        //Middle Characters
        int breakpoint=(2*rows+1)/2;//middle of characters we are printing
        char chr='A'; 
        for(int i=0;i<2*rows+1;i++){
            cout << chr;
            if(i<=breakpoint)chr++;
            else chr--; //we decrement the charater after mid or peak
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