#include<bits/stdc++.h>
using namespace std;

string line;

void solve()
{
	list<char> beiju;
	list<char>::iterator it = beiju.end();
	char ch = ' ';
	
	for (int i = 0; i < (int)line.size(); i++)
	{
		ch = line[i];
		
		if (ch == '[')
		{
			it = beiju.begin();
		}
		else if (ch == ']')
		{
			it = beiju.end();
		}
		else
		{
			beiju.insert(it, ch);
		}
	}
	
	for (it = beiju.begin(); it != beiju.end(); it++)
	{
		cout << *it;
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

    while (getline(cin, line))
    {
        solve();
        cout << "\n";
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
