#include<bits/stdc++.h>
using namespace std;

void solve()
{
	char reg[10];
	int num = 0, period = 0;
	int task = 0;
	pair<int, int> tmp;
	unordered_map<int, int> period_map;
	priority_queue<pair<int, int>> queries;
	
	cin >> reg;
	
	while (reg[0] != '#')
	{
		cin >> num >> period;
		
		queries.push(make_pair(-period, -num));
		period_map[num] = period;
		
		cin >> reg;
	}
	
	cin >> task;
	
	while (task--)
	{
		tmp = queries.top();
		cout << -tmp.second << endl;
		queries.pop();
		queries.push(make_pair(tmp.first - period_map[-tmp.second], tmp.second));
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
    
	solve();

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
