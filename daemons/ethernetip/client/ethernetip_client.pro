######################################################################
# generated by pvdevelop at: Do Aug 2 07:25:56 2007
######################################################################

TEMPLATE = app
CONFIG  += warn_on release console
CONFIG  -= qt
DEFINES += PVBROWSER

# Input
# HEADERS   += 
SOURCES     += ethernetip_client.cpp

!macx {
unix:INCLUDEPATH  += ../../../foreign/tuxeip/tuxeip-1.0/src
unix:LIBS         += ../../../foreign/tuxeip/tuxeip-1.0/src/libtuxeip.a
unix:LIBS         += -lpthread
unix:LIBS         += /usr/lib/librllib.so
unix:INCLUDEPATH  += /opt/pvb/rllib/lib
}

macx:LIBS         += /usr/lib/libpthread.dylib
macx:LIBS         += /usr/lib/librllib.dylib
macx:INCLUDEPATH  += ../../../foreign/tuxeip/tuxeip-1.0/src
macx:LIBS         += ../../../foreign/tuxeip/tuxeip-1.0/src/libtuxeip.dylib
macx:INCLUDEPATH  += /opt/pvb/rllib/lib

win32-g++ {
QMAKE_LFLAGS      += -static-libgcc
win32:INCLUDEPATH += $(PVBDIR)/rllib/lib
win32:LIBS        += $(PVBDIR)/win-mingw/bin/librllib.a
win32:DEFINES     += VALGRING
win32:INCLUDEPATH += ../../../foreign/tuxeip/tuxeip-1.0/src
win32:LIBS        += ../../../foreign/tuxeip/tuxeip-1.0/src/release/libtuxeip.a
win32:LIBS        += -lws2_32
}
else {
win32:INCLUDEPATH += $(PVBDIR)/rllib/lib
win32:LIBS        += wsock32.lib imm32.lib advapi32.lib
win32:LIBS        += $(PVBDIR)/win/bin/rllib.lib
win32:DEFINES     += VALGRING
win32:INCLUDEPATH += ../../../foreign/tuxeip/tuxeip-1.0/src
win32:LIBS        += ../../../foreign/tuxeip/tuxeip-1.0/src/tuxeip.lib
}

TARGET = ethernetip_client

