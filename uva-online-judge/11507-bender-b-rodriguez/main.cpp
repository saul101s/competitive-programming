#include<bits/stdc++.h>
using namespace std;

void solve();

int L;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    
    scanf("%d", &L);

    while (L)
    {
        solve();
        printf("\n");
        
        scanf("%d", &L);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	char bend[3];
	string dir = "+x";
	
	L--;
	
	while (L--)
	{
		scanf("%s", bend);
		
		if (strcmp(bend, "+z") == 0)
		{
			if (dir == "+x")
			{
				dir = "+z";
			}
			else if (dir == "-x")
			{
				dir = "-z";
			}
			else if (dir == "+z")
			{
				dir = "-x";
			}
			else if (dir == "-z")
			{
				dir = "+x";
			}
		}
		else if (strcmp(bend, "-z") == 0)
		{
			if (dir == "+x")
			{
				dir = "-z";
			}
			else if (dir == "-x")
			{
				dir = "+z";
			}
			else if (dir == "+z")
			{
				dir = "+x";
			}
			else if (dir == "-z")
			{
				dir = "-x";
			}
		}
		else if (strcmp(bend, "+y") == 0)
		{
			if (dir == "+x")
			{
				dir = "+y";
			}
			else if (dir == "-x")
			{
				dir = "-y";
			}
			else if (dir == "+y")
			{
				dir = "-x";
			}
			else if (dir == "-y")
			{
				dir = "+x";
			}
		}
		else if (strcmp(bend, "-y") == 0)
		{
			if (dir == "+x")
			{
				dir = "-y";
			}
			else if (dir == "-x")
			{
				dir = "+y";
			}
			else if (dir == "+y")
			{
				dir = "+x";
			}
			else if (dir == "-y")
			{
				dir = "-x";
			}
		}
	}
	
	printf("%s", dir.c_str());
}
