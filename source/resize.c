/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** resize
*/

#include <stdlib.h>
#include "bytebuffer.h"

int bytebuffer_resize(bytebuffer_t *buffer, size_t size)
{
    uint8_t *temp = NULL;

    if (size == buffer->size)
        return 0;
    if (size == 0) {
        free(buffer->bytes);
        buffer->bytes = NULL;
        buffer->capacity = 0;
        buffer->size = 0;
        return 0;
    }
    temp = realloc(buffer->bytes, size * sizeof(uint8_t));
    if (temp == NULL) {
        return -1;
    }
    buffer->bytes = temp;
    buffer->capacity = size;
    buffer->size = buffer->size > buffer->capacity ?
                                                buffer->capacity : buffer->size;
    return 0;
}
