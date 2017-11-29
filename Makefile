all : pendu test

pendu : 
	gcc charlist.c display.c main.c pendu.c word.c -o pendu
	
test :	
	gcc charlist.c display.c pendu.c test.c word.c -o test
	
clean :
	rm pendu test