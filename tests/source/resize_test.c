/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** resize_test
*/

#include <criterion/criterion.h>
#include "bytebuffer.h"

Test(resize_tests, resize_same_size)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    int status = bytebuffer_resize(buffer, buffer->size);

    cr_assert(status == 0, "Expected returnvalue of function to be 0.");
    cr_expect(buffer->capacity == 64, "Expected buffer capacity: %d but got: %d", 64, buffer->capacity);
    cr_expect(buffer->bytes != NULL, "Expected buffer bytes to be not NULL.");
}

Test(resize_tests, resize_zero_size)
{
    bytebuffer_t *buffer = bytebuffer_create(64);
    buffer->size = 42;
    int status = 0;

    status = bytebuffer_resize(buffer, 0);
    cr_assert(status == 0, "Expected returnvalue of function to be 0.");
    cr_expect(buffer->bytes == NULL, "Expected buffer bytes to be NULL.");
    cr_expect(buffer->capacity == 0, "Expected buffer capacity: %d but got: %d", 0, buffer->capacity);
    cr_expect(buffer->size == 0, "Expected buffer capacity: %d but got: %d", 0, buffer->capacity);
}

Test(resize_tests, resize_expand_success)
{
    bytebuffer_t *buffer = bytebuffer_create(128);
    int status = bytebuffer_resize(buffer, 256);

    cr_assert(status == 0, "Expected return of function to be 0.");
    cr_expect(buffer->bytes != NULL, "Expected buffer data to be not NULL.");
    cr_expect(buffer->capacity == 256, "Expected capacity: %d but got :%d.", 256, buffer->capacity);
}

Test(resize_tests, resize_expand_fail)
{
    bytebuffer_t *buffer = bytebuffer_create(128);
    int status = bytebuffer_resize(buffer, 10000000000000);

    cr_assert(status == -1, "Expected return of function to be -1.");
    cr_expect(buffer->bytes != NULL, "Expected buffer data to be not NULL.");
    cr_expect(buffer->capacity == 128, "Expected capacity: %d but got :%d.", 128, buffer->capacity);
}

Test(resize_tests, resize_shrink_success)
{
    bytebuffer_t *buffer = bytebuffer_create(128);
    int status = bytebuffer_resize(buffer, 64);

    cr_assert(status == 0, "Expected return of function to be 0.");
    cr_expect(buffer->bytes != NULL, "Expected buffer data to be NULL.");
    cr_expect(buffer->capacity == 64, "Expected capacity: %d but got :%d.", 64, buffer->capacity);
}
