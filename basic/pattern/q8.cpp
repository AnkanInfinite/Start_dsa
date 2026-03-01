#include<iostream>
using namespace std;
void print8(int n){
    int nstars=2*n -1;
    for(int rows=0;rows<n;rows++){
        for(int space=0;space<rows;space++){
            cout << " ";
        }
        for(int stars=0;stars<nstars;stars++){
            cout << "*";
        }
        nstars-=2;
        cout << endl;
    }
}

int main(){
    print8(5);
    return 0;
}