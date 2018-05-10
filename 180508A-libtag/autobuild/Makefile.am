AUTOMAKE_OPTIONS = foreign subdir-objects

lib_LTLIBRARIES = libtag.la
libtag_la_SOURCES = src/include/format.h\
src/include/info.h\
src/include/libtag.h\
src/include/main.h\
src/include/optarg.h\
src/include/read_write.h\
src/include/tag.h\
src/include/tag_query.h\
src/include/utils.h\
src/include/xattr_max.h\
src/build_qtree.c\
src/format.c\
src/libtag.c\
src/match.c\
src/optarg.c\
src/query_checker.c\
src/read_write.c\
src/tag_delete.c\
src/tag_get.c\
src/tag_list.c\
src/tag_query.c\
src/tag_restore.c\
src/tag_save.c\
src/tag_set.c\
src/utils.c

bin_PROGRAMS = tag
tag_SOURCES = src/main.c src/include/libtag.h
tag_LDADD = libtag.la

dist_man_MANS = doc/tag.1
