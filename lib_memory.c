/**
 * @file
 * Memory management wrappers
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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib_memory.h"
#include "lib_file.h"

void *safe_calloc(size_t nmemb, size_t size)
{
  void *p = NULL;

  if (!nmemb || !size)
    return NULL;

  if (((size_t) -1) / nmemb <= size)
  {
    mutt_error(_("Integer overflow -- can't allocate memory!"));
    sleep(1);
    mutt_exit(1);
  }

  if (!(p = calloc(nmemb, size)))
  {
    mutt_error(_("Out of memory!"));
    sleep(1);
    mutt_exit(1);
  }
  return p;
}

void safe_free(void *ptr)
{
  if (!ptr)
    return;
  void **p = (void **) ptr;
  if (*p)
  {
    free(*p);
    *p = 0;
  }
}

void *safe_malloc(size_t siz)
{
  void *p = NULL;

  if (siz == 0)
    return 0;
  if ((p = malloc(siz)) == NULL)
  {
    mutt_error(_("Out of memory!"));
    sleep(1);
    mutt_exit(1);
  }
  return p;
}

void safe_realloc(void *ptr, size_t siz)
{
  void *r = NULL;
  void **p = (void **) ptr;

  if (siz == 0)
  {
    if (*p)
    {
      free(*p);
      *p = NULL;
    }
    return;
  }

  r = realloc(*p, siz);
  if (!r)
  {
    mutt_error(_("Out of memory!"));
    sleep(1);
    mutt_exit(1);
  }

  *p = r;
}

