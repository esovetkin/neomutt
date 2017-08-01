## Process this file with automake to produce Makefile.in
include $(top_srcdir)/flymake.am

AUTOMAKE_OPTIONS = 1.6 foreign

EXTRA_DIST = lib.h lib_ascii.h lib_base64.h lib_buffer.h lib_file.h lib_md5.h lib_memory.h lib_sha1.h lib_string.h

AM_CPPFLAGS = -I$(top_srcdir)

noinst_LIBRARIES = liblib.a
noinst_HEADERS =

liblib_a_SOURCES = compat.c exit.c lib_ascii.c lib_base64.c lib_buffer.c lib_file.c lib_md5.c lib_memory.c lib_sha1.c lib_string.c
