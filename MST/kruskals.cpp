// Kruskal's algorithm to find minimum cost from a graph
// It depends on edges. Uses disjoint set union.
// 1. Sort the edges by their weight in non decreasing order.
// 2. Select the edge one by one from beggining.
// 3. If adding an edge forms a cycle -
// 		discard It
//    else
// 		Add the picked edge into the minimum spanning tree.
// O(E(log*)V).


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize() {
	for(int i=0; i<MAX; i++)
		id[i] = i;
}

int root(int x) {
	while(id[x] != x) {
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void union1(int a, int b) {
	int root_a = root(a);
	int root_b = root(b);
	id[root_a] = root_b;
}

long long Kruskal(pair<long long, pair<int, int> > p[]) {
	int x,y;
	long long cost, minimumCost = 0;
	// Lets go over all sorted edges
	// Find if adding the vertex of edge (connecting the edge into graph) forms an cycle.
	// If root of both vertex is same then they will form a cycle.
	for(int i=0; i<edges; i++) {
		// extract vertex endpoint and edge's weight (cost)
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if (root(x) != root(y)){
			minimumCost += cost;
			union1(x, y); // wow here i felt it was so easy to implement
		}
	}
	return minimumCost;
}

int main(){
	int x,y;
	ll weight, minimumCost;
	initialize();

	cin >> nodes >> edges;
	// we will make a pair of weight with the edge
	// pair <long long, pair<int, int> > p[MAX]; 
	// edge is denoted by pair of both vertex

	for(int i=0; i<edges; i++) {
		cin >> x >> y >> weight;
		p[i] = make_pair(weight, make_pair(x,y));
	}

	// sort the edges in non descreasing order of weight
	sort(p, p+edges);
	minimumCost = Kruskal(p);
	cout << minimumCost << endl;
	return 0;
}