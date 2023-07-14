#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>

int _putchar(char c);
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
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
