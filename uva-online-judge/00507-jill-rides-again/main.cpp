#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int stops[20000];
int r = 1;

void solve()
{
  int n_stops;
  int start = 1, best_start = -1, best_end = -1;
  int sum = 0, ans = 0;
  
  cin >> n_stops;
  
  for (int i = 1; i < n_stops; i++)
  {
    cin >> stops[i];
  }
  
  for (int i = 1; i < n_stops; i++)
  {
    sum += stops[i];
    
    if (sum > ans)
    {
      ans = sum;
      
      best_start = start;
      best_end = i + 1;
    }
    else if (sum == ans)
    {
      if (((i + 1) - start) > (best_end - best_start))
      {
        best_start = start;
        best_end = i + 1;
      }
    }
    
    else if (sum < 0)
    {
      sum = 0;
      start = i + 1;
    }
  }
  
  if (best_start == -1)
  {
    cout << "Route " << r++ << " has no nice parts";
  }
  else
  {
    cout << "The nicest part of route " << r++ << " is between stops " <<
      best_start << " and " << best_end;
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
