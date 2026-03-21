/*
You are given two integers n1 and n2. You need find the Greatest Common Divisor (GCD) of the two given numbers. Return the GCD of the two numbers.
The Greatest Common Divisor (GCD) of two integers is the largest positive integer that divides both of the integers.

constraints:
1 <= n1, n2 <= 1000
*/
#include<iostream>
int min_int(int n1,int n2){
    if(n1>n2)return n2;
    return n1;
}
int gcd(int n1,int n2){
    int t=1;
    for(int i=1;i<=min_int(n1,n2);i++){
        if(n1%i==0 and n2%i==0){
            if(i>t)t=i;
        }
    }
    return t;
}
//SomeWhat better than bruteforce
int gcd_find(int n1,int n2){
    for(int i=min_int(n1,n2);i>0;i--){
        if(n1%i==0 and n2%i==0)return i;
    }
    
}
//beest approrach
//throuch recursion
int gcd_rec(int n1,int n2){
    if(n2==0)return n1;
    return gcd_rec(n2,n1%n2);
}
//through iteration
int gcd_iteration(int n1,int n2){
    while(n1>0 and n2>0){
        if(n1>n2){
            n1=n1%n2;
        }
        else{
            n2=n2%n1;
        }
    }
    if(n1)return n1; //n1=0 implies false
    return n2;
}
int main(){
    int x1,x2;
    do{
        std :: cout << "Enter 2 positive integer : ";
        std :: cin >> x1 >> x2;
    }while(x1<0 || x2<0);
    std::cout << "The gcd of "<< x1 << " and "<< x2 << " is " << gcd_iteration(x1,x2) << std::endl;
    return 0;
}