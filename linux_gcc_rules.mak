# Global rules for all GCC builds

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar
STRIP = $(CROSS_COMPILE)strip
MKDIR = mkdir -p

ifndef MACHINE_TYPE
ifndef CROSS_COMPILE
	TMP_MACHINE_TYPE = $(shell uname -i)
	# sometimes "unknown" is returned - default to i386
	ifeq ($(TMP_MACHINE_TYPE),x86_64)
		MACHINE_TYPE = x86_64
	else
		MACHINE_TYPE = i386
	endif
else
	MACHINE_TYPE = unknown
endif
endif

ifndef KERNEL_VER
	ifeq ($(DETECT_KERNEL_VER),1)
		# extract the first two numbers of the kernel version
		KERNEL_VER = $(shell uname -r | sed -e "s/\([0-9]*\)\.\([0-9]*\)\..*/\1.\2/g")
	else
		# use this as default
		KERNEL_VER = 2.6
	endif
endif

ifndef MACHINE_OPT
ifndef CROSS_COMPILE
	ifeq ($(MACHINE_TYPE),x86_64)
		MACHINE_OPT = -m64
	else
	ifeq ($(MACHINE_TYPE),i386)
		MACHINE_OPT = -m32
	endif
	endif
endif
endif

BIN_PATH = linux-$(KERNEL_VER)/$(MACHINE_TYPE)

ifndef BUILD_TARGET
	BUILD_TARGET = release
endif

ifeq ($(findstring debug,$(BUILD_TARGET)),debug)
	EXTRA_CFLAGS = -D_DEBUG -g $(MACHINE_OPT)
else
	EXTRA_CFLAGS = -O3 $(MACHINE_OPT)
endif
