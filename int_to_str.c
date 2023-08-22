#include <stdlib.h>

/**
 * integer_to_string - Converts an integer to a string representation.
 *
 * @num: The integer to be converted.
 *
 * Return: A pointer to the dynamically alloc str. NULL if mem alloc fails.
 */
char *integer_to_string(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *result;

	temp = absolute_value(num);
	length = required_string_length(temp, 10);

	if (num < 0 || num_l < 0)
	{
		length++;
	}
	result = malloc(length + 1);

	if (!result)
	{
		return (NULL);
	}

	fill_string_buffer(temp, 10, result, length);
	if (num < 0 || num_l < 0)
	{
		result[0] = '-';
	}
	return (result);
}

/**
 * absolute_value - Calculates the absolute value of an integer.
 *
 * @i: The integer to calculate the absolute value of.
 *
 * Return: The absolute value of the integer.
 */
unsigned int absolute_value(int i)
{
	if (i < 0)
	{
		return (-(unsigned int)i);
	}
	return ((unsigned int)i);
}

/**
 * required_string_length - Calcs req str len to rep a number in a given base.
 *
 * @num: The number for which the length is calculated.
 * @base: The base of the number representation.
 *
 * Return: The required length of the string.
 */
int required_string_length(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_string_buffer - Fills a buf with a num rep in a given base.
 *
 * @num: The number to be represented.
 * @base: The base of the number representation.
 * @buffer: The buffer to store the result.
 * @buffer_size: The size of the buffer in bytes.
 */
void fill_string_buffer(unsigned int num, unsigned int base,
	char *buffer, int buffer_size)
{
	int remainder, i = buffer_size - 1;

	buffer[buffer_size] = '\0';

	while (i >= 0)
	{
		remainder = num % base;

		if (remainder > 9)
		{
			buffer[i] = remainder + 87;
		}
		else
		{
			buffer[i] = remainder + '0';
		}
		num /= base;
		i--;
	}
}
