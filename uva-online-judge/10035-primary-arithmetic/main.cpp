#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

long a, b;

void solve()
{
  int carries = 0;
  int carried = 0;
  
  while (a > 0 && b > 0) {
    int aDig = a % 10;
    int bDig = b % 10;
    if (aDig + bDig + carried >= 10) {
      carried = 1;
      ++carries;
    } else {
      carried = 0;
    }
    a /= 10;
    b /= 10;
  }
  
  if (carried > 0) {
     while (a % 10 == 9) {
        ++carries;
        a /= 10;
    }
    
    while (b % 10 == 9) {
        ++carries;
        b /= 10;
    }
  }
  
  if (carries == 0) {
    cout << "No carry operation.";
  } else {
    cout << carries << " carry operation";
    if (carries > 1)
      cout << "s";
    cout << ".";
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

  while (cin >> a >> b && (a != 0 || b != 0))
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
