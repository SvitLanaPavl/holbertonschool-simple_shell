#include "main.h"

/**
 * _strlen - Returns the length of the string
 * Description: returns the length of the string
 * @s: the character argument
 * Return: length
 */

int _strlen(char *s)
{
	size_t length = 0;

	while (*s)
	{
		length++;
		s++;
	}
	return (length);
}
/**
 * _strcat - Concatenates two strings
 * Description: appends source string to destination string
 * overwriting the terminating null byte at te destination string
 * @dest: the destination string argument
 * @src: the source string argument
 * Return: a pointer to the resulting string
 */

char *_strcat(char *dest, char *src)
{
	int i_d = 0;
	int i_s = 0;

	while (dest[i_d])
	{
		i_d++;
	}
	while (src[i_s])
	{
	dest[i_d] = src[i_s];
	i_d++;
	i_s++;
	}
	dest[i_d] = '\0';
	return (dest);
}
/**
 * _strcmp - Compares two strings
 * Description: compares two strings
 * @s1: string 1 argument
 * @s2: string 2 argument
 * Return: 0 if the strings are equal, less than
 * 0 - the first string is less than the second one, greater than 0
 * the first string is greater than the second one
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 == *s2)
{
	if (*s1 == '\0' || *s2 == '\0')
		break;

	s1++;
	s2++;
}

if (*s1 == '\0' && *s2 == '\0')
return (0);
else
return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/**
 * _strcpy - Copies the string
 * Description: Copies the string pointed to by src,
 * including the terminating null byte, to the buffer
 * pointed to by dest
 * @dest: destination argument
 * @src: source argument
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int counter;

for (counter = 0; src[counter] != '\0'; counter++)
{
	dest[counter] = src[counter];
}
dest[counter] = '\0';
return ((char *)dest);
}
/**
 * _strdup - returns pointer to a newly allocated space in memory
 * Description: returns a pointer to a newly allocated space in
 * memory which contains a copy of the string given as a parameter
 * @str: string argument
 * Return: pointer to the duplicated string, NULL if insufficient memory
 * available
 */
char *_strdup(char *str)
{
	char *new_str;
	size_t length = 0;

	if (str == NULL)
	return (NULL);

	length = strlen(str) + 1;
	new_str = malloc(length);
	if (new_str == NULL)
	return (NULL);

	memcpy(new_str, str, length);
	return (new_str);
}
