HEADER = tokenizer.h history.h

all: uimain

uimain: uimain.o tokenizer.o history.o
	gcc uimain.o tokenizer.o history.o -o uimain

uimain.o: uimain.c $(HEADER)
	gcc -c uimain.c -o uimain.o

tokenizer.o: tokenizer.c
	gcc -c tokenizer.c -o tokenizer.o

history.o: history.c
	gcc -c history.c -o history.o
clean:
	-rm *.o
	-rm *~
	-rm *.c#
	-rm uimain
