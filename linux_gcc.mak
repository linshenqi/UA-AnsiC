# generate Stack and Test Server

# parameters:
#	BUILD_TARGET=debug|release
#	MACHINE_TYPE=x86_64|i386
#	KERNEL_VER=2.6|...

all:
	$(MAKE) -C Stack -f linux_gcc.mak all
	$(MAKE) -C AnsiCServer -f linux_gcc.mak all
	
clean:
	$(MAKE) -C Stack -f linux_gcc.mak clean
	$(MAKE) -C AnsiCServer -f linux_gcc.mak clean

strip:
	$(MAKE) -C Stack -f linux_gcc.mak strip
	$(MAKE) -C AnsiCServer -f linux_gcc.mak strip
