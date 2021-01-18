#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int l = 0, m = 0;
	int clength = 0;
	int lsum = 0;
	int crosses = 0;
	string cbank = "";
	bool is_left = true;
	queue<int> left;
	queue<int> right;
	
	cin >> l >> m;
	l *= 100;
	
	while (m--)
	{
		cin >> clength >> cbank;
		
		if (cbank == "left")
		{
			left.push(clength);
		}
		else
		{
			right.push(clength);
		}
	}
	
	while (left.size() > 0 || right.size() > 0)
	{
		lsum = 0;
		
		if (is_left)
		{
			while ((left.size() > 0) && (lsum + left.front() <= l))
			{
				lsum += left.front();
				left.pop();
			}
		}
		else
		{
			while ((right.size() > 0) && (lsum + right.front() <= l))
			{
				lsum += right.front();
				right.pop();
			}
		}
		
		crosses++;
		is_left = !is_left;
	}
	
	cout << crosses;
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

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
