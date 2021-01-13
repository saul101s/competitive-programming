#include<bits/stdc++.h>
using namespace std;

void solve();

int n;

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

void solve()
{
	int x, y, a, nums = n;
	bool jolly = true;
	vector<bool> differences(nums);
	
	differences.assign(n, 0);
	cin >> x;
	
	if (nums == 1)
	{
		cout << "Jolly";
		return;
	}
	
	nums--; // One number already read
	
	while (jolly && nums--)
	{
		cin >> y;
		
		a = abs(x - y);
		
		if (a < n && !differences[a])
		{
			differences[a] = true;
		}
		else
		{
			jolly = false;
		}
		
		x = y;
	}
	
	if (!jolly)
	{
		while (nums--)
		{
			cin >> y;
		}
	}
	
	cout << (jolly ? "Jolly" : "Not jolly");
}
