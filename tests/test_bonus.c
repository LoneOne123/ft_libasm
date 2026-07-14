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

void test_atoi_base() {
    char *test_str_bin = "       1010";
    char *test_str_dec = "42f";
    char *test_str_hex = "2a";
    char *test_str_bin_neg = "-101f0";
    char *test_str_dec_neg = " -42";
    char *test_str_hex_neg = "-2a";
    char *base_bin = "01";
    char *base_dec = "0123456789";
    char *base_hex = "0123456789abcdef";
    char *base_invalid = "0";
    char *base_invalid_2 = " 01";
    int total_tests = 8;
    int passed_tests = 0;

    printf("Check ft_atoi_base():\n\n");
    printf("##### Binary string (String = \"%s\", Base = \"%s\") #####\n", test_str_bin, base_bin);
    int result_bin_og = strtol(test_str_bin, NULL, 2);
    int result_bin_ft = ft_atoi_base(test_str_bin, base_bin);
    printf("Return of strtol: %i\n", result_bin_og);
    printf("Return of ft_atoi_base: %i\n", result_bin_ft);
    if (result_bin_og == result_bin_ft) {
        printf(GREEN "Test passed for binary string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for binary string.\n\n" RESET); 
    }

    printf("##### Negative binary string (String = \"%s\", Base = \"%s\") #####\n", test_str_bin_neg, base_bin);
    result_bin_og = strtol(test_str_bin_neg, NULL, 2);
    result_bin_ft = ft_atoi_base(test_str_bin_neg, base_bin);
    printf("Return of strtol: %i\n", result_bin_og);
    printf("Return of ft_atoi_base: %i\n", result_bin_ft);
    if (result_bin_og == result_bin_ft) {
        printf(GREEN "Test passed for negative binary string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for negative binary string.\n\n" RESET); 
    }

    printf("##### Decimal string (String = \"%s\", Base = \"%s\") #####\n", test_str_dec, base_dec);
    int result_dec_og = strtol(test_str_dec, NULL, 10);
    int result_dec_ft = ft_atoi_base(test_str_dec, base_dec);
    printf("Return of strtol: %i\n", result_dec_og);
    printf("Return of ft_atoi_base: %i\n", result_dec_ft);
    if (result_dec_og == result_dec_ft) {
        printf(GREEN "Test passed for decimal string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for decimal string.\n\n" RESET);    
    }

    printf("##### Negative decimal string (String = \"%s\", Base = \"%s\") #####\n", test_str_dec_neg, base_dec);
    result_dec_og = strtol(test_str_dec_neg, NULL, 10);
    result_dec_ft = ft_atoi_base(test_str_dec_neg, base_dec);
    printf("Return of strtol: %i\n", result_dec_og);
    printf("Return of ft_atoi_base: %i\n", result_dec_ft);
    if (result_dec_og == result_dec_ft) {
        printf(GREEN "Test passed for negative decimal string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for negative decimal string.\n\n" RESET);
    }

    printf("##### Hexadecimal string (String = \"%s\", Base = \"%s\") #####\n", test_str_hex, base_hex);
    int result_hex_og = strtol(test_str_hex, NULL, 16);
    int result_hex_ft = ft_atoi_base(test_str_hex, base_hex);
    printf("Return of strtol: %i\n", result_hex_og);
    printf("Return of ft_atoi_base: %i\n", result_hex_ft);
    if (result_hex_og == result_hex_ft) {
        printf(GREEN "Test passed for hexadecimal string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for hexadecimal string.\n\n" RESET);
    }

    printf("##### Negative hexadecimal string (String = \"%s\", Base = \"%s\") #####\n", test_str_hex_neg, base_hex);
    result_hex_og = strtol(test_str_hex_neg, NULL, 16);
    result_hex_ft = ft_atoi_base(test_str_hex_neg, base_hex);
    printf("Return of strtol: %i\n", result_hex_og);
    printf("Return of ft_atoi_base: %i\n", result_hex_ft);
    if (result_hex_og == result_hex_ft) {
        printf(GREEN "Test passed for negative hexadecimal string.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for negative hexadecimal string.\n\n" RESET);
    }

    printf("##### Invalid base (String = \"%s\", Base = \"%s\") #####\n", test_str_dec, base_invalid);
    int result_invalid_og = strtol(test_str_dec, NULL, 1); // strtol with base 1 is invalid and should return 0
    int result_invalid_ft = ft_atoi_base(test_str_dec, base_invalid);
    printf("Return of strtol: %i\n", result_invalid_og);
    printf("Return of ft_atoi_base: %i\n", result_invalid_ft);
    if (result_invalid_og == result_invalid_ft) {
        printf(GREEN "Test passed for invalid base.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for invalid base.\n\n" RESET);
    }

    printf("##### Invalid base (String = \"%s\", Base = \"%s\") #####\n", test_str_dec, base_invalid_2);
    result_invalid_og = strtol(test_str_dec, NULL, 1); // strtol with base 1 is invalid and should return 0
    result_invalid_ft = ft_atoi_base(test_str_dec, base_invalid_2);
    printf("Return of strtol: %i\n", result_invalid_og);
    printf("Return of ft_atoi_base: %i\n", result_invalid_ft);
    if (result_invalid_og == result_invalid_ft) {
        printf(GREEN "Test passed for invalid base.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for invalid base.\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_atoi_base().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_list_push_front() {
    t_list *list = NULL;
    char *data1 = "first";
    char *data2 = "second";
    char *data3 = "third";
    int total_tests = 3;
    int passed_tests = 0;

    printf("Check ft_list_push_front():\n\n");
    printf("##### Push first element (Data = \"%s\") #####\n", data1);
    ft_list_push_front(&list, data1);
    if (list != NULL && list->data == data1 && list->next == NULL) {
        printf(GREEN "Test passed for pushing first element.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for pushing first element.\n\n" RESET);
    }

    printf("##### Push second element (Data = \"%s\") #####\n", data2);
    ft_list_push_front(&list, data2);
    if (list != NULL && list->data == data2 && list->next != NULL && list->next->data == data1) {
        printf(GREEN "Test passed for pushing second element.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for pushing second element.\n\n" RESET);
    }

    printf("##### Push third element (Data = \"%s\") #####\n", data3);
    ft_list_push_front(&list, data3);
    if (list != NULL && list->data == data3 && list->next != NULL && list->next->data == data2) {
        printf(GREEN "Test passed for pushing third element.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for pushing third element.\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_list_push_front().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_list_size() {
    t_list *list = NULL;
    char *data1 = "first";
    char *data2 = "second";
    char *data3 = "third";
    int total_tests = 4;
    int passed_tests = 0;

    printf("Check ft_list_size():\n\n");
    printf("##### Size of empty list #####\n");
    int size_og = 0; // Manually calculated size of empty list
    int size_ft = ft_list_size(list);
    printf("Return of manual calculation: %i\n", size_og);
    printf("Return of ft_list_size: %i\n", size_ft);
    if (size_og == size_ft) {
        printf(GREEN "Test passed for size of empty list.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for size of empty list.\n\n" RESET);
    }

    ft_list_push_front(&list, data1);
    printf("##### Size after pushing first element (Data = \"%s\") #####\n", data1);
    size_og = 1; // Manually calculated size after pushing first element
    size_ft = ft_list_size(list);
    printf("Return of manual calculation: %i\n", size_og);
    printf("Return of ft_list_size: %i\n", size_ft);
    if (size_og == size_ft) {
        printf(GREEN "Test passed for size after pushing first element.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for size after pushing first element.\n\n" RESET);
    }

    ft_list_push_front(&list, data2);
    printf("##### Size after pushing second element (Data = \"%s\") #####\n", data2);
    size_og = 2; // Manually calculated size after pushing second element
    size_ft = ft_list_size(list);
    printf("Return of manual calculation: %i\n", size_og);
    printf("Return of ft_list_size: %i\n", size_ft);
    if (size_og == size_ft) {
        printf(GREEN "Test passed for size after pushing second element.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for size after pushing second element.\n\n" RESET);
    }

    ft_list_push_front(&list, data3);
    printf("##### Size after pushing third element (Data = \"%s\") #####\n", data3);
    size_og = 3; // Manually calculated size after pushing third element
    size_ft = ft_list_size(list);
    printf("Return of manual calculation: %i\n", size_og);
    printf("Return of ft_list_size: %i\n", size_ft);
    if (size_og == size_ft) {
        printf(GREEN "Test passed for size after pushing third element.\n\n" RESET);
        passed_tests++;
    } else {
        printf(RED "Test failed for size after pushing third element.\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_list_size().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_list_sort() {
    t_list *list = NULL;
    char *data1 = "abc";
    char *data2 = "bcd";
    char *data3 = "cde";
    int total_tests = 3;
    int passed_tests = 0;

    printf("Check ft_list_sort():\n\n");
    printf("##### Sort empty/null list #####\n");
    ft_list_sort(&list, strcmp);
    if (list == NULL){
        printf("List still NULL.\n");
        printf(GREEN "Test passed for sorting of empty/NULL list.\n\n" RESET);
        passed_tests++;
    }
    else {
        printf(RED "Test failed list not NULL\n\n" RESET);
    }

    ft_list_push_front(&list, data1);
    ft_list_push_front(&list, data2);
    ft_list_push_front(&list, data3);
    printf("##### Sort list with strings and cmp #####\n");
    printf("List before sort: %s -> %s -> %s\n", (char *) list->data, (char *) list->next->data, (char *) list->next->next->data);
    ft_list_sort(&list, strcmp);
    printf("List after sort: %s -> %s -> %s\n", (char *) list->data, (char *) list->next->data, (char *) list->next->next->data);
    if (list->data == data1 && list->next->data == data2 && list->next->next->data == data3){
        printf(GREEN "Test passed for sorting of string list with strcmp.\n\n" RESET);
        passed_tests++;
    }
    else {
        printf(RED "Test failed list not sorted\n\n" RESET);
    }

    t_list *int_list = NULL;
    int a = 1;
    int b = 2;
    int c = 3;
    printf("##### Sort list with ints and own greater function #####\n");
    ft_list_push_front(&int_list, &b);
    ft_list_push_front(&int_list, &c);
    ft_list_push_front(&int_list, &a);
    printf("List before sort: %i -> %i -> %i\n",*(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    ft_list_sort(&int_list, greater);
    printf("List after sort: %i -> %i -> %i\n", *(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    if (*(int *) int_list->data == a && *(int *) int_list->next->data == b && *(int *) int_list->next->next->data == c){
        printf(GREEN "Test passed for sorting of int list with greater.\n\n" RESET);
        passed_tests++;
    }
    else {
        printf(RED "Test failed list not sorted\n\n" RESET);
    }

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_list_remove_if().\n\n" RESET, total_tests - passed_tests, total_tests);
    }
}

void test_list_remove() {
    t_list *int_list = NULL;
    int *a = malloc(sizeof(int));
    int *b = malloc(sizeof(int));
    int *c = malloc(sizeof(int));
    *a = 1;
    *b = 2;
    *c = 3;
    int data_ref_i = 5;
    int total_tests = 5;
    int passed_tests = 0;

    printf("Check ft_list_remove_if():\n\n");

    printf("##### Remove element from empty list #####\n");
    if (int_list == NULL) {
        printf("List before remove: NULL/EMPTY\n");
    }
    else {
        printf("List before remove: not NULL/EMPTY");
    }
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);
    if (int_list == NULL) {
        printf("List after remove: NULL/EMPTY\n\n");
        passed_tests++;
        printf(GREEN "Test passed for removing element from empty list.\n\n" RESET);
    }
    else {
        printf("List after remove: not NULL/EMPTY");
        printf(RED "Test failed list not NULL\n\n" RESET);
    }


    printf("##### Remove non existing element from list #####\n");
    ft_list_push_front(&int_list, b);
    ft_list_push_front(&int_list, c);
    ft_list_push_front(&int_list, a);
    printf("List before ft_list_remove_if(..., 5, ..., ...): %i -> %i -> %i\n",*(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);
    printf("List after ft_list_remove_if(..., 5, ..., ...): %i -> %i -> %i\n\n",*(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    
    if (*(int *) int_list->data == 1 && *(int *) int_list->next->data == 3 && *(int *) int_list->next->next->data == 2) {
        passed_tests++;
        printf(GREEN "Test passed for removing non existant element list.\n\n" RESET);
    }
    else {
        printf(RED "Test failed list is not the same like before\n\n" RESET);
    }



    printf("##### Remove first element from list #####\n");
    data_ref_i = 1;
    printf("List before ft_list_remove_if(..., 1, ..., ...): %i -> %i -> %i\n",*(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);
    printf("List after ft_list_remove_if(..., 1, ..., ...): %i -> %i -> %p\n\n",*(int *) int_list->data, *(int *) int_list->next->data, (void *) int_list->next->next);
    if (*(int *) int_list->data == 3 && *(int *) int_list->next->data == 2 && (void *) int_list->next->next == NULL) {
        passed_tests++;
        printf(GREEN "Test passed for removing first element list.\n\n" RESET);
    }
    else {
        printf(RED "Test failed!\n\n" RESET);
    }
    

    printf("##### Remove second element from list #####\n");
    data_ref_i = 3;
    int *d = malloc(sizeof(int));
    *d = 1;
    ft_list_push_front(&int_list, d);
    printf("List before ft_list_remove_if(..., 3, ..., ...): %i -> %i -> %i\n",*(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);
    printf("List after ft_list_remove_if(..., 1, ..., ...): %i -> %i -> %p\n\n",*(int *) int_list->data, *(int *) int_list->next->data, (void *) int_list->next->next);
    if (*(int *) int_list->data == 1 && *(int *) int_list->next->data == 2 && (void *) int_list->next->next == NULL) {
        passed_tests++;
        printf(GREEN "Test passed for removing second element list.\n\n" RESET);
    }
    else {
        printf(RED "Test failed!\n\n" RESET);
    }

    printf("##### Remove third element from list #####\n");
    data_ref_i = 2;
    int *e = malloc(sizeof(int));
    *e = 3;
    ft_list_push_front(&int_list, e);
    printf("List before ft_list_remove_if(..., 2, ..., ...): %i -> %i -> %i\n",*(int *) int_list->data, *(int *) int_list->next->data, *(int *) int_list->next->next->data);
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);
    printf("List after ft_list_remove_if(..., 2, ..., ...): %i -> %i -> %p\n\n",*(int *) int_list->data, *(int *) int_list->next->data, (void *) int_list->next->next);
    if (*(int *) int_list->data == 3 && *(int *) int_list->next->data == 1 && (void *) int_list->next->next == NULL) {
        passed_tests++;
        printf(GREEN "Test passed for removing third element list.\n\n" RESET);
    }
    else {
        printf(RED "Test failed!\n\n" RESET);
    }

    data_ref_i = 1;
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);
    data_ref_i = 3;
    ft_list_remove_if(&int_list, &data_ref_i, greater, free_fcnt);

    if (passed_tests == total_tests) {
        printf(GREEN "%i/%i passed.\n\n" RESET, passed_tests, total_tests);
    } else {
        printf(RED "%d out of %d tests failed for ft_list_remove_if().\n\n" RESET, total_tests - passed_tests, total_tests);
    }


    return;
}

int main(){
    test_atoi_base();
    printf("---------------------------------------------------------------\n\n");
    test_list_push_front();
    printf("---------------------------------------------------------------\n\n");
    test_list_size();
    printf("---------------------------------------------------------------\n\n");
    test_list_sort();
    printf("---------------------------------------------------------------\n\n");
    test_list_remove();

    return 0;
}