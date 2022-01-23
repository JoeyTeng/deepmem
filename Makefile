# 指令编译器和选项
CC=gcc
CFLAGS=-Wall -std=gnu99

# 目标文件
TARGET=wasmvm
SRCS = src/deep_mem.c\
	   src/deep_log.c\
	   src/deep_main.c\
	   src/xoroshiro128plus.c
INC = -I./include
OBJS = $(SRCS:.c=.o)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ -lpthread -lm -g

clean:
	rm -rf $(TARGET) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) $(INC) -o $@ -c -g $<
