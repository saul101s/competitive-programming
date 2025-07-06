#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

char str[1000001];

void solve()
{
  int t, i, j;
  cin >> t;
  
  while (t--)
  {
    cin >> i >> j;
    if (i > j) { int aux = i; i = j; j = aux; }
    
    for (; i < j; i++)
    {
      if (str[i] != str[i+1])
      {
        cout << "No\n";
        break;
      }
    }
    if (i == j)
    {
      cout << "Yes\n";
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
  
  int c = 1;

  while (cin >> str)
  {
    cout << "Case " << c++ << ":\n";
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
