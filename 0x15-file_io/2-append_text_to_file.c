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
	int fn;
	int nlet;
	int rWR;

	if (!filename)
		return (-1);

	fn = open(filename, O_WRONLY | O_APPEND);
	if (fn == -1)
		return (-1);

	if (text_content)
	{
		for (nlet = 0; text_content[nlet]; nlet++)

		rWR = write(fn, text_content, nlet);

		if (rWR == -1)
			return (-1);
	}
	close(fn);
	return (1);
}
