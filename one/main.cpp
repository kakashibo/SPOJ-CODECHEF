#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define i64 long long


int main () {
	//freopen ("in.txt", "r", stdin);
	int n, min1, min2, min3, max1, max2, max3, res1, res2, res3;
	cin>>n>>min1>>max1>>min2>>max2>>min3>>max3;

	for (int i=max1; i>=min1;i--) {
		//check that this i is ok
		if (n-i < min2+min3) continue;
		int rem = n-i;
		if(max2+max3 < rem) continue;
		int res2 = min (max2, rem-min3);
		int res3 = n-i-res2;
		cout<<i<<" "<<res2<<" "<<res3<<endl;
		return 0;
	}
	return 0;
}