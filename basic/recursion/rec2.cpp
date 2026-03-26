/*
Given an integer N, return the sum of first N natural numbers. Try to solve this using recursion.

*/
#include<iostream>
int NnumberSum(int n){
    if(n==1)return 1;
    return n + NnumberSum(n-1);
}

int main(){
    int x;
    do{
        std::cout << "Enter Natural NUmber Till which to find sum : ";
        std::cin >> x;
    }while(x<0);
    std::cout << "The sum of natural numbers till "<< x << " is "<< NnumberSum(x)<< std::endl;
    return 0;
}