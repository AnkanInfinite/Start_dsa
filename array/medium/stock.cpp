/*
Given an array arr of n integers, where arr[i] represents price of the stock on the ith day. 
Determine the maximum profit achievable by buying and selling the stock at most once. 

The stock should be purchased before selling it, and both actions cannot occur on the same day.

Example:
Input: arr = [10, 7, 5, 8, 11, 9]
Output: 6
Explanation: Buy on day 3 (price = 5) and sell on day 5 (price = 11), profit = 11 - 5 = 6.

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
*/
#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
/*
Approach 1 :
we select from first to buy and then traverse through rest of the elements 
to find the largest profit
Time Complexity : O(N^2)
Space Complexity : O(1)
*/
int stockBuySell_1(std::vector<int> &prices){
    int maxProfit=std::numeric_limits<int>::min();
    int buyPrice=-1;
    int curProfit=0;
    for(int i=0;i<prices.size();i++){
        buyPrice=prices[i];
        for(int j=i+1;j<prices.size();j++){
            curProfit=prices[j]-buyPrice;
            maxProfit=std::max(maxProfit,curProfit);
        }
    }
    if(maxProfit<0)return 0;
    return maxProfit;
}

/*
Approach 2 : 
We track the minimum price as we traverse the array and
considering if we sell on current day how much profit will we make and track
maximum possible profit

Time Complexity : O(N)
Sapce Complexity : O(1)
*/

int stockBuySell_2(std::vector<int> &prices){
    int minPrice=std::numeric_limits<int>::max();
    int curProfit=0;
    int maxProfit=std::numeric_limits<int>::min();
    for(auto it : prices){
        minPrice=std::min(minPrice,it);
        curProfit=it-minPrice;
        if(curProfit > maxProfit){
            maxProfit=curProfit;
        }
    }
    return maxProfit;
}