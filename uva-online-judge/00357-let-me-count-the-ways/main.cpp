#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N;
int COIN_TYPES = 5, coinValue[] = {1, 5, 10, 25, 50};
long memo[6][30005];

long ways(int type, int m)
{
  if (m == 0) return 1;
  if (m < 0) return 0;
  if (type == COIN_TYPES) return 0;
  
  if (memo[type][m] != -1) return memo[type][m];
  
  return memo[type][m] = ways(type, m - coinValue[type]) + ways(type + 1, m);
}

void solve()
{
  long res = ways(0, N);
  
  if (res == 1)
  {
    cout << "There is only 1 way to produce " << N << " cents change.";
  }
  else
  {
    cout << "There are " << res << " ways to produce " << N << " cents change.";
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  memset(memo, -1, sizeof memo);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("my-output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif
  
  while (cin >> N)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
