// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
  struct timespec wait = {seconds, 0};
	return nanosleep(&wait, NULL);
}
