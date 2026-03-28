/*
Given a string s, return true if the string is palindrome, otherwise false.
A string is called palindrome if it reads the same forward and backward.

constraints:
1 <= s.length <= 10^3
s consist of only uppercase and lowercase English characters.

Example Run:
Enter string to check : AnknA
The string AnknA is palindrome

Enter string to check : Ankna
The string Ankna is not palindrome

Enter string to check : Ankan
The string Ankan is not palindrome
*/
#include<iostream>
#include<string>
// i is first index i.e. 0
bool checkPalindrome(std::string &s,int i=0){
    if(s[i] != s[(s.size()-1-i)]){
        return false;
    }
    if(i>s.size()/2){
        return true;
    }
    return checkPalindrome(s,i+1);
}

int main(){
    std::string s;
    std::cout << "Enter string to check : ";
    std::cin >> s;
    if(checkPalindrome(s)){
        std::cout << "The string " << s << " is palindrome" << std::endl;
    }
    else{
        std::cout << "The string " << s << " is not palindrome" << std::endl;
    }
    return 0;
}