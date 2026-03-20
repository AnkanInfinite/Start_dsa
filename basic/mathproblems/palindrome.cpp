/*
You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.
A palindrome number is a number which reads the same both left to right and right to left.

constraints:
0 <= n <= 5000
n will contain no leading zeroes except when it is 0 itself.
*/
#include<iostream>
bool ispalindrome(int n){
    int copy=n;
    int rev=0;
    while(n){
        rev=rev*10+n%10;
        n/=10;
    }
    if(copy==rev){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int x;
    do{
        std::cout <<"Enter Integer : ";
        std :: cin >> x;
    }while(x<0);
    if(ispalindrome(x)){
        std::cout << x << " is a palindrome number " << std::endl;
    }
    else{
        std::cout << x << " is not a palindrome number " << std::endl;
    } 
    return 0;
}