//Printing from 1 to n using backtracking
/*
Enter till which to print : 8
1 2 3 4 5 6 7 8 
*/
#include<iostream>
void print(int n){
    if(n<1)return;
    print(n-1);
    std::cout << n << ' ';
}

int main(){
    int x;
    do{
        std::cout << "Enter till which to print : ";
        std::cin >> x;
    }while(x<0);
    print(x);
    std::cout << std::endl;
    return 0;

}