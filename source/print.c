/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** print
*/

#include <stdio.h>
#include "bytebuffer.h"

void bytebuffer_print(bytebuffer_t *buffer, int mode)
{
    for (uint64_t i = 0; i < buffer->size; i++) {
        printf("%x%x", buffer->bytes[i] >> 4, buffer->bytes[i] & 0x0F);
    }
    printf("\n");
}
