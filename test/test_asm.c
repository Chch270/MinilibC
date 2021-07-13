/*
** EPITECH PROJECT, 2021
** test
** File description:
** asm test
*/

#include "tests.h"

Test(test_asm_strlen, asm_strlen_empty)
{
    cr_assert(my_strlen("") == strlen(""));
}

Test(test_asm_strlen, asm_strlen_line)
{
    cr_assert(my_strlen("hello") == strlen("hello"));
}

Test(test_asm_strlen, asm_strlen_multiple_time)
{
    char str[] = "Hello world!";

    cr_assert(my_strlen(str) == strlen(str));
    cr_assert(my_strlen(str) == strlen(str));
    cr_assert(my_strlen(str) == strlen(str));
}

Test(test_asm_strchr, asm_strchr_find)
{
    cr_assert_str_eq(my_strchr("hello", 'l'), strchr("hello", 'l'));
}

Test(test_asm_strchr, asm_strchr_find_null)
{
    cr_assert_str_eq(my_strchr("hello", '\0'), strchr("hello", '\0'));
}

Test(test_asm_strchr, asm_strchr_no_find)
{
    cr_assert(my_strchr("hello", 'z') == strchr("hello", 'z'));
}

Test(test_asm_memset, asm_memset_zero)
{
    char str[] = "hello";

    cr_assert_str_eq(my_memset(str, 'a', 0), memset(str, 'a', 0));
}

Test(test_asm_memset, asm_memset_nbr)
{
    char str[] = "hello";
    char str2[] = "hello";

    cr_assert_str_eq(my_memset(str, 'a', 3), memset(str2, 'a', 3));
}

Test(test_asm_rindex, asm_rindex_chr)
{
    char str[] = "hello";

    cr_assert_str_eq(my_rindex(str, 'l'), rindex(str, 'l'));
}

Test(test_asm_rindex, asm_rindex_last)
{
    char str[] = "hello";

    cr_assert_str_eq(my_rindex(str, 'o'), rindex(str, 'o'));
}

Test(test_asm_rindex, asm_rindex_no_chr)
{
    char str[] = "hello";

    cr_assert(my_rindex(str, 'z') == NULL);
}

Test(test_asm_strstr, asm_strstr_basic)
{
    char *str = "Hello World!";
    char *str2 = "lo";
    char *str3 = my_strstr(str, str2);

    cr_assert_str_eq(str3, strstr(str, str2));
}

Test(test_asm_strstr, asm_strstr_last)
{
    char *str = "Hello World!";
    char *str2 = "!";
    char *str3 = my_strstr(str, str2);

    cr_assert_str_eq(str3, strstr(str, str2));
}

Test(test_asm_strstr, asm_strstr_no_find)
{
    char *str = "Hello World!";
    char *str2 = "42";
    char *str3 = my_strstr(str, str2);

    cr_assert(str3 == NULL);
}

Test(test_asm_strstr, asm_strstr_no_second_string)
{
    char *str3 = my_strstr("", "");

    cr_assert_str_eq(str3, strstr("", ""));
}

Test(test_asm_strcmp, asm_strcmp_same)
{
    cr_assert(my_strcmp("coucou", "coucou") == strcmp("coucou", "coucou"));
}

Test(test_asm_strcmp, asm_strcmp_greater)
{
    cr_assert(my_strcmp("coucoua", "coucou") > 0);
}

Test(test_asm_strcmp, asm_strcmp_lower)
{
    cr_assert(my_strcmp("coucou", "coucoua") < 0);
}

Test(test_asm_strncmp, asm_strncmp_same)
{
    cr_assert(my_strncmp("coucou", "coucou", 3) == 0);
}

Test(test_asm_strncmp, asm_strncmp_greater_long)
{
    cr_assert(my_strncmp("coucou", "coucou", 100) == 0);
}

Test(test_asm_strncmp, asm_strncmp_greater)
{
    cr_assert(my_strncmp("coucoua", "coucou", 100) > 0);
}

Test(test_asm_strncmp, asm_strncmp_lower)
{
    cr_assert(my_strncmp("coucou", "coucoua", 100) < 0);
}

Test(test_asm_strncmp, asm_strncmp_nothing)
{
    cr_assert(my_strncmp("", "", 100) == 0);
}

Test(test_asm_strncmp, asm_strncmp_nothing_nothing)
{
    cr_assert(my_strncmp("", "", 0) == 0);
}

Test(test_asm_strncmp, asm_strncmp_stop)
{
    cr_assert(my_strncmp("azerty", "azrety", 2) == 0);
}

Test(test_asm_memcpy, asm_memcpy_zero)
{
    char *str = "hello";
    char str2[] = "aaaaaa";

    cr_assert_str_eq(my_memcpy(str, str2, 0), memcpy(str, str2, 0));
}

Test(test_asm_memcpy, asm_memcpy_basic)
{
    char str[] = "hello";
    char str2[] = "aaaaaa";

    cr_assert_str_eq(my_memcpy(str, str2, 3), memcpy(str, str2, 3));
}

Test(test_asm_memcpy, asm_memcpy_all)
{
    char str1[] = "hello";
    char str2[] = "aaaaa";

    cr_assert_str_eq(my_memcpy(str1, str2, 5), memcpy(str1, str2, 5));
}

Test(test_asm_strcasecmp, asm_strcasecmp_basic)
{
    char str1[] = "HELLO WORLD!";
    char str2[] = "hello world!";

    cr_assert(my_strcasecmp(str1, str2) == strcasecmp(str1, str2));
}

Test(test_asm_strcasecmp, asm_strcasecmp_upper)
{
    char str1[] = "hElLo WoRlD!";
    char str2[] = "HELLO WORLD!";

    cr_assert(my_strcasecmp(str1, str2) == strcasecmp(str1, str2));
}

Test(test_asm_strpbrk, asm_strpbrk_basic)
{
    cr_assert_str_eq(my_strpbrk("hello world!", "lol"), strpbrk("hello world!", "lol"));
}

Test(test_asm_strpbrk, asm_strpbrk_invert)
{
    cr_assert_str_eq(my_strpbrk("hello world!", "ol"), strpbrk("hello world!", "ol"));
}

Test(test_asm_strpbrk, asm_strpbrk_null)
{
    cr_assert(my_strpbrk("hello world!", "zz") == NULL);
}

Test(test_asm_memmove, asm_memmove_basic)
{
    char str1[] = "hello";
    char str2[] = "aaaaa";

    cr_assert_str_eq(my_memmove(str1, str2, 5), memmove(str1, str2, 5));
}

Test(test_asm_memmove, asm_memmove_adding_src)
{
    char str[] = "hello world!";
    char str2[] = "hello world!";

    cr_assert_str_eq(my_memmove(str, str + 2, 5), memmove(str2, str2 + 2, 5));
}

Test(test_asm_memmove, asm_memmove_adding_dest)
{
    char str[] = "hello world!";
    char str2[] = "hello world!";

    cr_assert_str_eq(my_memmove(str + 2, str, 5), memmove(str2 + 2, str2, 5));
}
/*
Test(test_asm_strcspn, asm_strcspn_basic)
{
    int x = my_strcspn("hello world!", "w");
    int y = strcspn("hello world!", "w");

    cr_assert(x == y, "%d %d\n", x, y);
}
*/
