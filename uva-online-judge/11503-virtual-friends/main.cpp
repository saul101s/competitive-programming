#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
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
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

void solve()
{
	int F;
	int id = 0;
	string f1, f2;
	int f1_id, f2_id;
	map<string, int> user_ids;
	
	cin >> F;
	
	UnionFind set(2*F);
	
	while (F--)
	{
		cin >> f1 >> f2;
		
		if (user_ids.find(f1) == user_ids.end())
		{
			f1_id = id++;
			user_ids[f1] = f1_id;
		}
		else
		{
			f1_id = user_ids[f1];
		}
		
		if (user_ids.find(f2) == user_ids.end())
		{
			f2_id = id++;
			user_ids[f2] = f2_id;
		}
		else
		{
			f2_id = user_ids[f2];
		}
		
		set.unionSet(f1_id, f2_id);
		
		cout << set.sizeOfSet(f1_id) << endl;
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
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
