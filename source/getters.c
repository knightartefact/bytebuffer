/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** getters
*/

#include "bytebuffer.h"

uint64_t bytebuffer_free_space(bytebuffer_t *buffer)
{
    uint64_t free_space = 0;

    free_space = buffer->capacity - buffer->size;
    return free_space;
}

uint64_t bytebuffer_size(bytebuffer_t *buffer)
{
    return buffer->size;
}

uint64_t bytebuffer_capacity(bytebuffer_t *buffer)
{
    return buffer->capacity;
}
