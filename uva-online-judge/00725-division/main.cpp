#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

int N;

void solve()
{
	bool found = false;
	
	for (int fghij = 1234; fghij <= 98765 / N; fghij++)
	{
		int abcde = fghij * N;
		int tmp, used = (fghij < 10000); // number 0 is used
		tmp = abcde;
		
		while (tmp)
		{
			used |= 1 << (tmp % 10);
			tmp /= 10;
		}
		
		tmp = fghij;
		
		while (tmp)
		{
			used |= 1 << (tmp % 10);
			tmp /= 10;
		}
		
		if (used == (1 << 10) - 1)
		{
			printf("%0.5d / %0.5d = %d\n", abcde, fghij, N);
			found = true;
		}
	}
	
	if (!found)
	{
		printf("There are no solutions for %d.\n", N);
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

	cin >> N;

    while (N != 0)
    {
        solve();
        
        cin >> N;
        
        if (N != 0)
		{
			printf("\n");
		}
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
