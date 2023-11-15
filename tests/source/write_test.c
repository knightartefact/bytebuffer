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

Test(write_tests, write_80_bytes_in_sequence)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    char seq1[] = "123456789abcdefghijklmnopqrstuvwxyz";
    char seq2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ&$ù=/ç*-+:;,?§!%";
    char full_seq[] = "123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ&$ù=/ç*-+:;,?§!%";
    int size_seq1 = strlen(seq1);
    int size_seq2 = strlen(seq2);
    int size_total = size_seq1 + size_seq2;
    uint64_t expected_capacity = 64 * EXPAND_RATIO + size_seq2;
    int write_status = 0;

    write_status = bytebuffer_write(buffer, seq1, size_seq1);
    cr_expect(write_status == 0);
    cr_expect(buffer->size == size_seq1, "Expected size: %ld, but got: %ld", size_seq1, buffer->size);
    cr_expect(buffer->capacity == 64, "Expected capacity: %ld, but got: %ld", 64, buffer->capacity);
    cr_expect_arr_eq(buffer->bytes, seq1, size_seq1);

    write_status = bytebuffer_write(buffer, seq2, size_seq2);
    cr_expect(write_status == 0);
    cr_expect(buffer->size == size_total, "Expected size: %ld, but got: %ld", size_total, buffer->size);
    cr_expect(buffer->capacity == expected_capacity, "Expected capacity: %ld, but got: %ld", expected_capacity, buffer->capacity);
    cr_expect_arr_eq(buffer->bytes, full_seq, size_total);
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

Test(write_tests, write_1_byte)
{
    bytebuffer_t *buffer = bytebuffer_create(10);
    char bytes[] = "Hello, World!";
    int write_status = 0;

    write_status = bytebuffer_write_byte(buffer, bytes[0]);
    cr_expect(write_status == 0);
    cr_expect(buffer->size == 1, "Expected size: %ld, but got: %ld", 1, buffer->size);
    cr_expect(buffer->capacity == 10, "Expected capacity: %ld, but got: %ld", 10, buffer->capacity);
    cr_expect_arr_eq(buffer->bytes, bytes, 1);
    bytebuffer_delete(buffer);
}

Test(write_tests, write_bytes_sequence_per_byte)
{
    bytebuffer_t *buffer = bytebuffer_create(10);
    char bytes[] = "Hello, World!";
    int write_status = 0;
    uint64_t expected_capacity = EXPAND_RATIO * buffer->capacity;

    for (int i = 0; i < strlen(bytes); i++) {
        write_status = bytebuffer_write_byte(buffer, bytes[i]);
        cr_expect(write_status == 0);
        cr_expect(buffer->size == i + 1, "Expected size: %ld, but got: %ld", i + 1, buffer->size);
        cr_expect_eq(buffer->bytes[i], bytes[i], "Expected byte: %c, but got: %c", bytes[i], buffer->bytes[i]);
    }
    cr_expect(buffer->capacity == expected_capacity, "Expected capacity: %ld, but got: %ld", expected_capacity, buffer->capacity);
    bytebuffer_delete(buffer);
}

