#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PARTS 7
#define PHRASE "messi"
#define HINT "A Short Goat From Argentina"

int fails = 0;
bool won = false;

char CORRECT_GUESS[] = {};
char INCORRECT_GUESS[] = {};

void welcomeBanner();
void playHangman();
void showHint();
void loadGuess();
void printGuesses();
bool checkCharacterGuess(char guess);
bool checkWin();
void printResults();
void drawHangman(int range);

int main()
{
    loadGuess();
    do
    {
        welcomeBanner();
        system("echo ------------------------------------------------------------------------------------");
        printGuesses();
        system("echo ------------------------------------------------------------------------------------");
        drawHangman(fails);
        playHangman();
        sleep(1);
        if (checkWin() == true)
            won = true;
    } while (fails != PARTS && won == false);
    printResults();
}

void playHangman()
{
    char guess = ' ';
    printf(">>> ");
    scanf(" %c", &guess);

    if (checkCharacterGuess(guess) == true)
    {
        printf("(%c) is in the phrase \n", guess);
    }
    else
    {
        printf("(%c) is not in the phrase / word \n", guess);
        fails += 1;
    }
}

void loadGuess()
{
    for (int counter = 0; counter < strlen(PHRASE); counter++)
    {
        CORRECT_GUESS[counter] = '_';
    }
}

void showHint()
{
    printf("HINT: %s\n", HINT);
}

void printGuesses()
{
    for (int counter = 0; counter < strlen(PHRASE); counter++)
    {
        printf("%c", CORRECT_GUESS[counter]);
    }
    printf("\n");
}

bool checkWin()
{

    bool isNotEmpty = true;

    for (int counter = 0; counter < strlen(PHRASE); counter++)
    {
        if (CORRECT_GUESS[counter] == '_')
            isNotEmpty = false;
    }

    return isNotEmpty;
}

bool checkCharacterGuess(char guess)
{
    bool found = false;

    for (int index = 0; index < strlen(PHRASE); index++)
    {
        if (PHRASE[index] == tolower(guess))
        {
            CORRECT_GUESS[index] = PHRASE[index];
            found = true;
        }
        else
        {
            continue;
        }
    }
    return found;
}

void printResults()
{
    welcomeBanner();
    printGuesses();
    system("echo ------------------------------------------------------------------------------------");
    if (won)
    {
        printf("\nVICTORY\n");
    }
    else
    {
        printf("\nDEFEAT\n");
    }
}

void welcomeBanner()
{
    system("clear");
    system("echo ------------------------------------------------------------------------------------");
    system("echo HANGMAN");
    system("echo ------------------------------------------------------------------------------------");
    showHint();
    system("echo ------------------------------------------------------------------------------------");
    printf("Word: ");
}

void drawHangman(int range)
{
    printf("~~~~~~~\n");
    printf("      !\n");

    char *parts[7] = {"      O", "     /", "|", "\\", "      |", "     / ", "\\"};

    for (int index = 0; index < range; index++)
    {
        printf("%s", parts[index]);

        if (index == 0 || index == 3 || index == 4)
            printf("\n");
    }

    printf("\n");
    printf("\n");
    printf("\n");
}