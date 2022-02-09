#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int columns = 0;

void solve()
{
  int y1, y2, gap, col_gap;
  bool can_be_closed = true;
  
  cin >> columns;
  cin >> y1 >> y2;
  col_gap = y1 - y2;
  columns--;
  
  gap = col_gap;
  
  while (columns--)
  {
    cin >> y1 >> y2;
    
    if (can_be_closed)
    {
      col_gap = y1 - y2;
      
      if (col_gap != gap)
        can_be_closed = false;
    }
  }
  
  cout << (can_be_closed ? "yes" : "no");
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
    
    if (t) cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
