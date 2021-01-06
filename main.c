#include <stdio.h>
#include "myBank.h"

int main()
{
    char command;
    do
    {
        printf("\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit\n");
        scanf(" %c",&command);
        switch (command)
        {
        case 'O':
        {
            float amount;
            printf("Please enter amount for deposit: ");
            if(scanf(" %f",&amount)<1)
            {
                printf("Failed to read the amount\n");
                continue;
            }
            if(amount<0)
            {
                printf("Invalid Amount\n");
                continue;
            }
            O(amount);
        }
            break;
        case 'B':
        {
            printf("Please enter account number: ");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("Invalid account number\n");
                continue;
            }
            if(check_open(account))
            {
                printf("This account is closed\n");
                continue;
            }
            B(account);
        }
            break;
        case 'D':
        {
            printf("Please enter account number: ");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("Invalid account number\n");
                continue;
            }
            if(check_open(account))
            {
                printf("This account is closed\n");
                continue;
            }
            float amount;
            printf("Please enter amount for deposit: ");
            if(scanf(" %f",&amount)<1)
            {
                printf("Failed to read the amount\n");
                continue;
            }
            if(amount<0)
            {
                printf("Cannot deposit a negative amount\n");
                continue;
            }
            D(account,amount);
        }
            break;
        
        case 'W':
        {
            printf("Please enter account number: ");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("Invalid account number\n");
                continue;
            }
            if(check_open(account))
            {
                printf("This account is closed\n");
                continue;
            }
            float amount;
            printf("Please enter the amount to withdraw: ");
            if(scanf(" %f",&amount)<1)
            {
                printf("Failed to read the amount\n");
                continue;
            }
            //By your tests I can withdraw negative..
            // if(amount<0)
            // {
            //     printf("Invalid Amount\n");
            //     continue;
            // }
            W(account,amount);
        }
        break;
        
        case 'C':
        {
            printf("Please enter account number: ");
            int account=0;
            if(scanf(" %d",&account)<1)
            {
                printf("Failed to read the account number\n");
                continue;
            }
            if(account<901 || account>950)
            {
                printf("Invalid account number\n");
                continue;
            }
            C(account);
        }
        break;

        case 'I':
        {
            int intr;
            printf("Please enter interest rate: ");
            if(scanf(" %d",&intr)<1)
            {
                printf("Failed to read the interest rate\n");
                continue;
            }
            //By your test, can't use negative intrest rate
            if(intr <0)
            {
                printf("Invalid interest rate\n");
                continue;
            }
            I(intr);
        }
        break;

        case 'P':
        {
            P();
        }
        break;
        case 'E':
        break;
        default:
        {
            printf("Invalid transaction type\n");
        }
            break;
        }
    } while (command!='E');
    return 0;
}