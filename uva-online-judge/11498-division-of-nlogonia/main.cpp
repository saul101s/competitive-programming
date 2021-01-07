#include<bits/stdc++.h>
using namespace std;

void solve();

int N, M;

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

    while (t)
    {
		scanf("%d %d", &N, &M);
		
		while (t--)
		{
			solve();
			printf("\n");
		}
		
		scanf("%d", &t);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	int X, Y;
	char vertical, horizontal;
	
	scanf("%d %d", &X, &Y);
	
	if (X == N || Y == M)
	{
		printf("divisa");
		return;
	}
	
	if (Y > M)
	{
		vertical = 'N';
	}
	else
	{
		vertical = 'S';
	}
	
	if (X > N)
	{
		horizontal = 'E';
	}
	else
	{
		horizontal = 'O';
	}
	
	printf("%c%c", vertical, horizontal);
	
}
