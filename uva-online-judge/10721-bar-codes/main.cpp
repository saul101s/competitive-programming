#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n, k, m;
long memo[51][51];

long bc(int _n, int _k, int _m)
{
  if (_n < 0) return 0;
  if (_k == 0)
  {
    if (_n == 0) return 1;
    else return 0;
  }
  if (memo[_n][_k] != -1) return memo[_n][_k];
  
  long ans = 0;
  
  for (int i = 1; i <= _m; i++)
  {
    ans += bc(_n - i, _k - 1, _m);
  }
  
  return memo[_n][_k] = ans;
}

void solve()
{
  memset(memo, -1, sizeof memo);
  cout << bc(n, k, m);
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

  while (cin >> n >> k >> m)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
