/*
You are given an integer n. Return the integer formed by placing the digits of n in reverse order.
constraints:
  0 <= n <= 5000
  n will contain no leading zeroes except when it is 0 itself.

*/
#include<iostream>
int revInt(int n){
    int rev=0;
    while(n>0){
        rev=rev*10+n%10;
        n/=10;
    }
    return rev;
}

int main(){
    int x;
    do{
        std :: cout << "Enter a positive integer : ";
        std :: cin >> x;
    }while(x<0);
    std::cout << "The reverse of "<< x << " is " << revInt(x) << std::endl;
    return 0;
}