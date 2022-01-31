#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

unsigned int cont = 1;

void solve()
{
  int t, current, next;
  int high, low;
  
  high = 0;
  low = 0;
  
  cin >> t;
  cin >> current;
  
  t--;
  
  while (t--)
  {
    cin >> next;
    
    if (next < current)
      low++;
    else if (next > current)
      high++;
      
    current = next;
  }
  
  cout << "Case " << cont++ << ": " << high << " " << low;
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
