/*
Given an array of integers nums, return the second-largest element in the array. If the second-largest element does not exist, return -1.

sample run:
How many elements to enter : 10
Enter Elements :
4 5 8 4 51 8 4 1 84 1 5 1 
The Second largest element is 51
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
int second_largest_element(std::vector<int> &nums){
    if(nums.size() < 2 )return -1;
    int n=nums.size()-1;
    //THOUGHT 1 = use bubble sort to sort the last two elements of array
    //AFTER = CAN'T use bubble sort for only last two elements as they may be identical
    //THOUGHT 2 = Sort the complete array then iterate through last till 1 swap
    /*
    Implementing thought 2
    Time Complexity : O(N logN)
    Space Complexity : O(1)
    std::sort(nums.begin(),nums.end());
    int i=n;
    while (i>0){
        if(nums[i]>nums[i-1]){
            return nums[i-1] ;
        }
        i--;
    }
    return -1;
    */

    //THOUGHT 3 = Using variables largest and second largest and single iteration of array
    //Time Complexity: O(N)
    //Space Complexity: O(1)
    int secondLargest=std::numeric_limits<int>::min();
    int largest=secondLargest;
    for(auto it : nums){
        if(it>largest){
            secondLargest=largest;
            largest=it;
        }
        else if(it>secondLargest && it<largest){
            secondLargest=it;
        }
    }
    if(secondLargest==std::numeric_limits<int>::min())return -1;
    return secondLargest;
}

int main(){
    int x;
    std::cout << "How many elements to enter : ";
    do{
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums;
    std::cout << "Enter Elements :" << std::endl;
    while(x){
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
        x--;
    }
    std::cout << "The Second largest element is " << second_largest_element(nums);
    std::cout << std::endl;
    return 0;
}