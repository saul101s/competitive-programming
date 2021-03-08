#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

void solve()
{
  int n, tmp, l = 0, r = 0;
  
  cin >> n;
  cin >> tmp;
  
  n--;
  l = tmp;
  r = tmp;
  
  while (n--)
  {
    cin >> tmp;
    l = min(l, tmp);
    r = max(r, tmp);
  }
  
  cout << (r - l) * 2;
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
