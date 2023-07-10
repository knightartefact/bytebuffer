/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** delete_test
*/

#include <criterion/criterion.h>
#include "bytebuffer.h"

Test(delete_tests, test_success)
{
    bytebuffer_t *buffer = bytebuffer_create(128);

    bytebuffer_delete(buffer);
}
