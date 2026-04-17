/*
Given an array of integers called nums, sort the array in non-decreasing order using the insertion sort algorithm and return the sorted array.
A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.
sample output:
Enter how many elements to enter :12
4 5 8 5 8 45 8 54 8 45 488 4 5 
The elements after sorting : 
4 4 5 5 8 8 8 8 45 45 54 488 


Time Complexity: Worst and Average -> O(N^2)
                 Best -> O(N)
Space Complexity : O(1)
*/

#include<iostream>
#include<vector>

std::vector<int> insertion_sort(std::vector<int> nums){
    int size=nums.size();
    if(size<2)return nums;
    for(int i=1;i<size;i++){
        int j=i;
        //in c++ && operator evaluates from left to right so we won't face issue of nums[-1] if we check for j>0 first
        /*
        using swap
        while(j>0 && nums[j]<nums[j-1]){
            //swap
            int temp=nums[j];
            nums[j]=nums[j-1];
            nums[j-1]=temp;
            j--;
        }
        */
       //using shift is more optimal
       int temp=nums[j];
       while(j>0 && temp<nums[j-1]){
        nums[j]=nums[j-1];
        j--;
       }
       nums[j]=temp;
    }
    return nums;
}

int main(){
    int x;
    do{
        std::cout << "Enter how many elements to enter :";
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums;int temp;
    while(x){
        std::cin >> temp;
        nums.push_back(temp);
        x--;
    }
    std::vector<int> ans = insertion_sort(nums);
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : ans){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}