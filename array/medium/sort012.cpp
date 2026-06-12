/*
Given an array nums consisting of only 0, 1, or 2. Sort the array in non-decreasing order.
The sorting must be done in-place, without making a copy of the original array.
*/

#include<iostream>
#include<vector>
/*
apprroach 1 : counting sort approach
Time Complexity : O(N)  but requires two passes
Space Complexity : O(1)
*/
void sortZeroOneTwo_1(std::vector<int>& nums) {
        int n0=0,n1=0,n2=0;
        for(auto it : nums){
            if(it==0){
                n0++;
            }
            else if(it==1){
                n1++;
            }
            else{
                n2++;
            }
        }

        int idx=0;
        while(n0){
            nums[idx]=0;
            idx++;
            n0--;
        }
        while(n1){
            nums[idx]=1;
            idx++;
            n1--;
        }
        while(n2){
            nums[idx]=2;
            idx++;
            n2--;
        }
}