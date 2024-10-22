// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
  void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  mem_list_add(start, size);
  return start;
}

void *calloc(size_t nmemb, size_t size)
{
	void *start = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  memset(start, 0, nmemb * size);
  mem_list_add(start, size);
	return start;
}

void free(void *ptr)
{
  struct mem_list *item = mem_list_find(ptr);
  munmap(ptr, item->len);
  mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
	if (ptr == NULL) {
    return malloc(size);
  } else if (size == 0) {
    free(ptr);
  } else {
    struct mem_list *item = mem_list_find(ptr);
    ptr = mremap(ptr, item->len, size, MREMAP_MAYMOVE);
  }
  return ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	return realloc(ptr, nmemb * size);
}
