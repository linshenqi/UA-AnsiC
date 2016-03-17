ROOT = ..
ODIR = win32
OPENSSLDIR = $(ROOT)\openssl
TARGET_DIR = $(ROOT)\bin\$(ODIR)

TARGET = $(TARGET_DIR)\AnsiCServer.exe

OPENSSLINC = $(OPENSSLDIR)\include

CFLAGS = /MT /Ox /W3 /Gs0 /GF /Gy /nologo /Zi /Fd$(TARGET).pdb \
         /I$(ROOT)\Stack\core /I$(ROOT)\Stack\stackcore /I$(ROOT)\Stack\securechannel \
         /I$(ROOT)\Stack\proxystub\clientproxy /I$(ROOT)\Stack\proxystub\serverstub /I$(ROOT)\Stack\platforms\win32 /I$(OPENSSLINC)

LIBS = $(ROOT)\lib\$(ODIR)\uastack.lib $(OPENSSLDIR)\lib\ssleay32.lib $(OPENSSLDIR)\lib\libeay32.lib \
       rpcrt4.lib ws2_32.lib gdi32.lib advapi32.lib crypt32.lib user32.lib

OBJECTS = \
	$(ODIR)\ansicservermain.obj \
	$(ODIR)\browsenext.obj \
	$(ODIR)\browseservice_.obj \
	$(ODIR)\init_valriables_of_addressspace.obj \
	$(ODIR)\readservice.obj \

all: $(TARGET)

clean:
	-del $(TARGET) $(TARGET).pdb 2>nul
	-del $(OBJECTS) 2>nul
	-rmdir $(ODIR) 2>nul

$(TARGET_DIR):
	-mkdir $(ROOT)\bin
	mkdir $(ROOT)\bin\$(ODIR)

$(ODIR):
	mkdir $(ODIR)

$(TARGET): $(TARGET_DIR) $(ODIR) $(OBJECTS)
	link /nologo /subsystem:console /opt:ref /debug /out:$(TARGET) $(OBJECTS) $(LIBS)

{}.c{$(ODIR)}.obj:
	$(CC) $(CFLAGS) /Fo$@ /c $<
