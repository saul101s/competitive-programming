#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) { 
    if (!isSameSet(i, j)) { numSets--; 
    int x = findSet(i), y = findSet(j);
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void solve()
{
	int c;
	int c1, c2;
	int succ = 0, unsucc = 0;
	char action;
	string line;
	stringstream ss;
	
	cin >> c;
	cin.ignore(5, '\n');
	
	UnionFind connections(c + 1);
	
	while (getline(cin, line) && line != "")
	{
		ss = stringstream(line);
		ss >> action >> c1 >> c2;
		
		if (action == 'c')
		{
			connections.unionSet(c1, c2);
		}
		else
		{
			if (connections.isSameSet(c1, c2))
			{
				succ++;
			}
			else
			{
				unsucc++;
			}
		}
	}
	
	cout << succ << "," << unsucc << endl;
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
        
        if (t != 0)
		{
			cout << "\n";
		}
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
