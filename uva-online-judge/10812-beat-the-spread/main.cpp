#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000



void solve()
{
  uint32_t s, d;
  cin >> s >> d;
  
  // a = (s + d) / 2
  // b = s - a
  if ((s+d) % 2 != 0) {
    cout << "impossible";
  } else {
    int a = (s+d) / 2;
    int b = s - a;
    if (b < 0) {
      cout << "impossible";  
    } else {
      cout << a << " " << b;      
    }
  }
  
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
