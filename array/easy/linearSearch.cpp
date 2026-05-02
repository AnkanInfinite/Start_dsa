/*
Given an array of integers nums and an integer target,
find the smallest index (0 based indexing) where the target appears in the array.
If the target is not found in the array, return -1

*/
#include<iostream>
#include<vector>

int linear_search(std::vector<int> &nums,int target){
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]==target)return i;
    }
    return -1;
}

int main(){
    int x;
    std::cout << "How many elements to enter : ";
    do{
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums;
    std::cout << "Enter Elements :" << std::endl;
    while(x){
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
        x--;
    }
    std::cout << "Enter element to find : ";
    std::cin >> x;
    std::cout << "The Index of desired element is  " << linear_search(nums,x);
    std::cout << std::endl;
    return 0;
}