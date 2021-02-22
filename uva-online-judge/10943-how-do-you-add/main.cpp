#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N, K;
int memo[101][101];

int ways(int n, int k)
{
  if (k == 1) return 1;
  if (memo[n][k] != -1) return memo[n][k];
  
  int ans = 0;
  for (int i = 0; i <= n; i++)
  {
    ans = (ans + ways(n - i, k - 1)) % 1000000;
  }
  
  return memo[n][k] = ans;
}

void solve()
{
  cout << ways(N, K);
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
 
  memset(memo, -1, sizeof memo);
  while (cin >> N >> K && N && K)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
