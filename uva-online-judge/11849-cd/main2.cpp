#include<bits/stdc++.h>
using namespace std;

int N, M;

void solve()
{
	bitset<1000000001> jack_cds; // 120MB
	int cd = 0;
	int shared = 0;
	
	while (N--)
	{
		cin >> cd;
		jack_cds.set(cd);
	}
	
	while (M--)
	{
		cin >> cd;
		
		if (jack_cds.test(cd))
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

