#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int n;
int age;
priority_queue<int, vector<int>, greater<int>> orderedAges;

void solve()
{
  while (n--)
  {
    cin >> age;
    orderedAges.push(age);
  }
    
  for (; orderedAges.size() > 1; orderedAges.pop())
    cout << orderedAges.top() << " ";
    
  cout << orderedAges.top();
  orderedAges.pop();
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

  while (n > 0)
  {
    solve();
    cout << "\n";
    cin >> n;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
