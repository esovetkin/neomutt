#include <stdio.h>
#include <stdarg.h>

void default_error(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  fputc('\n', stderr);
}

void (*mutt_error)(const char *, ...) = default_error;

