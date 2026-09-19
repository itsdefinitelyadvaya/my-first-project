#include<stdio.h>

void printScreen(char *line1, char *line2, char *line3, char *line4){
    printf("\n");
    printf("========================================\n");
    printf("||          * BANK ATM *              ||\n");
    printf("========================================\n");
    printf("|| %-36s ||\n", line1);
    printf("|| %-36s ||\n", line2);
    printf("|| %-36s ||\n", line3);
    printf("|| %-36s ||\n", line4);
    printf("========================================\n");
}

int main(){
    int note=0,withdraw=0,balance=0,option=0;

    printScreen("Welcome to the bank", "1.Deposit  2.Withdraw", "3.Check balance  4.Exit", "");

    int a=1;
    while(a>0){
        printf("Enter ur option\n");
        scanf("%d",&option);
        switch(option){
            case 1:
            {
                printScreen("You have chosen: DEPOSIT", "", "", "");
                int n=0;
                printf("Enter no of notes u have\n");
                scanf("%d",&n);
                for(int i=0;i<n;i++){
                    printf("Enter the amount to be deposited note the deposit should be in 100 or 200 or 500 denominations\n");
                    scanf("%d",&note);
                    if(note==100 || note==200 || note ==500){
                        balance = balance + note;
                    }
                    else{
                        printf("Please deposit legal money denomination\n");
                    }
                }
                printScreen("Deposit successful", "", "", "");
                break;
            }
            case 2:
                printScreen("You have chosen: WITHDRAW", "", "", "");
                printf("Enter amount to withdraw\n");
                scanf("%d",&withdraw);
                if(balance>=withdraw){
                    balance= balance -withdraw;
                    printScreen("Please collect your cash", "then remove your card", "", "");
                }
                else{
                    printScreen("Warning:", "Withdrawal amount cannot", "be more than balance", "");
                }
                break;
            case 3:
            {
                char balLine[40];
                sprintf(balLine, "Current Balance = %d", balance);
                printScreen("CHECK BALANCE", balLine, "", "");
                break;
            }
            case 4:
                printScreen("Exiting... Thank you!", "", "", "");
                a=0;
                break;
            default:
                printScreen("Wrong option chosen", "", "", "");
                break;
        }
    }
    return 0;
}
