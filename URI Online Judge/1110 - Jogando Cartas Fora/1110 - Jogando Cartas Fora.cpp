#include <bits/stdc++.h>
using namespace std;

int main()
{
	int c, toBase;
	queue<int> cards;

	while(cin >> c)
	{
		if(c == 0)
		{
			break;
		}

		cout << "Discarded cards: ";

		for(int x = 1; x <= c; x++)
		{
			cards.push(x);
		}

		while(cards.size() > 1)
		{
			cout << cards.front();

			if(cards.size() > 2)
			{
				cout << ", ";
			}

			cards.pop();
			toBase = cards.front();
			cards.push(toBase);
			cards.pop();
		}

		cout << "\nRemaining card: " << cards.front() << endl;
		cards = queue<int>();
	}

	return(0);
}
