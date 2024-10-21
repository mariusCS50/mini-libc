// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
  while (*destination++ = *source++);

  return destination;
}


char *strncpy(char *destination, const char *source, size_t len)
{
  while (len-- && (*destination++ = *source++));

	return destination;
}

char *strcat(char *destination, const char *source)
{
	strcpy(destination + strlen(destination), source);

	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
  destination += strlen(destination);
	strncpy(destination, source, len);
  *(destination + len) = '\0';

	return destination;
}

int strcmp(const char *str1, const char *str2)
{
  for (; *str1 && *str1 == *str2; str1++, str2++);
  return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	for (; --len && *str1 && *str1 == *str2; str1++, str2++);
  return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	for (; *str && *str != c; str++);
	return (*str == c ? str : NULL);
}

char *strrchr(const char *str, int c)
{
  char *last_occ = NULL;
	for (; *str; str++) {
    last_occ = (*str == c ? (char *)str : last_occ);
  }
	return (*str == c ? str : last_occ);
}

char *strstr(const char *haystack, const char *needle)
{
  int steps = strlen(haystack) - strlen(needle);
  while (steps--) {
    if (strncmp(haystack, needle, strlen(needle)) == 0) return (char *)haystack;
    haystack++;
  }
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int steps = strlen(haystack) - strlen(needle);
  char *last_occ = NULL;
  while (steps--) {
    if (strncmp(haystack, needle, strlen(needle)) == 0) last_occ = (char *)haystack;;
    haystack++;
  }
	return last_occ;
}

void *memcpy(void *destination, const void *source, size_t num)
{
  strncpy((char *)destination, (char *)source, num);
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char buffer[256];
  strcpy(buffer, source);
  strncpy((char *)destination, buffer, num);
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return strncmp((char *)ptr1, (char *)ptr2, num);
}

void *memset(void *source, int value, size_t num)
{
	for (; num--; *(char *)source++ = value);
	return source;
}
