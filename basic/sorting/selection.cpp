/*
Given an array of integers nums, sort the array in non-decreasing order using the selection sort algorithm and return the sorted array.
A sorted array in non-decreasing order is an array where each element is greater than or equal to all previous elements in the array.

output:
Enter how many elements to enter :8
2 5 6 3 2 1 4 2
The elements after sorting : 
1 2 2 2 3 4 5 6 
*/

#include<iostream>
#include<vector>
/*
We consider Two arrays initially first having 0 elements and second the entire array.
we consider the array first to be sorted and in second array take the first element and swap it with the smallest element in the second array.
Now the first sorted array contains one element and the second unsorted array the rest of the elements.
We repeat this process till only one element remains in the second array as single element is always sorted.
*/
std::vector<int> selection_sort(std::vector<int> &nums){
    for(int i=0;i<nums.size() - 1;i++){
        int min_element_index=i;
        for(int j=i;j<nums.size();j++){
            if(nums[min_element_index]>nums[j]){
                min_element_index=j;
            }
            
        }
        if(min_element_index != i){
            int temp=nums[i];
            nums[i]=nums[min_element_index];
            nums[min_element_index]=temp;
        }
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
    std::vector<int> ans = selection_sort(nums);
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : ans){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}