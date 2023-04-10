#include "main.h"

/**
 * read_textfile- a function that reads a text file and prints it to the POSIX standard output.
 * @filename: filename.
 * @letters: numbers of letters printed.
 *
 * Return: numbers of letters printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{

	char *buf;
	int fn;
	ssize_t nRD;
	ssize_t nWR;


	if (!filename)
		return (0);

	fn = open(filename, O_RDONLY);

	if (fn == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nRD = read(fn, buf, letters);
	nWR = write(STDOUT_FILENO, buf, nRD);

	close(fn);

	free(buf);

	return (nWR);
}
