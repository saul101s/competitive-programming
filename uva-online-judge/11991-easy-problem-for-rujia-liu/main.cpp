#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

int n, m;

void solve()
{
	int v = 0, k = 0;
	int i = 1;
	map<int, vi> indices;
	
	while (n--)
	{
		cin >> v;
		indices[v].push_back(i);
		i++;
	}
	
	while (m--)
	{
		cin >> k >> v;
		
		if (indices.find(v) != indices.end() && (int)indices[v].size() < k)
		{
			cout << 0 << endl;
		}
		else
		{
			cout << indices[v][k - 1] << endl;
		}
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


    while (cin >> n >> m)
    {
        solve();
        // cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
