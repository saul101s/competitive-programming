#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int coinValue[40], coinITValue[40];
int memo[40][301][301];

int m, S;

int cc(int type, int val, int ITVal)
{
  float e_modulus = sqrt(val*val + ITVal*ITVal);
  
  if (e_modulus > S) return INF;
  if (e_modulus == S) return 0;
  if (type == m) return INF;
  if (memo[type][val][ITVal] != -1) return memo[type][val][ITVal];
  
  return memo[type][val][ITVal] = min(
            1 + cc(type, val+coinValue[type], ITVal+coinITValue[type]),
            cc(type+1, val, ITVal));
}

void solve()
{
  cin >> m >> S;
  
  for (int i = 0; i < m; i++)
  {
    cin >> coinValue[i] >> coinITValue[i];
  }
  
  memset(memo, -1, sizeof memo);
  
  int ans = cc(0, 0, 0);
  
  if (ans < INF) cout << ans;
  else cout << "not possible";
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
