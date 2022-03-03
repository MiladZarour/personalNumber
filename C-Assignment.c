#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define FORMAT "YYMMDD-nnnC"

void multiplication(char *ptr, char *multi) // multiplicate the array 2 and 1
{
    for (char i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            multi[i] = (ptr[i] - '0') * 2;
        }
        else
        {
            multi[i] = (ptr[i] - '0') * 1;
        }
    }
}

void organise_array(const char *str, char *organise) // delete the '-' from the array and assign the value to another array
{
    int i = 0, d = 0, n = 0;
    for (i = 0, d = 0; i < strlen(str); ++i)
    {
        if (isdigit(str[i]))
        {
            organise[i - n] = str[i];
        }

        else if (str[i] == '-')
        {
            n++;
        }
    }
    organise[i] = '\0';
}

int add_the_numbers(char *str, int size) // adding the numbers of the array
{
    int sum = 0;
    for (int i = 0; i < size - 1; i++)
    {
        if (str[i] >= 10)
        {
            str[i] -= 9;
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        sum = sum + str[i];
    }

    return sum;
}

int control_digit(int number)
{
    int c = (10 - (number % 10)) % 10;
    return c;
}

bool is_format_good(const char *input)
{
    char format[] = FORMAT;
    bool is_correct = true;

    uint8_t i = 0;

    while (i < sizeof(FORMAT) - 1)
    {
        if (isalpha(format[i]))
        {
            if (!isdigit(input[i]))
            {
                is_correct = false;
                break;
            }
        }
        else
        {
            if (format[i] != input[i])
            {
                is_correct = false;
                break;
            }
        }
        i++;
    }

    return is_correct;
}

int main(void)
{
    char string[sizeof(FORMAT) + 1] = {0};
    char arrayOrganaized[sizeof(FORMAT) + 1] = {0};
    char newArr[10] = {0};

    // Read the string from the standard input
    printf("Enter date and time in the format of %s: ", FORMAT);
    fgets(string, sizeof(string), stdin);
    string[strlen(string) - 1] = '\0';

    if (is_format_good(string)) // No need to check the rest if the format is wrong...
    {
        strcpy(arrayOrganaized, string);

        organise_array(string, arrayOrganaized);
        multiplication(arrayOrganaized, newArr);

        int CheckC = newArr[9];
        newArr[9] = 0;
        int num = add_the_numbers(newArr, sizeof(newArr));
        char control = control_digit(num);

        printf("The last number of the personal number is : %d\n", control);
        // Fixed spelling errors
        if (CheckC == control)
        {
            printf("You entered right personal number\n");
        }
        else
        {
            printf("You entered wrong personal number\n");
        }
    }
    else
    {
        printf("The format is wrong...\n");
    }
    return 0;
}