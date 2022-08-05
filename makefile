LDLIBS=-lnetfilter_queue

all: netfilter

netfilter: main.o headers.o pch.o
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f netfilter *.o
