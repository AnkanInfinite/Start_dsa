#include<iostream>
using namespace std;
void print13(int n){
    int number=1;
    for(int rows=1;rows<=n;rows++){
        for(int columns=1;columns<=rows;columns++){
            cout << number<<" ";
            number++;
        }
        cout << endl;
    }
}

int main(){
    int x=0;
    do{
        cout << "Enter a positive Number : ";
        cin >> x;
    }while(x<0);
    print13(x);
    return 0;
}