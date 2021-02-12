#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int c = 1;

void solve()
{
  int a, b;
  int sum = 0;
  
  cin >> a >> b;
  
  if (a % 2 == 0)
  {
    a++;
  }
  
  if (b % 2 == 0)
  {
    b--;
  }
  
  if (a == b)
  {
    sum = a;
  }
  else
  {
    sum = ((a + b) * (((b - a) / 2) + 1)) / 2;
  }
  
  
  cout << "Case " << c++ << ": " << sum;
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
