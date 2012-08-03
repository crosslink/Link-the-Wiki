#
#Written (w) 2009 by David Alexander, University of Otago
#

ifeq ($(strip $(DEBUG)),)
    BUILD = -O3
else 
    BUILD = -g
endif

CFLAGS = $(BUILD)
CC = g++

PROGRAM = link_extract link_extract_pass2 link_index link_index_merge link_this title_extract

all : $(PROGRAM)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

disk.o: disk.c
	$(CC) $(CFLAGS) -c disk.c -o $@

directory_iterator.o : directory_iterator.c
	$(CC) $(CFLAGS) -c directory_iterator.c -o $@

directory_iterator_internals.o : directory_iterator_internals.c
	$(CC) $(CFLAGS) -c directory_iterator_internals.c -o $@

directory_iterator_recursive.o : directory_iterator_recursive.c
	$(CC) $(CFLAGS) -c directory_iterator_recursive.c -o $@
	
unicode.o: unicode.c
	$(CC) $(CFLAGS) -c unicode.c -o $@	
	
unicode_tables.o: unicode_tables.c
	$(CC) $(CFLAGS) -c unicode_tables.c -o $@	
	
ctypes.o: ctypes.c
	$(CC) $(CFLAGS) -c ctypes.c -o $@	

link_extract: disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o link_extract.o
	$(CC) $(CFLAGS) link_extract.o disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o -o $@

link_extract_pass2 : disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o unicode.o unicode_tables.o ctypes.o link_extract_pass2.o
	$(CC) $(CFLAGS) link_extract_pass2.o disk.o directory_iterator.o directory_iterator_internals.o unicode.o unicode_tables.o ctypes.o directory_iterator_recursive.o -o $@

link_index : disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o link_index.o
	$(CC) $(CFLAGS) link_index.o disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o -o $@

link_index_merge : link_index_merge.o
	$(CC) $(CFLAGS) link_index_merge.o -o $@

link_this : disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o link_this.o
	$(CC) $(CFLAGS) link_this.o disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o -o $@

title_extract : disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o title_extract.o
	$(CC) $(CFLAGS) title_extract.o disk.o directory_iterator.o directory_iterator_internals.o directory_iterator_recursive.o -o $@
	
clean:		
		rm -f $(PROGRAM) *.o
