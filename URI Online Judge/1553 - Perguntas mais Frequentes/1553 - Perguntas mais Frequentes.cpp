#include <bits/stdc++.h>
using namespace std;

int main()
{
    int quest, freq, ocr, result;
    int questVet[1001], compareQuest[1001];

    while(cin >> quest >> freq)
    {
        if(quest == 0 && freq == 0)
        {
            break;
        }

        ocr = 0; result = 0;

        for(int j = 0; j < quest; ++j)
        {
            cin >> questVet[j];
            compareQuest[j] = questVet[j];
        }

        for(int n = 0; n < quest; ++n)
        {
            for(int p = n; p < quest; ++p)
            {
                if(questVet[n] == compareQuest[p])
                {
                    ++ocr;
                    compareQuest[p] = 0;
                }
            }

            if(ocr >= freq)
            {
                ++result;
            }

            ocr = 0;
        }
        
        cout << result << endl;
    }

    return(0);
}
