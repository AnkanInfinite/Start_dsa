/*
Enter a positive Number : 10
**********
****  ****
***    ***
**      **
*        *
*        *
**      **
***    ***
****  ****
**********
*/

#include<iostream>
using namespace std;
//function to print upper part of pattern
void printup(int n){
    for(int rows=0;rows<n;rows++){
        //printing leading stars 
        for(int lstar=0;lstar<n-rows;lstar++){
            cout << '*';
        }
        //Middle Spaces
        for(int ms=0;ms<2*rows;ms++){
            cout << ' ';
        }
        //trailing stars
        for(int tstar=0;tstar<n-rows;tstar++){
            cout << '*';
        }
        cout << endl;
    }
}
//function to print lower part of pattern
void printlw(int n){
    for(int rows=0;rows<n;rows++){
        //leading stars
        for(int lstars=0;lstars<=rows;lstars++){
            cout << '*';
        }
        //middle spaces
        for(int ms=0;ms<2*(n-1-rows);ms++){
            cout << ' ';
        }
        //trailing stars
        for(int tstars=0;tstars<=rows;tstars++){
            cout << '*';
        }
        cout << endl;
    }
}
//function to distribute upper and lower rows
void print19(int n){
    int upp=n/2+n%2;//Number of rows in upper part n/2 +n%2 handles even and odd
    int lp=n-upp;//Number of rows in lower part
    printup(upp);
    printlw(lp);
}

int main(){
    int x=0;
    do{
        cout << "Enter a positive Number : ";
        cin >> x;
    }while(x<0);
    print19(x);
    return 0;
}