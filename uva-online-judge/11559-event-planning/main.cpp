#include<bits/stdc++.h>
using namespace std;

void solve();

int participants, budget, hotels, trip_weeks;
constexpr int MAX_COST = 2000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("my-output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif

    while (scanf("%d %d %d %d\n", &participants, &budget, &hotels, &trip_weeks) == 4)
    {
        solve();
        printf("\n");
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

void solve()
{
	int min_cost = MAX_COST + 1, hotel_cost, hotel_free_rooms, weeks;
	int trip_cost;
	
	while (hotels--)
	{
		weeks = trip_weeks;
		
		scanf("%d", &hotel_cost);
		
		trip_cost = hotel_cost * participants;
		
		if (trip_cost > budget)
		{
			while (weeks)
			{
				// Discard free rooms line
				scanf("%d", &hotel_free_rooms);
				weeks--;
			}
		}
		
		while (weeks)
		{
			// Search for availability: if there are enough rooms
			// for all the participants the same week
			
			scanf("%d", &hotel_free_rooms);
			weeks--;
			
			if (hotel_free_rooms >= participants)
			{
				if (trip_cost < min_cost)
				{
					min_cost = trip_cost;
					break;
				}
			}
		}
		
		while (weeks)
		{
			// Discard remaining ints from line
			scanf("%d", &hotel_free_rooms);
			weeks--;
		}
	}
	
	if (min_cost > MAX_COST)
	{
		printf("stay home");
	}
	else
	{
		printf("%d", min_cost);
	}
}
