#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

int rows, cols;

void solve()
{
	vector<vii> mat_t;
	string indices;
	stringstream si;
	string values;
	stringstream sv;
	int r = 0;
	int nzr = 0;
	int index;
	int value;
	
	mat_t.assign(cols + 1, vii());
	
	while (r < rows)
	{
		getline(cin, indices);
		getline(cin, values);
		
		si = stringstream(indices);
		sv = stringstream(values);
		si >> nzr;
		
		while (nzr--)
		{
			si >> index;
			sv >> value;
			
			mat_t[index].push_back(make_pair(r, value));
		}
		
		r++;
	}
	
	cout << cols << " " << rows << endl;
	
	for (r = 1; r < (int)mat_t.size(); r++)
	{
		values = "";
		indices = "";
		nzr = 0;
		
		for (int c = 0; c < (int)mat_t[r].size() - 1; c++)
		{
			indices += to_string(mat_t[r][c].first + 1) + " ";
			values += to_string(mat_t[r][c].second) + " ";
			nzr++;
		}
		
		if (mat_t[r].size() > 0)
		{
			indices += to_string(mat_t[r][mat_t[r].size() - 1].first + 1);
			values += to_string(mat_t[r][mat_t[r].size() - 1].second);
			nzr++;
			
			cout << nzr << " " << indices << endl;
			cout << values << endl;
		}
		else
		{
			cout << 0 << endl << endl;
		}
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

    while (cin >> rows >> cols)
    {
		cin.ignore(5, '\n');
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
