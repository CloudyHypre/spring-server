# Installation directories following GNU conventions
prefix ?= /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
sbindir = $(exec_prefix)/sbin
datarootdir = $(prefix)/share
datadir = $(datarootdir)
includedir = $(prefix)/include
mandir = $(datarootdir)/man

BIN=bin
OBJ=obj
SRC=src

OBJ_MODS=obj/modules
SRC_MODS=src/modules

OBJ_EX=obj/example
SRC_EX=src/example

CC ?= gcc
CFLAGS ?= -Wextra -Wall -iquote$(SRC)

SERVERFLAGS = -DIS_SERVER=1 -DIS_CLIENT=0
CLIENTFLAGS = -DIS_SERVER=0 -DIS_CLIENT=1

.PHONY: all install uninstall clean

EXES = client

all: $(EXES)

client: $(OBJ_MODS)/termflag.o $(OBJ_MODS)/mainsocket.o $(OBJ_MODS)/inputpayload.o $(OBJ_MODS)/inputcommand.o $(OBJ_MODS)/nextperiodic.o $(OBJ_MODS)/sockettime.o $(OBJ_MODS)/readlist.o $(OBJ_MODS)/socketlist.o $(OBJ_MODS)/disconnectfunction.o $(OBJ_MODS)/connectfunction.o $(OBJ_MODS)/command.o $(OBJ_MODS)/periodic.o $(OBJ_MODS)/network.o $(OBJ_MODS)/log.o $(OBJ_MODS)/component.o $(OBJ_MODS)/main_client.o $(OBJ)/client.o | $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

$(OBJ)/%.o: $(SRC)/%.c | $(OBJ)
	$(CC) $(CFLAGS) -o $@ -c $<
	
$(OBJ_MODS)/main_client.o: $(SRC_MODS)/main.c | $(OBJ_MODS)
	$(CC) $(CFLAGS) $(CLIENTFLAGS) -o $@ -c $<
	
$(OBJ_MODS)/%.o: $(SRC_MODS)/%.c | $(OBJ_MODS)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_EX)/%.o: $(SRC_EX)/%.c | $(OBJ_EX)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_MODS): $(OBJ)
	mkdir -p $(OBJ_MODS)
	
$(OBJ_EX): $(OBJ)
	mkdir -p $(OBJ_EX)

$(BIN):
	mkdir -p $(BIN)

$(OBJ):
	mkdir -p $(OBJ)

clean:
	rm -rf $(BIN)
	rm -rf $(OBJ)
