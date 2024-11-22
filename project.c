#include<stdio.h>
void new_account();
void view_details(int);
void view_all_details();
void check_balance(int);
void deposite_money(int,float);
void withdraw_money(int,float);
void transfer_money(int,int,float);

#define max_accounts 200
typedef struct account
{
    char account_holder_name[20];
    int account_number;
    float balance;
}Account;

Account acc[max_accounts];
int total=0;
void main()
{
    int account_number;
    int ch;
    float amount;
    int from_acc;
    int to_acc;
    while(1)
    {
        printf("----------------------------------------------------\n");
        printf("choices : \n");
        printf("1. Add a new account\n");
        printf("2. View Account Details\n");
        printf("3. View All Account\n");
        printf("4. Check the Balance\n");
        printf("5. Deposite Money\n");
        printf("6. Withdraw Money\n");
        printf("7. Transfer Money\n");
        printf("8. Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                new_account();
                break;
            case 2:
                printf("enter account number : ");
                scanf("%d", &account_number);
                view_details(account_number);
                break;
            case 3:
                view_all_details();
                break;
            case 4:
                printf("enter account number : ");
                scanf("%d", &account_number);
                check_balance(account_number);
                break;
            case 5:
                printf("enter account number : ");
                scanf("%d", &account_number);
                printf("enter amount to deposit : ");
                scanf("%f", &amount);
                deposite_money(account_number,amount);
                break;
            case 6:
                printf("enter account number : ");
                scanf("%d", &account_number);
                printf("enter amount to withdraw : ");
                scanf("%f", &amount);
                withdraw_money(account_number,amount);
                break;
            case 7:
                printf("enter current account number : ");
                scanf("%d", &from_acc);
                printf("enter account number to transfer : ");
                scanf("%d", &to_acc);
                printf("enter amount : ");
                scanf("%f", &amount);
                transfer_money(from_acc,to_acc,amount);
                break;
            case 8:
                printf("exiting the program\n");
                return ;
            default:
                printf("Incorrect choice!\nPlease enter correct choice");
                break;
        }
    }
}

void new_account()
{
    if(total >=max_accounts)
    {
        printf("limit exceeds!. Cannot add your acccount");
        return;
    }
    Account new;
    printf("enter account holder name : ");
    scanf("%s",new.account_holder_name);
    new.account_number=total+1;
    new.balance=0.0;

    acc[total]=new;
    total++;
    printf("your account has been created.\nyour account number is : %d\n",new.account_number);
}

void view_details(int account_number)
{
    if ( (account_number<=0) || (account_number > total) )
    {
        printf("the account number you have entered is wrong. Please enter correct account number.");
        return;
    }

    Account account = acc[account_number - 1];
    printf("account number : %d\n",account.account_number);
    printf("account holder name : %s\n",account.account_holder_name);
    printf("balance : %f\n",account.balance);
}

void view_all_details()
{
    if (total == 0)
    {
        printf("No Data Available\n");
        return;
    }

    for(int i =0;i<total;i++)
    {
        printf("account %d : \n",i+1);
        printf("account number : %d\n",acc[i].account_number);
        printf("account holder name : %s\n",acc[i].account_holder_name);
        printf("balance : %f\n",acc[i].balance);
    }
}

void check_balance(int account_number)
{
    if ( (account_number<=0) || (account_number > total) )
    {
        printf("the account number you have entered is wrong.\nPlease enter correct account number.");
        return;
    }
    printf("balance : %f\n",acc[account_number-1].balance);
}

void deposite_money(int account_number,float amount)
{
    if ( (account_number<=0) || (account_number > total) )
    {
        printf("the account number you have entered is wrong.\nPlease enter correct account number.");
        return;
    }

    acc[account_number -1].balance+=amount;
    printf("you have successfully deposite the amount!\nYour New Balance is : %f",acc[account_number -1].balance);
}

void withdraw_money(int account_number,float amount)
{
    if ( (account_number<=0) || (account_number > total) )
    {
        printf("the account number you have entered is wrong.\nPlease enter correct account number.");
        return;
    }

    if(acc[account_number -1].balance<amount)
    {
        printf("not enough balance!");
        return;
    }

    acc[account_number -1].balance-=amount;
    printf("you have successfully withdraw the amount!\nYour New Balance is : %f",acc[account_number -1].balance);
}

void transfer_money(int from_acc,int to_acc,float amount)
{
    if ( (from_acc<=0) || (from_acc > total) || ((to_acc<=0) || (to_acc > total)) )
    {
        printf("the account number you have entered is wrong.\nPlease enter correct account number.");
        return;
    }
    if(acc[from_acc-1].balance<amount)
    {
        printf("not enough balance!");
        return;
    }
    acc[from_acc-1].balance-=amount;
    acc[to_acc-1].balance+=amount;
    printf("your money have been transfered successfully!\n");
    printf("your balance in \n");
    printf("account %d is : %f\n",acc[from_acc-1].account_number, acc[from_acc-1].balance);
    printf("account %d is : %f\n",acc[to_acc-1].account_number,acc[to_acc-1].balance);
}

/*
 char name[20];
    printf("enter account holder name : ");
    scanf("%s",name);
    strcpy(new.account_holder_name,"name");
*/