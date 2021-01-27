#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

void solve()
{
  int n, p;
  int length = 0, sum = 0;
  bool exist = false;
  vi l;
  
  cin >> n >> p;
  
  while (p--)
  {
    cin >> length;
    l.push_back(length);
  }
  
  for (int i = 0; i < (1 << l.size()); i++)
  {
    sum = 0;
    
    for (int j = 0; j < (int)l.size(); j++)
    {
      if (i & (1 << j))
      {
        sum += l[j];
        
        if (sum > n)
        {
          break;
        }
      }
    }
    
    if (sum == n)
    {
      exist = true;
      break;
    }
  }
  
  cout << (exist ? "YES" : "NO");
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
