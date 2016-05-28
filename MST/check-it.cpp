#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
#define dbg2(x,y) { cout << #x << " : " << (x) << " , " << #y << " : " << (y) << endl; }
 
using namespace std;
 
// strategy:
// the edge numbers which are included should cover all the vertices => yes
 
// What is a Spanning Tree?
// Given an undirected and connected graph G = (V, E), a spanning tree of the graph G 
// is a tree that spans G (that is, it includes every vertex of G) 
// and is a subgraph of G (every edge in the tree belongs to G)
 
const int MAX = 1e5 + 5;
pair<ll, ll> p[MAX];
ll nodes, edges;
 
int main(){
	ll x,y;
	ll tc;
	cin >> tc;
	while(tc--) {
		cin >> nodes >> edges;
 
		set <ll> all_nodes;
		set<ll>::iterator it;

		for(ll i=1; i<=edges; i++) {
			cin >> x >> y;
			p[i] = make_pair(x,y);
		}

		// we have a array of all edges containing there vertices
		// F*** man i wasted whole day on this problem because re-reading problem
		// statement it said nodes-1, i was doing edges-1 confusion between N, M
		// Lessons: Always use same variable name as problem in competitive coding, maybe?
		for (int i = 1; i <= nodes-1; ++i) {
			cin >> x;
			ll temp1 = p[x].first;
			ll temp2 = p[x].second;
			// dbg2(temp1, temp2);
			all_nodes.insert(temp1);
			all_nodes.insert(temp2);
		}
 
		// for every edge scan the edge's vertices if it completes all the vertices then yes

		// for (it = all_nodes.begin(); it != all_nodes.end(); ++it) {
		// 	cout << *it << " ";
		// }
		// cout << endl;
		if (all_nodes.size() == nodes) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		all_nodes.clear();
	}
 
 
	return 0;
}
