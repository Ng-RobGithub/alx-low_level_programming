#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: filename.
 * @text_content: content written in the file
 * Return: 1 on success. -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fn;
	int nlet;
	int nWR;

	if (filename == NULL)
		return (-1);

	fn = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fn == NULL)
		return (-1);

	if (text_content)
		text_content = "";
	for (nlet = 0; text_content[nlet]; nlet++)

	nWR = write(fn, text_content, nlet);

	if (nWR == -1)
		return (-1);

	close(fn);

	return (1);
}
