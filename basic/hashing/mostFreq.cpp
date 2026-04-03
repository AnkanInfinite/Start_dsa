/*
Given an array nums of n integers, find the most frequent element in it i.e., the element that occurs the maximum number of times.
If there are multiple elements that appear a maximum number of times, find the smallest of them.

constraints:
1 <= n <= 10^5
1 <= nums[i] <= 10^4

output :
Enter how many elements to enter :10
1 1 5 5 5 4  4 4 1 2
The element occouring maximum number of times : 1
*/
//vector is most optimal for smaller constraints but i used map to be usable for larger constraints
#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits>

//First try
int mostFrequentElement(std::vector<int> &nums){
    std::vector<int> mostFrequent;
    std::unordered_map<int,int> mpp;
    for(auto it : nums){
        mpp[it]++;
    } 
    auto it = mpp.begin();
    mostFrequent.emplace_back(it->first) ; //assuming first element to occour most frequently 
    ++it; //skiping first iterator as we assumned it to be most frequent
    for( ;it != mpp.end(); ++it){
        auto last = mostFrequent.back();
        //if same number of occourances
        if(mpp[last] == it->second){
            mostFrequent.push_back(it->first);
        }
        //If we find elements with more occurances
        else if(mpp[last] < it->second){
            mostFrequent.clear();
            mostFrequent.push_back(it->first);
        }
    }
    int min=*mostFrequent.begin(); // we assume first to be minimum
    if(mostFrequent.size() > 1){
        for(auto it : mostFrequent){
            if( it < min){
                min =it;
            }
        }
    }
    return min;
}

//after expalination and help of gemini
int mostFrequentElement1(std::vector<int> &nums){
    int ans=std::numeric_limits<int>::max();
    int highetFreq=0;
    std::unordered_map<int,int> mpp;
    for(auto it : nums){
        mpp[it]++;
    }
    for(auto it : mpp){
        if(highetFreq < it.second){
            highetFreq=it.second;
            ans=it.first;
        }
        else if(highetFreq == it.second && ans > it.first){
            ans=it.first;//we keep the smaller of the most occouring element
        }
    }
    return ans;
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
    int ans = mostFrequentElement1(nums);
    std::cout << "The element occouring maximum number of times : " << ans << std::endl;
    return 0;
}