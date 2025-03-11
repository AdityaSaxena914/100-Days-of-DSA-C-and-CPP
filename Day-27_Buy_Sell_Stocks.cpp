// 📌 Problem: Best Time to Buy and Sell Stock (Leetcode #121)
// 🔹 Problem Statement:
// You are given an array prices[], where prices[i] represents the price of a stock on day i.
// Find the maximum profit you can achieve by buying one stock and selling one later.

// You cannot sell before buying.
// If no profit can be made, return 0.

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
void insert(vector<int> &prices, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
}
int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }
    return maxProfit;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> prices(n);
    cout << "Enter the elements of the array: ";
    insert(prices, n);
    cout << "\nEntered Array is:\n";
    for (int i : prices)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << "The maximum profit is: " << maxProfit(prices) << endl;

    return 0;
}