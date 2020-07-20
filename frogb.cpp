#include<bits/stdc++.h>
typedef int in;
#define int long long
using namespace std;

// int solve(vector<int>arr, int pos, int k, vector<int>&dp) {
// 	int n = arr.size();
// 	if (pos == n - 1) {
// 		return 0;
// 	}
// 	if (dp[pos] != -1) {
// 		return dp[pos];
// 	}

// 	int res = INT_MAX;

// 	for (int i = 1; i <= k; i++) {
// 		if (pos + i <= n - 1) {
// 			res = min(res, abs(arr[pos] - arr[i + pos]) + solve(arr, pos + i, k, dp));
// 		}
// 	}
// 	return dp[pos] = res;
// }

int solve(vector<int>arr, int k) {

	vector<int>dp;
	dp.resize(arr.size());
	int n = arr.size();
	dp[0] = 0;
	dp[1] = abs(arr[1] - arr[0]);
	for (int i = 2; i < n; i++) {
		int res = INT_MAX;
		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				res = min(res, abs(arr[i] - arr[i - j]) + dp[i - j]);
			}
		}

		dp[i] = res;

	}
	return dp[n - 1];
}
in main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// cout << "hoho";
	int n, k;
	cin >> n >> k;

	vector<int>arr;
	arr.resize(n);
	vector<int>dp;
	dp.resize(n);
	for (int i = 0; i < n; i++)
		dp[i] = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << solve(arr, k);

}

