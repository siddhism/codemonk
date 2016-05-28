#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

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
	ll tc;
	cin >> tc;
	while(tc--){
		string word, reserve;
		string::iterator it; 
		cin >> word >> reserve;
		sort(reserve.begin(), reserve.end());

		// This is how i debugged that reserve.erase(reserve.begin(), 1) should have been => reserve.erase(reserve.begin())
		// while (not reserve.empty()) {
		// 	it = reserve.begin();
		// 	// cout << *it;
		// 	cout << "before " << reserve << endl;
		// 	reserve.erase(reserve.begin());
		// 	cout << "after " << reserve << endl;
		// }

		// sort the reserve word and for every letter in word, see if reserve has a smaller one
		// if yes replace and delete, otherwise move forward

		for (int i = 0; i < word.size(); ++i) {
			if (not reserve.empty()) {
				it = reserve.begin();
				if (int(*it) < int(word[i])) {
					word[i] = *it;
					reserve.erase(reserve.begin());
				}
			}
			else {
				break;
			}
		}
		cout << word << endl;
	}
	return 0;
}