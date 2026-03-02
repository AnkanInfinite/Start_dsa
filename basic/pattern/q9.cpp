#include<iostream>
using namespace std;
//to print upperpart of diamond
void uppart(int n){
    for(int rows=0;rows<n;rows++){
        //for first spaces
        for(int prespace=0;prespace<n-rows-1;prespace++){
            cout << " ";
        }
        //for stars in middle
        for(int stars=0;stars<2*rows+1;stars++){
            cout << "*";
        }
        //for space at end
        for(int postspace=0;postspace<n-rows-1;postspace++){
            cout << " ";
        }
        cout << endl;
    }
}
//to print lower part of diamond
void lowpart(int n){
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

//auxilary function to distribute number of rows between upper and lower
void print9(int t){
    int half=t/2;
    uppart(half+(t%2));//handles odd numebr of rows 
    lowpart(half);
}

int main(){
    print9(10);
    return 0;
}