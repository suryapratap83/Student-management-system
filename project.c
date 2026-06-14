/*
* Student Management System
* Author : Surya Pratap Singh
* Language : C
* Description : A console-based student management
               system with file handling and login
*/
#include <stdio.h>
#include <string.h>
/* Student struct -stores all details of one student*/
typedef struct student {
    int rollno;   // unique roll number
    char name[20]; // full name max 20 characters
    float marks;   // marks out of 100
    char course[20]; // course name max 20 characters
} student;

// Global array - stores up to 50 students
student arr[50];

// Tracks total number of students currently stored
int count = 0;
/*
* Function : saveToFile
* Purpose : Saves all students data to binary file
* Returns : void
*/

void saveToFile() {
    FILE *fp;
    // open file in write binary mode
    fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Error saving!");
        return;
    }
    // write each student to file one by one
    for (int i = 0; i < count; i++) {
        fwrite(&arr[i], sizeof(student), 1, fp);
    }
    fclose(fp); // always close file after writing
}
/*
* Function : loadFromfile
* Purpose : Loads saved students from fill when program starts
* Returns : void
*/
void loadFromFile() {
    FILE *fp;
    // open file in read binary mode
    fp = fopen("students.dat", "rb");
    // if file doesn't exist yet - just return quietly
    if (fp == NULL) {
        return;
    }
    // keep reading students until end of file
    while (fread(&arr[count], sizeof(student), 1, fp) == 1) {
        count++; // increase count for each student loaded
    }
    fclose(fp); // always close file after reading
}
/*
*Function : login 
* Purpose : Verifies user  name and password before acess
* Returns : 1 if login successful, 0 if failed
*/

int login() {
    char username[20], password[20];
    // correct credentials stored here
    char correct_user[] = "admin";
    char correct_pass[] = "1234";
    int attempts = 3; // user gets 3 chances

    printf("\n===== STUDENT MANAGEMENT SYSTEM =====");
    while (attempts > 0) {
        printf("\n\nUsername: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        // strcmp returns 0 if strings match
        if (strcmp(username, correct_user) == 0 && strcmp(password, correct_pass) == 0) {
            printf("\nLogin successful! Welcome!");
            return 1; // login succea
        } else {
            attempts--; // reduce attempts by 1
            if (attempts > 0)
                printf("Wrong credentials! %d attempts left.", attempts);
        }
    }
    printf("\nToo many failed attempts. Exiting.");
    return 0;  // login failed
}
/*
* Function  : addstudents
* Purpose : takes input from user and adds student to array
* Returns : void
*/

void addstudents() {
    // take all students details from user 
    printf("\nEnter Roll No: ");
    scanf("%d", &arr[count].rollno);
    printf("\nEnter Name: ");
    scanf(" %[^\n]", arr[count].name);  // %[^\n] reads full name with spaces
    printf("\nEnter Marks: ");
    scanf("%f", &arr[count].marks);
    printf("\nEnter Course: ");
    scanf(" %[^\n]", arr[count].course);
    count++; // move to next empty slot
    printf("Student added successfully!");
}
/*
* Function  : viewstudents
* Purpose : Displays all students currently stored
* Returns : void
*/

void viewstudents() {
    // check if any studens exist
    if (count == 0) {
        printf("\nNo students found!");
        return;
    }
    // loop through all students and print details
    for (int i = 0; i < count; i++) {
        printf("\n--- Student %d ---", i + 1);
        printf("\nRoll No: %d", arr[i].rollno);
        printf("\nName: %s", arr[i].name);
        printf("\nMarks: %.2f", arr[i].marks);
        printf("\nCourse: %s", arr[i].course);
    }
}
/*
* Functions : deletestudents
* Purpose : Finds student by roll number and deletes
*           using arrays shifting techniques
* Returns : void
*/

void deletestudents() {
    int rollno;
    printf("\nEnter Roll No: ");
    scanf("%d", &rollno);
    // search for student with matching roll number
    for (int i = 0; i < count; i++) {
        if (arr[i].rollno == rollno) {
            // shifts all students after deleted
            for (int j = i; j < count - 1; j++) {
                arr[j] = arr[j + 1];
            }
            count--;  // reduce total count by 1
            printf("Student deleted successfully!");
            return;
        }
    }
    printf("Student not found!");
}
/*
* Function : searchstudents
* Purpose :  Searches and displays one students by roll
* Returns : void
*/

void searchstudents() {
    int rollno;
    printf("\nEnter Roll No: ");
    scanf("%d", &rollno);
    // loop through array to find matching roll number
    for (int i = 0; i < count; i++) {
        if (arr[i].rollno == rollno) {
            // print details of found student
            printf("\nRoll No: %d", arr[i].rollno);
            printf("\nName: %s", arr[i].name);
            printf("\nMarks: %.2f", arr[i].marks);
            printf("\nCourse: %s", arr[i].course);
            return;
        }
    }
    printf("Student not found!");
}
/*
* Function : updatestudents
* Purpose : Finds student by roll number
* Return : void
*/
void updatestudents() {
    int rollno;
    printf("\nEnter Roll No: ");
    scanf("%d", &rollno);
    // search for students with matching roll number
    for (int i = 0; i < count; i++) {
        if (arr[i].rollno == rollno) {
            // overwrite existing details with new input
            printf("\nEnter New Roll No: ");
            scanf("%d", &arr[i].rollno);
            printf("\nEnter New Name: ");
            scanf(" %[^\n]", arr[i].name);
            printf("\nEnter New Marks: ");
            scanf("%f", &arr[i].marks);
            printf("\nEnter New Course: ");
            scanf(" %[^\n]", arr[i].course);
            printf("Student updated successfully!");
            return;
        }
    }
    printf("Student not found!");
}
/*
* Function : main
* Purpose : Entry point - runs login, loads data, shows menu
* Returns : 0 on success
*/

int main() {
    // run login first - exit if failed
    if (login() == 0) {
        return 0;
    }
    // load prevously saved students from file

    loadFromFile();

    int menu;
    do {
        // display menu options
        printf("\n\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Delete Student");
        printf("\n4. Search Student");
        printf("\n5. Update Student");
        printf("\n6. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            addstudents();
            saveToFile(); // save after every add
            break;
        case 2:
            viewstudents();
            break;
        case 3:
            deletestudents();
            saveToFile(); //  save after every delete
            break;
        case 4:
            searchstudents();
            break;  
        case 5:
            updatestudents();
            saveToFile(); // save after every update
            break;
        case 6:
            printf("Goodbye!");
            break;
        default:
            printf("Invalid choice!");
        }
    } while (menu != 6);

    return 0; // program ended successfully
}
