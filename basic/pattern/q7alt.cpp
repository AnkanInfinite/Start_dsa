#include<iostream>
using namespace std;
void print7(int n){
    for(int rows=0;rows<n;rows++){
        //for first spaces
        for(int prespace=0;prespace<n-rows;prespace++){
            cout << " ";
        }
        //for stars in middle
        for(int stars=0;stars<2*rows+1;stars++){
            cout << "*";
        }
        //for space at end
        for(int postspace=0;postspace<n-rows;postspace++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    print7(5);
    return 0;
}