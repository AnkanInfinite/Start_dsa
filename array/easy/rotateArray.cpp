#include<vector>
#include<iostream>

//function to reverse array
void reverseArray(std::vector<int> &nums,int left,int right){
        while(left<right){
            int temp=nums[left];
            nums[left]=nums[right];
            nums[right]=temp;
            left++;
            right--;
        }
}

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

void rotate_right(std::vector<int>& nums, int k) {
        int n=nums.size();
        //if we rotate array by the number of elements in array it becomes the original array
        k=k%n;
        //reverse entire array 
        reverseArray(nums,0,n-1);
        //reverse first k elements
        reverseArray(nums,0,k-1);
        //reverse next all elements
        reverseArray(nums,k,n-1);
}

/*
Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.
*/
void rotate_left(std::vector<int>& nums, int k) {
    int n=nums.size();
    k=k%n;
    //reverse  entire array 
    reverseArray(nums,0,n-1);
    //reverse last k elements
    reverseArray(nums,n-k,n-1);
    //reverse the first elements till last k elements
    reverseArray(nums,0,n-k-1);

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
    rotate_left(nums,7);
    std::cout << "The array after rotating : " << std::endl;
    for(auto it : nums){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}