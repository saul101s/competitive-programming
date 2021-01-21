#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int B, SG ,SB;
	
	cin >> B >> SG >> SB;
	
	int power = 0;
	int used_bf = 0;
	pair<int, int> battle;
	priority_queue<int> green_t;
	priority_queue<int> blue_t;
	pair<int, int> BF[B];
	
	while (SG--)
	{
		cin >> power;
		green_t.push(power);
	}
	
	while (SB--)
	{
		cin >> power;
		blue_t.push(power);
	}
	
	while (green_t.size() > 0 && blue_t.size() > 0)
	{
		while (green_t.size() > 0 && blue_t.size() > 0 && used_bf < B)
		{
			BF[used_bf++] = make_pair(green_t.top(), blue_t.top());
			green_t.pop();
			blue_t.pop();
		}
		
		for (int i = 0; i < used_bf; i++)
		{
			battle = BF[i];
			
			if (battle.first > battle.second)
			{
				green_t.push(battle.first - battle.second);
			}
			else if (battle.first < battle.second)
			{
				blue_t.push(battle.second - battle.first);
			}
		}
		
		used_bf = 0;
	}
	
	if (green_t.size() > 0)
	{
		cout << "green wins" << endl;
		
		while (green_t.size() > 0)
		{
			cout << green_t.top() << endl;
			green_t.pop();
		}
	}
	else if (blue_t.size() > 0)
	{
		cout << "blue wins" << endl;
		
		while (blue_t.size() > 0)
		{
			cout << blue_t.top() << endl;
			blue_t.pop();
		}
	}
	else
	{
		cout << "green and blue died" << endl;
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
    cin >> t;

    while (t--)
    {
        solve();
        
        if (t != 0)
		{
			cout << "\n";
		}
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
