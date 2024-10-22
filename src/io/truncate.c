// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	int call = syscall(__NR_truncate, path, length);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return 0;
}
