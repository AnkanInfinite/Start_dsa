/*
Given an integer n, write a function to print all numbers from 1 to n (inclusive) using recursion.
-> You must not use any loops such as for, while, or do-while.
-> The function should print each number on a separate line, in increasing order from 1 to n.

example:
Enter NUmber till which to print : 8
1
2
3
4
5
6
7
8
*/

#include<iostream>

void print(int n1,int n2){
    if(n1>n2)return;
    std::cout << n1 << std::endl;
    print(n1+1,n2);
}

int main(){
    int x;
    do{
        std::cout << "Enter NUmber till which to print : ";
        std::cin >> x;
    }while(x<0);
    print(1,x);
    return 0;
}