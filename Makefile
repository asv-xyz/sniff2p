CC=g++
INCDIRS=./include
CFLAGS=-Wall -Wextra $(foreach D,$(INCDIRS),-I$(D))
SRC=$(wildcard ./src/*.cpp)
OBJ=$(SRC:.cpp=.o)
TGT=./bin/executable

.PHONY: all clean

all: $(TGT)

$(TGT): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(TGT)

%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ) $(TGT)
