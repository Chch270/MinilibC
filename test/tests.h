/*
** EPITECH PROJECT, 2021
** B-ASM-400-PAR-4-1-asmminilibc-charlie.chou
** File description:
** tests
*/

#ifndef TESTS_H_
#define TESTS_H_

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>

int my_strlen(char *str);
char *my_strchr(const char *s, int c);
void *my_memset(void *s, int c, size_t n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_rindex(const char *s, int c);
void *my_memcpy(void *dest, const void *src, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);
char *my_strstr(const char *haystack, const char *needle);
int my_strcasecmp(const char *s1, const char *s2);
char *my_strpbrk(const char *s, const char *accept);
size_t my_strcspn(const char *s, const char *reject);

#endif /* !TESTS_H_ */
