#include<iostream>
using namespace std;
void pattern(int n){
    for(int rows=0;rows<n;rows++){
        for(int columns=n;columns>rows;columns--){
            cout << n+1-columns;
        }
        cout << endl;
    }
}
int main(){
    int n;
    cin >> n;
    pattern(n);
    return 0;
}