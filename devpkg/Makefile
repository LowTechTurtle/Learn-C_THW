PREFIX = /usr/local
CFLAGS = -g -Wall -I$(PREFIX)/apr/include/apr-1
CFLAGS += -L$(PREFIX)/apr/lib -lapr-1 -pthread -laprutil-1

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install - d $(DESTDIR) / $(PREFIX) /bin/
	install devpkg $(DESTDIR) / $(PREFIX) /bin/

clean:
	rm -rf *.o
	rm -f devpkg
	rm -rf *.dSYM
