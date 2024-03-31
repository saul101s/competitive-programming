#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

uint32_t n;

void solve()
{
  // Example
  // 150
  // 150 / 2 = 75
  // 75 / 3 = 25
  // 25 / 5 = 5
  // 5 / 5 = 1
  // 150 = 5^2 * 3 * 2
  // divisors(n) = number of times that "mabu" toggles the light
  // divisors(150) = (count(5) + 1) * (count(3) + 1) * (count(2) + 1)
  // count(5) -> how many times 5 is factor of 150
  
  int divisors = 1;
  uint32_t reminder = n;
  int div = 2;
  int lastDiv = 2;
  int count = 0;
  
  while (reminder > 1 && div*div <= n) {
    if (reminder % div != 0) {
      divisors *= (count + 1);
      int diff = max(1, lastDiv - div);
      div += diff;
      while (reminder % div != 0 && div*div <= n) {
        div += diff;
      }
      lastDiv = div;
      count = 1;
    } else {
      ++count;
    }
    
    reminder = reminder / div;
  }
  
  divisors *= (count + 1);
  
  if (divisors % 2 == 0) {
    cout << "no";
  } else {
    cout << "yes";
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

  cin >> n;

  while (n != 0)
  {
    solve();
    cout << "\n";
    cin >> n;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
