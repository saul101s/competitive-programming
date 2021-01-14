#include<bits/stdc++.h>
using namespace std;

int SZ, P;

enum direction
{
	UP = 0,
	DOWN = 1,
	LEFT = 2,
	RIGHT = 3
};

void solve()
{
	int x, y, steps, max_steps = 1;
	direction dir = UP;
	y = ceil(SZ / 2.0f);
	x = ceil(SZ / 2.0f);
	
	// cerr << "[" << y << ", " << x << "]" << endl;
	
	P--;
	while (P > 0)
	{
		steps = min(max_steps, P);
		
		// cerr << max_steps << " - " << P << " --> " << steps << " - " << dir << endl;
		
		switch (dir)
		{
			case UP:
				y += steps;
				dir = LEFT;
				break;
			case DOWN:
				y -= steps;
				dir = RIGHT;
				break;
			case LEFT:
				x -= steps;
				dir = DOWN;
				max_steps++;
				break;
			case RIGHT:
				x += steps;
				dir = UP;
				max_steps++;
				break;
		}
		
		P -= steps;
	}
	
	cout << "Line = " << y << ", column = " << x << ".";
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

    cin >> SZ >> P;

    while (SZ && P)
    {
        solve();
        cout << "\n";
        
        cin >> SZ >> P;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
