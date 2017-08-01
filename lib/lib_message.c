/**
 * @file
 * Message logging
 *
 * @authors
 * Copyright (C) 2017 Richard Russon <rich@flatcap.org>
 *
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
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include "lib_debug.h"
#include "lib_memory.h"

/**
 * default_error - YYY
 * @param format -- const char *
 * @param ...    -- vararg
 * @retval void 
 */
static void default_error(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);
  fputc('\n', stderr);
}

void (*mutt_error)(const char *, ...) = default_error;

/**
 * default_message - YYY
 * @param format -- const char *
 * @param ...    -- vararg
 * @retval void 
 */
static void default_message(const char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  vfprintf(stdout, format, ap);
  va_end(ap);
  fputc('\n', stdout);
}

void (*mutt_message)(const char *, ...) = default_message;

/**
 * default_perror - YYY
 * @param message -- const char *
 * @retval void 
 */
static void default_perror(const char *message)
{
  char *p = strerror(errno);

  mutt_debug(1, "%s: %s (errno = %d)\n", message, p ? p : "unknown error", errno);
  mutt_error("%s: %s (errno = %d)", message, p ? p : _("unknown error"), errno);
}

void (*mutt_perror) (const char *) = default_perror;

