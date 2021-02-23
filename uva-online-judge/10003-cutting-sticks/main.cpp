#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int l, n, A[52], memo[52][52];

int cut(int left, int right)
{
  if (left + 1 == right) return 0;
  if (memo[left][right] != -1) return memo[left][right];
  
  int ans = INF;
  for (int i = left + 1; i < right; i++)
  {
    ans = min(ans, cut(left, i) + cut(i, right) + (A[right] - A[left]));
  }
  
  return memo[left][right] = ans;
}

void solve()
{
  for (int i = 1; i <= n; i++)
  {
    cin >> A[i];
  }
  
  A[n+1] = l;
 
  memset(memo, -1, sizeof memo);
  cout << "The minimum cutting is " << cut(0, n + 1) << ".";
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

  A[0] = 0;
  
  while (cin >> l && l)
  {
    cin >> n;
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
