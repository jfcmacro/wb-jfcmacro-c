const OPER_OK = 0;
const OPER_FAIL = 1;

struct result {
   int status;
};

struct values {
   char path[256];
};

program COMPILERPROG {
   version COMPILERVERS {
       result COMPILE(values) = 1;
   } = 1;
} = 0x30010002;

