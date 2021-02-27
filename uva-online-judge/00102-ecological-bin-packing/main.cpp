#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int b[3], g[3], c[3];
int bm[3], gm[3], cm[3];

void solve()
{
  bm[0] = b[1] + b[2];
  bm[1] = b[0] + b[2];
  bm[2] = b[0] + b[1];
  cm[0] = c[1] + c[2];
  cm[1] = c[0] + c[2];
  cm[2] = c[0] + c[1];
  gm[0] = g[1] + g[2];
  gm[1] = g[0] + g[2];
  gm[2] = g[0] + g[1];
  
  int sum = 0;
  int min = INF;
  char ans[3];
  
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (j == i) continue;
      
      for (int k = 0; k < 3; k++)
      {
        if (k == i || k == j) continue;
        
        sum = bm[i] + cm[j] + gm[k];
        
        if (sum < min)
        {
          min = sum;
          ans[i] = 'B';
          ans[j] = 'C';
          ans[k] = 'G';
        }
      }
    }  
  }
  
  cout << ans[0] << ans[1] << ans[2] << " " << min;
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

  while (cin >> b[0] >> g[0] >> c[0] >> b[1] >> g[1] >> c[1] >> b[2] >> g[2] >> c[2])
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
