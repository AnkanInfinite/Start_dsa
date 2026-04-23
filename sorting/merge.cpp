/*
Given an array of integers, nums,sort the array in non-decreasing order using the merge sort algorithm. Return the sorted array.
A sorted array in non-decreasing order is one in which each element is either greater than or equal to all the elements to its left in the array.

sample run:
Enter how many elements to enter :12
13  4324 23 42 34 2 34 2 34 23  53252 35 
The elements after sorting : 
2 2 13 23 23 34 34 34 35 42 4324 53252 

Time Complexity :
   O(N log N)
Space Complexity:
   O(N)
*/

#include<iostream>
#include<vector>
//function where two individually sorted parts of array merges into a single sorted array
void merge(std::vector<int> &arr , int low , int mid , int high){
    std::vector<int> temp;
    int left=low; //Start of 1st part of array
    int right=mid+1;//Start of second part of array
    //Since both parts of array are sorted individually we compare the elements sequencially of both part of array till either part is fully traversed.
    while(left <= mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    //if first part of array is fully traversed and second part still has elements
    //It means we can directly add rest of the elements into our sorted array
    while(left>mid && right <=high){
        temp.push_back(arr[right]);
        right++;
    }
    //Similarly if second part of array is fully traversed and first part still has elements
    while(right>high && left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    //now array is modified according to sorted order
    for(int i=low ; i<=high ; i++){
        //Since temp stores from index 0 we use i - low which starts from 0
        //And Since we may be modifying part of array such as from index 3 to 8 with individually sorted parts 3 to 5 and 6 to 8 
        //so our low index can be any integer 3,4,2,1,0 and NOT ONLY 0 hence we can't directly start from 0 index for the temp array
        arr[i]=temp[i-low];
    }
}

void merge_sort(std::vector<int> &arr , int low , int high){
    //If only one element then return as base condition
    if(low>=high) return;
    //Dividing the single array into two parts
    int mid=(low+high)/2;
    //Sorting the first part
    merge_sort(arr,low,mid);
    //after first part is sorted WE sort the second part
    merge_sort(arr,mid+1,high);
    //After both parts of the array are individually sorted we merge them into a single sorted array
    merge(arr,low,mid,high);
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
    merge_sort(nums,0,nums.size()-1);
    std::cout << "The elements after sorting : " << std::endl;
    for(auto it : nums){
        std::cout << it <<' ';
    }
    std::cout << std::endl;
    return 0;
}