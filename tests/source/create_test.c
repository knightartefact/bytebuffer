/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** create_test
*/

#include <criterion/criterion.h>
#include "bytebuffer.h"

Test(creation_tests, test_success)
{
    bytebuffer_t *buffer = bytebuffer_create(128);

    cr_assert(buffer != NULL, "Expected buffer object to be not NULL.");
    cr_expect(buffer->bytes != NULL, "Expected buffer data to be not NULL.");
    cr_expect(buffer->size == 0, "Expected buffer size: %d but got %d.", 128, buffer->size);
    cr_expect(buffer->capacity == 128, "Expected buffer capacity: %d but got %d.", 128, buffer->capacity);
    bytebuffer_delete(buffer);
}

Test(creation_tests, test_fail_too_large)
{
    bytebuffer_t *buffer = bytebuffer_create(10000000000000000);

    cr_assert(buffer == NULL, "Expected buffer object to be NULL.");
    bytebuffer_delete(buffer);
}
