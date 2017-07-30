/**
 * @file
 * File management functions
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

#ifndef _MUTT_LIB_FILE_H
#define _MUTT_LIB_FILE_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "lib_file.h"

#ifdef DEBUG
extern char debugfilename[_POSIX_PATH_MAX];
extern FILE *debugfile;
extern int debuglevel;
extern char *debugfile_cmdline;
extern int debuglevel_cmdline;
void mutt_debug(int level, const char *fmt, ...);
#else
#define mutt_debug(...) do { } while (0)
#endif

#undef MAX
#undef MIN
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

/* Flags for mutt_read_line() */
#define MUTT_CONT (1 << 0) /**< \-continuation */
#define MUTT_EOL  (1 << 1) /**< don't strip `\n` / `\r\n` */

int safe_fclose(FILE **f);
int safe_fsync_close(FILE **f);
void mutt_unlink(const char *s);
int mutt_copy_bytes(FILE *in, FILE *out, size_t size);
int mutt_copy_stream(FILE *fin, FILE *fout);
int safe_symlink(const char *oldpath, const char *newpath);
int safe_rename(const char *src, const char *target);
int mutt_rmtree(const char *path);
int safe_open(const char *path, int flags);
FILE *safe_fopen(const char *path, const char *mode);
void mutt_sanitize_filename(char *f, short slash);
int mutt_rx_sanitize_string(char *dest, size_t destlen, const char *src);
char *mutt_read_line(char *s, size_t *size, FILE *fp, int *line, int flags);
size_t mutt_quote_filename(char *d, size_t l, const char *f);
char *mutt_concatn_path(char *dst, size_t dstlen, const char *dir,
                        size_t dirlen, const char *fname, size_t fnamelen);
char *mutt_concat_path(char *d, const char *dir, const char *fname, size_t l);
const char *mutt_basename(const char *f);
int mutt_mkdir(const char *path, mode_t mode);

#endif /* _MUTT_LIB_FILE_H */
