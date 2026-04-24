/*
Given an array of integers nums, sort the array in non-decreasing order using the recursive Bubble Sort algorithm, and return the sorted array.
 You must implement Bubble Sort using recursion only.
 Do not use built-in sorting functions (sort, sorted, Arrays.sort, etc.).
 A sorted array in non-decreasing order is an array where each element is greater than or equal to the previous one.
 Time Complexity:
  Best- O(N)
  Worst- O(N^2)
Space Complexity :
 O(N)
*/

/*
FUNCTION OVERLOADING:
 C++ compiler checks what argumnets are passed during calling
 then calls the function with same name but with the passed parameters
 We define same function name with different paraments and the return type may or may not be same 
 We have to change parameters either the number of them , order of them or their type to overload a function (Or we can say function signature with same function name but rest are different)
 Only changing the return type of function doesn't work 
*/

#include<iostream>
#include<vector>
//FUNCTION 1
void recursive_bubble_sort(std::vector<int> &nums , int n){
    //array of single elemenet is always sorted
    if (n==1) return;
    bool didswap=false;//flag
    //We move the largest element to last index
    for(int i=0;i<n-1;i++){
        if(nums[i]>nums[i+1]){
            //swap
            didswap=true;
            int temp=nums[i+1];
            nums[i+1]=nums[i];
            nums[i]=temp;
        }
    }
    if(!didswap) return; //If no swap occurs means the array is already sorted so we break out of recursion and return the array
    //Now since the largest element is at the last index we consider the array till second last index
    recursive_bubble_sort(nums,n-1);
}
//Using function overloading to sort the array when only the array is passed not the size
//FUNCTION 2 or Wrapper function
std::vector<int> recursive_bubble_sort(const std::vector<int> &nums){
    int n=nums.size();
    std::vector<int> arr = nums;
    recursive_bubble_sort(arr,n);
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
    std::vector<int> ans = recursive_bubble_sort(nums);//it calls function 2 where a single copy of passed array is modified without touching the original
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : ans){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}