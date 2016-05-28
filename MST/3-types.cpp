#include <bits/stdc++.h>
using namespace std;
int n, m;
int a,b,c,ans;
const int MAX = 1e4 + 5;
int w[1<<20], W[1<<20][3];

// differnet implementation of disjoint set union (DSU)
int get(int x){
	if(w[x]==x)
		return x;
	return w[x]=get(w[x]); // returning assignment here
}

void merge(int x, int y){
	w[x] = y;
}

// modified version for our question, also push type with the get/merge
// w is overall graph, W[node][1] is for males, W[node][2] is female one

int get1(int x, int y) {
	if (W[x][y]==x) {
		return x;
	}
	return get1(W[x][y], y);
}

void merge1(int a, int b, int c) {
	// here c is type
	W[a][c] = b;
}


int main() {
	int tc;
	// cin >> tc;
	// while(tc--){
		// cout << tc << " was tc " << endl;
		cin >> n >> m;
		// initialize , make everyone root of itself in overall, men and womens graph
		for (int i = 1; i <= n; ++i) {
			w[i] = W[i][1] = W[i][2] = i;
		}

		for (int i = 1; i <= m; ++i) {
			cin >> a >> b >> c;
			for (int j = 1; j <= 2; ++j) {
				if (c&j) {
					// && vs & difference couldn't debug for ours
					// if 1&1 = 1, 2&2 = true, 1&2 or 2&1 = false (same true, diff false)
					// so for c type only get node of that type, type 1 to type 1 me jao , 2 to 2 me (hindi)
					int ta = get1(a, j);
					int tb = get1(b, j);
					if(ta==tb)
						continue;
					merge1(ta, tb, j);
				}
			}
			// at this point all type 1 and type 2 edges are connected
			if (c != 3) {
				continue;
			} // don't know why this condition was necessary
			a = get(a);
			b = get(b); // now we are getting overall root of the a and b node
			if(a==b){
				continue; // they are already connected
			}
			merge(a, b);
			ans++; // as many merges of type 3 increase count
		}
		// so we have handled all edges if they were type 1/2/3
		// our main motive was to find ans, we need to take as few as possible so we take max 3rd type
		// jitne ans edge h they are most important, as these are 3rd type after these we need
		// 2n-2-2k (k=ans here) more edges need to be connected
		// read https://www.hackerearth.com/code-monk-minimum-spanning-tree/algorithm/3-types/editorial/
		// n-1 and n-1 for each men and women graph (1st and 2nd type edges) and 2k nodes are connected
		// per k 3rd type edge (they do two merge)
		ans = (n-1-ans)*2 + ans;

		// now check for connectivity connectedComponents > 1 means disconnected
		// if all nodes are connected = they are there own root, if not increase connectedComponents
		int cnt = 0;
		// cout << ans << n-1-ans << endl;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <=2; ++j) {
				if(W[i][j]==i)
					++cnt;
			}
		}
		// for (int i = 1; i <=n; ++i) {
		// 	cout << w[i] << " " << W[i][1] << " " << W[i][2] << endl;
		// }
		if (cnt>2) {
			cout << -1 << endl;
			return 0;
		}
		cout << m-ans << endl; // as m are total nodes, as few as possible = ans, max. destroyed = m-ans

	// }
	return 0;
}
// PS: solved with help of editorial