/*
Given an array nums of size n and an integer k,
find the length of the longest sub-array that sums to k.
If no such sub-array exists, return 0.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
/*
Approach 1:
check all sub arrays and store length of each sub array whose sum is k in an array
Return largest element of the created array
Time Complexity: O(N^2)
Space Complexity: O(N)
Note: If question asks for length of all subarrays with sum k , then it is ok 
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
    int maxLen=0;
    int n=nums.size();
    int sum=0;
    while(right<n && left<=right){
        sum+=nums[right];
        while(sum>k && left<=right){
            sum-=nums[left];
            left++;//We move the left pointer till we get sum<=k
        }
        if(sum==k){
            maxLen=std::max(maxLen,right-left+1);//Store the longest window length whose sum of elements is k
        }
        right++;            
    }
    return maxLen;
}

/*
Approach 4: Works for Arrays containing Negative elements
Using HashMap and prefixSum
We store the sum(prefixSum) and the index where we get the sum in map
for each new sum(current) we check if we have (sum-k) in our map
as if previously we got prefixSum==sum(current) - k(target sum)
then the subarray from the index of prefixSum till current index has sum equal to K
Now we store the maxLength of SubArray

Time Complexity : O(N) or it can be O(N^2) at worst case for unordered map which is very rare can use map insted to get O(N logN)
Space Complexity : O(N)
*/

int longest_subarray_sum_k_4(std::vector<int> &nums , int k){
    std::unordered_map<long long , int > preSum;
    int maxLen=0;
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        if(sum==k){
            maxLen=std::max(maxLen,i+1);
        }
        long long rem=sum-k; 
        if(preSum.find(rem) != preSum.end()){
            maxLen=std::max(i-preSum.at(rem),maxLen);
        }
        //We only insert to hasmap the most left sum as the next elemnts may be 0
        if(preSum.find(sum) == preSum.end()){
            preSum[sum]=i;
        }
    }
    return maxLen;
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