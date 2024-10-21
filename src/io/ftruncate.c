// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	int call = syscall(__NR_ftruncate, fd, length);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return call;
}
