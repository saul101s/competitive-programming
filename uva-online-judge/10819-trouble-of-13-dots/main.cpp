#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int m, n;
int prices[105], favours[105], memo[105][10205];

int favour(int item, int wasted)
{
  if (wasted > m && m < 1800) return -INF;
  if (wasted > m + 200) return -INF;
  if (item == n)
  {
    if (wasted > m && wasted <= 2000) return -INF;
    return 0;
  }
  if (memo[item][wasted] != -1) return memo[item][wasted];
  
  return memo[item][wasted] = max(favours[item] + favour(item + 1, wasted + prices[item]),
                                 favour(item + 1, wasted));
}

void solve()
{
  for (int i = 0; i < n; i++)
  {
    cin >> prices[i] >> favours[i];
  }
  
  memset(memo, -1, sizeof memo);
  cout << favour(0, 0);
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

  while (cin >> m >> n)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
