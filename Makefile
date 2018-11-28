all: c2f

install: all
	install -g wheel -p ./c2f /usr/local/bin	
	ln -s /usr/local/bin/c2f /usr/local/bin/f2c

uninstall:
	rm /usr/local/bin/f2c
	rm /usr/local/bin/c2f

c2f: c2f.c
	gcc -o c2f c2f.c

.PHONY: all install uninstall
