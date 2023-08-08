#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(const char *msg);
void print_magic(const Elf64_Ehdr *header);
void print_class(const Elf64_Ehdr *header);
void print_data(const Elf64_Ehdr *header);
void print_version(const Elf64_Ehdr *header);
void print_osabi(const Elf64_Ehdr *header);
void print_abiversion(const Elf64_Ehdr *header);
void print_type(const Elf64_Ehdr *header);
void print_entrypoint(const Elf64_Ehdr *header);
void print_elf_header(const Elf64_Ehdr *header);

/**
* print_error - Prints an error message.
* @msg: The error message to print.
*
* Description: This function prints an error message to stderr.
* It is used for displaying error information during program execution.
*/
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
* print_magic - Prints the magic number of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the magic number of the ELF header,
* which is a unique identifier indicating that the file is in ELF format.
*/
void print_magic(const Elf64_Ehdr *header)
{
	int i; /* Declare the loop variable outside the loop */

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header->e_ident[i]);
	}
	printf("\n");
}

/**
* print_class - Prints the class of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the class of the ELF header,
* which represents the architecture for which the object file is intended.
*/
void print_class(const Elf64_Ehdr *header)
{
	printf("Class: ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Unknown\n");
}

/**
* print_data - Prints the data encoding of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the data encoding of the ELF header,
* which represents the byte order and data format used by the object file.
*/
void print_data(const Elf64_Ehdr *header)
{
	printf("Data: ");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Unknown\n");
}

/**
* print_version - Prints the version of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the version of the ELF header,
* which represents the version of the ELF file format being used.
*/
void print_version(const Elf64_Ehdr *header)
{
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
}

/**
* print_osabi - Prints the OS/ABI of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the OS/ABI of the ELF header,
* which represents the operating system and ABI (Application Binary Interface)
* for which the object file is targeted.
*/
void print_osabi(const Elf64_Ehdr *header)
{
	printf("OS/ABI: ");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone (embedded) application\n");
			break;
		default:
			printf("Unknown\n");
	}
}

/**
* print_abiversion - Prints the ABI version of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the ABI version of the ELF header,
* which represents the version of the ABI (Application Binary Interface)
* for which the object file is targeted.
*/
void print_abiversion(const Elf64_Ehdr *header)
{
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
}

/**
* print_type - Prints the type of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the type of the ELF header,
* which represents the object file type, such as executable, shared
* object, or relocatable.
*/
void print_type(const Elf64_Ehdr *header)
{
	printf("Type: ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("Unknown\n");
	}
}

/**
* print_entrypoint - Prints the entry point address of the ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the entry point address of the ELF header,
* which represents the memory address where the program execution starts.
*/
void print_entrypoint(const Elf64_Ehdr *header)
{
	printf("Entry point address: 0x%lx\n", header->e_entry);
}

/**
* print_elf_header - Prints the entire ELF header.
* @header: A pointer to the ELF header structure.
*
* Description: This function prints the contents of the ELF header,
* including the magic number, class, data encoding, version, OS/ABI,
* ABI version, type, and entry point address.
*/
void print_elf_header(const Elf64_Ehdr *header)
{
	print_magic(header);
	print_class(header);
	print_data(header);
	print_version(header);
	print_osabi(header);
	print_abiversion(header);
	print_type(header);
	print_entrypoint(header);
}

/**
* main - Entry point of the program.
* @argc: The number of command-line arguments.
* @argv: An array of strings containing the command-line arguments.
*
* Description: This is the main function that serves as the entry point
* for the program. It takes command-line arguments as input and performs
* the necessary operations related to the ELF header.
*
* Return: The exit status of the program.
*/
int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr header;
	ssize_t bytes_read;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return (1);
	}

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}

	bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	if (bytes_read == -1)
	{
		perror("Error reading file");
		close(fd);
		return (1);
	}

	print_elf_header(&header);

	close(fd);
	return (0);
}
