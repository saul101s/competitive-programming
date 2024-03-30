#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int v, t;

void solve()
{
  // float a = v / (float)t;
  // float t2 = 2*t;
  // float dx = 0.5f * a * t2*t2;
  // a * t2*t2 = v/t * 2t * 2t = v/t * 4t^2 = v * 4t
  // 0.5 * v * 4t = v * 2t
  
  cout << v * 2*t;
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

  while (cin >> v >> t)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
