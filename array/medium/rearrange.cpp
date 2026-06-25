/*
Given an integer array nums of even length consisting of an equal number 
of positive and negative integers.Return the answer array in such a way 
that the given conditions are met:

> Every consecutive pair of integers have opposite signs.
> For all integers with the same sign, the order in which they were present in nums is preserved.
> The rearranged array begins with a positive integer.
*/
#include<vector>
/*
Approach 1 :
Create two arrays to store positive and negative elements preseving their relative order
Overide The oiginal array as required
Time Complexity : O(N)
Space Complexity : O(N)
*/

std::vector<int> rearrangeArray_1(std::vector<int> &nums){
    int n=nums.size();
    std::vector<int> posElements;
    std::vector<int> negElements;
    for(auto el : nums){
        if(el<0){
            negElements.push_back(el);
        }
        else{
            posElements.push_back(el);
        }
    }
    int idx1=0;
    int idx2=0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            nums[i]=posElements[idx1];
            idx1++;
        }
        else{
            nums[i]=negElements[idx2];
            idx2++;
        }
    }
    /*
    loop 2 could have been done in N/2 iterations
    for i 0 till < n/2
    for even positions 2*i
    and fo odd positions 2*i + 1
    */
    return nums;
}