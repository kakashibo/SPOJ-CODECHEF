#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <fstream>
#include <list>
#include <set>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <complex>
#include <cmath>
#include <sstream>
#include <deque>

using namespace std;


long long dp[200001][11];

long long a[200001];

int main() {
	int n,k,x;
	cin >> n >> k >> x;
	for(int i = 1 ; i <= n ;i++) {
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ;i++) {
		dp[i][0] = a[i];
		for(int j = 1 ; j <= k ;j++) {
			dp[i][j] = dp[i][j-1]*x;
		}
	}
	for(int i = 2 ; i <= n ;i++) {
		for(int j = 0 ; j <= k ;j++) {
			for(int l = 0 ; l <= j ;l++) {
				dp[i][j] = max(dp[i][j] , (dp[i-1][l]|dp[i][j-l]) );
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i  <= k ; i++) {
		ans = max(ans , dp[n][i]);
	}
	cout << ans << endl;
	return 0;
}