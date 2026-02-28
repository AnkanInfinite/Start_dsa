#include<iostream>
using namespace std;
void pattern(){
    for(int rows=0;rows<5;rows++){
        for(int columns=5;columns>rows;columns--){
            cout << "*";
        }
        cout << endl;
    }
}
int main(){
    pattern();
    return 0;
}