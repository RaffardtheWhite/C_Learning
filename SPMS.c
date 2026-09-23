//SPMS AKA Student Performance Management System
#include <stdio.h>
#include <string.h>
void add_student();
void display_all_students();
void search_student();
void delete_student();
void modify_student();
void sort_students_by_score();

struct Student {
    char name[20];
    int id;
    float score;
};
    struct Student students[100];
    int count = 0;


int main(void){

    int choice = 7;

    while (choice != 0) {
        printf("---Welcome to the Student Performance Management System---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Modify student information\n");
        printf("4. Search student information\n");
        printf("5. Display all student information\n");
        printf("6. Sort student information by score\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");

        scanf("%d", &choice);

        
        int illegal = 0;
        if (choice < 0 || choice > 6) {
            illegal = 1;
            printf("Illegal choice! Please enter a number between 0 and 6.\n");
        }
        if (!illegal) {
            printf("You have chosen option %d\n", choice);
        }

        switch (choice) {
            case 1:
                printf("Adding student...\n");
                add_student();
                break;
            case 2:
                printf("Deleting student...\n");
                delete_student();
                break;
            case 3:
                printf("Modifying student information...\n");
                modify_student();
                break;
            case 4:
                printf("Searching student information...\n");
                search_student();
                break;
            case 5:
                printf("Displaying all student information...\n");
                display_all_students();
                break;
            case 6:
                printf("Sorting student information by score...\n");
                sort_students_by_score();
                break;
            case 0:
                printf("Exiting the system. Goodbye!\n");
                break;    
        }
    }
    return 0;
}



// Function to add a student
void add_student() {
    if (count >= 100) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter student name: ");
    scanf("%s", newStudent.name);
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter student score: ");
    scanf("%f", &newStudent.score);
    
    students[count++] = newStudent;
    printf("Student added successfully!\n");
    printf("%d\n", count);
}

//function to display all students
void display_all_students() {
    if (count <= 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student Information:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %d, Score: %.2f\n", students[i].name, students[i].id, students[i].score);
    }
}

//function to search for a student by id
void search_student() {
    if (count <= 0) {
        printf("No students to search.\n");
        return;
    }

    int targetId;
    printf("Enter student ID to search: ");
    scanf("%d", &targetId);
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id == targetId) {
            printf("Student found: Name: %s, ID: %d, Score: %.2f\n", students[i].name, students[i].id, students[i].score);
            found = 1;
            return;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", targetId);
    }
}

//function to delete a student by id
void delete_student() {
    if (count <= 0) {
        printf("No students to delete.\n");
        return;
    }

    int del_targetId;
    printf("Enter student ID to delete: ");
    scanf("%d", &del_targetId);
    int del_found = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].id == del_targetId) {
            del_found = i;
            for (int j = del_found; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student with ID %d deleted successfully.\n", del_targetId);
            del_found = -1;
            return;
        }
    }
    if (del_found == -1) {
        printf("Student with ID %d not found.\n", del_targetId);
    }
}

//function to modify a student's information by id
void modify_student() {
    if (count <= 0){
        printf("No students to modify.\n");
        return;
    }
int mod_targetId;
    printf("Enter student ID to modify: ");
    scanf("%d", &mod_targetId);
    int mod_found = -1;
    for (int i = 0; i < count; i++) {
        if (students[i].id == mod_targetId) {
            mod_found = i;
            printf("Enter new name for student (current: %s): ", students[i].name);
            scanf("%s", students[i].name);
            printf("Enter new score for student (current: %.2f): ", students[i].score);
            scanf("%f", &students[i].score);
            printf("Student with ID %d modified successfully.\n", mod_targetId);
            return;
        }
    }
    if (mod_found == -1) {
        printf("Student with ID %d not found.\n", mod_targetId);
    }
}

//function to sort students by score
void sort_students_by_score() {
    if (count <= 0) {
        printf("No students to sort.\n");
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by score in descending order.\n");
}