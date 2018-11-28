all: c2f

c2f: c2f.c
	gcc -o c2f c2f.c

.PHONY: all
