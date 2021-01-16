#include<bits/stdc++.h>
using namespace std;

constexpr int MINUTES = 1000000;
int n, m;

void solve()
{
	int start = 0, end = 0, interval = 0;
	bool conflict = false;
	bitset<MINUTES> minutes;
	
	while (n-- && !conflict)
	{
		cin >> start >> end;
		
		for (int i = start; i < end && !conflict; i++)
		{
			// Test conflict
			if (minutes.test(i))
			{
				conflict = true;
			}
			else
			{
				minutes.set(i);
			}
		}
	}
	
	while (m-- && !conflict)
	{
		cin >> start >> end >> interval;
		
		while (end < MINUTES && !conflict)
		{
			for (int i = start; i < end && !conflict; i++)
			{
				// Test conflict
				if (minutes.test(i))
				{
					conflict = true;
				}
				else
				{
					minutes.set(i);
				}
			}
			
			start += interval;
			end += interval;
		}
	}
	
	cout << (conflict ? "CONFLICT" : "NO_CONFLICT");
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

    cin >> n >> m;

    while (n || m)
    {
        solve();
        cout << "\n";
        
        cin >> n >> m;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
