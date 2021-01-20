#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int c, sid, index = 1;
	int count = 0;
	int _max = 0;
	map<int, int> indices;
	map<int, int>::iterator it;
	
	cin >> c;
	
	while (c--)
	{
		cin >> sid;
		
		it = indices.find(sid);
		
		if (it != indices.end())
		{
			_max = max(_max, count);
			
			if (index - (*it).second <= count)
			{
				count = index - (*it).second;
			}
			else
			{
				count++;
			}
			
			(*it).second = index;
		}
		else
		{
			indices.insert(it, make_pair(sid, index));
			count++;
		}
		
		index++;
	}
	
	_max = max(_max, count);
	
	cout << _max;
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
