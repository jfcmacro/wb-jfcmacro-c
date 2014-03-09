#ifndef _DEBUG_H
#define _DEBUG_H
#include "utilidades.h"

#ifdef DEBUG
#define debug(message) writeLogFile(message);
#else
#define debug(message) 
#endif

#endif
