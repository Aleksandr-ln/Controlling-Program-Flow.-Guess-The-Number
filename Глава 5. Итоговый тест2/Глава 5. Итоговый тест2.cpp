// MUST HAVE! //
// Названия программы и папки кирилицей
// В гите должно быть только код, остальные файлы, студия сама сгенерирует. Нужно добавить в гитигнор еще файлики
// MUST HAVE! //

#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) // Нужно делать const int&. Ну ок, ты ссылки еще не знаешь, но const то знаешь)))) И поделай функции const
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
   
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void startingGame(int randNumb) // Тоже const&
{
    randNumb = getRandomNumber(1, 100); // Вызов функции для получения нового рандомного числа, для каждой последующей игры
    // Копированик кода getRandomNumber(). Сделай что бы ты раз ее вызывал
    std::cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is.\n";
    int usersGuess;
    for (int iii = 1; iii <= 7; iii++) // зачем iii, i достаточно 
    {
        std::cout << "Guess #" << iii << ":"; // вывод в главной фунции должен быть
        std::cin >> usersGuess; // ввод тоже
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

char requestForReplay(int randNumb) // тоже const&. Или указатели но & проще
 // char? Зачем? Ты знаешь зачем тип char???
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
    return 0; // Как return 0 вяжется к char?? 
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавка значения системных часов в качестве стартового числа
    rand(); // Первый вызов rand() для сброса результата этой функции (для большего отличия первого рандомного числа от стартового)
    int randNumb = getRandomNumber(1, 100); // копирование кода
    
    startingGame(randNumb);
    requestForReplay(randNumb);
    

    return 0;
}
