
all: calclient calsvr

CLIENTOBJ = calclient.o calclient_stub.o cal_xdr.o 
SVROBJ = calsvr.o calsvr_proc.o cal_xdr.o 

calclient: ${CLIENTOBJ}
	${CC} -o $@ ${CLIENTOBJ}

calsvr: ${SVROBJ}
	${CC} -o $@ ${SVROBJ}

calsvr.c: cal.x
	rpcgen -C -s tcp $< -o $@

calsvr_proc.c: cal.x
	rpcgen -C -Ss $< -o $@

calclient_stub.c: cal.x
	rpcgen -C -l $< -o $@

cal.h: cal.x
	rpcgen -C -h $< -o $@

cal_xdr.c: cal.x
	rpcgen -C -c $< -o $@
