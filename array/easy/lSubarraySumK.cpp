/*
Given an array nums of size n and an integer k,
find the length of the longest sub-array that sums to k.
If no such sub-array exists, return 0.
*/

#include<iostream>
#include<vector>

/*
Approach 1:
check all sub arrays and store length of each sub array whose sum is k in an array
Return largest element of the created array
Time Complexity: O(N^2)
Space Complexity: O(N)
*/

int longest_subarray_sum_k_1(std::vector<int> &nums , int k){
    std::vector<int> length;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        int l=0;//To store length of subarray
        for(auto it=nums.begin()+i ; it != nums.end() ;it++){
            sum+=*it;l++;
            if(sum==k){
                length.emplace_back(l);
                continue;
            }
        }
    }
    if(length.empty())return 0;
    int longestSubarray=0;
    for(auto value : length){
        if(value>longestSubarray){
            longestSubarray=value;
        }
    }
    return longestSubarray;
}

/*
Approach 2:
We can optimise approach 1 by keeping a varable to store the maximum of length of subArrays with sum k
Time Complexity: O(N^2)
Space Complexity: O(1)
*/

int longest_subarray_sum_k_2(std::vector<int> &nums , int k){
    int maxLength=0;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        int l=0;//To store length of subarray
        for(auto it=nums.begin()+i ; it != nums.end() ;it++){
            sum+=*it;l++;
            if(sum==k){
                if(l>maxLength)maxLength=l;
                continue;
            }
        }
    }
    return maxLength;
}

/*
Approach 3:
Using Two pointers/Sliding window technique
We intitilise two pointers left and right to 0
we run a single loop right<size of array 
Time Complexity : O(N)
Space Complexity : O(1)

NOTE: Only works for array containing non-negative , as it assumes increasing window size increases sum and vice-versa
*/

int longest_subarray_sum_k_3(std::vector<int> &nums , int k){
    int left=0;
    int right=0;
    int maxSubarray=0;
    int n=nums.size();
    int sum=0;
    while(right<n && left<=right){
        sum+=nums[right];
        while(sum>k){
            sum-=nums[left];
            left++;//We move the left pointer till we get sum<=k
        }
        if(sum==k){
            maxSubarray=std::max(maxSubarray,right-left+1);//Store the longest window length whose sum of elements is k
        }
        right++;            
    }
    return maxSubarray;
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
    std::cout << "Enter Sum of the sub-array to be found : ";
    std::cin >> x;
    std::cout << "The Length of longest sub-array with sum " << x << " is : " <<longest_subarray_sum_k_3(nums,x) << std::endl;
    return 0;
}