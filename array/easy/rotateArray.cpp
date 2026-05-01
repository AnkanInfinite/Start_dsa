#include<vector>
#include<iostream>

/*
Given an integer array nums, rotate the array to the left by one.
*/

void rotateArrayByOne(std::vector<int>& nums) {
        int temp=nums[0];
        nums.erase(nums.begin());
        nums.push_back(temp);
}

/*
Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/

void rotate(std::vector<int>& nums, int k) {
        int n=nums.size();
        //if we rotate array by the number of elements in array it becomes the original array
        k=k%n;
        //reverse entire array 
        int left=0;
        int right=n-1;
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
        //reverse first k elements
        left=0;right=k-1;
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
        //reverse next all elements
        left=k;right=n-1;
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
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
    rotate(nums,7);
    std::cout << "The array after rotating : " << std::endl;
    for(auto it : nums){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}