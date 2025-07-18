#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int height = 0;
int width = 0;
string line;
int line_height[10004];

void solve()
{
  getline(cin, line);
  getline(cin, line);
  
  int times_on = 0;
  int current_height = height;
  
  stringstream ss(line);
  
  for (int x = 0; x < width; x++) {
    ss >> line_height[x];
  }
  
  for (int x = 0; x < width; x++) {
    int diff = current_height - line_height[x];
    if (diff > 0) { times_on += diff; }
    current_height = line_height[x];
  }
  
  cout << times_on;
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

  line.resize(10004);

  while (cin >> height && height != 0)
  {
    cin >> width;
    
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
