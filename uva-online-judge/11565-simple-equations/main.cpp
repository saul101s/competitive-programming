#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

void solve()
{
  int A, B, C;
  
  cin >> A >> B >> C;
  
  for (int x = -22; x <= 22; x++)
  {
    if (x * x <= C)
    {
      for (int y = -100; y <= 100; y++)
      {
        if (x != y && x * x + y * y <= C)
        {
          for (int z = -100; z <= 100; z++)
          {
            if ((x != y) && (x != z) && (y != z)
                && (x + y + z == A)
                && (x * y * z == B)
                && (x*x + y*y + z*z == C))
            {
              cout << x << " " << y << " " << z;
              return;
            }
          }
        }
      }
    }
  }
  
  cout << "No solution.";
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
