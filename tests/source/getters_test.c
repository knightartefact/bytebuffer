/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** getters_test
*/

#include <criterion/criterion.h>
#include "bytebuffer.h"

Test(getters_tests, get_size)
{
    bytebuffer_t *buffer = bytebuffer_create(128);
    uint64_t size = 0;

    buffer->size = 42;
    size = bytebuffer_size(buffer);
    cr_assert(size == 42, "Expected size: %d but got: %d.", 42, size);
    bytebuffer_delete(buffer);
}

Test(getters_tests, get_capacity)
{
    bytebuffer_t *buffer = bytebuffer_create(128);
    uint64_t size = bytebuffer_capacity(buffer);

    cr_assert(size == 128, "Expected capacity: %d but got: %d.", 128, size);
    bytebuffer_delete(buffer);
}

Test(getters_tests, get_free_space)
{
    bytebuffer_t *buffer = bytebuffer_create(128);
    uint64_t size = 0;
    uint64_t free_space = 128 - 42;

    buffer->size = 42;
    size = bytebuffer_free_space(buffer);
    cr_assert(size == free_space, "Expected free space: %d but got: %d.", free_space, size);
    bytebuffer_delete(buffer);
}
