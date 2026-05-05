/*
Given an array of nums of n integers. Every integer in the array appears twice except one integer. 
Find the number that appeared once in the array.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
/*
Approach 1 : using hashmap
Time Complexity: O(N)
Space Complexity: O(N/2 +1) or just O(N)
*/
 int single_number_1(const std::vector<int>& nums){
        std::unordered_map<int,int> mpp;
        for(auto value : nums){
            mpp[value]++;
        }
        for(auto pair : mpp){
            if(pair.second == 1)return pair.first;
        }
        return -1; //In case nothing appears just once
    }
/*
Approach 2 : Using XOR
To meet leetcode demand of constant space
Time Complexity:O(N)
Space Complexity:O(1)

XOR
1. XOR of a number with itself i.e. n^n is 0
2. XOR of a number with 0 is number itself i.e. n^0 is n
3. Order of XOR doesnot matter i.e. A^B^A^A^B = (A^A^A)^(B^B)
*/

int single_number_2(const std::vector<int> &nums){
    int result=0;
    for(auto value : nums){
        result=result^value;
    }
    return result;
}



int main(){
    int x;
    std::cout << "How many elements to enter in array 1: ";
    do{
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums;
    std::cout << "Enter Elements of array 1 :" << std::endl;
    while(x){
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
        x--;
    }
    std::cout << "The number which occurs one time is :" <<single_number_2(nums) << std::endl;
    return 0;
}