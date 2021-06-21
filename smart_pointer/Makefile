CC = g++
SRC = src
CFLAG = -Wall

include $(SRC)/objlist
OBJS = main.o $(SRCOBJS)



test: $(OBJS)
	@echo "included"
	$(CC) $(CFLAG) $(OBJS) -o $@

clean:
	rm -f $(OBJS) test
	rm main.o

# src/String.o: src/String.h
# src/forString.o: src/forString.h
# src/RCobject.o: src/RCobject.h
# src/RCP.o: src/RCP.h