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

// typedef pair<ll, ll> PII;
multiset < pair < ll , ll > > great;
multiset < ll > good;
vector < pair < ll , ll > > v;
bool finished [100000 + 10];

int main(){
	ll tc,m,n,i,temp1, temp2, G, H;
	cin >> tc;
	// pair of integers(longs) => denoting skill and proficiency

	while(tc--){
		cin >> n >> m;
		// initialized all visited equals false
		memset(finished, false, sizeof(finished));
		good.clear();                           // clear storage for every case
        great.clear();
        v.clear();
		
		// this are the new ones with desired skill and proficiency level
		for (int i = 0; i < m; ++i) {
			cin >> temp1 >> temp2;
			v.push_back(make_pair(temp1, temp2));
		}

		// this are the old people with skill, prof
		for (int i = 0; i < n; ++i) {
			cin >> temp1 >> temp2;
			great.insert(make_pair(temp1, temp2));
			good.insert(temp1);
		}
		cin >> G >> H;
		ll numGreat = 0, numGood= 0;
		for (int i = 0; i < m; ++i) {
			// for every new candidate first we check if they can get a great combination
			pair<ll, ll> node = v[i];
			if (great.find(node) != great.end()) {    // check if this pair found in the old subjects
				numGreat++; numGood++;
				finished[i] = true;  // mark as selectedto be good pair and great combination
				great.erase(great.find(node));  // erase it from old subject from both great and good combos
				good.erase(good.find(v[i].first)); //
			}
		}
		// Now all great combos are formed, lets check for good ones
		for (int i = 0; i < m; ++i) {
			if (finished[i]) {
				continue; // we can't choose an old subject more than once
			}
			if (good.find(v[i].first) != good.end()) {
				numGood++;
				good.erase(good.find(v[i].first));
				finished[i] = true;
			}
		}
		if (numGood >= G && numGreat >= H) {
			cout << "Great" << endl;
		}
		else if (numGood >= G) {
			cout << "Good" << endl;
		}
		else {
			cout << ":(" << endl;
		}

	}
	return 0;
}
//PS: solved with help of editorial