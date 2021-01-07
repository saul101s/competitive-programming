#include<bits/stdc++.h>
using namespace std;

void solve();

int c = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

	int t;
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
	int s1, s2, s3;
	
	scanf("%d %d %d", &s1, &s2, &s3);
	vector<int> v = {s1, s2, s3};
	
	sort(v.begin(), v.end());
	
	printf("Case %d: %d", c++, v[1]);
}
