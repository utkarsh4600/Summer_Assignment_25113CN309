#include<stdio.h>
#include<string.h>
#include<unistd.h>

struct customer{
    int id;
    char name[100];
    int pc;
    int hours;
    float rate;
    float bill;
    int status;
}c[500];

int n=0;

void addCustomer();
void displayCustomers();
void searchCustomer();
void updateCustomer();
void removeCustomer();
void checkPC();
void startSession();
void endSession();
void generateBill();
void totalEarnings();
void countCustomers();

int main(){
    printf("**WELCOME**\n");
    int flag=0,choice;

    while(flag!=1){
        sleep(1);
        printf("\n========== GAMING CAFE MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Customer\n2. Display All Customers\n3. Search Customer\n4. Update Customer\n5. Remove Customer\n6. Check PC Availability\n7. Start Gaming Session\n8. End Gaming Session\n9. Generate Bill\n10. Display Total Earnings\n11. Count Customers\n12. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            addCustomer();
            break;

            case 2:
            displayCustomers();
            break;

            case 3:
            searchCustomer();
            break;

            case 4:
            updateCustomer();
            break;

            case 5:
            removeCustomer();
            break;

            case 6:
            checkPC();
            break;

            case 7:
            startSession();
            break;

            case 8:
            endSession();
            break;

            case 9:
            generateBill();
            break;

            case 10:
            totalEarnings();
            break;

            case 11:
            countCustomers();
            break;

            case 12:
            flag=1;
            break;

            default:
            printf("Enter valid choice.\n");
        }
    }

    printf("Thank you ! Have a nice day.\n");
    return 0;
}

void addCustomer(){
    printf("\n========== ADD CUSTOMER ==========\n");

    if(n==500){
        printf("Customer limit reached.\n");
        return;
    }

    printf("Enter Customer ID : ");
    scanf("%d",&c[n].id);
    getchar();

    printf("Enter Customer Name : ");
    fgets(c[n].name,sizeof(c[n].name),stdin);
    c[n].name[strlen(c[n].name)-1]='\0';

    printf("Enter PC Number : ");
    scanf("%d",&c[n].pc);

    printf("Enter Hours : ");
    scanf("%d",&c[n].hours);

    printf("Enter Rate Per Hour : ");
    scanf("%f",&c[n].rate);

    c[n].bill=c[n].hours*c[n].rate;
    c[n].status=1;

    sleep(1);
    printf("\nCustomer added successfully.\n");
    n++;
}

void displayCustomers(){
    if(n==0){
        printf("\nNo customers found.\n");
        return;
    }

    printf("\n========== ALL CUSTOMERS ==========\n");

    for(int k=0;k<n;k++){
        printf("Customer ID : %d\n",c[k].id);
        printf("Customer Name : %s\n",c[k].name);
        printf("PC Number : %d\n",c[k].pc);
        printf("Hours : %d\n",c[k].hours);
        printf("Rate Per Hour : %.2f\n",c[k].rate);
        printf("Bill : %.2f\n",c[k].bill);

        if(c[k].status==1)
        printf("Status : Playing\n");
        else
        printf("Status : Session Ended\n");

        printf("\n-----------------------------\n");
    }
}

void searchCustomer(){
    int check,f=0;

    printf("\n========== SEARCH CUSTOMER ==========\n");
    printf("Enter Customer ID : ");
    scanf("%d",&check);

    for(int k=0;k<n;k++){
        if(check==c[k].id){
            f=1;

            printf("Customer ID : %d\n",c[k].id);
            printf("Customer Name : %s\n",c[k].name);
            printf("PC Number : %d\n",c[k].pc);
            printf("Hours : %d\n",c[k].hours);
            printf("Rate Per Hour : %.2f\n",c[k].rate);
            printf("Bill : %.2f\n",c[k].bill);

            if(c[k].status==1)
            printf("Status : Playing\n");
            else
            printf("Status : Session Ended\n");
        }
    }

    if(f==0)
    printf("\nCustomer not found.\n");
}

void updateCustomer(){
    int check,f=0;

    printf("\n========== UPDATE CUSTOMER ==========\n");
    printf("Enter Customer ID : ");
    scanf("%d",&check);
    getchar();

    for(int k=0;k<n;k++){
        if(check==c[k].id){
            f=1;

            printf("Enter Customer Name : ");
            fgets(c[k].name,sizeof(c[k].name),stdin);
            c[k].name[strlen(c[k].name)-1]='\0';

            printf("Enter PC Number : ");
            scanf("%d",&c[k].pc);

            printf("Enter Hours : ");
            scanf("%d",&c[k].hours);

            printf("Enter Rate Per Hour : ");
            scanf("%f",&c[k].rate);

            c[k].bill=c[k].hours*c[k].rate;

            sleep(1);
            printf("\nCustomer updated successfully.\n");
            break;
        }
    }

    if(f==0)
    printf("\nCustomer not found.\n");
}

void removeCustomer(){
    int check,f=0;

    printf("\n========== REMOVE CUSTOMER ==========\n");
    printf("Enter Customer ID : ");
    scanf("%d",&check);

    for(int k=0;k<n;k++){
        if(check==c[k].id){
            f=1;

            for(int q=k;q<n-1;q++)
            c[q]=c[q+1];

            n--;

            sleep(1);
            printf("\nCustomer removed successfully.\n");
            break;
        }
    }

    if(f==0)
    printf("\nCustomer not found.\n");
}
void checkPC(){
    int pc,f=0;

    printf("\n========== CHECK PC AVAILABILITY ==========\n");
    printf("Enter PC Number : ");
    scanf("%d",&pc);

    for(int k=0;k<n;k++){
        if(c[k].pc==pc && c[k].status==1){
            f=1;
            break;
        }
    }

    if(f==1) printf("\nPC is occupied.\n");
    else printf("\nPC is available.\n");
}

void startSession(){
    int check,f=0;

    printf("\n========== START GAMING SESSION ==========\n");
    printf("Enter Customer ID : ");
    scanf("%d",&check);

    for(int k=0;k<n;k++){
        if(check==c[k].id){
            f=1;

            if(c[k].status==1)
                printf("\nSession is already running.\n");
            else{
                c[k].status=1;
                sleep(1);
                printf("\nGaming session started successfully.\n");
            }
            break;
        }
    }

    if(f==0) printf("\nCustomer not found.\n");
}

void endSession(){
    int check,f=0;

    printf("\n========== END GAMING SESSION ==========\n");
    printf("Enter Customer ID : ");
    scanf("%d",&check);

    for(int k=0;k<n;k++){
        if(check==c[k].id){
            f=1;

            if(c[k].status==0)
                printf("\nSession is already ended.\n");
            else{
                c[k].status=0;
                sleep(1);
                printf("\nGaming session ended successfully.\n");
            }
            break;
        }
    }

    if(f==0) printf("\nCustomer not found.\n");
}

void generateBill(){
    int check,f=0;

    printf("\n========== GENERATE BILL ==========\n");
    printf("Enter Customer ID : ");
    scanf("%d",&check);

    for(int k=0;k<n;k++){
        if(check==c[k].id){
            f=1;

            printf("Customer ID : %d\n",c[k].id);
            printf("Customer Name : %s\n",c[k].name);
            printf("PC Number : %d\n",c[k].pc);
            printf("Hours Played : %d\n",c[k].hours);
            printf("Rate Per Hour : %.2f\n",c[k].rate);
            printf("Total Bill : %.2f\n",c[k].bill);
            break;
        }
    }

    if(f==0) printf("\nCustomer not found.\n");
}

void totalEarnings(){
    float total=0;

    printf("\n========== TOTAL EARNINGS ==========\n");

    for(int k=0;k<n;k++)
        total+=c[k].bill;

    printf("Total Earnings : %.2f\n",total);
}

void countCustomers(){
    printf("\n========== TOTAL CUSTOMERS ==========\n");
    printf("Total Customers : %d\n",n);
}
