#include <iostream>
#include <vector>
#include <ctime>

int main() 
{
    srand(time(0));
    setlocale(LC_ALL,"ru");
    int n = 8;
    std::vector<std::vector<int>> mas(n);
    for (int i = 0;i < mas.size();i++)
    {
        mas[i].resize(n);// для работы с памятью
        for (int j = 0;j < mas.size();j++)
        {
            if (i == j)
                mas[i][j] = 0;
            else
            {
                mas[i][j] = rand() % 4;//заполняем случайными числами 
            }
            if (mas[i][j] == 2)
                mas[i][j] = 1;
        }
    }
    for(int i =0 ; i<mas.size();i++)
    {
        for(int j=0;j<mas.size();j++)
        {
            if(i!=j)
            {
                if(abs(i - j))
                {
                    if(mas[i][j]== 1)
                    {
                        mas[j][i] = 1;
                    }
                    if (mas[i][j] == 3)
                        mas[j][i] = 0;
                    if (mas[i][j] == 0)
                        mas[j][i] = 3;
                }
                
            }
        }
    }
    for (int i = 0;i < mas.size();i++)
    {
        for (int j = 0;j < mas.size();j++)
        {
            std::cout << mas[i][j] << " ";//выводим
        }
        std::cout << "\n";
    }
    std::vector <int> diff; // создаем массив, чтобы определить у кого больше обед
    for (int i = 0;i < mas.size();i++)
    {
        int wins = 0, losses = 0;
        for (int j = 0;j < mas.size();j++)
        {
            if (i != j)
            {
                if (mas[i][j] == 3)
                    wins++;
                if(mas[i][j] == 0)
                    losses++;
            }
        }
        if (wins > losses)  
            diff.push_back(i);// добавляем в массив

    }
    std::cout << "Команды, имеющие больше побед, чем поражений " << "\n";
    for (int i = 0;i < diff.size();i++)
    {
        std::cout << diff[i] + 1 << " ";// увеличиваем потому что счет идет с 0
    }
    std::cout << "\n";
    std::vector<int> best;// создаем вектор чтобы определить какая команда выиграла больше половины игр
    for (int i = 0; i < mas.size(); ++i) {
        int wins = 0, games = 0;
        for (int j = 0; j < mas[i].size(); ++j) {
            if (j != i) {
                    if (mas[i][j] == 3)//если выйгрыш то увеличиваем wins
                    ++wins;
                ++games;// считаем количество игр
            }
        }
        if (wins > games / 2)
        {
            best.push_back(i);//добавляем в массив
        }
    }
    std::cout << "Команды,выигравшие больше половины игр:" << "\n";
    for (int i = 0; i < best.size(); ++i)
    {
        std::cout << best[i] + 1 << " ";
    }
}