#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n;
ii block[10000];
int lis[10000];

void solve()
{
  int l = 0, m = 0;;
  
  for (int i = 0; i < n; i++)
  {
    cin >> l >> m;
    block[i] = make_pair(l, m);
  }
  
  sort(block, block + n);
  
  for (int i = 0; i < n; i++)
  {
    lis[i] = 1;
  }
  
  int ans = 1;
  
  for (int i = 1; i < n; i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (block[i].second >= block[j].second)
      {
        lis[i] = max(lis[i], lis[j] + 1);
        ans = max(ans, lis[i]);
      }
    }
  }
  
  cout << ans;
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
  
  cin >> n;
  
  while (n)
  {
    solve();
    cout << "\n";
    
    cin >> n;
    
    if (!n)
    {
      cout << "*\n";
    }
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
