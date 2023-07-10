/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** write_test
*/

#include <criterion/criterion.h>
#include "bytebuffer.h"

Test(write_tests, write_10_bytes_to_empty)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "AbCdEfGhIj";
    int write_status = 0;

    write_status = bytebuffer_write(buffer, bytes, strlen(bytes));
    cr_expect(write_status == 0);
    cr_expect_arr_eq(buffer->bytes, bytes, strlen(bytes));
    bytebuffer_delete(buffer);
}

Test(write_tests, write_80_bytes_to_empty)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ&$ù=/ç*-+:;,?§!%";
    uint64_t expected_capacity = 64 * EXPAND_RATIO + strlen(bytes);
    int write_status = 0;

    write_status = bytebuffer_write(buffer, bytes, strlen(bytes));
    cr_expect(write_status == 0);
    cr_expect(buffer->size == strlen(bytes), "Expected size: %ld, but got: %ld", strlen(bytes), buffer->size);
    cr_expect(buffer->capacity == expected_capacity, "Expected capacity: %ld, but got: %ld", expected_capacity, buffer->capacity);
    cr_expect_arr_eq(buffer->bytes, bytes, strlen(bytes));
    bytebuffer_delete(buffer);
}

Test(write_tests, write_infinite_bytes)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "123456789abcdefghijklmnopqrstuvwxyz";
    int write_status = 0;

    bytebuffer_write(buffer, bytes, strlen(bytes));
    write_status = bytebuffer_write(buffer, bytes, 100000000000000000);
    cr_expect(write_status == -1);
    cr_expect(buffer->size == strlen(bytes), "Expected size: %ld, but got: %ld", strlen(bytes), buffer->size);
    cr_expect(buffer->capacity == 64, "Expected capacity: %ld, but got: %ld", 64, buffer->capacity);
    cr_expect_arr_eq(buffer->bytes, bytes, strlen(bytes));
    bytebuffer_delete(buffer);
}

Test(write_tests, write_zero_byte)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char bytes[] = "";
    int write_status = 0;

    write_status = bytebuffer_write(buffer, bytes, strlen(bytes));
    cr_expect(write_status == 0);
    cr_expect(buffer->size == strlen(bytes), "Expected size: %ld, but got: %ld", strlen(bytes), buffer->size);
    cr_expect(buffer->capacity == 64, "Expected capacity: %ld, but got: %ld", 64, buffer->capacity);
    cr_expect_arr_eq(buffer->bytes, bytes, strlen(bytes));
    bytebuffer_delete(buffer);
}

