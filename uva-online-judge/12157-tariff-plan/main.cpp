#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int c = 1;

void solve()
{
  int N, mile, juice, charges, call_time;
  
  cin >> N;
  mile = juice = charges = call_time = 0;
  
  while (N--)
  {
    cin >> call_time;
    
    charges = (call_time / 30) + 1;
    mile += charges * 10;
    
    charges = (call_time / 60) + 1;
    juice += charges * 15;
  }
  
  cout << "Case " << c++ << ": ";
  
  if (mile < juice)
    cout << "Mile " << mile;
  else if (juice < mile)
    cout << "Juice " << juice;
  else
    cout << "Mile Juice " << mile;
    
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
