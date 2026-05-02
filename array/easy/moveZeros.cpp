/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
*/

#include<iostream>
#include<vector>
#include<utility> //for swap
//Left shift elements by 1
void left_shift_one(std::vector<int> &nums,int index ){
    while(index<nums.size()-1){
        nums[index]=nums[index+1];
        index++;
    }
}
//Time complexity: O(N^2)
void move_zeros_end_1(std::vector<int> &nums){
    int n=nums.size();
    int i=0;
    for(int j=0;j<n;j++){
        if(nums[i]==0){
            left_shift_one(nums,i);
            nums[n-1]=0;
            continue;
        }
        i++;
    }
}

//Two pointer method minimizes number of operations
//Time complexity: O(N)
void move_zeros_end(std::vector<int> &nums){
    int nonZeroIndex=0; //To store correct non zero element index
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            //swap element with correct non zero position
            std::swap(nums[nonZeroIndex],nums[i]);
            nonZeroIndex++;
        }
    }
    while(nonZeroIndex<n){
        nums[nonZeroIndex]=0;
        nonZeroIndex++;
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
    move_zeros_end(nums);
    std::cout << "The array after moving zeros to end : " << std::endl;
    for(auto it : nums){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}