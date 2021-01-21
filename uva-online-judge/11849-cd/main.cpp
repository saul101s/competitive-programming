#include<bits/stdc++.h>
using namespace std;

int N, M;

void solve()
{
	unordered_set<int> jack_cds;
	int cd = 0;
	int shared = 0;
	
	while (N--)
	{
		cin >> cd;
		jack_cds.insert(cd);
	}
	
	while (M--)
	{
		cin >> cd;
		
		if (jack_cds.find(cd) != jack_cds.end())
		{
			shared++;
		}
	}
	
	cout << shared;
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

    cin >> N >> M;

    while (N || M)
    {
        solve();
        cout << "\n";
        
        cin >> N >> M;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
