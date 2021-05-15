CC = gcc
teamP : covidmain.c covid.o
	$(CC) -o $@ $^
teamP.exe : covidmain.c covid.o
	$(CC) -o $@ $^
covid.o : covid.c
	$(CC) -c $^
clean :
	rm *.o *.exe
