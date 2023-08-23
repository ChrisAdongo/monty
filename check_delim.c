#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string.
 *
 * @str: The string to analyze.
 * @delims: Delimiter characters.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str, char *delims)
{
	int count = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * split_string - Splits a string into words based on delimiters.
 *
 * @str: The string to split.
 * @delims: Delimiter characters.
 *
 * Return: A 2D array of pointers to words.
 */
char **split_string(char *str, char *delims)
{
	char **words = NULL;
	int word_count, word_length, n, i = 0;

	if (str == NULL || !*str)
	{
		return (NULL);
	}

	word_count = count_words(str, delims);

	if (word_count == 0)
	{
		return (NULL);
	}

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	{
		return (NULL);
	}

	while (i < word_count)
	{
		word_length = get_word_length(str, delims);
		if (is_delimiter(*str, delims))
		{
			str = find_next_word(str, delims);
		}
		words[i] = malloc((word_length + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < word_length)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0';
		str = find_next_word(str, delims);
		i++;
	}
	words[i] = NULL;
	return (words);
}

/**
 * is_delimiter - Checks if a character is a delimiter.
 *
 * @ch: The character to check.
 * @delims: Pointer to a null-terminated array of delimiters.
 *
 * Return: 1 if the character is a delimiter, 0 otherwise.
 */
int is_delimiter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * get_word_length - Gets the length of the current word.
 *
 * @str: The string to analyze.
 * @delims: Delimiter characters.
 *
 * Return: The length of the current word.
 */
int get_word_length(char *str, char *delims)
{
	int length = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			length++;
		}
		if (length > 0 && is_delimiter(str[i], delims))
			break;
		i++;
	}
	return (length);
}

/**
 * find_next_word - Finds the start of the next word in a string.
 *
 * @str: The string to search.
 * @delims: Delimiter characters.
 *
 * Return: A pointer to the first character of the next word.
 */
char *find_next_word(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (is_delimiter(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
