#include<iostream>
using namespace std;
void pattern(){
    for(int rows=0;rows<5;rows++){
        for(int columns=0;columns<rows+1;columns++){
            cout << rows+1;
        }
        cout << endl;
    }
}
int main(){
    pattern();
    return 0;
}