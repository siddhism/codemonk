#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define mp make_pair
#define pb push_back
#define all(a) a.begin(),a.end()
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define mset(x,v) memset(x, v, sizeof(x))
#define dbg(x) { cout << #x << " : " << (x) << endl; }
#define dbg2(x,y) { cout << #x << " : " << (x) << " , " << #y << " : " << (y) << endl; }
#define MOD 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define whiletc int t;cin>>t;while(t--)

using namespace std;

int main(){
	ll tc,n,i,j,x,temp;
	cin >> tc;
	std::vector<int> positives, negatives;
	std::vector<int>::iterator it;
	bool has_zero = false;
	while(tc--){
		// initialization
		has_zero = false;
		positives.clear();
		negatives.clear();

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> temp;
			if (temp < 0) {
				negatives.pb(temp);
			}
			else if(temp > 0) {
				positives.pb(temp);
			}
			else {
				has_zero = true;
			}
		}

		ll high=1, low=1;
		if (has_zero && negatives.empty()) {
			low = 0;
		}
		if (has_zero && positives.empty()) {
			high = 0;
		}
		if (not positives.empty()) {
			sort(all(positives));
			for (it = positives.begin(); it != positives.end(); ++it) {
				high *= *it;
				if (not negatives.empty()) { // If negatives are not empty we would multiply all in lowest score
					low *= *it;
				}
			}
			if (negatives.empty()) { // If no negatives pick only first one
				low *= *positives.begin();
			}
		}

		if (not negatives.empty()) {
			sort(all(negatives));
			// if even number of negative numbers => high me sare lenge, 
			// otherwise ek last wala chhod denge -5 -4 -3

			if (negatives.size()%2==0) {
				for (it=negatives.begin(); it!=negatives.end() ; ++it) {
					high *= *it;
					low *= *it;
				}
				// since minimum needs all negatives when negatives are in even, skip multiplying last one
				low /= *(negatives.end()-1);
			}
			else {
				for (it=negatives.begin(); it!=negatives.end()-1 ; ++it) {
					high *= *it;
					low *= *it;
				}
				// since minimum needs all negatives when negatives are in odd, multiply by last one
				low *= *it;
				if (positives.empty() && n==1) { // If no positives pick only first one TC: n =1 , -1
					high *= *it;
				}
			}
		}
		cout << high << " " << low << endl;

	}
	return 0;
}