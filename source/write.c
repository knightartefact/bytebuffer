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
    memmove(buffer->bytes + buffer->size, data, size);
    buffer->size += size;
    return 0;
}

int bytebuffer_write_byte(bytebuffer_t *buffer, uint8_t byte)
{
    uint64_t new_size = buffer->size;

    if (buffer->size >= buffer->capacity) {
        new_size = (size_t)(buffer->capacity * EXPAND_RATIO);
        if (bytebuffer_resize(buffer, new_size) == -1) {
            return -1;
        }
    }
    buffer->bytes[buffer->size] = byte;
    buffer->size += 1;
    return 0;
}
