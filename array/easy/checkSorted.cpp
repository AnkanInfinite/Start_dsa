/*
Given an array nums of n integers, return true if the array nums is sorted in non-decreasing order or else false.
*/
#include<iostream>
#include<vector>
bool check(const std::vector<int> &nums){
    for(auto it=nums.begin();it != nums.end() - 1 ; it++){
        if(*it > *(it+1))return false;
    }
    return true;
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
    if(check(nums)){
        std::cout << "The Array is sorted " << std::endl;
    }
    else{
        std::cout << "The Array is not sorted " <<std::endl;
    }
    
    return 0;
}