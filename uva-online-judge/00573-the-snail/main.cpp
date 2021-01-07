#include<bits/stdc++.h>
using namespace std;

void solve();

int H, U, D, F;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    scanf("%d %d %d %d", &H, &U, &D, &F);

    while (H != 0)
    {
        solve();
        printf("\n");
        
        scanf("%d %d %d %d", &H, &U, &D, &F);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	int days = 0;
	float current_height = 0;
	float height_per_day = U;
	float height_lost_per_fatigue = U * ((float)F / 100);
	
	while (true)
	{
		current_height += height_per_day;
		height_per_day = max(height_per_day - height_lost_per_fatigue, 0.0f);
		days++;
		
		if (current_height > H)
		{
			break;
		}
		
		current_height -= D;
		
		if (current_height < 0)
		{
			break;
		}
	}
	
	if (current_height < 0)
	{
		printf("failure");
	}
	else
	{
		printf("success");
	}
	
	printf(" on day %d", days);
}
