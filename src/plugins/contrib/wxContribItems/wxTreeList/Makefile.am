AM_CPPFLAGS = $(WX_CXXFLAGS) \
		-I$(srcdir)/include

if CODEBLOCKS_NT
AM_CPPFLAGS += -DWXMAKINGDLL
endif

wxcontribitemsdir=$(libdir)/codeblocks/wxContribItems

wxcontribitems_LTLIBRARIES = libwxtreelist.la

libwxtreelist_la_LDFLAGS = -version-info 0:1:0

if CODEBLOCKS_NT
libwxtreelist_la_LDFLAGS += -shared -no-undefined
endif

libwxtreelist_la_LIBADD = $(WX_LIBS)

libwxtreelist_la_SOURCES = \
./src/treelistctrl.cpp

sdkdir=$(includedir)/codeblocks/wxContribItems/wxTreeList/include/wx

sdk_HEADERS = \
./include/wx/treelistctrl.h
