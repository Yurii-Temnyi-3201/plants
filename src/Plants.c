#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define LIFE 20  // ��� ����� �������

int numPlants(int year) {
    if (year < 4) { //�� 4-�� ���� ����� ������� �� �� �����������
        return 0;
    } else if (year == 4) {
        return 1; //����� ������� ������ ����������� �� 4-� ��
    } else if (year > LIFE + 1) { //���� �� ����� �� ������������ ��� ����� �������, ��������� �� �������, �� �'������� � ��������� �����, � ���������� �������, �� ��� ������ � ��������� �����
        return numPlants(year - 1) + numPlants(year - 3) - numPlants(year - LIFE - 1);
    } else { //��� ��� ����� ���� �������� ������� � �������� ����
        return numPlants(year - 1) + numPlants(year - 3);
    }
}

int numFruits(int year) {
    if (year < 4) { //�� 4-�� ���� ����� �� �'���������
        return 0;
    } else { //������� ����� � ������ ���� ������� ������� ������, �� ������ ����������� ��� ���� ����
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
        printf("�������\n");
        Sleep(500);
        printf("\n���� ���\n");
        Sleep(500);
        printf("\n� ������ �� �������� ���� ��� �������. ���� ���, ���� �'������ � 4-�� ����, ������ ��������� � �����, � ��� �� ��������� 1-� ����� �����\n");
        Sleep(500);
        printf("���� ������� (��� ����� ��� ��������� ����� ����� ������ � ����� ���� �� ������� �� �� ���� ���������). �� ������� ����� ����� �������� � 5-�� ����,\n");
        Sleep(500);
        printf("����� ����������� � 7-�, � ������� ��� ���� ����������� � 23-�� ���� � ��������� ���� ����� � 24-��. ��� ��������� ����� ����� ������ � 20-�� ����\n");
        Sleep(500);
        printf("������� ������� �� ��������� �����, � � 21-�� � ��� �� ��������� �����.\n\n");
        Sleep(500);
        printf("��� ������� ��� ������� ������ 1 �� ���������� ����. ��� �����, ������ 0.");
        Sleep(500);
        printf("\n> ");

        if (scanf("%d", &a) != 1) //�������� �� ���
        {
            fflush(stdin);
            printf("������������ ����. ��������� �� ���.\n");
            Sleep(500);
            continue;
        }
        system("cls");

        if (a == 1)
        {
            int years = 24; //������� ����
            int totalPlants = 0, totalFruits = 0, maxPlantsYear = 0, maxFruitYear = 0, maxPlants = 0, maxFruits = 0; // ���� ��� ���������� �������� ������� ������ � ����� �� ���� ���, ����, � ����� ���� ����������� ������� ������ � �����, ����������� ������� ������ � �����, �� ���� � ����-���� �� ��������
            int i, year;

            printf("г� | ʳ������ ����� | ʳ������ �����\n");
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
            printf("\n�������� ������� �����: %d\n", totalPlants);
            Sleep(500);
            printf("�������� ������� �����: %d\n", totalFruits);
            Sleep(500);
            printf("г� � ������������ ������� �����: %d (�������: %d)\n", maxPlantsYear, maxPlants);
            Sleep(500);
            printf("г� � ������������ ������� �����: %d (�������: %d)\n", maxFruitYear, maxFruits);
            Sleep(500);
            printf("\n\n\n�������� ����-��� ������ ��� ���������� ������...");
            getch();
            return 0;
        }
        if (a == 0) {
            return 0;
        }
        else
        {
            printf("������������ ����. ��������� �� ���.\n");
            getch();
        }
    }
}