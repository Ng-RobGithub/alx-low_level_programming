#include "main.h"

/**
 * append_text_to_file - a function that appends text at the end of a file.
 * @filename: Name of the file.
 * @text_content: NULL terminated string to add @EOF
 *
 * Return: 1 on success. -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	FILE *file;
	size_t content_length, result;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);
	file = fopen(filename, "a");
	if (file == NULL)
		return (-1);

	content_length = strlen(text_content);
	result = fwrite(text_content, sizeof(char), content_length, file);
	fclose(file);

	if (result != content_length)
		return (-1);
	return (1);
}
