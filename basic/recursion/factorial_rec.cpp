/*
You are given an integer n. Return the value of n! or n factorial.
Factorial of a number is the product of all positive integers less than or equal to that number.

*/
#include<iostream>
int fac(int n){
    if(n==0)return 1;
    return n*fac(n-1);
}

int main(){
    int x;
    do{
        std::cout << "Enter Number to find its factorial : ";
        std::cin >> x;
    }while(x<0);
    std::cout << "The factorial of " << x << " is " << fac(x) << std::endl;
}