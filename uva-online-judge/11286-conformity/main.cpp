#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

constexpr int COURSES = 5;

int n;

void solve()
{
	int course;
	int max_pop = 0;
	int most_pop_count = 1;
	set<int> selection;
	map<set<int>, int> frequencies;
	
	while (n--)
	{
		selection.clear();
		
		for (int i = 0; i < COURSES; i++)
		{
			cin >> course;
			selection.insert(course);
		}
		
		frequencies[selection]++;
	}
	
	for (auto it = frequencies.begin(); it != frequencies.end(); it++)
	{
		if ((*it).second > max_pop)
		{
			max_pop = (*it).second;
			most_pop_count = (*it).second;
		}
		else if ((*it).second == max_pop)
		{
			most_pop_count += (*it).second;
		}
	}
	
	cout << most_pop_count;
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

    cin >> n;

    while (n != 0)
    {
        solve();
        cout << "\n";
        
        cin >> n;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
