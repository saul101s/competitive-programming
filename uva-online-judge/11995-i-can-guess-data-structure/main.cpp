#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

int n;

void solve()
{
	int a, b;
	stack<int> s;
	queue<int> q;
	priority_queue<int> pq;
	
	bool is_s, is_q, is_pq;

    is_s = is_q = is_pq = true;

    while (n--) {
		cin >> a >> b;

		if (a == 1)
		{
			if (is_s)
				s.push(b);
			if (is_q)
			  q.push(b);
			if (is_pq)
			  pq.push(b);
		} 
		else 
		{ // a == 2;
			if (is_s) {
				if (s.empty() || s.top() != b)
				{
					is_s = false;
				}
				else
				{
					s.pop();
				}
			}
			
			if (is_q)
			{
				if (q.empty() || q.front() != b)
				{
					is_q = false;
				}
				else
				{
					q.pop();
				}
			}
			
			if (is_pq)
			{
				if (pq.empty() || pq.top() != b)
				{
					is_pq = false;
				}
				else
				{
					pq.pop();
				}
			}
		}
    }

    if (!is_s && !is_q && !is_pq) {
      cout << "impossible";
    } else if (is_s && !is_q && !is_pq) {
      cout << "stack";
    } else if (!is_s && is_q && !is_pq) {
      cout << "queue";
    } else if (!is_s && !is_q && is_pq) {
      cout << "priority queue";
    } else {
      cout << "not sure";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    
    while (cin >> n)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
