#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user {
    char id[100];
    char name[100];
    int age;
};

int isIdUnique(const char *id) {
    FILE *fp = fopen("users.txt", "r");
    struct user u;

    if (fp == NULL) return 1; 

    while (fscanf(fp, "%s %s %d", u.id, u.name, &u.age) != EOF) {
        if (strcmp(u.id, id) == 0) {
            fclose(fp);
            return 0; 
        }
    }
    fclose(fp);
    return 1; 
}

void CreateUser(struct user *u) {
    FILE *fp = fopen("users.txt", "a");
    if (fp == NULL) {
        printf("Unable to open the file. Please try again.\n");
        return;
    }

    if (!isIdUnique(u->id)) {
        printf("User ID already exists. Please use a unique ID.\n");
        fclose(fp);
        return;
    }

    fprintf(fp, "%s %s %d\n", u->id, u->name, u->age);
    printf("User added successfully.\n");
    fclose(fp);
}

void readUser() {
    FILE *fp = fopen("users.txt", "r");
    struct user u;
    int i = 1;

    if (fp == NULL) {
        printf("No users found. The file does not exist or is empty.\n");
        return;
    }

    printf("\n--- User List ---\n");
    while (fscanf(fp, "%s %s %d", u.id, u.name, &u.age) != EOF) {
        printf("User %d:\n", i++);
        printf("  ID: %s\n", u.id);
        printf("  Name: %s\n", u.name);
        printf("  Age: %d\n", u.age);
    }

    if (i == 1) {
        printf("No users found.\n");
    }

    fclose(fp);
}

void updateUser(char *changableUser) {
    FILE *fp = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct user u;
    int found = 0;

    if (fp == NULL || temp == NULL) {
        printf("Unable to open the file. Please try again.\n");
        return;
    }

    while (fscanf(fp, "%s %s %d", u.id, u.name, &u.age) != EOF) {
        if (strcmp(u.id, changableUser) == 0) {
            printf("Enter the new ID of the user: ");
            scanf("%s", u.id);
            printf("Enter the new age of the user: ");
            scanf("%d", &u.age);
            getchar();
            printf("Enter the new name of the user: ");
            scanf("%[^\n]%*c", u.name);
            found = 1;
        }
        fprintf(temp, "%s %s %d\n", u.id, u.name, u.age);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User data updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("User not found.\n");
    }
}

void deleteUser(char *delUser) {
    FILE *fp = fopen("users.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    struct user u;
    int found = 0;

    if (fp == NULL || temp == NULL) {
        printf("Unable to open the file. Please try again.\n");
        return;
    }

    while (fscanf(fp, "%s %s %d", u.id, u.name, &u.age) != EOF) {
        if (strcmp(u.id, delUser) == 0) {
            found = 1;
            continue;
        }
        fprintf(temp, "%s %s %d\n", u.id, u.name, u.age);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("users.txt");
        rename("temp.txt", "users.txt");
        printf("User deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("User not found.\n");
    }
}

int main() {
    int n = 0;

    do {
        printf("\nSelect an operation from the list below:\n");
        printf("1. Create a new user\n");
        printf("2. Display all users\n");
        printf("3. Update user data\n");
        printf("4. Delete user data\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 0:
                printf("Exiting the program. Goodbye!\n");
                break;

            case 1: {
                struct user u;
                printf("Enter the unique ID for the user: ");
                scanf("%s", u.id);
                printf("Enter the age of the user: ");
                scanf("%d", &u.age);
                getchar(); 
                printf("Enter the name of the user: ");
                scanf("%[^\n]%*c", u.name);
                CreateUser(&u);
                break;
            }

            case 2:
                readUser();
                break;

            case 3: {
                char changeableUser[100];
                printf("Enter the user's unique ID for modification: ");
                scanf("%s", changeableUser);
                updateUser(changeableUser);
                break;
            }

            case 4: {
                char delUser[100];
                printf("Enter the unique ID of the user to delete: ");
                scanf("%s", delUser);
                deleteUser(delUser);
                break;
            }

            default:
                printf("Please enter a valid option.\n");
        }
    } while (n != 0);

    return 0;
}
