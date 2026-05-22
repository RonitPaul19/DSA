// You are given an array of prices where prices[i] is the price of a given
// stock on an ith day. You want to maximize your profit by choosing a single
// day to buy one stock and choosing a different day in the future to sell that
// stock. Return the maximum profit you can achieve from this transaction. If
// you cannot achieve any profit, return 0.
#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> prices) {
  int mini = prices[0];
  int maxProfit = 0;

  for (int i = 0; i < prices.size(); i++) {
    int cost = prices[i] - mini;
    maxProfit = max(maxProfit, cost);
    mini = min(mini, prices[i]);
  }

  return maxProfit;
}

int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int result = maximumProfit(prices);
  cout << result;
  return 0;
}
