/*
Given a binary array nums, return the maximum number of consecutive 1s in the array.
A binary array is an array that contains only 0s and 1s.
*/
#include<iostream>
#include<vector>
/*
Time Complexity: O(N)
Space Complexity: O(1)
*/
int max_consecutive_ones(std::vector<int> &nums){
    int highestStreak=0;
    int currentStreak=0;
    for(auto value : nums){
        if(value){
            currentStreak++;//for 1 our current streak increases
            highestStreak=std::max(currentStreak,highestStreak);
        }
        else{
            currentStreak=0;//When 0 occurs our streak breaks and reset to 0
        }
    }
    return highestStreak;
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
    std::cout << "Maximum Number of consecutive occurance of 1 is  :" <<max_consecutive_ones(nums) << std::endl;
    return 0;
}