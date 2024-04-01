#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N;

void solve()
{
  cout << "f91(" << N << ") = ";
  
  if (N <= 100) {
    cout << 91;
  } else {
    cout << N-10;
  }
  
  // slower
  // cout << "f91(" << N << ") = " << max(91, N - 10);
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

  cin >> N;

  while (N != 0)
  {
    solve();
    cout << "\n";
    cin >> N;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
