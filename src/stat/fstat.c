// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	int call = syscall(__NR_fstat, fd, st);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return 0;
}
