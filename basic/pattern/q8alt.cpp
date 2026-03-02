#include<iostream>
using namespace std;
void print8(int n){
    for(int rows=0;rows<n;rows++){
        //for first spaces
        for(int prespace=0;prespace<rows;prespace++){
            cout << " ";
        }
        //for stars in middle
        for(int stars=0;stars<2*(n-rows)-1;stars++){
            cout << "*";
        }
        //for space at end
        for(int postspace=0;postspace<rows;postspace++){
            cout << " ";
        }
        cout << endl;
    }
}

int main(){
    print8(5);
    return 0;
}