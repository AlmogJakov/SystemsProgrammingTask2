#include <stdio.h>
#include "myBank.h"

double Accs[2][50];

int checkAcc(int x) {
    if (x>950||x<901) { // check if x in range of accounts numbers
        printf("Invalid account number.\n");
        return 0;
    }
    if (Accs[1][x-901]==0) {
        printf("This account is closed\n");
        return 0;
    }
    return 1;
}

void openAcc(double x) {
    int found = 0;
    int iterator = 0;
    while (found==0&&iterator<50){
        if (Accs[1][iterator]==0){
            Accs[1][iterator] = 1;
            Accs[0][iterator] = ((int)(x*100))/100.0; // save the amount with 2 digits only after the dot
            found = 1;
        } else {
            iterator++;
        }
    }
    if (found == 1) printf("New account number is: %.2d\n", 901+iterator);
    else printf("no space to open a new account.\n");
}

void balance(int x) {
    if (x>950||x<901) { // check if x in range of accounts numbers
        printf("Invalid account number.\n");
        return;
    }
    if (Accs[1][x-901]==0) printf("This account is closed\n");
    else printf("The balance of account number %d is: %.2lf\n", x, Accs[0][x-901]);
}

void deposit(int acc, double amount){
    if (acc>950||acc<901) { // check if acc in range of accounts numbers
        printf("Out of account numbers range.\n");
        return;
    }
    if (amount<0) { // check if amount is positive
        printf("Cannot deposit a negative amount.\n");
        return;
    }
    if (Accs[1][acc-901]==0) printf("This account is closed\n");
    else {
        Accs[0][acc-901] = ((int)((Accs[0][acc-901]+amount)*100))/100.0; // save the amount with 2 digits only after the dot
        printf("The new balance is: %.2lf\n", Accs[0][acc-901]);
    }
}

void withdrawal(int acc, double amount){
    if (acc>950||acc<901) { // check if acc in range of accounts numbers
        printf("Out of account numbers range.\n");
        return;
    }
    if (Accs[1][acc-901]==0) printf("This account is closed\n");
    else {
        if (Accs[0][acc-901]-amount>=0){
            Accs[0][acc-901] = ((int)((Accs[0][acc-901]-amount)*100))/100.0; // save the amount with 2 digits only after the dot
            printf("The new balance is: %.2lf\n", Accs[0][acc-901]);
        } else {
            printf("Cannot withdraw more than the balance\n");
        }
    }
}

void closeAcc(int acc){
    if (acc>950||acc<901) { // check if acc in range of accounts numbers
        printf("Invalid account number.\n");
        return;
    }
    if (Accs[1][acc-901]==0) printf("This account is already closed\n");
    else {
        Accs[1][acc-901] = 0;
        printf("Closed account number %d\n", acc);
    }
}

void addInterest(int interest){
    if (interest<0) {
        printf("Invalid interest rate\n");
        return;
    }
    for (int i = 0; i<50; i++) {
        if (Accs[1][i]==1) {
            // save the amount with 2 digits only after the dot
            //Accs[0][i] = Accs[0][i]*(1+(interest/100.0));
            Accs[0][i] = ((int)((Accs[0][i]*(1+(interest/100.0)))*100))/100.0;
        }
    }
}
void printAllAccs() {
    for (int i = 0; i<50; i++) {
        if (Accs[1][i]==1) {
            printf("The balance of account number %d is %.2lf\n", i+901, Accs[0][i]);
        }
    }
}

void closeAllAccs() {
    for (int i = 0; i<50; i++) {
        if (Accs[1][i]==1) {
            Accs[1][i] = 0;
        }
    }
}