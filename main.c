#include <stdio.h>
#include "myBank.h"

int main()
{
    char option; // temporary option input
    double amount; // temporary amount input
    int interest; // temporary interest input
    int accNum; // temporary account input
    int bool = 1; // boolean to run the whole task until exit

    while(bool==1){
            printf("Please choose a transaction type:\n");
            printf("O-Open Account\n");
            printf("B-Balance Inquiry\n");
            printf("D-Deposit\n");
            printf("W-Withdrawal\n");
            printf("C-Close Account\n");
            printf("I-Interest\n");
            printf("P-Print\n");
            printf("E-Exit\n");
            scanf(" %c", &option);

        if (option=='O'){ // openAcc
            printf("Please enter amount for deposit:\n");
            if (scanf(" %lf", &amount)==1) {
                if (amount>=0) openAcc(amount);
                else printf("Invalid Amount\n");
            }
            else { // invalid input
                printf("Failed to read the amount\n");
            }

        } else if (option=='B') { // balance
            printf("Please enter account number:\n");
            if (scanf(" %d", &accNum)==1) {
                balance(accNum);
            }
            else { // invalid input
                printf("Failed to read the account number\n");
            }

        } else if (option=='D') { // deposit
            printf("Please enter account number:\n");
            if (scanf(" %d", &accNum)==1) {
                if (checkAcc(accNum)==1) {
                    printf("Please enter the amount to deposit:\n");
                    if (scanf(" %lf", &amount)==1) {
                            deposit(accNum, amount);
                    } else {
                        printf("Failed to read the amount\n");
                    }
                }
            } else {
                printf("Failed to read the account number\n");
            }

        } else if (option=='W') { // withdrawal
            printf("Please enter account number:\n");
            if (scanf(" %d", &accNum)==1) {
                if (checkAcc(accNum)==1) {
                    printf("Please enter the amount to withdrawal:\n");
                    if (scanf(" %lf", &amount)==1) {
                            withdrawal(accNum, amount);
                    } else {
                        printf("Failed to read the amount\n");
                    }
                }
            } else {
                printf("Failed to read the account number\n");
            }

        } else if (option=='C') { // closeAcc
            printf("Please enter account number:\n");
            if (scanf(" %d", &accNum)==1) {
                closeAcc(accNum);
            }
            else { // invalid input
                printf("Failed to read the account number\n");
            }

        } else if (option=='I') { // addInterest
            printf("Please enter interest rate:\n");
            if (scanf(" %d", &interest)==1) {
                addInterest(interest);
            }
            else { // invalid input
                printf("Failed to read the interest rate\n");
            }

        } else if (option=='P') { // printAllAccs
            printAllAccs();

        } else if (option=='E') { // closeAllAccs
            closeAllAccs();
            bool = 0;

        } else {
            printf("Invalid transaction type\n");
        }
        printf("\n");
    }
    return 0;
}
