#include<stdio.h>
#include<stdlib.h>
int main(){
    printf("\n\n\n\t\t\t\t.....WELCOME TO SIMPLE CALCULATOR.....\n\n");
    printf("\t\tA calculator is a device that performs arithmetic operations on numbers. \n\t\tBasic calculators can do only addition, subtraction, multiplication \n\t\tand division mathematical calculations.\n\n");
    system("COLOR 2");
    char ans;
    do{
        printf("\n\t\tPress to 'c' for continue || Press to 'e' for exit : ");
        scanf("%s",&ans);
        system("cls");
        if(ans == 'c'){
        ///user inputs two numbers from keyboard
        double number1,number2,result;
        printf("\n\n\t\tEnter the two number from keyboard : ");
            scanf("%lf%lf",&number1,&number2);
            printf("\n");

            ///user input a choice for calculation
            int choice,divisionchoice;
            printf("\t\tYou can pick any one operation : 1. Addition;\n\t\t\t\t\t\t 2. Subtraction;\n\t\t\t\t\t\t 3. Multiplication;\n\t\t\t\t\t\t 4. Division;\n");
            printf("\t\tEnter your choice : ");
            fflush(stdin);
            scanf("%d",&choice);
            printf("\n");

            switch(choice){
             case 1:
                result = number1 + number2;
                printf("\n\t\t%.2lf + %.2lf = %.2lf\n",number1,number2,result);
                break;
             case 2:
                result = number1 - number2;
                printf("\n\t\t%.2lf - %.2lf = %.2lf\n",number1,number2,result);
                break;
             case 3:
                result = number1 * number2;
                printf("\n\t\t%.2lf * %.2lf = %.2lf\n",number1,number2,result);
                break;
             case 4:
                result = number1 / number2;
                printf("\n\t\tThe Division is : %.2lf / %.2lf = %lf\n\n",number1,number2,result);
                printf("\t\tEnter the Choice for Division(1:Quotient; 2:Remainder) : ");
                scanf("%d",&divisionchoice);

                if(number2!=0){
                    switch(divisionchoice){
                     case 1:
                        result = (int)number1 / (int)number2;
                        fflush(stdout);
                        printf("\n\t\t%lf / %lf = %.lf\n",number1,number2,result);
                        break;
                     case 2:
                        result = (int)number1 % (int)number2;
                        printf("\n\t\t%.2lf %% %.2lf = %lf\n",number1,number2,result);
                        break;
                     default:
                        printf("\t\tInvalid choice for division. Please enter 1 or 2.\n");
                    }
                }
                else{
                    printf("\t\tError : Divisor is zero");
                }
                break;
             default:
                printf("\t\tInvalid Choice. Please enter a number between 1 and 4.\n");
                break;
            }
        }
    }
    while(ans != 'e');
    return 0;
}
