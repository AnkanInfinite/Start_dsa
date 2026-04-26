/*
Given an array of integers called nums, sort the array in non-decreasing order using the quick sort algorithm and return the sorted array.
A sorted array in non-decreasing order is an array where each element is greater than or equal to all preceding elements in the array.

Time Complexity: O(N log N)

Space Complexity: O(1) {without considering stack Space}
*/

#include<iostream>
#include<vector>
//swap
void swap(int &n1,int &n2){
    int temp=n1;
    n1=n2;
    n2=temp;
}

void quick_sort(std::vector<int> &nums , int low , int high){
    if(low>=high)return;
    int i=low;
    int pIndex=low;
    int j=high;
    //Finding correct position of pivot in a sorted array
    while(i<j){
        while(i<=high && nums[i]<=nums[low]){
            i++;
        }
        while(j>=low && nums[j]>nums[low]){
            j--;
        }
        //swap
        if(i<j){
           swap(nums[i],nums[j]);
        }
    }
    //Putting pivot in corrcet place
    pIndex=j;
    swap(nums[low],nums[pIndex]);
    //recursively sorting the subarrays on either side of pivot
    quick_sort(nums,low,pIndex-1);
    quick_sort(nums,pIndex+1,high);
    
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
    quick_sort(nums,0,nums.size()-1);
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : nums){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}