#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int a, b;

void solve()
{
  int diff1, diff2;
  
  diff1 = b - a;
  diff2 = a - b;
  
  if (diff1 < 0) diff1 += 100;
  else diff2 += 100;
  
  cout << min(diff1, diff2);
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

  cin >> a >> b;

  while (a != -1 || b != -1)
  {
    solve();
    cout << "\n";
    
    cin >> a >> b;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
