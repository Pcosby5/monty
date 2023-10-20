#include "monty.h"

/**
 * is_number - Check if a string is a valid integer
 * @str: The string to check
 * Return: 1 if it's a number, 0 otherwise
 */
int is_number(const char *str)
{
    int i = 0;

    if (str == NULL || *str == '\0')
        return 0;

    if (str[i] == '-' || str[i] == '+')
        i++;

    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }

    return 1;
}
