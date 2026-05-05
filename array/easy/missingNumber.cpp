/*
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive),
return the only number missing from the array within this range.
Sample run:
How many elements to enter in array 1: 8
Enter Elements of array 1 :
0 1 3 4 5 6 7 8
Missing Number in array :2

*/
#include<iostream>
#include<vector>
#include<unordered_map>

/*
Approach 1:
storing numbers appeared in a map
and returning the number which has not appeared
Time Complexity: O(N)
Space Complexity: O(N)
*/
int missing_number_1(std::vector<int> &nums){
    std::unordered_map<int,int> mpp;
    int ans;
    for(int i=0;i<=nums.size();i++){
        mpp[i]=0; //creating map from 0 to n to store number of occurances
    }
    for(auto it : nums){
        mpp[it]++;//Updating number of times an integer occurs
    }
    for(auto value : mpp){
        if(!value.second){
            ans=value.first; //we return the integer which occour 0 times that is it is missing
            break;
        }
    }
    return ans;
}

/*
Approach 2:
Since the integers are from 0 till n with increment of 1
we calculate the expected sum by formula S=(n*(n+1))/2
And then Calculate the sum of elements present in Array
After that we get the missing number by substracting them

Time Complexity:O(N)
Space Complexity:O(1)
*/

int missing_number_2(std::vector<int> &nums){
    int n=nums.size();
    long long expectedSum=(n*(n+1))/2; //Prevent overflow of standard 32bit int
    long long sum=0;
    for(auto integer : nums){
        sum+=integer;
    }

    return expectedSum - sum;
}



int main(){
    int x;
    std::cout << "How many elements to enter in array 1: ";
    do{
        std::cin >> x;
    }while(x<1);
    std::vector<int> nums;
    std::cout << "Enter Elements of array 1 :" << std::endl;
    while(x){
        int temp;
        std::cin >> temp;
        nums.push_back(temp);
        x--;
    }
    std::cout << "Missing Number in array :" <<missing_number_2(nums) << std::endl;
    return 0;
}