/*
Given an integer n. You need to recreate the pattern given below for any value of N. Let's say for N = 5, the pattern should look like as below:



5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5
*/

#include<iostream>
using namespace std;
int min(int n1,int n2){
    if(n1>n2) return n2;
    else return n1;
}

void print22(int n){
    for(int rows=0;rows<2*n-1;rows++){
        for(int columns=0;columns<2*n-1;columns++){
            int top=rows;//distance of value from top
            int down=(2*n-2)-rows;//distance from bottomm
            int left=columns;//distance from left
            int right=(2*n-2)-columns;//distance from right
            cout << n-min(min(top,down),min(left,right));
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
    print22(x);
    return 0;
}