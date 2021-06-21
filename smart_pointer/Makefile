CC = g++
SRC = src
SRCOBJS = src/String.o src/forString.o src/RCobject.o src/RCP.o

include $(SRC)/objlist
OBJS = main.o $(SRCOBJS)

test: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -f $(OBJS) test
