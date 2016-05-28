#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define pb push_back
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define mset(x,v) memset(x, v, sizeof(x))
#define all(x) x.begin(),x.end()
#define dbg(x) { cout << #x << " : " << (x) << endl; }
#define dbg2(x,y) { cout << #x << " : " << (x) << " , " << #y << " : " << (y) << endl; }
#define MOD 1000000007

using namespace std;
pair<ll, ll> p;

int main(){
	ll c, p, n, i, temp;
	vector<ll>::iterator it, it2;
	cin >> c >> p >> n;
	vector<pair<ll, ll>> existing[n], waiting[p];
	priority_queue<pair<ll, ll>> pq;
	// insert n students who have already taken courses to their course number vector
	// vectors contains courses with their <z factors, number of students>
	// pq contains all vectors in sorted z factor order with course number
	for(i=0; i<n; i++) {
		cin >> temp;
		// every course bucket contains one student, so thats z factor too
		existing[i].push_back(make_pair(temp, 1));
	}
	// monk and his friends
	for(i=0; i<p; i++) {
		cin >> temp;
		waiting[i].push_back(make_pair(temp, 1));
	}
	// if number of students already applied is smaller than courses, 
	// insert them to existing list
	if(n < c){
		ll remaining = c - n;
		// get from waiting list and put into courses vectors
		for(i=0; i<remaining; i++){
			ll course_number = n+i;
			existing[course_number].push_back(make_pair(waiting[i].first, 1));
			cout << course_number << " "; // also printed result here
		}
	}

	// Prepare pq with z factors and course number
	for(i=0;i<c;i++){
		pq.push(make_pair(existing[i].first, i));
	}
	// Now everyone will go according to course 's z score
	// z = x * c (x is last two students)
	ll remaining = p - c;
	for(i=0; i<remaining; i++){
		ll friend_number = i+c;
		// z = x * c (c course number) (x sum of last_two people)
		z_factor = waiting[friend_number].first;
		// was framing it write here i gave up
	}





	return 0;
}