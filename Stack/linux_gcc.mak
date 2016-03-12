ROOT = ..

include $(ROOT)/linux_gcc_rules.mak

TARGET = $(ROOT)/lib/$(BIN_PATH)/$(CC)/$(BUILD_TARGET)/libuastack.a

DIRS = core stackcore securechannel transport/tcp transport/https \
       proxystub/clientproxy proxystub/serverstub platforms/linux

CFLAGS = -Wall -pthread \
         $(patsubst %,-I%,$(DIRS)) $(EXTRA_CFLAGS)

SOURCES = $(wildcard $(patsubst %,%/*.c,$(DIRS)))

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

$(TARGET): $(OBJECTS)
	$(MKDIR) $(dir $@)
	$(AR) rcs $@ $^

./$(BIN_PATH)/$(CC)/$(BUILD_TARGET)/%.o : %.c
	$(MKDIR) $(dir $@)
	$(CC) -c $(CFLAGS) -MMD -MP -MT $@ -MF $(@:%.o=%.d) -o $@ $<
