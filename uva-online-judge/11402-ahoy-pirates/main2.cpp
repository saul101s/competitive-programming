#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

void answer_query(bitset<1024000> bs, int lb, int ub, int c)
{
	bitset<1024000> tmp;
	tmp |= (1 << (ub + 1)) - 1;
	tmp ^= (1 << (lb + 1)) - 1;
	
	cout << "C" << c << ": " << (bs & tmp).count() << endl;
}

void solve()
{
	int pairs;
	int times;
	int upd_v;
	int q;
	char query;
	int lb, ub;
	string pirates;
	bitset<1024000> bs;
	bitset<1024000> tmp;
	
	cin >> pairs;
	
	while (pairs--)
	{
		cin >> times >> pirates;
		tmp = bitset<1024000>(pirates);
		
		while (times--)
		{
			bs << pirates.size();
			bs & tmp;
		}
	}
	
	
	cin >> q;
	
	for (int c = 0; c < q; c++)
	{
		upd_v = -1;
		cin >> query >> lb >> ub;
		
		switch (query)
		{
			case 'F':
				upd_v = 1;
				break;
			case 'E':
				upd_v = 0;
				break;
			case 'I':
				upd_v = 2;
				break;
			case 'S':
				answer_query(bs, lb, ub, c);
				break;
		}
		
		if (upd_v >= 0)
		{
			tmp.reset();
			tmp |= (1 << (ub + 1)) - 1;
			tmp ^= (1 << (lb + 1)) - 1;
			
			if (upd_v == 2)
			{
				bs ^= tmp;
			}
			else if (upd_v == 1)
			{
				bs |= tmp;
			}
			else
			{
				bs &= ~tmp;
			}
		}
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
    int c = 1;
    cin >> t;

    while (t--)
    {
		cout << "Case " << c << ":" << endl;
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

