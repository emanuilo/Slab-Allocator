#ifndef _slab_h_
#define _slab_h_

//#include "cache.h"
#include <stdlib.h>

#define BLOCK_SIZE (4096)
#define CACHE_L1_LINE_SIZE (64)

typedef struct kmem_cache_s kmem_cache_t;

void kmem_init(void *space, int block_num);

kmem_cache_t *kmem_cache_create(const char *name, size_t size, void(*ctor)(void *), void(*dtor)(void *)); // Allocate cache

kmem_cache_t *_kmem_cache_create(const char *name, size_t size, void(*ctor)(void *), void(*dtor)(void *));

int kmem_cache_shrink(kmem_cache_t *cachep); // Shrink cache

int _kmem_cache_shrink(kmem_cache_t *cachep);

void *kmem_cache_alloc(kmem_cache_t *cachep); // Allocate one object from cache

void* _kmem_cache_alloc(kmem_cache_t *cachep);

void kmem_cache_grow(kmem_cache_t* cachep); // Allocate new slab

void kmem_cache_free(kmem_cache_t *cachep, void *objp); // Deallocate one object from cache

int  _kmem_cache_free(kmem_cache_t *cachep, void *objp);

void *kmalloc(size_t size); // Alloacate one small memory buffer

void kfree(const void *objp); // Deallocate one small memory buffer

void kmem_cache_destroy(kmem_cache_t *cachep); // Deallocate cache

void kmem_cache_info(kmem_cache_t *cachep); // Print cache info

int kmem_cache_error(kmem_cache_t *cachep); // Print error message

#endif