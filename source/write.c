/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** write
*/

#include <stdio.h>
#include <string.h>
#include "bytebuffer.h"

int bytebuffer_write(bytebuffer_t *buffer, const void *data, size_t size)
{
    uint64_t free_space = bytebuffer_free_space(buffer);
    uint64_t new_size = buffer->size;

    if (size > free_space) {
        new_size = (size_t)(buffer->capacity * EXPAND_RATIO) + size;
        if (bytebuffer_resize(buffer, new_size) == -1) {
            return -1;
        }
    }
    memmove(buffer->bytes, data, size);
    buffer->size += size;
    return 0;
}
