CC = gcc
cinquiry.exe : covidmain.c covid.o
	$(CC) -o $@ $^
covid.o : covid.c
	$(CC) -c $^
clean :
	rm *.o *.exe