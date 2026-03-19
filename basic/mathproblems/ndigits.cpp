/*
You are given an integer n. You need to return the number of digits in the number.



The number will have no leading zeroes, except when the number is 0 itself.
*/

#include<iostream>
using namespace std;
int cdigits(int n){
    int count=0;
    do{
        n/=10;
        count++;
    }while(n!=0);
    return count;
}

int main(){
    int x;
    cout << "Enter A number :";  
    cin >> x;
    int copy=x;
    cout << "There are " << cdigits(copy) << " digits in " << x << endl;
    return 0;
}