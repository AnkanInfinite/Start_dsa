/*
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:



*        *
**      **
***    ***
****  ****
**********
****  ****
***    ***
**      **
*        *

*/

#include<iostream>
using namespace std;
void print20(int n){
    //Upper part
    for(int rows=0;rows<n;rows++){
        //leading stars
        for(int lstars=0;lstars<=rows;lstars++){
            cout << "*";
        }
        //for middle spaces
        for(int ms=0;ms<2*(n-1-rows);ms++){
            cout << ' ';
        }
        //Trailing stars
         for(int tstars=0;tstars<=rows;tstars++){
            cout << "*";
        }
        cout << endl;
    }
    //lower part
    for(int rows=0;rows<n-1;rows++){
        //leading stars
        for(int lstars=0;lstars<n-1-rows;lstars++){
            cout << "*";
        }
        //for middle spaces
        for(int ms=0;ms<2*(rows+1);ms++){
            cout << ' ';
        }
        //Trailing stars
         for(int tstars=0;tstars<n-1-rows;tstars++){
            cout << "*";
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
    print20(x);
    return 0;
}