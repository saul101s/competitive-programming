#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

#define MAX_N 1010
#define MAX_W 40

int memo[MAX_N][MAX_W];
int ans, N, MW, P[MAX_N], W[MAX_N], G;

int value(int id, int w)
{
  if (id == N || w == 0) return 0;
  if (memo[id][w] != -1) return memo[id][w];
  if (W[id] > w) return memo[id][w] = value(id + 1, w);
  return memo[id][w] = max(value(id + 1, w), value(id + 1, w - W[id]) + P[id]);
}

void solve()
{
  memset(memo, -1, sizeof memo);
  
  cin >> N;
  
  for (int i = 0; i < N; i++)
  {
    cin >> P[i] >> W[i];
  }
  
  cin >> G;
  
  ans = 0;
  
  while (G--)
  {
    cin >> MW;
    ans += value(0, MW);
  }
  
  cout << ans;
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
