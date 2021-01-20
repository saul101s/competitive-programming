#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int total_trees = 0;
	string name;
	set<string> names;
	unordered_map<string, int> frequencies;
	
	while (getline(cin, name) && name != "")
	{
		names.insert(name);
		frequencies[name]++;
		total_trees++;
	}
	
	for (auto it = names.begin(); it != names.end(); it++)
	{
		printf("%s %.4f\n", (*it).c_str(), ((frequencies[*it] / (float)total_trees) * 100));
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

    int t = 1;
    cin >> t;
    
    cin.ignore(5, '\n');
    cin.ignore(5, '\n');

    while (t--)
    {
        solve();
        
        if (t != 0)
		{
			printf("\n");
		}
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
