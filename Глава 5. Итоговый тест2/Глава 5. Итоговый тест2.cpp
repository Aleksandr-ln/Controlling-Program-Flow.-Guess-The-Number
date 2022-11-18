#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
   
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void startingGame(int randNumb)
{
    randNumb = getRandomNumber(1, 100); // Вызов функции для получения нового рандомного числа, для каждой последующей игры
    std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
    int usersGuess;
    for (int iii = 1; iii <= 7; iii++)
    {
        std::cout << "Guess #" << iii << ":";
        std::cin >> usersGuess;
        if (usersGuess > randNumb)
        {
            std::cout << "Your guess is too high.\n";
        }
        else if (usersGuess < randNumb)
        {
            std::cout << "Your guess is too low.\n";
        }
        else if (usersGuess = randNumb)
        {
            std::cout << "Correct! You win!\n";
            break;
        }
        if (iii == 7)
        {
            std::cout << "Sorry, you lose. The correct number was " << randNumb << ".\n";
        }
    }
}

char requestForReplay(int randNumb)
{
    while (true)
    {
        std::cout << "Would you like to play again (y/n)? ";
        char sm;
        std::cin >> sm;

        if (sm == 'y')
        {
            startingGame(randNumb);
        }
        else if (sm == 'n')
        {
            std::cout << "Thank you for playing.\n";
            break;
        }
    }
    return 0;
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавка значения системных часов в качестве стартового числа
    rand(); // Первый вызов rand() для сброса результата этой функции (для большего отличия первого рандомного числа от стартового)
    int randNumb = getRandomNumber(1, 100);
    
    startingGame(randNumb);
    requestForReplay(randNumb);
    

    return 0;
}