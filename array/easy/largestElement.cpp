/*
Given an array of integers nums, return the value of the largest element in the array

sample run:
How many elements to enter : 12
Enter Elements :
1 5 4 8 4 5 1 8 1 2 125  1 0 5 5  
The largest element is 125

Time complexity: O(N)
Space Complexity: O(1)
*/
#include<iostream>
#include<vector>

int largest_element(std::vector<int> &nums){
    int largest=nums[0];
    for(auto it : nums){
        if(it>largest)largest=it;
    }
    return largest;
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
    std::cout << "The largest element is " << largest_element(nums);
    std::cout << std::endl;
    return 0;
}