#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define RED   "\x1b[31m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

int greater(void *a, void *b) {
    int ia = *(int *)a;
    int ib = *(int *)b;
    
    if (ia > ib) {
        return 1;
    }
    if (ia < ib) {
        return -1;
    }
    return 0;
}

void free_fcnt(void *data) {
    free(data);
    return;
}

void test_strlen() {
    // char *null_str = NULL;
    char *empty_str = "";
    char *test_str_one_char = "a";
    char *test_str_multiple_chars = "hello";
    int total_tests = 3;
    int passed_tests = 0;

    printf("Check ft_strlen():\n\n");
    
    // printf("##### Null string (String = %s) #####\n", null_str);
    // printf("Return of strlen: %li\n", strlen(null_str));
    // printf("Return of ft_strlen: %li\n", ft_strlen(null_str));
    // if (strlen(null_str) == ft_strlen(null_str)) {
    //     printf(GREEN "Test passed for null string.\n\n" RESET);
    //     passed_tests++;
    // } else {
    //     printf(RED "Test failed for null string.\n\n" RESET);
    // }

    printf("##### Empty string (String = \"%s\") #####\n", empty_str);
    printf("Return of strlen: %li\n", strlen(empty_str));
    printf("Return of ft_strlen: %li\n", ft_strlen(empty_str));
    if (strlen(empty_str) == ft_strlen(empty_str)) {
        printf(GREEN "Test passed for empty string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for empty string.\n\n" RESET);
    }

    printf("##### String with one character (String = \"%s\") #####\n", test_str_one_char);
    printf("Return of strlen: %li\n", strlen(test_str_one_char));
    printf("Return of ft_strlen: %li\n", ft_strlen(test_str_one_char));
    if (strlen(test_str_one_char) == ft_strlen(test_str_one_char)) {
        printf(GREEN "Test passed for string with one character.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with one character.\n\n" RESET);
    }

    printf("##### String with multiple characters (String = \"%s\") #####\n", test_str_multiple_chars);
    printf("Return of strlen: %li\n", strlen(test_str_multiple_chars));
    printf("Return of ft_strlen: %li\n", ft_strlen(test_str_multiple_chars));
    if (strlen(test_str_multiple_chars) == ft_strlen(test_str_multiple_chars)) {
        printf(GREEN "Test passed for string with multiple characters.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with multiple characters.\n\n" RESET);
    }
    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_strlen().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_strcpy() {
    // char *null_str = NULL;
    char *empty_str = "";
    char *test_str_one_char = "a";
    char *test_str_multiple_chars = "hello";
    char dest_og[6];
    char dest_ft[6];
    int total_tests = 3;
    int passed_tests = 0;

    printf("Check ft_strcpy():\n\n");
    printf("##### Empty string (String = \"%s\") #####\n", empty_str);
    printf("Return of strcpy: %s\n", strcpy(dest_og, empty_str));
    printf("Return of ft_strcpy: %s\n", ft_strcpy(dest_ft, empty_str));
    if (strcmp(dest_og, dest_ft) == 0) {
        printf(GREEN "Test passed for empty string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for empty string.\n\n" RESET);
    }

    printf("##### String with one character (String = \"%s\") #####\n", test_str_one_char);
    printf("Return of strcpy: %s\n", strcpy(dest_og, test_str_one_char));
    printf("Return of ft_strcpy: %s\n", ft_strcpy(dest_ft, test_str_one_char));
    if (strcmp(dest_og, dest_ft) == 0) {
        printf(GREEN "Test passed for string with one character.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with one character.\n\n" RESET);
    }

    printf("##### String with multiple characters (String = \"%s\") #####\n", test_str_multiple_chars);
    printf("Return of strcpy: %s\n", strcpy(dest_og, test_str_multiple_chars));
    printf("Return of ft_strcpy: %s\n", ft_strcpy(dest_ft, test_str_multiple_chars));
    if (strcmp(dest_og, dest_ft) == 0) {
        printf(GREEN "Test passed for string with multiple characters.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with multiple characters.\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_strcpy().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_strcmp() {
    char *empty_str = "";
    char *test_str_one_char = "a";
    char *test_str_one_char_b = "b";
    char *test_str_multiple_chars = "hello";
    int total_tests = 5;
    int passed_tests = 0;

    printf("Check ft_strcmp():\n\n");
    printf("##### Empty string (String = \"%s\") #####\n", empty_str);
    printf("Return of strcmp: %i\n", strcmp(empty_str, empty_str));
    printf("Return of ft_strcmp: %i\n", ft_strcmp(empty_str, empty_str));
    if (strcmp(empty_str, empty_str) == ft_strcmp(empty_str, empty_str)) {
        printf(GREEN "Test passed for empty string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for empty string.\n\n" RESET);
    }

    printf("##### String with one character (String = \"%s\") #####\n", test_str_one_char);
    printf("Return of strcmp: %i\n", strcmp(test_str_one_char, test_str_one_char));
    printf("Return of ft_strcmp: %i\n", ft_strcmp(test_str_one_char, test_str_one_char));
    if (strcmp(test_str_one_char, test_str_one_char) == ft_strcmp(test_str_one_char, test_str_one_char)) {
        printf(GREEN "Test passed for string with one character.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with one character.\n\n" RESET);
    }

    printf("##### String with multiple characters (String = \"%s\") #####\n", test_str_multiple_chars);
    printf("Return of strcmp: %i\n", strcmp(test_str_multiple_chars, test_str_multiple_chars));
    printf("Return of ft_strcmp: %i\n", ft_strcmp(test_str_multiple_chars, test_str_multiple_chars));
    if (strcmp(test_str_multiple_chars, test_str_multiple_chars) == ft_strcmp(test_str_multiple_chars, test_str_multiple_chars)) {
        printf(GREEN "Test passed for string with multiple characters.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with multiple characters.\n\n" RESET);
    }

    printf("##### Compare string with one character to empty string (String = \"%s\" vs \"%s\") #####\n", test_str_one_char, empty_str);
    printf("Return of strcmp: %i\n", strcmp(test_str_one_char, empty_str));
    printf("Return of ft_strcmp: %i\n", ft_strcmp(test_str_one_char, empty_str));
    if (strcmp(test_str_one_char, empty_str) == ft_strcmp(test_str_one_char, empty_str)) {
        printf(GREEN "Test passed for comparing string with one character to empty string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for comparing string with one character to empty string.\n\n" RESET);
    }

    printf("##### Compare string with one character to different string with one character (String = \"%s\" vs \"%s\") #####\n", test_str_one_char, test_str_one_char_b);
    printf("Return of strcmp: %i\n", strcmp(test_str_one_char, test_str_one_char_b));
    printf("Return of ft_strcmp: %i\n", ft_strcmp(test_str_one_char, test_str_one_char_b));
    if (strcmp(test_str_one_char, test_str_one_char_b) == ft_strcmp(test_str_one_char, test_str_one_char_b)) {
        printf(GREEN "Test passed for comparing string with one character to different string with one character.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for comparing string with one character to different string with one character.\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_strcmp().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_read_write() {
    char buffer_og[100];
    char buffer_ft[100];
    ssize_t bytes_read_og;
    ssize_t bytes_read_ft;
    ssize_t bytes_written_og;
    ssize_t bytes_written_ft;
    int total_tests = 2;
    int passed_tests = 0;

    printf("Check ft_read():\n\n");
    printf("(Original) Enter some text: ");
    fflush(stdout);
    bytes_read_og = read(STDIN_FILENO, buffer_og, sizeof(buffer_og) - 1);
    if (bytes_read_og < 0) {
        perror("Error reading from standard input");
        return;
    }
    buffer_og[bytes_read_og] = '\0'; // Null-terminate the string
    printf("(Original) bytes_read: %li\n", bytes_read_og);
    printf("(Original) You entered:");
    bytes_written_og = write(STDOUT_FILENO, buffer_og, bytes_read_og);
    printf("\n");
    if (bytes_written_og < 0) {
        perror("Error writing to standard output");
        return;
    }

    printf("\n(Ft) Enter same text: ");
    fflush(stdout);
    bytes_read_ft = ft_read(STDIN_FILENO, buffer_ft, sizeof(buffer_ft) - 1);
    if (bytes_read_ft < 0) {
        perror("Error reading from standard input");
        return;
    }
    buffer_ft[bytes_read_ft] = '\0'; // Null-terminate the string
    printf("(Ft) bytes_read: %li\n", bytes_read_ft);
    printf("(Ft) You entered:");
    bytes_written_ft = ft_write(STDOUT_FILENO, buffer_ft, bytes_read_ft);
    printf("\n");
    if (bytes_written_ft < 0) {
        perror("Error writing to standard output");
        return;
    }

    if (bytes_read_og == bytes_read_ft && strcmp(buffer_og, buffer_ft) == 0) {
        printf(GREEN "Test passed for ft_read().\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for ft_read().\n\n" RESET);
    }

    if (bytes_written_og == bytes_written_ft && strcmp(buffer_og, buffer_ft) == 0) {
        printf(GREEN "Test passed for ft_write().\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for ft_write().\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_strcmp().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_strdup() {
    char *empty_str = "";
    char *test_str_one_char = "a";
    char *test_str_multiple_chars = "hello";
    int total_tests = 3;
    int passed_tests = 0;

    printf("Check ft_strdup():\n\n");
    printf("##### Empty string (String = \"%s\") #####\n", empty_str);
    char *dup_empty_og = strdup(empty_str);
    char *dup_empty_ft = ft_strdup(empty_str);
    printf("Return of strdup: %s\n", dup_empty_og);
    printf("Return of ft_strdup: %s\n", dup_empty_ft);
    if (strcmp(dup_empty_og, dup_empty_ft) == 0) {
        printf(GREEN "Test passed for empty string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for empty string.\n\n" RESET);
    }
    free(dup_empty_og);
    free(dup_empty_ft);

    printf("##### String with one character (String = \"%s\") #####\n", test_str_one_char);
    char *dup_one_char_og = strdup(test_str_one_char);
    char *dup_one_char_ft = ft_strdup(test_str_one_char);
    printf("Return of strdup: %s\n", dup_one_char_og);
    printf("Return of ft_strdup: %s\n", dup_one_char_ft);
    if (strcmp(dup_one_char_og, dup_one_char_ft) == 0) {
        printf(GREEN "Test passed for string with one character.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with one character.\n\n" RESET);
    }
    free(dup_one_char_og);
    free(dup_one_char_ft);

    printf("##### String with multiple characters (String = \"%s\") #####\n", test_str_multiple_chars);
    char *dup_multiple_chars_og = strdup(test_str_multiple_chars);
    char *dup_multiple_chars_ft = ft_strdup(test_str_multiple_chars);
    printf("Return of strdup: %s\n", dup_multiple_chars_og);
    printf("Return of ft_strdup: %s\n", dup_multiple_chars_ft);
    if (strcmp(dup_multiple_chars_og, dup_multiple_chars_ft) == 0) {
        printf(GREEN "Test passed for string with multiple characters.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for string with multiple characters.\n\n" RESET);
    }
    free(dup_multiple_chars_og);
    free(dup_multiple_chars_ft);
}

int main(){
    test_strlen();
    printf("---------------------------------------------------------------\n\n");
    test_strcpy();
    printf("---------------------------------------------------------------\n\n");
    test_strcmp();
    printf("---------------------------------------------------------------\n\n");
    test_read_write();
    printf("---------------------------------------------------------------\n\n");
    test_strdup();

    return 0;
}