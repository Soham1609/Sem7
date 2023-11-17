#include <bits/stdc++.h>
using namespace std;

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp) {
    if (ind == -1 || W == 0) {
        return 0;
    }

    if (dp[ind][W] != -1) {
        return dp[ind][W];
    }

    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = 0;

    if (wt[ind] <= W) {
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);
    }

    return dp[ind][W] = max(notTaken, taken);
}

int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n), val(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}
// Time Complexity: O(n * W)
// Space Complexity: O(n * W)