/*
Given an integer array nums, find the subarray with the largest sum and 
return the sum of the elements present in that subarray.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include<iostream>
#include<vector>
#include<limits>
/*
Approach 1 :
Considering all possible subarrays and storing maximum sum
Time Complexity : O(N^2)
Space complexity : O(1)
*/
int maxSubaray_1(std::vector<int> &nums){
    int maxSum=std::numeric_limits<int>::min();
    for(int i=0;i<nums.size();i++){
        int curSum=0;
        for(int j=i;j<nums.size();j++){
            curSum+=nums[j];
            maxSum=std::max(maxSum,curSum);
        }
    }
    return maxSum;
}

/*
Appraoch 2 : Kadane's Algorithm
We start from first and calculate sum of current subarray 
if the sum of current subarray becomes negative we reset current sum to zero and start calculating 
sum of subarray form that index
Because carrying negative sum will definately reduce the sum and hence conflict our goal to obtain
subarray containg maximum sum

Time Complexity : O(N)
Space Complexity : O(1)
*/

int maxSubarray_2(std::vector<int> &nums){
    int maxSum=std::numeric_limits<int>::min();
    int curSum=0;
    for(auto it : nums){
        curSum+=it;
        maxSum=std::max(curSum,maxSum);
        if(curSum<0)curSum=0;
    }
    return maxSum;
}