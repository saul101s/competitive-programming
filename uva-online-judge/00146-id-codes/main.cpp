#include<bits/stdc++.h>
using namespace std;

string input;

void solve()
{
	vector<char> v;
	string nxt_perm = "";
	
	for (int i = 0; i < (int)input.size(); i++)
	{
		v.push_back(input[i]);
	}
	
	if (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < (int)v.size(); i++)
		{
			nxt_perm += v[i];
		}
		
		cout << nxt_perm;
	}
	else
	{
		cout << "No Successor";
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

    getline(cin, input);

    while (input != "#")
    {
        solve();
        cout << "\n";
        
        getline(cin, input);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
