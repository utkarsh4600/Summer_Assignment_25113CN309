#include<stdio.h>
#include<string.h>
#include<unistd.h>

struct product{
    int product_id;
    char product_name[100];
    int quantity;
    float price;
}p[5000];

int main(){
    printf("**WELCOME**\n");

    int flag=0,choice,n=0,check,f=0;

    while(flag!=1){
        sleep(1);

        printf("\n========== INVENTORY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Product\n2. Display All Products\n3. Search Product\n4. Update Product\n5. Delete Product\n6. Check Product Price\n7. Count Total Products\n8. Display Total Inventory Value\n9. Exit\n");

        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        getchar();

        switch(choice){

            case 1:
            printf("\n========== ADD PRODUCT ==========\n");

            if(n==5000){
                printf("Inventory is full.\n");
                break;
            }

            printf("Enter Product ID : ");
            scanf("%d",&p[n].product_id);
            getchar();

            printf("Enter Product Name : ");
            fgets(p[n].product_name,sizeof(p[n].product_name),stdin);
            p[n].product_name[strlen(p[n].product_name)-1]='\0';

            printf("Enter Quantity : ");
            scanf("%d",&p[n].quantity);

            printf("Enter Price : ");
            scanf("%f",&p[n].price);

            sleep(1);
            printf("\nProduct added successfully.\n");

            n++;
            break;

            case 2:
            if(n==0){
                printf("\n========== NO PRODUCTS ==========\n");
            }
            else{
                printf("\n========== ALL PRODUCTS ==========\n");

                for(int k=0;k<n;k++){
                    printf("Product ID : %d\n",p[k].product_id);
                    printf("Product Name : %s\n",p[k].product_name);
                    printf("Quantity : %d\n",p[k].quantity);
                    printf("Price : %.2f\n",p[k].price);
                    printf("-----------------------------\n");
                }
            }
            break;

            case 3:
            f=0;

            printf("\n========== SEARCH PRODUCT ==========\n");
            printf("Enter Product ID : ");
            scanf("%d",&check);

            for(int k=0;k<n;k++){
                if(check==p[k].product_id){
                    f=1;

                    printf("Product ID : %d\n",p[k].product_id);
                    printf("Product Name : %s\n",p[k].product_name);
                    printf("Quantity : %d\n",p[k].quantity);
                    printf("Price : %.2f\n",p[k].price);
                }
            }

            if(f==0)
                printf("\n========== PRODUCT NOT FOUND ==========\n");

            break;

            case 4:
            f=0;

            printf("\n========== UPDATE PRODUCT ==========\n");
            printf("Enter Product ID : ");
            scanf("%d",&check);
            getchar();

            for(int k=0;k<n;k++){

                if(check==p[k].product_id){

                    f=1;

                    char verify[100];

                    printf("Enter Product Name : ");
                    fgets(verify,sizeof(verify),stdin);
                    verify[strlen(verify)-1]='\0';

                    if(strcmp(verify,p[k].product_name)==0){

                        printf("Enter Product ID : ");
                        scanf("%d",&p[k].product_id);
                        getchar();

                        printf("Enter Product Name : ");
                        fgets(p[k].product_name,sizeof(p[k].product_name),stdin);
                        p[k].product_name[strlen(p[k].product_name)-1]='\0';

                        printf("Enter Quantity : ");
                        scanf("%d",&p[k].quantity);

                        printf("Enter Price : ");
                        scanf("%f",&p[k].price);

                        sleep(1);
                        printf("\nProduct updated successfully.\n");

                        break;
                    }
                }
            }

            if(f==0)
                printf("\n========== PRODUCT NOT FOUND ==========\n");

            break;

            case 5:
            f=0;

            printf("\n========== DELETE PRODUCT ==========\n");
            printf("Enter Product ID : ");
            scanf("%d",&check);
            getchar();

            for(int k=0;k<n;k++){

                if(check==p[k].product_id){

                    f=1;

                    char verify[100];

                    printf("Enter Product Name : ");
                    fgets(verify,sizeof(verify),stdin);
                    verify[strlen(verify)-1]='\0';

                    if(strcmp(verify,p[k].product_name)==0){

                        for(int q=k;q<n-1;q++)
                            p[q]=p[q+1];

                        n--;

                        sleep(1);
                        printf("\nProduct deleted successfully.\n");

                        break;
                    }
                }
            }

            if(f==0)
                printf("\n========== PRODUCT NOT FOUND ==========\n");

            break;

            case 6:
            f=0;

            printf("\n========== CHECK PRODUCT PRICE ==========\n");
            printf("Enter Product ID : ");
            scanf("%d",&check);

            for(int k=0;k<n;k++){

                if(check==p[k].product_id){

                    f=1;

                    printf("Product Name : %s\n",p[k].product_name);
                    printf("Price : %.2f\n",p[k].price);
                }
            }

            if(f==0)
                printf("\n========== PRODUCT NOT FOUND ==========\n");

            break;

            case 7:
            printf("\n========== TOTAL PRODUCTS ==========\n");

            if(n==0)
                printf("\nNo products available.\n");
            else
                printf("\nTotal Products : %d\n",n);

            break;

            case 8:
            printf("\n========== TOTAL INVENTORY VALUE ==========\n");

            float total=0;

            for(int k=0;k<n;k++)
                total += p[k].quantity * p[k].price;

            printf("Total Inventory Value : %.2f\n",total);

            break;

            case 9:
            flag=1;
            break;

            default:
            printf("Enter valid choice.\n");
        }
    }

    printf("Thank you ! Have a nice day.\n");

    return 0;
}