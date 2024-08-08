#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void insideofgame(char choice);
int playerscore=0,computerscore=0;
int main(){
    char play,choice;
    printf("\n\n\n\n\t\t\t\t\t......WELCOME TO THE GAME......\n\n\n");
    printf("\t\tRock, paper, scissors is a fun and easy hand game that anyone can learn and enjoy. \n\t\tIt is a great way to improve critical thinking and communication skills to help make \n\t\tminor decisions when kids and their friends can’t agree, or even just an entertaining \n\t\tway to pass the time.\n\n");
    printf("\t\tRock beats scissors and loses to paper: Rock is strong enough to break scissors, \n\t\tbut paper wraps itself around the rock to shut it down.\n");
    printf("\t\tPaper beats rock but loses to scissors: Paper wraps itself around the rock to lock it down, \n\t\tbut it can’t fight back against the sharp scissors which can cut it.\n");
    printf("\t\tScissors beat paper but loses to rock: Scissors can cut through paper, \n\t\tbut they can not stand up to a rock slamming down on them.\n");
    printf("\n\t\tIf the match is tie it will turn blue.\n\t\tIf you win the game it will be green color.\n\t\tIf you lost the game, it will be red.\n");
    system("COLOR 6");
    do
    {
        fflush(stdout);
        printf("\n\n\t\tPress 'c' to Play || Press 'e' to exit :");
        scanf("%s",&play);
        system("cls");
        if(play == 'c'){
            printf("\n\n\n\n\t\t\t\t\t........ROCK-PAPER-SCISSORS........\n");
            printf("\n\t\tRock = 'R'\n\t\tPaper = 'P'\n\t\tScissors = 'S'\n");
            printf("\n\t\tEnter your choice : ");
            scanf("%s",&choice);
            /*if(choice != 'R' || choice != 'P' ||choice != 'S'){
                  printf("\n\t\tInvalid Choice! Please enter the right choice(R,P,S) :");
                  scanf("%s",&choice);
            }*/
            insideofgame(choice);
        }
       printf("\n");
       if(playerscore>computerscore){
           printf("\n\t\tPlayer is 'WIN' %d to %d\n",playerscore,computerscore);
       }
       else if(computerscore>playerscore){
          printf("\n\t\tComputer is 'WIN' %d to %d\n",computerscore,playerscore);
       }
       else{
          printf("\n\t\tGame is 'TIE!' %d to %d\n",playerscore,computerscore);
       }


    }
    while(play != 'e');
    system("cls");
    return 0;
}
void insideofgame(char choice){
     int random;
     int score,total=0;
     srand(time(NULL));
     ///random number generate
     random = rand()%3;

     ///game condition

    if(random==0 && choice=='R')
    {
        printf("\t\tComputer= Rock\n");
        printf("\t\tTIE!\n");
        system("COLOR 3");
        total=score;
        printf("\t\t%d score: ",total);
    }
    else if(random==1 && choice=='R')
    {
        printf("\t\tComputer= Paper\n");
        printf("\t\tGAME OVER!\n");
        system("COLOR 4");
        score--;
        total=total+score;
        printf("\t\t%d score",total);
        computerscore++;
    }
    else if(random==2 && choice=='R')
    {
        printf("\t\tComputer= Scissors\n");
        printf("\t\tWIN!\n");
        system("COLOR 2");
        score++;
        total=total+score;
        printf("\t\t%d score",total);
        playerscore++;
    }
    else if(random==0 && choice=='P')
    {
        printf("\t\tComputer= Rock\n");
        printf("\t\tWIN!\n");
        system("COLOR 2");
        score++;
        total=total+score;
        printf("\t\t%d score",total);
        playerscore++;
    }
    else if(random==1 && choice=='P')
    {
        printf("\t\tComputer= Paper\n");
        printf("\t\tTIE!\n");
        system("COLOR 3");
        total=score;
        printf("\t\t%d score",total);
    }
    else if(random==2 && choice=='P')
    {
        printf("\t\tComputer= Scissors\n");
        printf("\t\tGAME OVER!\n");
        system("COLOR 4");
        score--;
        total=total+score;
        printf("\t\t%d score",total);
        computerscore++;
    }
    else if(random==0 && choice=='S')
    {
        printf("\t\tComputer= Rock\n");
        printf("\t\tGAME OVER!\n");
        system("COLOR 4");
        score--;
        total=total+score;
        printf("\t\t%d score",total);
        computerscore++;
    }
    else if(random==1 && choice=='S')
    {
        printf("\t\tComputer= Paper\n");
        printf("\t\tWIN!\n");
        system("COLOR 2");
        score++;
        total=total+score;
        printf("\t\t%d score",total);
        playerscore++;
    }
    else if(random==2 && choice=='S')
    {
        printf("\t\tComputer= Scissors\n");
        printf("\t\tTIE!\n");
        system("COLOR 3");
        total=score;
        printf("\t\t%d score",total);
    }

}

