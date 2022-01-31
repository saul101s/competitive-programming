#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

unsigned int val = 0;

void solve()
{
  unsigned int res = 10;
  
  while (res > 9)
  {
    res = 0;
    
    while (val > 0)
    {
      res += val % 10;
      val /= 10;
    }
    
    val = res;
  }
  
  cout << res;
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

  cin >> val;

  while (val != 0)
  {
    solve();
    cout << "\n";
    
    cin >> val;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
