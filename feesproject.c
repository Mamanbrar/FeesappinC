#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define ESC 27
#define F1 59
#define F2 60

void gotoxy(int x, int y)
{
    COORD c = {x, y};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

struct studentdata
{
    char name[20];
    int uid;
    int fees;
};

struct studentdata s1;
struct studentdata s2;

int main()
{

    while (1)
    {

        system("cls");
        system("COLOR C0");

        FILE *ptr;

        gotoxy(72, 10);
        printf("..................MAMANDEEP SINGH BRAR..................");
        gotoxy(72, 13);
        printf("________YOUR WARM WELCOME IN BRAR'S IMAGINATION________");
        gotoxy(86, 16);
        printf("*******FEES APP*******");
        gotoxy(74, 19);
        printf("---------PRESS F1 FOR REGISTERING NEW STUDENT-------");
        gotoxy(74, 22);
        printf("---------PRESS F2 TO DEPOSIT FEES OF STUDENT-------");
        gotoxy(82, 25);
        printf("---------PRESS ESC TO EXIT----------");

        int ch;
        getch();
        ch = getch();
        if (ch == F1)
        {
            system("cls");
            system("COLOR B0");
            gotoxy(80, 22);
            printf("ENTER THE NAME OF STUDENT : ");
            gets(s1.name);
            gotoxy(80, 24);
            printf("ENTER UID OF THE STUDENT : ");
            scanf("%d", &s1.uid);
            gotoxy(80, 26);
            printf("ENTER TOTAL FEES OF STUDENT : ");
            scanf("%d", &s1.fees);

            ptr = fopen("studentdata.bin", "ab");
            fwrite(&s1, sizeof(s1), 1, ptr);
            fclose(ptr);

            system("cls");
            system("COLOR F0");
            gotoxy(74, 21);
            printf("---------PRESS F1 TO MAIN MENU-------");
            gotoxy(79, 23);
            printf("------------PRESS ESC TO EXIT----------");
            gotoxy(82, 25);
            printf("Your Details are as Follow - \n");
            gotoxy(82, 26);
            printf("Name : ");
            puts(s1.name);
            gotoxy(82, 27);
            printf("UID : %d\n", s1.uid);
            gotoxy(82, 28);
            printf("Fees : %d\n", s1.fees);
            gotoxy(84, 35);
            printf("INFORMATION SAVED");

            int ch1;
            getch();
            ch1 = getch();

            if (ch1 == F1)
            {
                continue;
            }

            else if (ch1 == ESC)
            {
                break;
            }
        }
        else if (ch == F2)
        {
            system("cls");
            system("COLOR B0");

            int uid, flag = 0, amount = 0;

            gotoxy(80, 22);
            printf("Enter the UID of student : ");
            scanf("%d", &uid);

            ptr = fopen("studentdata.bin", "rb+");

            fseek(ptr, 0, 1);

            while (fread(&s2, sizeof(s2), 1, ptr) == 1)
            {
                if (s2.uid == uid)
                {
                    gotoxy(80, 24);
                    printf("Enter the amount of fees want to give : ");
                    scanf("%d", &amount);
                    fseek(ptr, -sizeof(s2), 1);
                    s2.fees = s2.fees - amount;
                    fwrite(&s2, sizeof(s2), 1, ptr);
                    flag = 1;
                    break;
                }
            }

            system("cls");
            system("COLOR F0");

            gotoxy(74, 21);
            printf("---------PRESS F1 TO MAIN MENU-------");
            gotoxy(79, 23);
            printf("------------PRESS ESC TO EXIT----------");

            if (flag)
            {

                gotoxy(85, 26);
                printf("RECIPT");
                gotoxy(80, 28);
                printf("Name : ");
                puts(s2.name);
                gotoxy(80, 29);
                printf("UID : %d\n", s2.uid);
                gotoxy(80, 30);
                printf(" Pending Fees : %d\n", s2.fees);
            }
            else
            {

                gotoxy(80, 30);
                printf("***********NO RECORD FOUND***********");
            }

            int ch1;
            getch();
            ch1 = getch();

            if (ch1 == F1)
            {
                continue;
            }

            else if (ch1 == ESC)
            {
                break;
            }
        }
        else if (ch == ESC)
        {
            break;
        }
    }
        return 0;
    
}    