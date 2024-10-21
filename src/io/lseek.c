// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
	int call = syscall(__NR_lseek, fd, offset, whence);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return call;
}
