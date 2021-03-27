# Compile options. The -I<dir> tell the compiler where search include files
CXXFLAGS = -Wall -no-pie -fPIE -g #-I$(INCLUDE)

# Αρχεία .o
# INCL = 
OBJS = solution.o

# Το εκτελέσιμο πρόγραμμα
EXEC = solution

$(EXEC): $(OBJS) $(INCL)
	g++ $(OBJS) -o $(EXEC)

clean:
	rm -f $(OBJS) $(EXEC)


run: $(EXEC)
	./$(EXEC) < input.txt

gdb: $(OBJS)
	g++ $(OBJS) -g3 -o $(EXEC)
	gdb $(EXEC)