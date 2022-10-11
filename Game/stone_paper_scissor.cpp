#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
class game
{
private:
    int n;
    vector<string> comp{"Stone", "Paper", "Scissors"};

public:
    void get_input();
    void chk_value();
    void chk_result();
    int human = 0;
    int computer = 0;
    int draw = 0;
};
void game ::get_input()
{
    cout << "Enter a No. to select your Weapon : ";
    cin >> n;
}
void game ::chk_value()
{
    srand(time(NULL)); // to get a truly random no. everytime
    int cmp = rand() % comp.size();
    // cout << cmp;
    switch (n)
    {
    case 1:
        if (cmp == 0)
        {
            draw++;
            break;
        }
        else if (cmp == 1)
        {
            computer++;
            break;
        }
        else if (cmp == 2)
        {
            human++;
            break;
        }
        break;

    case 2:
        if (cmp == 0)
        {
            human++;
            break;
        }
        else if (cmp == 1)
        {
            draw++;
            break;
        }
        else if (cmp == 2)
        {
            computer++;
            break;
        }
        break;

    case 3:
        if (cmp == 0)
        {
            computer++;
            break;
        }
        else if (cmp == 1)
        {
            human++;
            break;
        }
        else if (cmp == 2)
        {
            draw++;
            break;
        }
        break;

    default:
        cout << "Wrong Input" << endl
             << endl;
        break;
    }
}
void game::chk_result()
{
    cout << "You : " << human << endl;
    cout << "Computer : " << computer << endl;
    cout << "Draw : " << draw << endl;
    if (human > computer)
    {
        cout << "Congrats, You Won!!" << endl;
    }
    if (computer > human)
    {
        cout << "Oops, You Lost :(" << endl;
    }
    else
    {
        cout << "It's a Draw" << endl;
    }
}
int main()
{
    game gm;
    int t;
    cout << "How many round do you want to play?" << endl;
    cin >> t;
    cout << "1. Stone \n2. Paper \n3. Scissors" << endl
         << endl;
    while (t--)
    {
        gm.get_input();
        gm.chk_value();
    }
    gm.chk_result();
    return 0;
}
