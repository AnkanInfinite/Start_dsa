/*
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays.
The elements in the union must be in ascending order.
The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

sample run:
How many elements to enter in array 1: 4
Enter Elements of array 1 :
1 1 2 6      
How many elements to enter in array 2: 5
Enter Elements of array 2 :
2 2 3 5 6
Array after union of two arrays :
1 2 3 5 6 

Approach: Two pointer
Time Complexity: O(M+N)
Space Complexity: O(M+N)

*/
#include<iostream>
#include<vector>

std::vector<int> union_sorted_array(const std::vector<int> &nums1, const std::vector<int> &nums2){
    std::vector<int> ans;
    size_t i=0,j=0;
    size_t n1=nums1.size(),n2=nums2.size();
    while(i<n1 && j<n2){
        //Create a temporary variable to pick which element to add in array
        int toInsert;
        if(nums1[i]<nums2[j]){
            toInsert=nums1[i];
            i++;//move pointer of array1
        }
        else if(nums1[i]==nums2[j]){
            toInsert=nums1[i];
            i++;j++;//pick anyone and move pointers of both array to avoid duplicates
        }
        else{
            toInsert=nums2[j];
            j++;
        }
        //We add element only if the merged array is empty or previous element is not same
        if(ans.empty() || ans.back() !=toInsert){
            ans.push_back(toInsert);
        }
    }
    //In case we have merged all elements of one array while some elements remain in other we insert all elements of the leftover array sequencially checking for duplicates 
    while(j<n2){
        if(ans.empty() || ans.back() !=nums2[j]){
            ans.emplace_back(nums2[j]);
        }
        j++;
    }
    while(i<n1){
        if(ans.empty() || ans.back() !=nums1[i]){
            ans.emplace_back(nums1[i]);
        }
        i++;
    }
    //return merged array
    return ans;
}

int main(){
    int x;
    std::cout << "How many elements to enter in array 1: ";
    do{
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums1;
    std::cout << "Enter Elements of array 1 :" << std::endl;
    while(x){
        int temp;
        std::cin >> temp;
        nums1.push_back(temp);
        x--;
    }
    std::cout << "How many elements to enter in array 2: ";
    do{
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums2;
    std::cout << "Enter Elements of array 2 :" << std::endl;
    while(x){
        int temp;
        std::cin >> temp;
        nums2.push_back(temp);
        x--;
    }
    std::vector<int> mergedArray=union_sorted_array(nums1,nums2);
    std::cout << "Array after union of two arrays :" << std::endl;
    for(auto it : mergedArray){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;

}