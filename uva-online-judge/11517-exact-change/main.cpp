#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N, coins;
int coinValue[100], memo[30005];

void fill_memo()
{
  for (int c = 0; c < coins; c++)
    for (int v = 30000 - coinValue[c]; v >= 0; v--)
      if (memo[v] < INF)
        memo[v+coinValue[c]] = min(memo[v+coinValue[c]], memo[v]+1);
}


void solve()
{
  cin >> N;
  cin >> coins;
  
  for (int i = 0; i < coins; i++)
  {
    cin >> coinValue[i];
  }
  
  for (int i = 0; i < 30005; i++)
  {
    memo[i] = INF;
  }
  
  memo[0] = 0;
  fill_memo();
  
  int paid = 0;
  
  for (int i = N; i < 30005; i++)
  {
    if (memo[i] < INF)
    {
      paid = i;
      break;
    }
  }
  
  cout << paid << " " << memo[paid];
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
