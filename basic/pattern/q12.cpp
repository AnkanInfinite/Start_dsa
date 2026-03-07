#include<iostream>
using namespace std;
void print12(int n){
    for(int rows=1;rows<=n;rows++){
        //for numbers in front
        for(int pre=1;pre<=rows;pre++){
            cout << pre;
        }
        //for sapce in between
        for(int nspace=1;nspace<=2*(n-rows);nspace++){
            cout << " ";
        }
        //for numbers in back
        for(int post=rows;post>0;post--){
            cout << post;
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
    print12(x);
    return 0;
}