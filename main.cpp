#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

//use defined header file-----------------------------------------
#include"projekt_data_lab.h"
//use defined header file-----------------------------------------


//global variables------------------------------------------------
int ans;
int x = -1;
int lb = 0;
int selectedOption;
//global variables------------------------------------------------



//function prototypes---------------------------------------------

void exitScreen();

void characterLoop(int c, int n);
void passMatchedText();

int logInScreen();
void showOption();

void optionSelect();

//main executive functions-----------------------------------------

void recNFound();

void updateFnc(FILE *pt, int t);

void updateInfo();

void transaction();

void checkAccount();

void removeAccount();

void viewList();

//main executive functions-----------------------------------------

//function prototypes---------------------------------------------

int main()
{
    FILE *pt;
    pt = fopen("record.txt", "a");
    fclose(pt);

    if (logInScreen())
    {
        characterLoop(10, 2);
        passMatchedText();

        do
        {
            x = -1;

            system("cls");
            showOption();
            optionSelect();

            //main execution happens here

            if (selectedOption != 7 && x != 1 && x != 2)
            {
                characterLoop(10, 2);
                characterLoop(32, 15);
                printf("Enter 1 to go to the main menu and 0 to exit: ");
                scanf("%d", &ans);
                getchar();

                if (ans != 1)
                {
                    exitScreen();
                }
            }
            else
            {
                ans = 0;
            }


        } while (ans == 1 || x == 1);
    }
    else
    {
        exitScreen();
    }

    getchar();
    return 0;
}

void exitScreen()
{
    system("cls");
    characterLoop(10, 6);
    printf("This projekt is developed by Himel Mazumder (011 161 045) ");
}

void characterLoop(int c, int n)
{
    int lc;
    for (lc = 0; lc < n; lc++)
    {
        printf("%c", c);
    }
}

void passMatchedText()
{
    printf("Password matched!\n");
    printf("Loading");

    for (int i = 0; i < 5; i++)
    {
        printf(".");
        Sleep(300);
    }
}

int logInScreen()
{
    char password[10];
    int choice, invalidOption;

    characterLoop(10, 2);
    characterLoop(32, 15);
    printf("Enter the password to log in: ");
    fflush(stdin);
    fgets(password, 10, stdin);

    while (strcmp(password, "1234\n"))
    {
        characterLoop(10, 2);
        printf("Wrong password!!\n");

        do
        {
            invalidOption = 0;

            printf("Enter 1 to try again and 0 to exit: ");
            fflush(stdin);
            scanf("%d", &choice);
            getchar();

            if (choice == 1)
            {
                system("cls");

                characterLoop(10, 2);
                characterLoop(32, 15);

                printf("Enter the password to log in: ");
                fflush(stdin);
                fgets(password, 10, stdin);
            }
            else if (choice == 0)
            {
                return 0;
            }
            else
            {
                characterLoop(10, 1);
                printf("Invalid!");

                Sleep(350);
                system("cls");
                printf("\n");

                invalidOption = 1;
            }
        } while (invalidOption);

    }

    return 1;
}

void showOption()
{
    characterLoop(10, 2);
    characterLoop(32, 25);
    printf("CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    characterLoop(10, 3);
    characterLoop(32, 25);
    characterLoop(178, 7);
    printf(" WELCOME TO THE MAIN MENU ");
    characterLoop(178, 7);
    characterLoop(10, 2);
    characterLoop(32, 18);
    printf("1. Create new account\n");
    characterLoop(32, 18);
    printf("2. Update information of existing account\n");
    characterLoop(32, 18);
    printf("3. For transaction\n");
    characterLoop(32, 18);
    printf("4. Check the details of existing account\n");
    characterLoop(32, 18);
    printf("5. Removing existing account\n");
    characterLoop(32, 18);
    printf("6. View customers' list\n");
    characterLoop(32, 18);
    printf("7. Exit");
    characterLoop(10, 5);
    characterLoop(32, 18);
    printf("Enter your choice: ");

}

void optionSelect()
{
    scanf("%d", &selectedOption);
    getchar();
    switch (selectedOption)
    {
        case 1:
            system("cls");
            characterLoop(32, 25);
            characterLoop(178, 5);
            printf(" ADD RECORD ");
            characterLoop(178, 5);
            characterLoop(10, 2);

            createAccount();
            characterLoop(10, 2);
            printf("Account created successfully!");
            break;
        case 2:
            system("cls");
            updateInfo();
            break;
        case 3:
            system("cls");
            break;
        case 4:
            system("cls");
            break;
        case 5:
            system("cls");
            break;
        case 6:
            system("cls");
            break;
        case 7:
            exitScreen();
            break;
        default:
            system("cls");
            printf("Wrong choice!");
            break;
    }

}

bool isFound(FILE *pt, int item)
{
    int temp;
    char c;

    do
    {
        fscanf(pt, "%d", &temp);
        if (temp == item)
        {
            return true;
            break;
        }

        c = fgetc(pt);

        while (c != EOF && c != 10)
        {
            c = fgetc(pt);
        }
        lb++;
    } while (c != EOF);

    return false;
}

void recNFound()
{
    printf("Record not found!!\n");
    printf("Enter 0 to try again, 1 to return to main menu, and 2 to exit: ");
}

void updateFnc(FILE *pt, int t)
{

    FILE *pt2;
    pt2 = fopen("new.txt", "w");

    int lc_t1 = 0, lc_t2 = 0;


    fseek(pt, 0, SEEK_SET);

    char addTmp[30];
    int phone;

    int ws = 0;

    system("cls");

    if (t == 4)
    {
        printf("Enter the new address: ");
        fgets(addTmp, 30, stdin);
        fgets_corrected(addTmp, 1);
    }
    else
    {
        printf("Enter the new phone number: ");
        fgets(addTmp, 30, stdin);
        fgets_corrected(addTmp, 0);
    }


    char c;


    while (lc_t1 < lb)
    {
        c = fgetc(pt);
        fprintf(pt2, "%c", c);

        if (c == 10)
            lc_t1++;
    }


    if (t == 4)
    {
        while (ws != t)
        {
            c = fgetc(pt);
            fprintf(pt2, "%c", c);

            if (c == 32)
                ws++;
        }
    }
    else
    {
        do
        {
            c = fgetc(pt);
            fprintf(pt2, "%c", c);

        } while (c != '|');

        while (ws != 2)
        {
            c = fgetc(pt);
            fprintf(pt2, "%c", c);

            if (c == 32)
                ws++;
        }
    }

    while (addTmp[lc_t2] != 0)
    {
        c = addTmp[lc_t2];
        fprintf(pt2, "%c", c);

        lc_t2++;
    }

    if (t == 4)
    {
        do
        {
            c = fgetc(pt);
        } while (c != '|');
    }
    else
    {
        do
        {
            c = fgetc(pt);
        } while (c != ' ');

        fprintf(pt2, " ");
    }



    while (c != EOF)
    {
        c = fgetc(pt);
        if (c != EOF)
            fprintf(pt2, "%c", c);
    }

    fclose(pt2);
    lb = 0;

    system("cls");
    printf("Changes saved!!");
}

void updateInfo()
{
    int sAC_N, option, lb;
    FILE *pt;
    pt = fopen("record.txt", "r");

    if (fgetc(pt) == EOF)
    {
        printf("No record found!");
    }
    else
    {
        do
        {
            fseek(pt, 0, SEEK_SET);
            printf("Enter the account number of the custormer whose info you want to change: ");
            scanf("%d", &sAC_N);
            getchar();

            if (!isFound(pt, sAC_N))
            {
                recNFound();
                scanf("%d", &x);
                getchar();

                if (x == 0)
                {
                    system("cls");
                }
                else if (x == 1)
                {

                }
                else if (x == 2)
                {
                    ans = 0;
                    exitScreen();
                }
            }
            else
            {
                x = 4;
            }
        } while (x == 0);


        if (x == 4)
        {
            printf("\nwhich information you want to change?\n1. Address\n2. Phone\n\nEnter your choice (1 for address and 2 for phone): ");
            scanf("%d", &option);
            getchar();


            if (option == 1)
            {
                updateFnc(pt, 4);
            }
            else if (option == 2)
            {
                updateFnc(pt, 6);
            }
            else
            {
                printf("wrong choice!!");
            }
        }
    }

    fclose(pt);

    if (x == 4)
    {
        remove("record.txt");
        rename("new.txt", "record.txt");
    }
}

void transaction()
{

}

void checkAccount()
{

}

void removeAccount()
{

}

void viewList()
{

}
