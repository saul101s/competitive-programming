#include<bits/stdc++.h>
using namespace std;

constexpr int CONTESTANTS = 100;
constexpr int PROBLEMS = 9;

struct submit
{
	int problem;
	int time;
	char result;
};

struct team
{
	int id;
	int problems_solved;
	int penalty;
	bool active;
	bool is_problem_solved[PROBLEMS];
	int incorrect_tries[PROBLEMS];
	
	team() : id(0), problems_solved(0), penalty(0), active(false) {};
};

bool compare(team a, team b)
{	
	if (a.problems_solved == b.problems_solved)
	{
		if (a.penalty == b.penalty)
		{
			return a.id < b.id;
		}

		return a.penalty < b.penalty;
	}
	
	return a.problems_solved > b.problems_solved;
}

void solve()
{
	int id;
	submit sub;
	string input;
	stringstream ss;
	team v[CONTESTANTS + 1];
	vector<team> teams;
	
	for (int i = 0; i < CONTESTANTS; i++)
	{
		v[i].id = i;
		for (int j = 0; j < PROBLEMS; j++)
		{
			v[i].is_problem_solved[j] = false;
			v[i].incorrect_tries[j] = 0;
		}
		
	}
	
	
	while (getline(cin, input) && input != "")
	{
		ss.str(input);
		
		ss >> id >> sub.problem >> sub.time >> sub.result;
		id--;
		sub.problem--;
		
		v[id].active = true;
		
		if (!v[id].is_problem_solved[sub.problem])
		{
			if (sub.result == 'C')
			{
				v[id].problems_solved += 1;
				v[id].penalty += sub.time + v[id].incorrect_tries[sub.problem] * 20;
				v[id].is_problem_solved[sub.problem] = true;
			}
			else if (sub.result == 'I')
			{
				v[id].incorrect_tries[sub.problem]++;
			}
		}
	}
	
	for (int i = 0; i < CONTESTANTS; i++)
	{
		if (v[i].active)
		{
			teams.push_back(v[i]);
		}
	}
	
	sort(teams.begin(), teams.end(), compare);
	
	for (auto it = teams.begin(); it != teams.end(); it++)
	{
		cout << (*it).id + 1 << " " << (*it).problems_solved << " " << (*it).penalty << endl;
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
    
    cin.ignore(5, '\n');
    cin.ignore(5, '\n');

    while (t--)
    {	
        solve();
        
        if (t > 0)
		{
			cout << "\n";
		}
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
