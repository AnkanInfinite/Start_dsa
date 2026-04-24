/*
Given an array of integers nums, sort the array in non-decreasing order using the recursive Insertion Sort algorithm, and return the sorted array.

You must implement Insertion Sort using recursion only.
Do not use loops (like for or while) or built-in sorting functions (sort, Arrays.sort, etc.).
A sorted array in non-decreasing order is an array where each element is greater than or equal to all elements that come before it.

Time complexity:
            O(N^2)
Space Complecxity:
            O(N)
*/

#include<iostream>
#include<vector>
//Function to put element in correct position
void insert_correct_position(std::vector<int> &nums , int index){
    if(index <=0 || nums[index]>=nums[index-1]) return;
    int temp=nums[index];
    nums[index]=nums[index-1];
    nums[index-1]=temp;
    insert_correct_position(nums,index-1);
}
void recursive_insertion_sort(std::vector<int> &nums,int n,int i=1){
    if(i>=n)return;
    //inserting the value at correct position
    insert_correct_position(nums,i);
    recursive_insertion_sort(nums,n,i+1);
}
//Function wrapper using function overloading
std::vector<int> recursive_insertion_sort(const std::vector<int> &nums){
    std::vector<int> arr = nums;
    int n=arr.size();
    recursive_insertion_sort(arr,n,1);
    return arr;
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
    std::vector<int> ans = recursive_insertion_sort(nums);//it calls function 2 where a single copy of passed array is modified without touching the original
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : ans){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}