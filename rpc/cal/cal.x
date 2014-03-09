const OPER_OK = 0;
const OPER_FAIL = 1;

struct result {
   int status;
   int result;
   int code_fail;
};

struct values {
   int val1;
   int val2;
};

program CALPROG {
   version CALVERS {
       result SUM(values) = 1;
       result SUB(values) = 2;
       result MUL(values) = 3;
       result DIV(values) = 4;
   } = 1;
} = 0x30010001;

