#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

uint32_t reverse(uint32_t n) {
  uint32_t reversed = 0;
  while (n > 0) {
    reversed = (reversed * 10) + (n % 10);
    n /= 10;
  }
  return reversed;
}

bool isPalindrome(uint32_t n) {
  string number = to_string(n);
  for (uint32_t i = 0; i < number.size() / 2; ++i) {
    if (number[i] != number[number.size() - 1 - i])
      return false;
  }
  return true;
}

void solve()
{
  uint32_t n;
  cin >> n;
  
  uint32_t sum = n + reverse(n);
  uint32_t count = 1;
  while (!isPalindrome(sum)) {
    sum += reverse(sum);
    ++count;
  }
  cout << count << " " << sum;
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
