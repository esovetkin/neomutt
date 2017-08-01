/**
 * @file
 * General purpose object for storing and parsing strings
 *
 * @authors
 * @copyright
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 2 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"
#include "lib_buffer.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "lib_memory.h"
#include "lib_string.h"

/**
 * mutt_buffer_new - creates and initializes a Buffer
 */
/**
 * mutt_buffer_new - YYY
 * @param void
 * @retval struct Buffer *
 */
struct Buffer *mutt_buffer_new(void)
{
  struct Buffer *b = NULL;

  b = safe_malloc(sizeof(struct Buffer));

  mutt_buffer_init(b);

  return b;
}

/**
 * mutt_buffer_init - initialize a new Buffer
 */
/**
 * mutt_buffer_init - YYY
 * @param b -- struct Buffer *
 * @retval struct Buffer *
 */
struct Buffer *mutt_buffer_init(struct Buffer *b)
{
  memset(b, 0, sizeof(struct Buffer));
  return b;
}

/**
 * mutt_buffer_from - Create Buffer from an existing Buffer
 *
 * Creates and initializes a Buffer*. If passed an existing Buffer*,
 * just initializes. Frees anything already in the buffer. Copies in
 * the seed string.
 *
 * Disregards the 'destroy' flag, which seems reserved for caller.
 * This is bad, but there's no apparent protocol for it.
 */
/**
 * mutt_buffer_from - YYY
 * @param seed -- char *
 * @retval struct Buffer *
 */
struct Buffer *mutt_buffer_from(char *seed)
{
  struct Buffer *b = NULL;

  if (!seed)
    return NULL;

  b = mutt_buffer_new();
  b->data = safe_strdup(seed);
  b->dsize = mutt_strlen(seed);
  b->dptr = (char *) b->data + b->dsize;
  return b;
}

/**
 * mutt_buffer_free - YYY
 * @param p -- struct Buffer **
 * @retval void 
 */
void mutt_buffer_free(struct Buffer **p)
{
  if (!p || !*p)
    return;

  FREE(&(*p)->data);
  /* dptr is just an offset to data and shouldn't be freed */
  FREE(p);
}

/**
 * mutt_buffer_printf - YYY
 * @param buf -- struct Buffer *
 * @param fmt -- const char *
 * @param ... -- vararg
 * @retval int 
 */
int mutt_buffer_printf(struct Buffer *buf, const char *fmt, ...)
{
  va_list ap, ap_retry;
  int len, blen, doff;

  va_start(ap, fmt);
  va_copy(ap_retry, ap);

  if (!buf->dptr)
    buf->dptr = buf->data;

  doff = buf->dptr - buf->data;
  blen = buf->dsize - doff;
  /* solaris 9 vsnprintf barfs when blen is 0 */
  if (!blen)
  {
    blen = 128;
    buf->dsize += blen;
    safe_realloc(&buf->data, buf->dsize);
    buf->dptr = buf->data + doff;
  }
  if ((len = vsnprintf(buf->dptr, blen, fmt, ap)) >= blen)
  {
    blen = ++len - blen;
    if (blen < 128)
      blen = 128;
    buf->dsize += blen;
    safe_realloc(&buf->data, buf->dsize);
    buf->dptr = buf->data + doff;
    len = vsnprintf(buf->dptr, len, fmt, ap_retry);
  }
  if (len > 0)
    buf->dptr += len;

  va_end(ap);
  va_end(ap_retry);

  return len;
}

/**
 * mutt_buffer_add - Add a string to a Buffer, expanding it if necessary
 *
 * dynamically grows a Buffer to accommodate s, in increments of 128 bytes.
 * Always one byte bigger than necessary for the null terminator, and the
 * buffer is always null-terminated
 */
/**
 * mutt_buffer_add - YYY
 * @param buf -- struct Buffer *
 * @param s   -- const char *
 * @param len -- size_t
 * @retval void 
 */
static void mutt_buffer_add(struct Buffer *buf, const char *s, size_t len)
{
  if (!buf || !s)
    return;

  if ((buf->dptr + len + 1) > (buf->data + buf->dsize))
  {
    size_t offset = buf->dptr - buf->data;
    buf->dsize += (len < 128) ? 128 : len + 1;
    safe_realloc(&buf->data, buf->dsize);
    buf->dptr = buf->data + offset;
  }
  if (!buf->dptr)
    return;
  memcpy(buf->dptr, s, len);
  buf->dptr += len;
  *(buf->dptr) = '\0';
}

/**
 * mutt_buffer_addstr - YYY
 * @param buf -- struct Buffer *
 * @param s   -- const char *
 * @retval void 
 */
void mutt_buffer_addstr(struct Buffer *buf, const char *s)
{
  mutt_buffer_add(buf, s, mutt_strlen(s));
}

/**
 * mutt_buffer_addch - YYY
 * @param buf -- struct Buffer *
 * @param c   -- char
 * @retval void 
 */
void mutt_buffer_addch(struct Buffer *buf, char c)
{
  mutt_buffer_add(buf, &c, 1);
}

