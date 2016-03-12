ROOT = ..

include $(ROOT)/linux_gcc_rules.mak

LIB_PATH = $(ROOT)/lib/$(BIN_PATH)/$(CC)/$(BUILD_TARGET)

UA_LIBS = uastack
LIB_EXTENSION = a

LIB_FILES = $(patsubst %,$(LIB_PATH)/lib%.$(LIB_EXTENSION),$(UA_LIBS))
LIB_FLAGS = $(patsubst %,-l%,$(UA_LIBS))

TARGET = $(ROOT)/bin/$(BIN_PATH)/$(CC)/$(BUILD_TARGET)/AnsiCServer

STACK_DIRS = core stackcore securechannel \
       proxystub/clientproxy proxystub/serverstub platforms/linux

INCLUDE_DIRS = $(patsubst %,../Stack/%,$(STACK_DIRS))

CFLAGS = -Wall -pthread \
         $(patsubst %,-I%,$(INCLUDE_DIRS)) $(EXTRA_CFLAGS)

SOURCES = $(wildcard *.c)

OBJECTS = $(SOURCES:%.c=./$(BIN_PATH)/$(CC)/$(BUILD_TARGET)/%.o)

DEPS = $(OBJECTS:%.o=%.d)

all: $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
$(OBJECTS): linux_gcc.mak $(ROOT)/linux_gcc_rules.mak
endif

strip:
	$(STRIP) -g $(TARGET)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(DEPS)
	$(RM) $(TARGET)

$(TARGET): $(OBJECTS) $(LIB_FILES)
	$(MKDIR) $(dir $@)
	$(CC) $(EXTRA_CFLAGS) -o $@ $(OBJECTS) -L$(LIB_PATH) $(LIB_FLAGS) -lssl -lcrypto -lpthread -lrt -lm -ldl

./$(BIN_PATH)/$(CC)/$(BUILD_TARGET)/%.o : %.c
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) -MMD -MP -MT $@ -MF $(@:%.o=%.d) -o $@ $<
