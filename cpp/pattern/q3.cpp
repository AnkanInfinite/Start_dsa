#include<iostream>
using namespace std;
void pattern(){
    for(int rows=0;rows<5;rows++){
        for(int columns=1;columns<=rows+1;columns++){
            cout << columns;
        }
        cout << endl;
    }
}
int main(){
    pattern();
    return 0;
}