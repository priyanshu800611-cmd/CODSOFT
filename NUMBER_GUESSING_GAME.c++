#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));   // random seed

    int num = rand() % 100 + 1;   // number between 1-100
    int guess, count = 0;

    cout << "Guess the number (1-100)\n";

    do {
        cout << "Enter guess: ";
        cin >> guess;
        count++;

        if (guess > num)
            cout << "Too high!\n";
        else if (guess < num)
            cout << "Too low!\n";
        else
            cout << "Correct!\nAttempts = " << count << endl;

    } while (guess != num);

    return 0;
}
