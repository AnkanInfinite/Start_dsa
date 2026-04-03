/*
Given an array nums of size n which may contain duplicate elements.
Rreturn a list of pairs where each pair contains a unique element from the array and its frequency in the array.
You may return the result in any order, but each element must appear exactly once in the output.

constraints:
1 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9

output :
Enter how many elements to enter :10
1 2 5 4 2 1 2 5 3 1
3->1
4->1
5->2
2->3
1->3
*/
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> countFrequencies(vector<int>& nums) {
    unordered_map<int,int> mpp;
    vector<vector<int>> ans;
    for(auto it : nums){
        mpp[it]++;
    }
    for(auto it : mpp){
       ans.push_back({it.first,it.second});
    }
    return ans;
}

int main(){
    int x;
    do{
        cout << "Enter how many elements to enter :";
        cin >> x;
    }while(x<1);
    vector<int> nums;int temp;
    while(x){
        cin >> temp;
        nums.push_back(temp);
        x--;
    }
    vector<vector<int>> ans = countFrequencies(nums);
    for(auto it : ans){
        cout << it[0] << "->" << it[1] << endl;
    }
    return 0;
}

