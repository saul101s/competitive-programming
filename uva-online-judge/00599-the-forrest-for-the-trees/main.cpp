#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

void solve()
{
	string line;
	bitset<26> has_edge;
	int v = 0;
	int e = 0;
	int acorns = 0;
	int trees = 0;
	
	while (getline(cin, line) && line[0] != '*')
	{
		has_edge.set(line[1] - 'A');
		has_edge.set(line[3] - 'A');
		e++;
	}
	
	getline(cin, line);
	
	v = (line.size() / 2) + 1;
	acorns = v - has_edge.count();
	trees = v - e - acorns;
	
	cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).";
	
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

    while (t--)
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
