SRC_DIR = src
BIN_DIR = bin

SRC_FILES = $(wildcard ${SRC_DIR}/*.c)
BIN_FILES = ${SRC_FILES:${SRC_DIR}/%.c=${BIN_DIR}/%}

all: ${BIN_FILES}

${BIN_DIR}/%: ${SRC_DIR}/%.c
	cc $< -o $@ -ltm1638
