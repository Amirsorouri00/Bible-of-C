CC      := gcc
CCFLAGS := -I
LDFLAGS := -lrt -lpthread

TARGETS:= master one two
MAINS  := $(addsuffix .o, $(TARGETS) )
OBJ    := #../../commons/commons.o
XPMEM  := #../lib/.libs/libxpmem.so  #../lib/.libs/libxpmem.a #
LIBS := #-L ../lib/.libs/libxpmem.so.0
DEPS   := #./commons/commons.h

BUILDPATH       := ./ #./build

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(TARGETS) $(OBJ)

$(OBJ): %.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CCFLAGS) $(BUILDPATH)

$(TARGETS): % : $(filter-out $(MAINS), $(OBJ)) %.o
	$(CC) -g -o $@ $(LIBS) $^ $(CCFLAGS) $(BUILDPATH) $(LDFLAGS)
	echo Build Done

