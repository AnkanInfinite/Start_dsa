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
Time Complexity : O(N)  or O(2N) to be specific
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

/*
Approach 2 : Single pass approach
Since we know that all positive elements would be stored in even positions of result array
and negative in odd positions
We can create of length same as given array and put elements in correct positions as required
Time Complexity : O(N)
Space Complexity : O(N)
*/

std::vector<int> rearrangeArray_2(const std::vector<int> &nums){
    int n=nums.size();
    std::vector<int> ans(n,0);
    int posIndex=0;
    int negIndex=1;
    for(auto el : nums){
        if(el < 0){
            ans[negIndex]=el;
            negIndex+=2;
        }
        else{
            ans[posIndex]=el;
            posIndex+=2;
        }
    }
    return ans;
}

/*
In case Number of Positive elements is not equal to Number of negative elements
And we are required keep any left over positive(negative) elements at end of result array 
preserving its relative order
Time Complexity : around O(2N)
Space Complexity : O(2N)
*/

std::vector<int> rearrangeArray_3(const std::vector<int> &nums){
    int n=nums.size();
    std::vector<int> posElements;
    std::vector<int> negElements;
    std::vector<int> ans;
    for(auto el : nums){
        if(el<0){
            negElements.push_back(el);
        }
        else{
            posElements.push_back(el);
        }
    }
    int equalNumber=std::min(negElements.size(),posElements.size());
    for(int i=0;i<equalNumber;i++){
        ans.push_back(posElements[i]);
        ans.push_back(negElements[i]);
    }
    //Now left over elements
    for(int i=equalNumber;i<posElements.size();i++){
        ans.push_back(posElements[i]);
    }
    for(int i=equalNumber;i<negElements.size();i++){
        ans.push_back(negElements[i]);
    }
    return ans;
}