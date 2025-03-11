C        = gcc
SOURCES  = llist.c dllist.c aqueue.c lqueue.c astack.c lstack.c main.c
HEADERS  = llist.h dllist.h aqueue.h lqueue.h astack.h lstack.h

program: $(SOURCES) $(HEADERS)
	$(C) -o $@ $(SOURCES)