#include<bits/stdc++.h>
using namespace std;

int D;

void solve()
{
	int corners = 1 << D;
	int potency = 0, max_potency = 0;
	int weights[corners];
	int potencies[corners];
	
	for (int i = 0; i < corners; i++)
	{
		cin >> weights[i];
	}
	
	for (int i = 0; i < corners; i++)
	{
		potency = 0;
		
		// Calculate potency
		for (int j = 0; j < D; j++)
		{
			// cerr << "Corner: " << i << ", neighbour: " << (i ^ 1 << j) << endl;
			potency += weights[i ^ 1 << j];
		}
		
		potencies[i] = potency;
	}
	
	for (int i = 0; i < corners; i++)
	{
		for (int j = 0; j < D; j++)
		{
			potency = potencies[i] + potencies[i ^ 1 << j];
			
			if (potency > max_potency)
			{
				max_potency = potency;
			}
		}
	}
	
	
	cout << max_potency;
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

    while (cin >> D)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
