#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		int sz = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sz = max(sz, abs(a[i])); // note:  don't forget to take the absolute value
		}
		// maintain the frequency of all elements (make sure to take its absolute value)
		vector<int> counter(sz + 1, 0);
		for (int i = 0; i < n; i++) {
			counter[abs(a[i])]++;
		}   
		// for all numbers except 0, there can be at most 2 different numbers (1 positive & 1 negative)
		// for 0, there can be at most 1 number since we cannot negate 0 (-1 * 0 = 0 itself)
		int ans = 0;
		for (int i = 0; i < (int) counter.size(); i++) {
			if (i == 0) {
				ans += (counter[i] >= 1 ? 1 : counter[i]);
			} else {
				ans += (counter[i] >= 2 ? 2 : counter[i]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}