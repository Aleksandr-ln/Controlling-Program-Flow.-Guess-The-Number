// MUST HAVE! //
// Названия программы и папки кирилицей
// В гите должно быть только код, остальные файлы, студия сама сгенерирует. Нужно добавить в гитигнор еще файлики
// MUST HAVE! //

#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) // Нужно делать const int&. Ну ок, ты ссылки еще не знаешь, но const то знаешь)))) И поделай функции const. Чего в параметрах не const принимаешь?
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
   
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

bool playGame(int randNumb, int guesses) // Тоже const&. Чего в параметрах не const принимаешь?
{
    for (int i = 1; i <= guesses; ++i)
    {
        std::cout << "Guess #" << i << ":"; // вывод в главной фунции должен быть
        int usersGuess;
        std::cin >> usersGuess; // ввод тоже

        if (usersGuess > randNumb)
        {
            std::cout << "Your guess is too high.\n";
        }
        else if (usersGuess < randNumb)
        {
            std::cout << "Your guess is too low.\n";
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool requestForReplay() // тоже const&. Или указатели но & проще. Ты возвращаешь char а функция должна возвращать bool?
{
    char letter;
    do
    {
        std::cout << "Would you like to play again (y/n)? ";
        std::cin >> letter;
    } while (letter != 'y' && letter != 'n');
    return (letter == 'y');
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавка значения системных часов в качестве стартового числа
    rand(); // Первый вызов rand() для сброса результата этой функции (для большего отличия первого рандомного числа от стартового)
    
    const int guesses = 7; //Почему тут обьявляешь? ты же ее не тут используешь, обьявляй там где ипсользуешь
        
    do
    {
        int randNumb = getRandomNumber(1, 100); // Почему тут обьявляешь? ты же ее не тут используешь, обьявляй там где ипсользуешь

        std::cout << "Let's play a game. I'm thinking of a number. You have " << guesses << " tries to guess what it is.\n";

        bool won = playGame(randNumb, guesses);
        if (won) // можно написать if(playGame(randNumb, guesses)), если тебе не нужна больше переменная won
        {
            std::cout << "Correct! You win!\n";
        }
        else
        {
            std::cout << "Sorry, you lose. The correct number was " << randNumb << ".\n";
        }
    } 
    while (requestForReplay());
    std::cout << "Thank you for playing.\n";
         
    return 0;
}
