/*
Given an array of integers called nums,sort the array in non-decreasing order using the bubble sort algorithm and return the sorted array.
A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

output:
Enter how many elements to enter :10
1 2 3 1 2 3 4 6 3 3
The elements after sorting : 
1 1 2 2 3 3 3 3 4 6 
*/

#include<iostream>
#include<vector>
/*
We Start from begining of array and swap adjacent elements to keep larger element at second positon
till the second position is at last index of array
Now we change last to previous index as at last the largest element is present
And we keep doing this till last doesn't become zero
Time complexility of the code is O(N^2)
*/
std::vector<int> bubble_sort(std::vector<int> &nums){
    int last=nums.size() - 1 ;
    while(last !=0){
        for(int j=0;j<last;j++){
            if(nums[j]>nums[j+1]){
                //swap
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
        last--;//Since last element is now lasrgest we don't check it in next iteration
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
    std::vector<int> ans = bubble_sort(nums);
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : ans){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}