CC=gcc 
CFLAGS=-Wall -std=c99 
 
poetry: poetry.o 
	$(CC) poetry.o -o poetry 
 
poetry.o : poetry.c 
	$(CC) $(CFLAGS) -c poetry.c 
 
clean : 
	rm poetry poetry.o