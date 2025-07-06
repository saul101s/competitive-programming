#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

char str[1000001];
int q[1000000];

void solve()
{
  char current_char = str[0];
  int current_char_idx = 0;
  int current_q = 1;
  int i = 1;
  
  for (i = 1; str[i] != '\0'; i++)
  {
    if (current_char != str[i])
    {
      for (int j = current_char_idx; j < i; j++)
      {
        q[j] = current_q - j + current_char_idx;
      }
      current_char = str[i];
      current_char_idx = i;
      current_q = 1;
    }
    else
    {
      current_q++;
    }
  }
  
  for (int j = current_char_idx; j < i; j++)
  {
    q[j] = current_q - j + current_char_idx;
  }
  
  int t, j;
  cin >> t;
  
  while (t--)
  {
    cin >> i >> j;
    if (i > j) { int aux = i; i = j; j = aux; }
    
    if (q[i] > j - i) cout << "Yes\n";
    else cout << "No\n";
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
  
  int c = 1;

  while (cin >> str)
  {
    cout << "Case " << c++ << ":\n";
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
