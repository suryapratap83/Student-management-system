#include<stdio.h>
    typedef struct student{
        int rollno;
        char name[20];
        float marks;
        char course[20];
    }student;
    student arr[50];
int main(){
int menu;
  int count =0;
do{
    printf("\n1.Add");
    printf("\n2.View");
    printf("\n3.delete");
    printf("\n4.search");
    printf("\n5.update");
    printf("\n6.exit");

    printf("\nEnter menu:");
    scanf("%d", &menu);
    switch(menu){
        case 1: 
      
    printf("\nEnter Roll No: ");
    scanf("%d", &arr[count].rollno);

    printf("\nEnter Name: ");
    scanf(" %s", arr[count].name);

    printf("\nEnter Marks: ");
    scanf("%f", &arr[count].marks);

    printf("\nEnter Course: ");
    scanf("%s", arr[count].course);

    count++; 

    printf("Student added successfully!");

    break;
        
        case 2:
       for(int i=0; i<count; i++){
    printf("\n%d", arr[i].rollno);

    printf("\n%s", arr[i].name);

    
    printf("\n%f", arr[i].marks);

    printf("\n%s", arr[i].course);
       }

        break;
         case 3:{
        int rollno;
        printf("\nenter rollno");
        scanf("%d", &rollno);
        for(int i=0; i<count; i++){
            if(arr[i].rollno==rollno){
                for(int j=i; j<count-1; j++){
                    arr[j]=arr[j+1];
            }
            count--;
        }
    }
        printf("student deleted succesfully");
        break;
}
        case 4:{
            int  rollno;
        printf("\nenter rollno");
        scanf("%d", &rollno);
        for(int i=0; i<count; i++){
            if(arr[i].rollno==rollno){
             printf("%d", arr[i].rollno);

    printf("%s", arr[i].name);

    
    printf("%f", arr[i].marks);

    printf(" %s", arr[i].course);
        }
    }
       
        break;
}
     case 5:{
           int  rollno;
        printf("\nenter rollno");
        scanf("%d", &rollno);
        for(int i=0; i<count; i++){
            if(arr[i].rollno==rollno){
             
    printf("\nEnter Roll No: ");
    scanf("%d", &arr[i].rollno);

    printf("\nEnter Name: ");
    scanf(" %s", arr[i].name);

    printf("\nEnter Marks: ");
    scanf("%f", &arr[i].marks);

    printf("\nEnter Course: ");
    scanf("%s", arr[i].course);
        }
  
}
printf("student update succesfully");
  break;

     }
        case 6:
        printf("exiting....");
        break;
        default :
        printf("invalid choice");
    
        
    
    }
}while(menu!=6);
    
}
