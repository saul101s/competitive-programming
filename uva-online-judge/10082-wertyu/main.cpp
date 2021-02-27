#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

string line;

char code(char ch)
{
  switch (ch)
  {
    case ' ':
      return ' ';
    case 'W':
      return 'Q';
    case 'E':
      return 'W';
    case 'R':
      return 'E';
    case 'T':
      return 'R';
    case 'Y':
      return 'T';
    case 'U':
      return 'Y';
    case 'I':
      return 'U';
    case 'O':
      return 'I';
    case 'P':
      return 'O';
    case '[':
      return 'P';
    case ']':
      return '[';
    case '\\':
      return ']';
    case 'S':
      return 'A';
    case 'D':
      return 'S';
    case 'F':
      return 'D';
    case 'G':
      return 'F';
    case 'H':
      return 'G';
    case 'J':
      return 'H';
    case 'K':
      return 'J';
    case 'L':
      return 'K';
    case ';':
      return 'L';
    case '\'':
      return ';';
    case 'X':
      return 'Z';
    case 'C':
      return 'X';
    case 'V':
      return 'C';
    case 'B':
      return 'V';
    case 'N':
      return 'B';
    case 'M':
      return 'N';
    case ',':
      return 'M';
    case '.':
      return ',';
    case '/':
      return '.';
    case '1':
      return '`';
    case '2':
      return '1';
    case '3':
      return '2';
    case '4':
      return '3';
    case '5':
      return '4';
    case '6':
      return '5';
    case '7':
      return '6';
    case '8':
      return '7';
    case '9':
      return '8';
    case '0':
      return '9';
    case '-':
      return '0';
    case '=':
      return '-';
    default:
      return ' ';
  }
}

void solve()
{
  string ans = "";
  
  for (int i = 0; i < (int)line.size(); i++)
  {
    ans += code(line[i]);
  }
  
  cout << ans;
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

  while (getline(cin, line))
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
