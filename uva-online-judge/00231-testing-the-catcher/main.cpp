#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int c = 1;
vi height;
vi lis;

void solve()
{  
  lis.assign(height.size(), 1);
  int interceptions = 1;
  
  for (int i = 1; i < (int)height.size(); i++)
  {
    for (int j = i - 1; j >= 0; j--)
    {
      if (height[i] <= height[j])
      {
        lis[i] = max(lis[i], lis[j] + 1);
        interceptions = max(interceptions, lis[i]);
      }
    }
  }
  
  cout << "Test #" << c++ << ":\n";
  cout << "  maximum possible interceptions: " << interceptions << "\n";
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

  int h;
  cin >> h;

  while (h != -1)
  {
    height.clear();
    height.push_back(h);
    while (cin >> h)
    {
      if (h == -1) 
      {
        solve();
        break;
      }
      else
      {
        height.push_back(h);
      }
    }
    
    cin >> h;
    
    if (h != -1) cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
