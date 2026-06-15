/*
Given an integer array nums of size n, return the majority element of the array.
The majority element of an array is an element that appears more than n/2 times in the array. 
The array is guaranteed to have a majority element.
*/

#include<iostream>
#include<vector>
#include<unordered_map>

/*
Approach 1 : hashMap
Time Complexity : O(N)
Space Complexity : O(N)
*/

int majorityElement(std::vector<int>& nums) {
    int n=nums.size();
    int ans=-1;
    std::unordered_map<int,int> mpp;
    for(auto it : nums){
        mpp[it]++;
    }
    for(auto el : mpp){
        if(el.second > n/2){
            ans=el.first;
            break;
        }
    }
    return ans;
}

