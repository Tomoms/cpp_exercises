CC = g++
CPPFLAGS = -O3 -march=native -Wall
OUT = out
OBJS = $(patsubst %.cpp, $(OUT)/%.o, $(wildcard *.cpp))

ex2: $(OBJS)
	$(CC) $(CPPFLAGS) $^ -o $@

$(OUT)/%.o: %.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

clean:
	rm -r out/
	rm ex2

$(shell mkdir $(OUT))
