#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

void screenheader();
void play();
void instruction();
void credits();

int main() {
    screenheader();
    char ans, choice;
    do {
        printf("\n\tPress 'c' to continue || Press 'e' to exit : ");
        scanf(" %c", &ans); // Added a space before %c to consume any leftover whitespace

        if (ans == 'c') {
            system("cls");
            printf("\n\n\t\t\t\tPlease Choose any Category : \n\n");
            printf("                            \t\tP: PLAY\n");
            printf("                            \t\tI: INSTRUCTIONS\n");
            printf("                            \t\tC: CREDITS\n");
            printf("                            \t\tQ: QUIT\n\n");
            printf("                                --------------------------\n\n");

            printf("                              Enter your Choice : ");
            scanf(" %c", &choice); // Added a space before %c to consume any leftover whitespace
            printf("\n");

            switch (choice) {
                case 'P':
                    play();
                    break;
                case 'I':
                    instruction();
                    break;
                case 'C':
                    credits();
                    break;
                case 'Q':
                    return 0;
                default:
                    printf("\n\n\n\tWrong choice!!!!Please choose C, I, P, Q\n\n");
            }
        }
    } while (ans != 'e');
    return 0;
}

void screenheader() {
    system("COLOR 2");
    printf("\n\t\t\t\t\t......WELCOME TO HANGMAN GAME......\n\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\t\t\t\t|   #  #    #    #   #  #### #   #    #    #   #  |\n");
    printf("\t\t\t\t|   #  #   # #   ##  # #     ## ##   # #   ##  #  |\n");
    printf("\t\t\t\t|   ####  #####  # # # #  ## # # #  #####  # # #  |\n");
    printf("\t\t\t\t|   #  # #     # #  ## #   # #   # #     # #  ##  |\n");
    printf("\t\t\t\t|   #  ##       ##   #  ###  #   ##       ##   #  |\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\n\n\tHangman is a word-guessing game. One player picks a secret word, and the other player tries to guess it.\n");
    printf("\tWhen the guessing player guesses a letter that isn't in the word, they lose a point and the first player\n");
    printf("\tdraws part of a stick-man for each wrong guess.\n\n\n\n");
}

void play() {
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t LOADING ");
    for (int i = 1; i <= 10; i++) {
        Sleep(300);
        printf(". ");
    }
    system("cls");
    printf("\n\n");
    printf("\t\t\t\t -------------------------------------------------\n");
    printf("\t\t\t\t|   #  #    #    #   #  #### #   #    #    #   #  |\n");
    printf("\t\t\t\t|   #  #   # #   ##  # #     ## ##   # #   ##  #  |\n");
    printf("\t\t\t\t|   ####  #####  # # # #  ## # # #  #####  # # #  |\n");
    printf("\t\t\t\t|   #  # #     # #  ## #   # #   # #     # #  ##  |\n");
    printf("\t\t\t\t|   #  ##       ##   #  ###  #   ##       ##   #  |\n");
    printf("\t\t\t\t -------------------------------------------------\n\n\n");

    printf("\t\t\t\t\t\t ________\n");
    printf("\t\t\t\t\t\t|        |\n");
    printf("\t\t\t\t\t\t|        0\n");
    printf("\t\t\t\t\t\t|       /|\\\n");
    printf("\t\t\t\t\t\t|       / \\\n");
    printf("\t\t\t\t\t\t|         \n");
    printf("\t\t\t\t\t      ////////////////\n\n\n");

    char word[100], ch;
    int i;

    printf("\t\t\t\tPLAYER-1:\n\n");
    printf("\t\t\t\tEnter your chosen word in small letter : ");
    for (i = 0;;) {
        ch = getch();
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
            word[i] = ch;
            ch = '*';
            printf("%c", ch);
            i++;
        } else if (ch == '\b' && i > 0) { // Ensure we don't go out of bounds
            --i;
            printf("\b \b");
        } else if (ch == '\r') {
            word[i] = '\0';
            break;
        }
    }
    system("cls");
    printf("\n\n\n\t\tPLAYER-2:\n\n");
    printf("\t\tWord Blocks[%d]: ",strlen(word));

    char answerArray[100];
    int wordLength = strlen(word);
    for (i = 0; i < wordLength; i++) {
        answerArray[i] = '_';
    }
    answerArray[wordLength] = '\0'; // Null-terminate the array

    printf("%s ", answerArray);
    int remainingLetters = wordLength;
    int score = 0;

    while (remainingLetters > 0 && score < 6) {
        char guess;
        int correctGuess = 0;
        printf("\n\n\t\tEnter your guess in small letter : ");
        scanf(" %c", &guess); // Added a space before %c to consume any leftover whitespace

        for (i = 0; i < wordLength; i++) {
            if (word[i] == guess && answerArray[i] == '_') {
                answerArray[i] = guess;
                remainingLetters--;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            score++;
            printf("\n\t\tIncorrect guess! You have %d incorrect guesses left.\n", 6 - score);
        }

        printf("\t\t%s \n", answerArray);

        // Draw the hangman based on the score
        printf("\t\t\t\t\t\t ________\n");
        printf("\t\t\t\t\t\t|        |\n");
        printf("\t\t\t\t\t\t|        %c\n", (score > 0) ? '0' : ' ');
        printf("\t\t\t\t\t\t|       %c%c%c\n", (score > 2) ? '/' : ' ', (score > 1) ? '|' : ' ', (score > 3) ? '\\' : ' ');
        printf("\t\t\t\t\t\t|       %c %c\n", (score > 4) ? '/' : ' ', (score > 5) ? '\\' : ' ');
        printf("\t\t\t\t\t\t|         \n");
        printf("\t\t\t\t\t      ////////////////\n\n\n");
    }

    if (remainingLetters == 0) {
        printf("\n\tCongratulations! You've guessed the word: %s\n", word);
    } else {
        printf("\n\tGame Over! The word was: %s\n", word);
    }
}

void instruction() {
    system("cls");
    printf("\n\n\t\t\t\tINSTRUCTIONS:\n\n");
    printf("\t1. The game is played by two players.\n");
    printf("\t2. Player 1 will enter a word secretly, and Player 2 will try to guess it.\n");
    printf("\t3. For every incorrect guess, a part of the hangman is drawn.\n");
    printf("\t4. Player 2 has a maximum of 6 incorrect guesses.\n");
    printf("\t5. If Player 2 guesses the word before the hangman is completely drawn, they win.\n");
    printf("\t6. If the hangman is completely drawn, Player 1 wins.\n\n");
    printf("\tPress any key to return to the main menu...\n");
    getch();
}

void credits() {
    system("cls");
    printf("\n\n\t\t\t\tCREDITS:\n\n");
    printf("\tProject : HANGMAN on C Programming Language\n");
    printf("\tHangman Game developed by: SIFAT ZAMAN\n");
    printf("\tDepartment of Computer Science & Engineering\n");
    printf("\tUnited International University\n");
    printf("\tRoll : 0112330278\n\n");
    printf("\tPress any key to return to the main menu...\n\n");
    getch();
}

