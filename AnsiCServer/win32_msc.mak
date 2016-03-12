ROOT = ..
OPENSSLDIR = $(ROOT)\openssl
TARGET_DIR = $(ROOT)\bin\win32

LIBS = $(ROOT)\lib\win32\uastack.lib $(OPENSSLDIR)\lib\ssleay32.lib $(OPENSSLDIR)\lib\libeay32.lib \
       rpcrt4.lib ws2_32.lib gdi32.lib advapi32.lib crypt32.lib user32.lib

TARGET = $(TARGET_DIR)\AnsiCServer.exe

OPENSSLINC = $(OPENSSLDIR)\include

CFLAGS = /MT /Ox /W3 /Gs0 /GF /Gy /nologo /Zi /Fd$(TARGET).pdb \
         /I$(ROOT)\Stack\core /I$(ROOT)\Stack\stackcore /I$(ROOT)\Stack\securechannel \
         /I$(ROOT)\Stack\proxystub\clientproxy /I$(ROOT)\Stack\proxystub\serverstub /I$(ROOT)\Stack\platforms\win32 /I$(OPENSSLINC)

OBJECTS = \
	browsenext.obj \
	browseservice_.obj \
	ansicservermain.obj \
	readservice.obj \
	init_valriables_of_addressspace.obj \

all: $(TARGET)

clean:
	-del $(TARGET) $(TARGET).pdb 2>nul
	del $(OBJECTS) 2>nul

$(TARGET_DIR):
	-mkdir $(ROOT)\bin
	mkdir $(ROOT)\bin\win32

$(TARGET): $(TARGET_DIR) $(OBJECTS)
	link /nologo /subsystem:console /opt:ref /debug /out:$(TARGET) $(OBJECTS) $(LIBS)

.c.obj:
	$(CC) $(CFLAGS) /Fo$*.obj /c $<
