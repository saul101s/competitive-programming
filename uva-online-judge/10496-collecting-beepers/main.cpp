#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N;
int distances[11][11];
int memo[11][1 << 11];

int tsp(int pos, int mask)
{
  if (mask == ((1 << (N+1)) - 1))
    return distances[pos][0];
    
  if (memo[pos][mask] != -1)
    return memo[pos][mask];
  
  int res = INF;
  for (int next = 0; next <= N; next++)
  {
    if (!(mask & (1 << next)) && next != pos)
    {
      res = min(res, distances[pos][next] + tsp(next, mask | (1 << next)));
    }
  }
  
  return memo[pos][mask] = res;
}

void solve()
{
  int xsize, ysize, x, y;
  
  cin >> xsize >> ysize >> x >> y;
  cin >> N;
  
  ii positions[N+1];
  positions[0] = make_pair(x, y);
  
  for (int i = 1; i <= N; i++)
  {
    cin >> x >> y;
    positions[i] = make_pair(x, y);
  }
  
  for (int i = 0; i <= N; i++)
  {
    for (int j = 0; j <= N; j++)
    {
      distances[i][j] = abs(positions[i].first - positions[j].first) +
                        abs(positions[i].second - positions[j].second);
    }
  }
  
  memset(memo, -1, sizeof memo);
  cout << "The shortest path has length " << tsp(0, 1);
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
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
