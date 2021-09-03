TARGET := tournament
CC := gcc
CC_FLAGS := -std=c11 -Wall -Wextra
OBJDIR := build

INCLUDE_DIRS := -I./include
CC_SRCS := $(shell find src -name '*.c')
CC_OBJS := $(patsubst %.c, ${OBJDIR}/%.o, ${CC_SRCS})

all: build

build: ${CC_OBJS}
	${CC} ${CC_OBJS} -o ${TARGET}

${OBJDIR}/%.o: %.c 
	@mkdir -p $(dir $@)
	${CC} ${CC_FLAGS} ${INCLUDE_DIRS} -c $< -o $@


.PHONY: test clean

test: build
	bats check.bats

clean: 
	rm -f ${TARGET}
	if [ -d "${OBJDIR}" ]; then rm -rf ${OBJDIR}; fi