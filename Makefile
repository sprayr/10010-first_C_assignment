CC=gcc
OBJS= matfunctions.o functionsq2.o functionsq1.o exe.o  main.o
EXEC= proj
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@

matfunctions.o: matfunctions.c matfunctions.h
functionsq1.o: functionsq1.c functionsq1.h matfunctions.c matfunctions.h
functionsq2.o: functionsq2.c functionsq2.h matfunctions.c matfunctions.h
exe.o: exe.c functionsq1.h functionsq2.h exe.h 
main.o: main.c exe.h

clean: 
	rm -f $(EXEC) $(OBJS)
	
