# *************************************************************# 
# Makefile                                                     #
# Reseni DU2-IJC, priklad a,b                                  # 
# Autor: Lukas Foltyn                                          # 
# Fakulta: VUT - Fakulta informacnich technologii              # 
# Posledni zmena:26.3.2020                                     # 
# Prekladac: gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0         # 
# *************************************************************#

.RECIPEPREFIX=-
CC=gcc
CPP=g++
CFLAGS=-std=c99 -pedantic -Werror -Wextra -g -O2
CPPFLAGS=-std=c++17 -pedantic -Wall
OBJECTS=io.o wordcount.o
STATIC_LIBRARY=libhtab.a
DYNAMIC_LIBRARY=libhtab.so
LIBRARY_OBJ=htab_begin.o htab_bucket_count.o htab_clear.o htab_create_item.o \
htab_end.o htab_erase.o htab_find.o htab_free.o htab_function.o \
htab_get_key.o htab_get_value.o htab_init.o htab_iterator.o htab_lookup_add.o \
htab_set_value.o htab_size.o htab.o

EXECUTABLES= tail wordcount wordcount-dynamic wordcountcpp

all: $(EXECUTABLES)

%.o: %.c
- $(CC) $(CFLAGS) -fPIC -c $<

tail:tail.o
- $(CC) $^ -o $@

wordcount:$(OBJECTS) $(STATIC_LIBRARY)
- $(CC) $(OBJECTS) -L . $(STATIC_LIBRARY) -o $@

wordcount-dynamic:$(OBJECTS) $(DYNAMIC_LIBRARY)
- $(CC) $(OBJECTS)  -L . $(DYNAMIC_LIBRARY) -o $@

$(DYNAMIC_LIBRARY):$(LIBRARY_OBJ)
- $(CC) $^ -shared -o $@

$(STATIC_LIBRARY):$(LIBRARY_OBJ)
- ar -rcs $@ $^

# dependecies of .h file
tail.o: tail.h
io.o: io.h
wordcount: io.h htab.h
$(LIBRARY_OBJ): lib_htab.h

# cpp files
wordcountcpp:wordcountcpp.o
- $(CPP) $^ -o $@

wordcountcpp.o: wordcountcpp.cc
- $(CPP) $(CPPFLAGS) -c $<

.PHONY: clean zip

clean:
- rm $(EXECUTABLES) $(STATIC_LIBRARY) $(DYNAMIC_LIBRARY) *.o 

zip:
- zip xfolty17 *.c *.cc *.h Makefile
  
  


