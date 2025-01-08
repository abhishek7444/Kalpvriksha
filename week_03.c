#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50



int is_vowel(char ch)
{
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void input_matrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols)
{
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Name at (%d,%d): ", i, j);
            scanf("%s", names[i][j]);
        }
    }
}

void print_matrix(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols)
{
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
}

int count_vowel_names(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols)
{
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (is_vowel(names[i][j][0]))
            {
                count++;
            }
        }
    }
    return count;
}

void find_longest_name(char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH], int rows, int cols, char longest_name[])
{
    strcpy(longest_name, ""); 
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (strlen(names[i][j]) > strlen(longest_name))
            {
                strcpy(longest_name, names[i][j]);
            }
        }
    }
}

int main()
{
    int rows, cols;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    char longest_name[MAX_NAME_LENGTH];

    printf("Enter number of rows (1-10): ");
    scanf("%d", &rows);
    while (rows < 1 || rows > 10)
    {
        printf("Invalid input. Enter number of rows (1-10): ");
        scanf("%d", &rows);
    }

    printf("Enter number of columns (1-101): ");
    scanf("%d", &cols);
    while (cols < 1 || cols > 101)
    {
        printf("Invalid input. Enter number of columns (1-101): ");
        scanf("%d", &cols);
    }

    input_matrix(names, rows, cols);

    print_matrix(names, rows, cols);

    int vowel_count = count_vowel_names(names, rows, cols);
    printf("\nNumber of names starting with a vowel: %d\n", vowel_count);

    find_longest_name(names, rows, cols, longest_name);
    printf("The longest name: %s\n", longest_name);

    return 0;
}