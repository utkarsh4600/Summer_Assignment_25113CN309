#include<stdio.h>
#include<string.h>
#include<unistd.h>

struct student{
    int roll;
    char name[100];
    int age;
    char course[100];
    float marks;
}s[5000];

int main(){
    printf("**WELCOME**\n");
    int flag=0,choice,n=0,check,f=0;

    while(flag!=1){
        sleep(1);
        printf("\n========== STUDENT RECORD SYSTEM ==========\n1. Add Student\n2. Display All Students\n3. Search Student\n4. Update Student\n5. Delete Student\n6. Display Topper\n7. Calculate Average Marks\n8. Count Total Students\n9. Display Total Marks\n10. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice); getchar();

        switch(choice){

            case 1:
            printf("\n========== ADD STUDENT ==========\n");
            if(n==5000){
                printf("Student limit reached.\n");
                break;
            }
            printf("Enter Roll Number : "); scanf("%d",&s[n].roll); getchar();
            printf("Enter Student Name : "); fgets(s[n].name,sizeof(s[n].name),stdin); s[n].name[strlen(s[n].name)-1]='\0';
            printf("Enter Age : "); scanf("%d",&s[n].age); getchar();
            printf("Enter Course : "); fgets(s[n].course,sizeof(s[n].course),stdin); s[n].course[strlen(s[n].course)-1]='\0';
            printf("Enter Marks : "); scanf("%f",&s[n].marks);
            sleep(1);
            printf("\nStudent added successfully.\n");
            n++;
            break;

            case 2:
            if(n==0) printf("\n==========NO STUDENTS==========\n");
            else{
                printf("\n========== ALL STUDENTS ==========\n");
                for(int k=0;k<n;k++){
                    printf("Roll Number : %d\n",s[k].roll);
                    printf("Student Name : %s\n",s[k].name);
                    printf("Age : %d\n",s[k].age);
                    printf("Course : %s\n",s[k].course);
                    printf("Marks : %.2f\n",s[k].marks);
                    printf("-----------------------------\n");
                }
            }
            break;

            case 3:
            f=0;
            printf("\n========== SEARCH STUDENT ==========\n");
            printf("Enter Roll Number : "); scanf("%d",&check);
            for(int k=0;k<n;k++){
                if(check==s[k].roll){
                    f=1;
                    printf("Roll Number : %d\n",s[k].roll);
                    printf("Student Name : %s\n",s[k].name);
                    printf("Age : %d\n",s[k].age);
                    printf("Course : %s\n",s[k].course);
                    printf("Marks : %.2f\n",s[k].marks);
                }
            }
            if(f==0) printf("\n==========STUDENT NOT FOUND==========\n");
            break;

            case 4:
            f=0;
            printf("\n========== UPDATE STUDENT ==========\n");
            printf("Enter Roll Number : "); scanf("%d",&check); getchar();
            for(int k=0;k<n;k++){
                if(check==s[k].roll){
                    char verify[100];
                    f=1;
                    printf("Enter Student Name : "); fgets(verify,sizeof(verify),stdin); verify[strlen(verify)-1]='\0';
                    if(strcmp(verify,s[k].name)==0){
                        printf("Enter Roll Number : "); scanf("%d",&s[k].roll); getchar();
                        printf("Enter Student Name : "); fgets(s[k].name,sizeof(s[k].name),stdin); s[k].name[strlen(s[k].name)-1]='\0';
                        printf("Enter Age : "); scanf("%d",&s[k].age); getchar();
                        printf("Enter Course : "); fgets(s[k].course,sizeof(s[k].course),stdin); s[k].course[strlen(s[k].course)-1]='\0';
                        printf("Enter Marks : "); scanf("%f",&s[k].marks);
                        sleep(1);
                        printf("\nStudent updated successfully.\n");
                        break;
                    }
                }
            }
            if(f==0) printf("\n==========STUDENT NOT FOUND==========\n");
            break;

            case 5:
            f=0;
            printf("\n========== DELETE STUDENT ==========\n");
            printf("Enter Roll Number : "); scanf("%d",&check); getchar();
            for(int k=0;k<n;k++){
                if(check==s[k].roll){
                    char verify[100];
                    f=1;
                    printf("Enter Student Name : "); fgets(verify,sizeof(verify),stdin); verify[strlen(verify)-1]='\0';
                    if(strcmp(verify,s[k].name)==0){
                        for(int q=k;q<n-1;q++) s[q]=s[q+1];
                        n--;
                        sleep(1);
                        printf("\nStudent deleted successfully.\n");
                        break;
                    }
                }
            }
            if(f==0) printf("\n==========STUDENT NOT FOUND==========\n");
            break;
                        case 6:
            if(n==0) printf("\n==========NO STUDENTS==========\n");
            else{
                int pos=0;
                for(int k=1;k<n;k++){
                    if(s[k].marks>s[pos].marks) pos=k;
                }
                printf("\n========== TOPPER ==========\n");
                printf("Roll Number : %d\n",s[pos].roll);
                printf("Student Name : %s\n",s[pos].name);
                printf("Age : %d\n",s[pos].age);
                printf("Course : %s\n",s[pos].course);
                printf("Marks : %.2f\n",s[pos].marks);
            }
            break;

            case 7:
            if(n==0) printf("\n==========NO STUDENTS==========\n");
            else{
                float total=0;
                for(int k=0;k<n;k++) total+=s[k].marks;
                printf("\nAverage Marks : %.2f\n",total/n);
            }
            break;

            case 8:
            printf("\n========== TOTAL STUDENTS ==========\n");
            if(n==0) printf("No students available.\n");
            else printf("Total Students : %d\n",n);
            break;

            case 9:
            if(n==0) printf("\n==========NO STUDENTS==========\n");
            else{
                float total=0;
                for(int k=0;k<n;k++) total+=s[k].marks;
                printf("\nTotal Marks : %.2f\n",total);
            }
            break;

            case 10:
            flag=1;
            break;

            default:
            printf("Enter valid choice.\n");
        }
    }

    printf("Thank you ! Have a nice day.\n");
    return 0;
}