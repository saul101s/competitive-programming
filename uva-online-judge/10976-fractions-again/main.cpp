#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int k;

void solve()
{
  int x, y = k + 1;
  int u, d;
  int counter = 0;
  string res = "";
  
  do
  {
    u = k * y;
    d = y - k;
    
    if (u % d != 0)
    {
      y++;
      continue;
    }
    
    x = u / d;
    
    res += "1/" + to_string(k) + " = 1/" + to_string(x) + " + 1/" + to_string(y) + "\n";
    counter++;
    y++;
    
  } while (x >= y);
  
  cout << counter << "\n";
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

  while (cin >> k)
  {
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
