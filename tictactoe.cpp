#include <iostream>
#include <cstdlib> // for system("clear") or system("cls") depending on the OS
#include <limits>  // for numeric_limits

using namespace std;

int checkwin();
void board();
char sqr[10] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
int i;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    clearScreen();
    cout << "\n\n\t\tTIC TAC TOE\n\n\tControls are as follows\n\n";
    cout << "\t        |     |     \n";
    cout << "\t     1  |  2  |  3  \n";
    cout << "\t   _____|_____|_____\n";
    cout << "\t        |     |     \n";
    cout << "\t     4  |  5  |  6  \n";
    cout << "\t   _____|_____|_____\n";
    cout << "\t        |     |     \n";
    cout << "\t     7  |  8  |  9  \n";
    cout << "\t        |     |     \n";
    cout << "\n\n\tPress Enter to Play!!\n";
    cin.get(); // Wait for user to press Enter

    char g;
    int m = 0;
    do
    {
        if (g == 'y' || g == 'Y')
        {
            m = 0;
            for (int j = 1; j <= 9; ++j)
                sqr[j] = ' ';
        }
        char mark;
        int player;

        cout << "\n\n";
        do
        {
            board();

            if (m % 2 == 0)
            {
                player = 1;
                mark = 'X';
            }
            else
            {
                player = 2;
                mark = 'O';
            }
            cout << "\n\tPlayer " << player << "'s turn";
            // INPUT
            int h = 0, choice;
            do
            {
                cout << "\n\n\t              Enter your choice: ";
                cin >> choice;
                if (cin.fail())
                {
                    cin.clear();                                         // clear the error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid input! Please enter a number between 1 and 9.\n";
                    continue;
                }
                if (choice >= 1 && choice <= 9)
                {
                    if (sqr[choice] == ' ')
                    {
                        sqr[choice] = mark;
                        ++h;
                    }
                }
                if (h == 0)
                    cout << "Invalid move! Enter again!";
            } while (h == 0);
            // INPUT
            i = checkwin();
            ++m;
        } while (i == -1);
        if (i == 1)
        {
            clearScreen();
            board();
            cout << "\nPlayer " << player << " wins! ";
        }
        if (i == 0)
        {
            clearScreen();
            board();
            cout << "\nGame Draw";
        }
        cout << "\n\nWant to continue? (y/n): ";
        cin >> g;
    } while (g == 'Y' || g == 'y');

    return 0;
}

int checkwin()
{
    if (sqr[1] == sqr[2] && sqr[2] == sqr[3] && sqr[1] != ' ')
        return 1;

    else if (sqr[4] == sqr[5] && sqr[5] == sqr[6] && sqr[4] != ' ')
        return 1;

    else if (sqr[7] == sqr[8] && sqr[8] == sqr[9] && sqr[7] != ' ')
        return 1;

    else if (sqr[1] == sqr[4] && sqr[4] == sqr[7] && sqr[1] != ' ')
        return 1;

    else if (sqr[2] == sqr[5] && sqr[5] == sqr[8] && sqr[2] != ' ')
        return 1;

    else if (sqr[3] == sqr[6] && sqr[6] == sqr[9] && sqr[3] != ' ')
        return 1;

    else if (sqr[1] == sqr[5] && sqr[5] == sqr[9] && sqr[1] != ' ')
        return 1;

    else if (sqr[3] == sqr[5] && sqr[5] == sqr[7] && sqr[3] != ' ')
        return 1;

    else if (sqr[1] != ' ' && sqr[2] != ' ' && sqr[3] != ' ' &&
             sqr[4] != ' ' && sqr[5] != ' ' && sqr[6] != ' ' &&
             sqr[7] != ' ' && sqr[8] != ' ' && sqr[9] != ' ')
        return 0;
    else
        return -1;
}

void board()
{
    clearScreen();
    cout << "\tNote: Enter positive integers only and enter Q to quit";
    cout << "\n\n\n\tPlayer 1==> X          Player 2==> O \n\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << sqr[1] << "  |  " << sqr[2] << "  |  " << sqr[3] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << sqr[4] << "  |  " << sqr[5] << "  |  " << sqr[6] << "  \n";
    cout << "\t_____|_____|_____\n";
    cout << "\t     |     |     \n";
    cout << "\t  " << sqr[7] << "  |  " << sqr[8] << "  |  " << sqr[9] << "  \n";
    cout << "\t     |     |     \n";
}
