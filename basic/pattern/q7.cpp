#include<iostream>
using namespace std;
void print7(int n){
    int nstars=0;
    for(int rows=0;rows<n;rows++){
        for(int space=0;space<n-rows;space++){
            cout << " ";
        }
        for(int stars=0;stars<=nstars;stars++){
            cout << "*";
        }
        nstars+=2;
        cout << endl;
    }
}

int main(){
    print7(5);
    return 0;
}