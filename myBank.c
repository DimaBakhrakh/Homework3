#include <stdio.h>
#include "myBank.h"

#define n 50
#define num 901

float bank[2][n]={0};


void O(float amount)
{
    int i = 0;
    while (bank[0][i]==1)
    {
        i++;
    }
    if(i==50)
    {
        printf("Sorry, can't create an account because we are full!\n\n");
        return;
    }
    bank[0][i]=1.0;
    bank[1][i]=amount;
    printf("New account number is: %d\n", num+i);
}

void B(int account)
{
    if(bank[0][account-num]!=1.0)
    {
        printf("This account is closed\n");
        return;
    }
    printf("The balance of account number %d is: %0.2f\n",account,bank[1][account-num]);
}

void D(int account, float amount)
{
    if(bank[0][account-num]!=1.0)
    {
        printf("This account is closed\n");
        return;
    }
    bank[1][account-num] +=amount;
    printf("The new balance is: %0.2f\n", bank[1][account-num]);
}

void W(int account, float amount)
{
    if(bank[0][account-num]!=1.0)
    {
        printf("This account is closed\n");
        return;
    }
    if(bank[1][account-num]-amount<0)
    {
        printf("Cannot withdraw more than the balance\n");
        return;
    }
    bank[1][account-num]-=amount;
    printf("The new balance is: %0.2f\n",bank[1][account-num]);
}

void C(int account)
{
    if(bank[0][account-num]!=1.0)
    {
        printf("This account is already closed\n");
        return;
    }
    bank[0][account-num]=0;
    printf("Closed account number %d\n",account);
}

void I(int interest)
{
    for(int i=0;i<n;i++)
    {
        if(bank[0][i]==1.0)
        {
            bank[1][i]=bank[1][i]+(interest/100.0)*bank[1][i];
        }
    }
}

void P()
{
    for(int i=0;i<n;i++)
    {
        if(bank[0][i]==1.0)
        {
            printf("The balance of account number %d is: %0.2f\n",i+num,bank[1][i]);
        }
    }
}

int check_open(int account)
{
    return bank[0][account-num] != 1.0;
}