#include<bits/stdc++.h>
using namespace std;

void solve();

int c;

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
    c = 1;
    scanf("%d", &t);

    while (t--)
    {
        solve();
        printf("\n");
        c++;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	int students, student_speed, max_speed;
	
	scanf("%d %d", &students, &max_speed);
	students--;
	
	while (students--)
	{
		scanf("%d", &student_speed);
		
		if (student_speed > max_speed)
		{
			max_speed = student_speed;
		}
	}
	
	printf("Case %d: %d", c, max_speed);
}
