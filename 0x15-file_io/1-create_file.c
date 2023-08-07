#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: Name of the file to be created
 * @text_content: NULL terminated string written in the file
 * Return: 1 on success. -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{

	int fd;
	int result;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		result = write(fd, text_content, strlen(text_content));
		if (result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
