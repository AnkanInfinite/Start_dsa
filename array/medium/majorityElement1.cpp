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

int majorityElement1(std::vector<int>& nums) {
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

/*
Approach 2 : Moore's voting algorithm
Here we select a element at it's first orrcurance
add 1 if it repeats and substract 1 if anyother element
when counter becomes 0 we treat the current element as it's first occurance
At the end of iterrating the array if counter is > 0 then we have found the majority element
otherwise majoity element doesn't exist

Time Complexity : O(N)
Space Complexity : O(1)
*/

int majorityElement2(std::vector<int> &nums){
    int majority=-1;
    int cnt=0;
    for(auto it : nums){
        if(!cnt){
            majority=it;
            cnt++;
        }
        else if(majority==it){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    /*
    Since our problem statement gurantees majority element we do not check 
    otherwise run the check
    int count=0;
    for(auto el : nums){
        if(majority==el)count++;
    }
    if(majority > n/2)return majority;
    else return "error code symbolising majority not found"
    */
    return majority;
}