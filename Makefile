target = main
CC = gcc
CFLAGS = -std=c99
src = $(wildcard *c)

all:$(target)
	
$(target):$(src)
		$(CC) $(src) -o $@
			
