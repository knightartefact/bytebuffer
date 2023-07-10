/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** bytebuffer
*/

#include <stdlib.h>
#include "bytebuffer.h"

static int bytebuffer_init(bytebuffer_t *buffer, uint64_t size)
{
    buffer->bytes = malloc(sizeof(uint8_t) * size);
    if (buffer->bytes == NULL) {
        return -1;
    }
    buffer->capacity = size;
    buffer->size = 0;
    return 0;
}

bytebuffer_t *bytebuffer_create(uint64_t size)
{
    bytebuffer_t *buffer = malloc(sizeof(bytebuffer_t *));

    if (buffer == NULL) {
        return NULL;
    }
    if (bytebuffer_init(buffer, size) == -1) {
        free(buffer);
        return NULL;
    }
    return buffer;
}

void bytebuffer_delete(bytebuffer_t *buffer)
{
    if (buffer == NULL)
        return;
    free(buffer->bytes);
    free(buffer);
}
