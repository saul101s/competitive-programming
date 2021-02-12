#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int i, j;

void solve()
{
  int cycle_length = 1, max_cycle_length = 1;
  int lo = i, hi = j;
  int tmp;
  
  if (hi < lo)
  {
    int aux = hi;
    hi = lo;
    lo = aux;
  }
  
  for (int k = lo; k <= hi; k++)
  {
    tmp = k;
    cycle_length = 1;
    
    while (tmp != 1)
    {
      if (tmp % 2 == 0)
      {
        tmp /= 2;
      }
      else
      {
        tmp = 3 * tmp + 1;
      }
      
      cycle_length++;
    }
    
    if (cycle_length > max_cycle_length)
    {
      max_cycle_length = cycle_length;
    }
  }
  
  cout << i << " " << j << " " << max_cycle_length;
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

  while (cin >> i >> j)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
