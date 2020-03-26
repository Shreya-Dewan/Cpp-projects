/*************************Bank Management System**********************/


/*************************Header Files**********************/

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#define LEN 7

/*************************Account Structure********************/
struct account{
char type[10];
char acc_no[20];
char pass[20];
char name[50];
unsigned long int mobile;
char email[20];
unsigned long int aadhar;
char nominee[50];
float balance;
};

/*************************Function Prototype**********************/

void choice(int);
void CreateAccount();
void UpdateAccount();
void Transaction();
void View3();
void FD();
void CloseAccount();
/***********************Driver Program*************************/

int main()
{
    int ch;
    char c;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t\t_________________________________________\n\t\t\t\t\t****WELCOME TO BANK MANAGEMENT SYSTEM****\n\t\t\t\t\t_________________________________________");
    printf("\n\n\t\t\tWe provide the following account related services:\n\n\t\t\t1. Create an account\n\t\t\t2. Update account details\n\t\t\t3. Transaction\n\t\t\t4. View last three transactions\n\t\t\t5. Open a Fixed Deposit account\n\t\t\t6. Close an account\n\n\n");
    printf("Select your option from the menu: ");
    scanf("%d",&ch);
    if(ch<1 || ch>6)
    {
       printf("\n\t\tInvalid choice\n\n");
       exit(0);
    }
    printf("\n\nYou've chosen: %d\nPress Y to confirm\nPress N to go back\nPress any key to exit\t",ch);
    fflush(stdin);
    scanf("%c",&c);

    switch(c)
    {
        case 'Y':
            case 'y': choice(ch);
        break;
        case 'N':
            case 'n': system("cls");
        main();
        break;
        default: break;
    }

    return 0;
}

/*************************Function to select operation**********************/

void choice(int ch)
{
    system("cls");
    switch(ch)
    {
        case 1: printf("\n\n\t\t\t\t***Create Account***\n\n");
                CreateAccount();
                break;
        case 2: printf("\n\n\t\t\t\t***Update Account Details***\n\n");
                UpdateAccount();
                break;
        case 3: printf("\n\n\t\t\t\t***Transaction Terminal***\n\n");
                Transaction();
                break;
        case 4: printf("\n\n\t\t\t\t***View last three transactions***\n\n");
                View3();
                break;
        case 5: printf("\n\n\t\t\t\t***Create Fixed Deposit Account***\n\n");
                FD();
                break;
        case 6: printf("\n\n\t\t\t\t***Close an Account***\n\n");
                CloseAccount();
                break;
    }
}

/*************************Function to Create Account**********************/

void CreateAccount()
{
    FILE *f, *accnum;
    char nums[LEN];
    int num;
    char filename[20];
    struct account a;
    printf("Choose account type:\n1. Savings\n2. Current\n eg: Type \"Savings\" for Savings account.\n");
    scanf("%s",&a.type);
    fflush(stdin);
   // itoa((num++), a.acc_no, 10);
    printf("Account holder's name: ");
    scanf("%s",&a.name);
    fflush(stdin);
    printf("Contact no.: ");
    scanf("%uld",&a.mobile);
    fflush(stdin);
    printf("Aadhar number: ");
    scanf("%uld",&a.aadhar);
    printf("Email id: ");
    scanf("%s",a.email);
    fflush(stdin);
    printf("Enter nominee's name: ");
    scanf("%s",a.nominee);
    fflush(stdin);
    printf("Enter opening balance(minimum 1000): ");
    scanf("%f", &a.balance);
    while(a.balance<1000)
    {
        printf("Minimum limit is 1000. Enter again: ");
        scanf("%f", &a.balance);
    }

    accnum= fopen("num.txt", "r");
        if(accnum==NULL)
    {
        printf("Error opening num file");
        exit(0);
    }
    int i=0;
    char ch;
    ch= fgetc(accnum);
    while(ch!=EOF)
    {
        nums[i++]=ch;
        ch= fgetc(accnum);
    }
    printf("%s", nums);

    fclose(accnum);

 /*   strcpy(filename,a.acc_no);
   strcat(filename,".txt");

    f=fopen(filename,"w");
    if(f==NULL)
    {
        printf("Error opening file");
        exit(0);
    }

    fwrite(&a, sizeof(struct account), 1, f);
    if(fwrite!= 0)
        printf("Account created successfully!\nYour account number is: %s\n", a.acc_no);
    else
        printf("Server error! Please try again.\n");
    fclose(f);
*/
    char c;
    printf("\t\tPress Y to go back to main menu.\n\t\tPress any key to exit\n");
    scanf("%c",&c);
    switch(c)
    {
        case 'Y':
            case 'y': main();
        break;
        default: exit(0);
    }


}

/*************************Function to Update Account**********************/

void UpdateAccount()
{

}

/*************************Function for Transaction**********************/

void Transaction()
{

}

/*************************Function to View last three transactions**********************/

void View3()
{

}

/*************************Function to Open FD**********************/

void FD()
{

}

/*************************Function to Open FD**********************/

void CloseAccount()
{

}
