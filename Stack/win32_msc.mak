ROOT = ..
OPENSSLDIR = $(ROOT)\openssl
TARGET_DIR = $(ROOT)\lib\win32

TARGET = $(TARGET_DIR)\uastack.lib

OPENSSLINC = $(OPENSSLDIR)\include

CFLAGS = /MT /Ox /W3 /Gs0 /GF /Gy /nologo /Zl /Zi /Fd$(TARGET).pdb \
         /Icore /Istackcore /Isecurechannel /Itransport\tcp /Itransport\https \
         /Iproxystub\clientproxy /Iproxystub\serverstub /Iplatforms\win32 /I$(OPENSSLINC)

OBJECTS = \
	core\opcua_timer.obj \
	core\opcua_core.obj \
	core\opcua_trace.obj \
	core\opcua_utilities.obj \
	core\opcua_proxystub.obj \
	core\opcua_list.obj \
	core\opcua_threadpool.obj \
	core\opcua_buffer.obj \
	core\opcua_string.obj \
	core\opcua_guid.obj \
	core\opcua_memorystream.obj \
	core\opcua_thread.obj \
	core\opcua_datetime.obj \
	core\opcua_memory.obj \
	stackcore\opcua_types.obj \
	stackcore\opcua_messagecontext.obj \
	stackcore\opcua_encoder.obj \
	stackcore\opcua_stringtable.obj \
	stackcore\opcua_crypto.obj \
	stackcore\opcua_binarydecoder.obj \
	stackcore\opcua_binaryencoder.obj \
	stackcore\opcua_enumeratedtype.obj \
	stackcore\opcua_builtintypes.obj \
	stackcore\opcua_securechannel.obj \
	stackcore\opcua_encodeableobject.obj \
	stackcore\opcua_pki.obj \
	stackcore\opcua_listener.obj \
	stackcore\opcua_stream.obj \
	stackcore\opcua_extensionobject.obj \
	stackcore\opcua_connection.obj \
	stackcore\opcua_decoder.obj \
	securechannel\opcua_secureconnection.obj \
	securechannel\opcua_securelistener_policymanager.obj \
	securechannel\opcua_securelistener_channelmanager.obj \
	securechannel\opcua_securelistener.obj \
	securechannel\opcua_soapsecurechannel.obj \
	securechannel\opcua_tcpsecurechannel.obj \
	securechannel\opcua_securestream.obj \
	proxystub\clientproxy\opcua_channel.obj \
	proxystub\clientproxy\opcua_asynccallstate.obj \
	proxystub\clientproxy\opcua_clientapi.obj \
	proxystub\serverstub\opcua_serverapi.obj \
	proxystub\serverstub\opcua_servicetable.obj \
	proxystub\serverstub\opcua_endpoint.obj \
	transport\tcp\opcua_tcplistener_connectionmanager.obj \
	transport\tcp\opcua_tcpconnection.obj \
	transport\tcp\opcua_tcplistener.obj \
	transport\tcp\opcua_tcpstream.obj \
	transport\https\opcua_httpslistener_connectionmanager.obj \
	transport\https\opcua_https_internal.obj \
	transport\https\opcua_httpsconnection.obj \
	transport\https\opcua_httpsstream.obj \
	transport\https\opcua_httpslistener.obj \
	platforms\win32\opcua_p_mutex.obj \
	platforms\win32\opcua_p_openssl_pki_nosecurity.obj \
	platforms\win32\opcua_p_win32_pki.obj \
	platforms\win32\opcua_p_binary.obj \
	platforms\win32\opcua_p_socket_interface.obj \
	platforms\win32\opcua_p_memory.obj \
	platforms\win32\opcua_p_wincrypt_random.obj \
	platforms\win32\opcua_p_openssl_random.obj \
	platforms\win32\opcua_p_openssl_rsa.obj \
	platforms\win32\opcua_p_pkifactory.obj \
	platforms\win32\opcua_p_internal.obj \
	platforms\win32\opcua_p_openssl_x509.obj \
	platforms\win32\opcua_p_openssl_hmac_sha.obj \
	platforms\win32\opcua_p_socket_ssl.obj \
	platforms\win32\opcua_p_openssl_sha.obj \
	platforms\win32\opcua_p_openssl.obj \
	platforms\win32\opcua_p_openssl_aes.obj \
	platforms\win32\opcua_p_socket_internal.obj \
	platforms\win32\opcua_p_utilities.obj \
	platforms\win32\opcua_p_thread.obj \
	platforms\win32\opcua_p_datetime.obj \
	platforms\win32\opcua_p_cryptofactory.obj \
	platforms\win32\opcua_p_trace.obj \
	platforms\win32\opcua_p_openssl_3des.obj \
	platforms\win32\opcua_p_openssl_nosecurity.obj \
	platforms\win32\opcua_p_timer.obj \
	platforms\win32\opcua_p_openssl_pki.obj \
	platforms\win32\opcua_p_string.obj \
	platforms\win32\opcua_p_guid.obj \
	platforms\win32\opcua_p_socket.obj \
	platforms\win32\opcua_p_interface.obj \
	platforms\win32\opcua_p_semaphore.obj \

all: $(TARGET)

clean:
	-del $(TARGET) $(TARGET).pdb 2>nul
	del $(OBJECTS) 2>nul

$(TARGET_DIR):
	-mkdir $(ROOT)\lib
	mkdir $(ROOT)\lib\win32

$(TARGET): $(TARGET_DIR) $(OBJECTS)
	lib /nologo /out:$(TARGET) $(OBJECTS)

.c.obj:
	$(CC) $(CFLAGS) /Fo$*.obj /c $<
