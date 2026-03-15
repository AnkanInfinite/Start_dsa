/*
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:



*****
*   *
*   *
*   *
*****
*/
#include<iostream>
using namespace std;
void print21(int n){
    for(int rows=0;rows<n;rows++){
        //Handels first and last row
        if(rows==0 || rows==n-1){
            for(int star=0;star<n;star++){
                cout << '*';
            }
            cout << endl;
            continue;
        }
        //printing other rows
        for(int columns=0;columns<n;columns++){
            //printing firstt and last star
            if(columns==0 || columns==n-1){
                cout << '*';
                continue;
            }
            //printing spaces
            cout << ' '; 
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
    print21(x);
    return 0;
}