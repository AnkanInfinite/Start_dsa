#include<iostream>
using namespace std;
void print11(int n){
    for(int rows=0;rows<n;rows++){
        if(rows%2==0){
            for(int column=0;column<=rows;column++){
                if(column%2==0){
                    cout << "1 ";
                }
                else{
                    cout << "0 ";
                }
            }
        }
        else{
            for(int column=0;column<=rows;column++){
                if(column%2==0){
                    cout << "0 ";
                }
                else{
                    cout << "1 ";
                }
            }
        }
        cout << endl;
    }
}

int main(){
    int x;
    cout << "Enter Numebr of rows : ";
    cin >> x;
    print11(x);
    return 0;
}