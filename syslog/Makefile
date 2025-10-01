all: ejemploLog

ejemploLog: ejemploLog.o
	${CC} -o $@ $< ${LDFLAGS}

ejemploLog.o: ejemploLog.c
	${CC} -c $<
