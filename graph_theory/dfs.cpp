#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector <int> adj[10];
bool visited[10];


void dfs(int s) {
	visited[s] = true;
	for(i=0; i<adj[s].size(); i++) {
		if(visited[adj[s][i]] == false) {
			dfs(adj[s][i]);
		}
	}
}


// Initialize all nodes , set visited to false for all
void initialize(){
	for(i=0; i<10; i++){
		visited[i] = false;
	}
}

int main(){
	ll nodes, edges, connectedComponents
	cin >> nodes;
	cin >> edges;
	for (ll i=0; i<edges; i++) {
		cin >> x >> y;
		// Undirected graph
		adj[x].push_back(y);
		adj[y].push_back(x);		
	}
	initialize()

	for(i=0; i<nodes; i++) {
		if (visited[i] == false) {
			dfs(i);
			connectedComponents++;
		}
	}
	cout << "connectedComponents " << connectedComponents << endl;
	return 0;
}