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
  int n, k = 0, min_k = 0;
  int curr = 0, next, step;
  
  cin >> n;
  
  while (n--)
  {
    cin >> next;
    
    step = next - curr;
    
    if (step == k)
    {
      k--;
    }
    else if (step > k)
    { 
      if (step > min_k)
      {
        min_k = step;
        k = step - 1;
      }
      else
      {
        min_k++;
        k = min_k;
      }
    }
    
    curr = next;
  }
  
  cout << "Case " << c++ << ": " << min_k;
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
