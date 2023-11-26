/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** read
*/

#include <string.h>
#include "bytebuffer.h"

int bytebuffer_read(bytebuffer_t *buffer, void *data, size_t size)
{
    if (buffer->size == 0)
        return 0;
    if (size > buffer->size)
        size = buffer->size;
    memmove(data, buffer->bytes, size);
    memmove(buffer->bytes, buffer->bytes + size, buffer->size - size);
    buffer->size -= size;
    return size;
}
