#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int m, n;

void solve()
{
  //int cuts = 0;
  //int min = 0;
  //int max = 0;
  //if (m >= n) { max = m; min = n; }
  //else { max = n; min = m; }
  
  //cuts += min - 1;
  //cuts += min * (max - 1);
  
  //cout << cuts;
  
  if (m >= n)
    cout << ((n - 1) + (n * (m - 1)));
  else
    cout << ((m - 1) + (m * (n - 1)));
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
