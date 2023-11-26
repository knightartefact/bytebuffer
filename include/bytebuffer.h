/*
** EPITECH PROJECT, 2023
** bytebuffer
** File description:
** bytebuffer
*/

#ifndef BYTEBUFFER_H_
#define BYTEBUFFER_H_

#include <stdint.h>
#include <stddef.h>

#define EXPAND_RATIO 1.61803398875

typedef struct bytebuffer_s bytebuffer_t;

struct bytebuffer_s {
    uint8_t *bytes;
    uint64_t size;
    uint64_t capacity;
};

bytebuffer_t *bytebuffer_create(uint64_t size);
void bytebuffer_delete(bytebuffer_t *buffer);

int bytebuffer_write(bytebuffer_t *buffer, const void *data, size_t size);
int bytebuffer_write_byte(bytebuffer_t *buffer, uint8_t byte);

int bytebuffer_read(bytebuffer_t *buffer, void *data, size_t size);

int bytebuffer_resize(bytebuffer_t *buffer, size_t size);

uint64_t bytebuffer_size(bytebuffer_t *buffer);
uint64_t bytebuffer_capacity(bytebuffer_t *buffer);
uint64_t bytebuffer_free_space(bytebuffer_t *buffer);

void bytebuffer_print(bytebuffer_t *buffer, int mode);

#endif /* !BYTEBUFFER_H_ */
