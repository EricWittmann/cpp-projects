//*****************************************************************************************************
//
//		This program simulates a series of 10 games of the game Morra. Players randomly display a
//      number of fingers and guess the total sum. The program determines the winner of each game,
//      outputs the results to both the console and a text file, and outputs the winner of the series.
//
//*****************************************************************************************************

#include <cstdlib>     // for rand() and srand()
#include <ctime>       // for time()
#include <fstream>     // for file I/O
#include <iomanip>
#include <iostream>
using namespace std;

//*****************************************************************************************************

int main() {
    const int MAX_FINGERS = 5,
              MIN_FINGERS = 1,
              MAX_GUESS = 10,
              MIN_GUESS = 0;
    int playerOneFingers,
        playerTwoFingers,
        playerOneGuess,
        playerTwoGuess,
        sum,
        playerOneWins = 0,
        playerTwoWins = 0;
    ofstream out("morraSeriesResults.txt");     // output file stream (write to file)

    short seed;         // seed for random number generator
    seed = time(0);     // get system time (0 = current time)
    srand(seed);        // seed random number generator

    for (int game = 1; game <= 10; game++) {
        playerOneFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;     // random number between 1 and 5 (player 1)
        playerOneGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;             // random number between 0 and 10 (player 1)
        playerTwoFingers = rand() % (MAX_FINGERS - MIN_FINGERS) + MIN_FINGERS;     // random number between 1 and 5 (player 2)
        playerTwoGuess = rand() % (MAX_GUESS - MIN_GUESS) + MIN_GUESS;             // random number between 0 and 10  (player 2)

        cout << left << "Game " << game << ":" << setw(12) << endl;     // left aligns the text and serw() sets the width of the column
        cout << "Player" << setw(12) << "|Fingers" << setw(12) << "|Total" << endl;
        cout << "============|===========|============" << endl;
        cout << setw(12) << "1"
             << "|" << setw(11) << playerOneFingers << "|" << playerOneGuess << endl;
        cout << setw(12) << "2"
             << "|" << setw(11) << playerTwoFingers << "|" << playerTwoGuess << "\n" << endl;

        sum = playerOneFingers + playerTwoFingers;
        cout << "Correct total is " << sum << endl;

        if (sum == playerOneGuess && sum == playerTwoGuess) {
            cout << "TIE" << "\n" << endl;
        } else if (sum == playerOneGuess) {
            cout << "Player 1 Wins" << "\n" << endl;
            playerOneWins++;
        } else if (sum == playerTwoGuess) {
            cout << "Player 2 Wins" << "\n" << endl;
            playerTwoWins++;
        } else {
            cout << "NO ONE WINS" << "\n" << endl;
        }

        cout << "-------------------------------------" << endl;
    }

    cout << "=====================================" << endl;     // Print results to console
    out << "=====================================" << endl;      // Output to file "morraSeriesResults.txt"
    cout << "Summary of the series" << endl;
    out << "Summary of the series" << endl;
    cout << "=====================================" << endl;
    out << "=====================================" << endl;
    cout << "Player 1 won " << playerOneWins << " games" << endl;
    out << "Player 1 won " << playerOneWins << " games" << endl;
    cout << "Player 2 won " << playerTwoWins << " games" << endl
         << endl;
    out << "Player 2 won " << playerTwoWins << " games" << endl
        << endl;

    cout << "Winner of the series: ";
    out << "Winner of the series: ";
    if (playerOneWins > playerTwoWins) {
        cout << "Player 1" << endl;
        out << "Player 1" << endl;
    } else if (playerOneWins < playerTwoWins) {
        cout << "Player 2" << endl;
        out << "Player 2" << endl;
    } else if (playerOneWins == playerTwoWins) {
        cout << "It is a TIE" << endl;
        out << "It is a TIE" << endl;
    } else {
        cout << "NO ONE WINS" << endl;
        out << "NO ONE WINS" << endl;
    }

    return 0;
}

//*****************************************************************************************************

/*

Game 1:
Player      |Fingers    |Total
============|===========|============
1           |2          |8
2           |3          |9

Correct total is 5
NO ONE WINS

-------------------------------------
Game 2:
Player      |Fingers    |Total
============|===========|============
1           |2          |8
2           |3          |5

Correct total is 5
Player 2 Wins

-------------------------------------
Game 3:
Player      |Fingers    |Total
============|===========|============
1           |1          |6
2           |4          |7

Correct total is 5
NO ONE WINS

-------------------------------------
Game 4:
Player      |Fingers    |Total
============|===========|============
1           |3          |6
2           |1          |4

Correct total is 4
Player 2 Wins

-------------------------------------
Game 5:
Player      |Fingers    |Total
============|===========|============
1           |3          |1
2           |4          |5

Correct total is 7
NO ONE WINS

-------------------------------------
Game 6:
Player      |Fingers    |Total
============|===========|============
1           |4          |2
2           |1          |3

Correct total is 5
NO ONE WINS

-------------------------------------
Game 7:
Player      |Fingers    |Total
============|===========|============
1           |2          |9
2           |3          |8

Correct total is 5
NO ONE WINS

-------------------------------------
Game 8:
Player      |Fingers    |Total
============|===========|============
1           |2          |1
2           |2          |5

Correct total is 4
NO ONE WINS

-------------------------------------
Game 9:
Player      |Fingers    |Total
============|===========|============
1           |3          |4
2           |2          |7

Correct total is 5
NO ONE WINS

-------------------------------------
Game 10:
Player      |Fingers    |Total
============|===========|============
1           |2          |6
2           |3          |4

Correct total is 5
NO ONE WINS

-------------------------------------
=====================================
Summary of the series
=====================================
Player 1 won 0 games
Player 2 won 2 games

Winner of the series: Player 2

*/