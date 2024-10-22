// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <stdarg.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	long call = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
  if (call < 0) {
    errno = -call;
    return MAP_FAILED;
  }
	return (void *)call;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
  long call = syscall(__NR_mremap, old_address, old_size, new_size, flags);
  if (call < 0) {
    errno = -call;
    return MAP_FAILED;
  }
	return (void *)call;
}

int munmap(void *addr, size_t length)
{
	int call = syscall(__NR_munmap, addr, length);
  if (call < 0) {
    errno = -call;
    return MAP_FAILED;
  }
	return call;
}
