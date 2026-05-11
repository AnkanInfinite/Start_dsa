/*
Given an array of integers nums and an integer target. 
Return the indices(0 - indexed) of two elements in nums such that they add up to target.
Each input will have exactly one solution, and the same element cannot be used twice. 
Return the answer in increasing order.
*/

#include<iostream>
#include<vector>
#include<unordered_map>

/*
Approach 1:
We take one index and add it with each other index element to try for target sum
If such pair is found we return it
Time Complexity : O(N^2)
Space Complexity : O(1)
*/
std::vector<int> two_sum_1(const std::vector<int> &nums , int target){
    
    for(int i=0 ; i<nums.size()-1 ; i++){
        for(int j=i+1 ; j<nums.size() ; j++){
            if((nums[i])+(nums[j]) == target){
                std::vector<int> ans={i,j};
                return ans;
            }
        }
    }
}

/*
Approach 2:
We use a hash map to store all elements and corresponding index
for each element we check if target-element is present
if present we return the vector of index of selected element and index of target-element
Time Complexity : O(N)
Space Complexity : O(N)
*/

std::vector<int> two_sum_2(const std::vector<int> &nums , int target){
    std::unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]=i;
    }
    for(auto value : mpp){
        int rem=target-value.first;
        if(mpp.find(rem) != mpp.end() && rem !=value.first){
            std::vector<int> ans;
            if(value.second < mpp[rem]){
                ans={value.second,mpp[rem]};
            }
            else{
                ans={mpp[rem],value.second};
            }
            return ans;
        }
    }
    return {};
}

/*
Optimised approach 2 
To handle duplicate and single pass approach
*/
std::vector<int> two_sum_3(const std::vector<int> &nums , int target){
    std::unordered_map<int,int> mpp;
    for(int i=0;i<nums.size();i++){
        int rem=target-nums[i];
        if(mpp.find(rem) != mpp.end()){
            return {mpp[rem],i};
        }
        mpp[nums[i]]=i;
    }
    return {};
}