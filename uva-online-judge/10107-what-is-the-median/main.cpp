#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int x, mid, median;
	bool odd = false;
	vector<int> v;
	
	while (cin >> x)
	{
		v.push_back(x);
		odd = !odd;
		
		mid = v.size() / 2;
		
		if (odd)
		{
			nth_element(v.begin(), v.begin() + mid, v.end());
			median = v[mid];
		}
		else
		{
			nth_element(v.begin(), v.begin() + mid, v.end());
			median = v[mid];
			nth_element(v.begin(), v.begin() + mid - 1, v.end());
			median += v[mid - 1];
			median /= 2;
		}
		
		cout << median << endl;
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
    
	solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
