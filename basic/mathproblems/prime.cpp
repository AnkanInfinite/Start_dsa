/*
You are given an integer n. You need to check if the number is prime or not. Return true if it is a prime number, otherwise return false.
A prime number is a number which has no divisors except 1 and itself.

constraints:
1 <= n <= 5000
*/
#include<iostream>
bool check_prime(int n){
    //we start from 2 as we exclude 2 divisors 1 and the number itself
    if(n==1)return false;
    for(int i=2;i*i<=n;++i){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int x;
    do{
        std::cout << "Enter a Number : ";
        std::cin >> x;
    }while(x<1);
    if(check_prime(x)){
        std::cout << x << " is a Prime Number ";
    }
    else{
        std::cout << x << " is not a Prime NUmber ";
    }
    std::cout << std::endl;
    return 0;
}