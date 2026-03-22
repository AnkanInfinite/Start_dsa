/*
You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
A number which completely divides another number is called it's divisor.

constraints:
1 <= n <= 1000
*/

#include<iostream>
#include<vector>
std::vector<int> divisors(int n){
    std::vector<int> vc;
    //We run loop till n/2 because last digit to divide a number n except itself must be either n/2 or less than that
    for(int i=1;i<=n/2;i++){
        if(n%i==0){
            vc.emplace_back(i); 
        }
    }
    vc.emplace_back(n);//Because n divides itself
    return vc;
}
//optimised method to FIND DIVISORS but UNSORTED
//Using property that for any non-negative number n if d is its divisor then n/d is also a divisor and this property is symmetric at squareroot of n
std:: vector<int> divisors_opt(int n){
    std:: vector<int> vtr;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            vtr.push_back(i);
        
            //now if n/i diffferent from i
            if(i!=n/i){
                vtr.push_back(n/i);
            }
        }
    }
    return vtr;
}

int main(){
    int x;
    do{
        std:: cout << "Enter a Numebr : ";
        std:: cin >> x;
    }while(x<0);
    std:: cout << "The divisors of " << x << " are ";
    std:: vector<int> divs =divisors(x);
    for(std::vector<int> :: iterator it=divs.begin();it != divs.end();++it){
        std:: cout << " " << *it;
    }
    std:: cout << std::endl;
    return 0;
}
