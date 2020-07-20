#include<bits/stdc++.h>
typedef int in;
#define int long long
using namespace std;

int solve(vector<int>arr) {
	vector<int>dp;
	int n = arr.size();
	dp.resize(n);
	dp[0] = 0;
	if (n >= 2) {
		dp[1] = abs(arr[1] - arr[0]);
	}

	for (int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 2] + abs(arr[i] - arr[i - 2]), dp[i - 1] + abs(arr[i] - arr[i - 1]));
	}

	return dp[n - 1];

}

in main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// cout << "hoho";
	int n;
	cin >> n;
	vector<int>arr;
	arr.resize(n);
	vector<int>dp;
	dp.resize(n);
	for (int i = 0; i < n; i++)
		dp[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << solve(arr);

}

