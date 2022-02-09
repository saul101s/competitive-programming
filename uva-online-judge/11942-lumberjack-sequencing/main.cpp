#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

void solve()
{
  int curr, next, diff;
  int order = 0, i = 8;
  bool ordered = true;
  
  cin >> curr >> next;
  
  diff = next - curr;
  
  while (diff == 0 && i--)
  {
    cin >> next;
    diff = next - curr;
  }
  
  if (diff < 0) order = -1;
  else order = 1;
  
  curr = next;
  
  while (i--)
  {
    cin >> next;
    diff = (next - curr) * order;
    
    if (diff < 0) ordered = false;
    
    curr = next;
  }
  
  cout << (ordered ? "Ordered" : "Unordered");
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
  
  cout << "Lumberjacks:\n";

  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
