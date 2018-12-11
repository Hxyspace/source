main.exe:main.o person.o
	@gcc main.o -lmingw32 -lSDL2main -lSDL2 person.o -o main.exe
main.o:main.c
	@gcc -c main.c -lmingw32 -lSDL2main -lSDL2 -o main.o
person.o:person.rc
	@windres person.rc person.o
clean:
	del main.o person.o