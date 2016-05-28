/* My First Template  
   :P
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define P pair<ll, int>
priority_queue< P, vector<P>, greater<P> > q;
ll a[100002];
int ans[100002];
vector<ll> price[100002];
int main()
{
	//freopen("Input.txt", "r", stdin);
	//freopen("SampleOutput.out", "w", stdout);
	int c,n,p,i;
    cin >> c >> p >> n;
    // c = course, p = monk  and p-1 friends, n = already enrolled students
    // solutions n = our p, solutions k = our n
    // push pair < z score, course_number>
    for(i=0; i<n; i++){
        cin >> a[i];
        q.push(mk(a[i], i));
        // push in course_number array of vector<ll> price, the value of i.q. a[i]
        // price array of vector, counts number of students in each course, and latest two
        price[i].push_back(a[i]);
    }
    // Now remaining items should be pushed in q with z score as zero
    for(i=n; i<c; i++){
        q.push(mk(0, i));
    }
    // scan monk and his friend's iqs in a[] now
    for(i=0; i<p; i++){
        cin >> a[i];
    }
    pair<ll, int> z;
    // lets deploy all friends to a course
    for(i=0; i<p; i++) {
        z = q.top();
        // depending on size of vector of price for this particular course
        if(price[z.second].size() == 0) {
            price[z.second].push_back(a[i]); // push into course's bucket
            z.first += a[i]; // increase z value by a[i] (current friend's i.q.)
            q.pop();
            q.push(z); // instead of q.push(mk(z.first, z.second)) like me
            ans[i] = z.second; // answer includes the course number
        }
        // if size is 1,
        else if (price[z.second].size() == 1) {
            price[z.second].push_back(a[i]);
            // z = x * c (x is sum of last two student (z.first + current) 
            // and c is num. of students would be two now)
            z.first = (z.first+a[i])*2;
            q.pop();
            q.push(z);
            ans[i] = z.second;
        }
        else {
            // z value = sum of last two students * num of students enrolled (1 bdhega abhi)
            ll l = price[z.second].size(); // size of array = 5, last one is a[4]
            z.first = (price[z.second][l-1] + a[i]) * (l + 1); // after adding new element new size will be l + 1
            price[z.second].push_back(a[i]);
            ans[i] = z.second;
            q.pop();
            q.push(z);
        }
    }
    // print answer (since course number starts from zero)
    for(i=0; i<p; i++){
        cout << ans[i]+1 << " ";
    }


	return 0;
}