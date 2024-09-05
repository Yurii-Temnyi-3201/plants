#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define LIFE 20  // час життя рослини

int numPlants(int year) {
    if (year < 4) { //до 4-го року жодна рослина ще не плодоносить
        return 0;
    } else if (year == 4) {
        return 1; //перша рослина починає плодоносити на 4-й рік
    } else if (year > LIFE + 1) { //якщо рік більше за максимальний час життя рослини, враховуємо всі рослини, які з'явилися в попередніх роках, і вираховуємо рослини, які вже вийшли з активного стану
        return numPlants(year - 1) + numPlants(year - 3) - numPlants(year - LIFE - 1);
    } else { //для всіх інших років враовуємо рослини з попердніх років
        return numPlants(year - 1) + numPlants(year - 3);
    }
}

int numFruits(int year) {
    if (year < 4) { //до 4-го року плоди не з'являються
        return 0;
    } else { //кількість плодів у даному році відповідає кількості рослин, які почали плодоносити три роки тому
        return numPlants(year - 3);
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a;

    while (1)
    {
        system("cls");
        Sleep(500);
        printf("Рослини\n");
        Sleep(500);
        printf("\nОПИС ГРИ\n");
        Sleep(500);
        printf("\nВ перший рік садиться один плід рослини. Потім плід, який з'явився в 4-му році, відразу потрапляє в землю, і цей рік вважається 1-м роком життя\n");
        Sleep(500);
        printf("нової рослини (при цьому при підрахунку числа живих рослин в цьому році ця рослина ще не буде врахована). Ця рослина дасть перші паростки в 5-му році,\n");
        Sleep(500);
        printf("почне плодоносити в 7-м, а останній раз буде плодоносити в 23-му році і перестане бути живим в 24-му. При підрахунку числа живих рослин в 20-му році\n");
        Sleep(500);
        printf("вихідна рослина ще вважається живою, а в 21-му – вже не вважається такою.\n\n");
        Sleep(500);
        printf("Для початку гри потрібно ввести 1 та підтвердити вибір. Щоб вийти, введіть 0.");
        Sleep(500);
        printf("\n> ");

        if (scanf("%d", &a) != 1) //перевірка на ввід
        {
            fflush(stdin);
            printf("Неправильний вибір. Спробуйте ще раз.\n");
            Sleep(500);
            continue;
        }
        system("cls");

        if (a == 1)
        {
            int years = 24; //кількість років
            int totalPlants = 0, totalFruits = 0, maxPlantsYear = 0, maxFruitYear = 0, maxPlants = 0, maxFruits = 0; // змінні для збереження загальної кількості рослин і плодів за весь час, року, у якому була максимальна кількість рослин і плодів, максимальної кількості рослин і плодів, які були в будь-який рік відповідно
            int i, year;

            printf("Рік | Кількість дерев | Кількість плодів\n");
            printf("----------------------------------------\n");
            for (year = 1; year <= years; year++)
            {
                int plants = numPlants(year);
                int fruits = numFruits(year);

                totalPlants += plants;
                totalFruits += fruits;

                if (plants > maxPlants) {
                    maxPlants = plants;
                    maxPlantsYear = year;
                }

                if (fruits > maxFruits) {
                    maxFruits = fruits;
                    maxFruitYear = year;
                }

                Sleep(500);
                printf("%d   | %16d | %16d\n", year, plants, fruits);
            }

            Sleep(500);
            printf("\nЗагальна кількість дерев: %d\n", totalPlants);
            Sleep(500);
            printf("Загальна кількість плодів: %d\n", totalFruits);
            Sleep(500);
            printf("Рік з максимальною кількістю дерев: %d (кількість: %d)\n", maxPlantsYear, maxPlants);
            Sleep(500);
            printf("Рік з максимальною кількістю плодів: %d (кількість: %d)\n", maxFruitYear, maxFruits);
            Sleep(500);
            printf("\n\n\nНатисніть будь-яку клавішу для завершення роботи...");
            getch();
            return 0;
        }
        if (a == 0) {
            return 0;
        }
        else
        {
            printf("Неправильний вибір. Спробуйте ще раз.\n");
            getch();
        }
    }
}