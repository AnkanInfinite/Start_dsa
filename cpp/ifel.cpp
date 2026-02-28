#include<bits/stdc++.h>
using namespace std;
//Voter Non-voter
int main(void){
    int age;
    cout << "Enter Age : ";
    cin >> age;
    if(age>17){
        cout << "You are eligible to vote \n";
    }
    else{
        cout << "You are not eligible to vote \n";
    }
    return 0;
}