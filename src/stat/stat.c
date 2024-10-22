// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	int call = syscall(__NR_stat, path, buf);
  if (call < 0) {
    errno = -call;
    return -1;
  }

  return 0;
}
