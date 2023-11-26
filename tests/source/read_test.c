/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** read_test
*/

#include <criterion/criterion.h>
#include "bytebuffer.h"
#include <stdio.h>

Test(bytebuffer_read, small)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[128] = {0};
    int read_bytes = 0;

    bytebuffer_write(buffer, bytes, strlen(bytes));
    read_bytes = bytebuffer_read(buffer, output, 10);
    cr_assert(read_bytes == 10, "Expected: %d, but got: %d\n", 10, read_bytes);
    cr_assert_arr_eq(output, bytes, 10);
    bytebuffer_delete(buffer);
}

Test(bytebuffer_read, all)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[128] = {0};
    int read_bytes = 0;

    bytebuffer_write(buffer, bytes, strlen(bytes));
    read_bytes = bytebuffer_read(buffer, output, 26);
    cr_assert(read_bytes == 26, "Expected: %d, but got: %d\n", 26, read_bytes);
    cr_assert_arr_eq(output, bytes, 26);
    bytebuffer_delete(buffer);
}

Test(bytebuffer_read, small_chained)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[128] = {0};
    int read_bytes = 0;

    bytebuffer_write(buffer, bytes, strlen(bytes));
    read_bytes = bytebuffer_read(buffer, output, 8);
    cr_assert(read_bytes == 8, "Expected: %d, but got: %d\n", 8, read_bytes);
    cr_assert_arr_eq(output, bytes, 8);
    read_bytes = bytebuffer_read(buffer, output, 10);
    cr_assert(read_bytes == 10, "Expected: %d, but got: %d\n", 10, read_bytes);
    cr_assert_arr_eq(output, bytes + 8, 10);
    read_bytes = bytebuffer_read(buffer, output, 5);
    cr_assert(read_bytes == 5, "Expected: %d, but got: %d\n", 5, read_bytes);
    cr_assert_arr_eq(output, bytes + 18, 5);
    bytebuffer_delete(buffer);
}

Test(bytebuffer_read, too_large)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char output[128] = {0};
    int read_bytes = 0;

    bytebuffer_write(buffer, bytes, strlen(bytes));
    read_bytes = bytebuffer_read(buffer, output, 50);
    cr_assert(read_bytes == 26, "Expected: %d, but got: %d\n", 26, read_bytes);
    cr_assert_arr_eq(output, bytes, 26);
    bytebuffer_delete(buffer);
}