#include <unistd.h>

void mutt_exit(int code)
{
  _exit(code);
}
