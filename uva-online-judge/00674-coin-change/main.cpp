#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

#define MAX_CENTS 7500

int coinVal[5] = {50, 25, 10, 5, 1};
int N = 5;
int memo[6][MAX_CENTS];
int Q;

int ways(int type, int value)
{
  if (value == 0) return 1;
  if (value < 0 || type == N) return 0;
  if (memo[type][value] != -1) return memo[type][value];
  
  return memo[type][value] = ways(type + 1, value) + ways(type, value - coinVal[type]);
}

void solve()
{
  cout << ways(0, Q);
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
  
  while (cin >> Q)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
