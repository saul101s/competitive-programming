#include<bits/stdc++.h>
using namespace std;

void solve();

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
    scanf("%d", &t);

    while (t--)
    {
        solve();
        printf("\n");
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	int n, k;
	
	scanf("%d %d", &n, &k);
	printf("%d", k ^ (k >> 1));
}
