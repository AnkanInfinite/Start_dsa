//Printing from n to 1 using backtracking
/*
Enter till which to print : 8
8 7 6 5 4 3 2 1 
*/
#include<iostream>
void print(int i,int n){
    if(i>n)return;
    print(i+1,n);
    std::cout << i << ' ';
    
}

int main(){
    int x;
    do{
        std::cout << "Enter till which to print : ";
        std::cin >> x;
    }while(x<0);
    print(1,x);
    std::cout << std::endl;
    return 0;

}