/*
Given an integer array nums sorted in non-decreasing order, remove all duplicates in-place so that each unique element appears only once.

Return the number of unique elements in the array.

If the number of unique elements be k, then,

->Change the array nums such that the first k elements of nums contain the unique values in the order that they were present originally.
->The remaining elements, as well as the size of the array does not matter in terms of correctness.
->The driver code will assess correctness by printing and checking only the first k elements of the modified array.

An array sorted in non-decreasing order is an array
where every element to the right of an element is either equal to or greater in value than that element.
*/
#include<iostream>
#include<vector>
//Approach 1
//Time complexity : O(N^2) Space :O(1)
int remove_duplicates1(std::vector<int> &nums){
    int i=0;
    while(i<nums.size()-1){
        if(nums[i]==nums[i+1]){
            nums.erase(nums.begin()+i);
            continue;
        }
        i++;
    }
    return nums.size();
}
//two pointer approach 
//Time complexity : O(N) Space: O(1)
int remove_duplicates(std::vector<int> &nums){
    if(nums.empty()){
        return 0;
    }
    int i=0;
    int n=nums.size();
    for(int j=1;j<n;j++){
        if(nums[j]!=nums[i]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;
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
    std::cout << "The number of unique elements is " << remove_duplicates(nums);
    std::cout << std::endl;
    
    return 0;
}