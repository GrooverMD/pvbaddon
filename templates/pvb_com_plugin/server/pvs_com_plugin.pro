######################################################################
# generated by pvdevelop at: So. Apr 1 08:35:00 2012
######################################################################

TEMPLATE = lib
CONFIG  += warn_on release
CONFIG  -= qt
win32:CONFIG  += dll

# Input
HEADERS += 
SOURCES += tcputil.cpp

#unix:DEFINES       += PVUNIX
#win32:DEFINES      += PVWIN32
unix:INCLUDEPATH   += /opt/pvb/pvserver

!macx {
unix:LIBS          +=
}

macx:LIBS          += 

win32:LIBS        += $(PVBDIR)/win-mingw/bin/libserverlib.a

win32-g++ {
#QMAKE_LFLAGS       += -static-libgcc
QMAKE_LFLAGS        += -Wl,--undefined
win32:LIBS         += -lws2_32 -ladvapi32
INCLUDEPATH += $(PVBDIR)/pvserver
}
else {
win32:LIBS         += wsock32.lib advapi32.lib
}

#DEFINES += USE_INETD
TARGET = pvs_com_plugin
