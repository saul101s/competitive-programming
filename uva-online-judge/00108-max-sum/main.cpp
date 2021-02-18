#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N;

void solve()
{
  int sum[N][N];
  int maxSubRect = -127*100*100;
  int subRect = 0;
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> sum[i][j];
      
      if (i > 0) sum[i][j] += sum[i-1][j];
      if (j > 0) sum[i][j] += sum[i][j - 1];
      if (i > 0 && j > 0) sum[i][j] -= sum[i - 1][j - 1];
    }
  }
  
  for (int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    for (int k = i; k < N; k++) for (int l = j; l < N; l++)
    {
      subRect = sum[k][l];
      if (i > 0) subRect -= sum[i - 1][l];
      if (j > 0) subRect -= sum[k][j - 1];
      if (i > 0 && j > 0) subRect += sum[i - 1][j - 1];
      maxSubRect = max(maxSubRect, subRect);
    }
  
  cout << maxSubRect;
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

  cin >> N;
  
  solve();
  cout << "\n";

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
