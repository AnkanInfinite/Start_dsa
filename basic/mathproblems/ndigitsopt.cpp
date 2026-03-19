/*
You are given an integer n. You need to return the number of digits in the number.
The number will have no leading zeroes, except when the number is 0 itself.
*/
//optimised code using log base 10 + 1
#include<iostream>
#include<cmath> //Using cmath as it is specially for c++ and math.h is for backward copatibility with c
using namespace std;
int cdigits(int n){
    if(n==0)return 1;
    int count=0;n=abs(n);
    count=(int)(log10(n)+1);//log10(n) gives power of 10 required and we add 1 to find number of divisions required to reach 0
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