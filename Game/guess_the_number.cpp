#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> computer(101, 0);
    cout << "\t\t\t\tWelcome to the NUMBER GUESSING GAME" << endl
         << endl;
    int guess;
    srand(time(NULL));
    int cmp = rand() % computer.size();
    int chance = 0;
    do
    {
        cout << "Enter your Guess (Between 0 - 100): ";
        cin >> guess;
        if (guess < cmp)
        {
            if (chance == 4)
            {
                cout << "Sorry, you lost :(" << endl;
                cout << "The number was : " << cmp;
                break;
            }
            else
            {
                cout << "Nopes. Think Higher" << endl;
                chance++;
            }
        }
        else if (guess > cmp)
        {
            if (chance == 4)
            {
                cout << "Sorry, you lost :(" << endl;
                cout << "The number was : " << cmp;
                break;
            }
            else
            {
                cout << "Nopes. Think Lower" << endl;
                chance++;
            }
        }
        else if (guess == cmp)
        {
            cout << "Well Done. Taaliyaan Honi chahiye." << endl;
            break;
        }
    } while (chance < 5);
    return 0;
}
