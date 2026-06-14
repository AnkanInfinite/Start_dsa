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

/*
Approach 2: Dutch National Flag Algorithm

Consider hypothetitcal aray
0 to N
where 0 to low-1 (extreme left) are all 0
low to mid-1 arre all 1
mid to high are unsorted porrtion 
and high+1 to N (extreme right) are all 2

To sort a given aray of 0s 1s and 2s
we consider low=0,as 0 to low-1 ,i.e. extreme left are 0 elements
mid=0,as low to mid-1 are 0 elements
high=N , as high+1 to N are 0 elements

After that we begin sorting from mid  to high

Time Complexity : O(N)
Space Complexity : O(1) 

*/

void sortZeroOneTwo_2(std::vector<int> &nums){
    int low=0,mid=0,high=nums.size()-1;
    while(mid<=high){
        if(nums[mid]==0){
            std::swap(nums[mid],nums[low]);
            mid++;low++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else if(nums[mid]==2){
            std::swap(nums[high],nums[mid]);
            high--;
        }
    }
}

/*
Note:
Dutch National flag algorrith preserves complex objects.
i.e. 
Imagine instead of just sorting numbers, 
you are sorting a database of User Objects based on their status:
0 (Banned), 1 (Active), 2 (Premium).
[ User: Bob (0) ] -> [ User: Alice (2) ] -> [ User: Charlie (1) ]
Approach 1 (Counting Sort) destroys data.
If you just count that there is one 0, one 1, and one 2, and then overwrite the array with 0, 1, 2,
you have obliterated Bob, Alice, and Charlie!
To fix this, you would need to allocate extra memory to hold the actual objects,
destroying your O(1) space complexity.

Approach 2 (Swapping) preserves data. 
Because it physically std::swaps the objects, the user data (names, emails, history) 
moves along with the status integer safely. It sorts the actual objects in-place.

In Approach 1: You read the entire array from start to finish. 
If the array is massive, by the time you finish counting and start the second pass 
to rewrite the array, the beginning of the array has already been kicked out of the CPU cache. 
Your CPU has to slow down and fetch it from the slow main RAM all over again.

In Approach 2: You process and place elements where they belong the very first time you look at them. 
This maximizes spatial locality, keeping the data in the fast CPU cache.
*/
