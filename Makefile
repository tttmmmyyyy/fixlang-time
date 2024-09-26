libfixtime.a : fixtime.o
	ar rcs libfixtime.a fixtime.o

fixtime.o : fixtime.c
	gcc -o fixtime.o -c fixtime.c