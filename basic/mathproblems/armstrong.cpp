/*
You are given an integer n. You need to check whether it is an armstrong number or not. Return true if it is an armstrong number, otherwise return false.
An armstrong number is a number which is equal to the sum of the digits of the number, raised to the power of the number of digits.

constraints:
0 <= n <= 109
*/
#include<iostream>
#include<cmath>
bool check_armstrong(int n1){
    int digits=0,copy=n1,original=n1;
    while(n1>0){
        digits++;
        n1/=10;
    }
    while(copy>0){
        n1=n1+pow(copy%10,digits);//because in previous while loop it became 0
        copy/=10;
    }
    if(n1==original)return true;
    return false;
}

int main(){
    int x;
    do{
        std:: cout << "Enter a number : ";
        std:: cin >> x;
    }while(x<0);
    if(check_armstrong(x)) std::cout << x << " is an Armstrong Number \n";
    else std:: cout << x <<" is not an Armstrong Number \n";
    return 0;
}