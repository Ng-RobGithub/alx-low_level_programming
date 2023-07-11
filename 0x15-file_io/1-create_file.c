
#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: Name of the file to be created
 * @text_content: NULL terminated string written in the file
 * Return: 1 on success. -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fn;
	int nlet;
	int rWR;

	if (!filename)
		return (-1);
	fn = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fn == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nlet = 0; text_content[nlet]; nlet++)

		rWR = write(fn, text_content, nlet);

	if (rWR == -1)
		return (-1);

	close(fn);
	return (1);
}
