#ifndef SEGMENT_H

typedef unsigned int Pid_t;
typedef unsigned int Boolean_t;
typedef enum Boolean_literal = { True, False } Boolean_literal;

typedef struct MemorySegment {
  unsigned long segmentNumber;
  unsigned long segmentBound;
  unsigned long baseAddress;
  Pid_t ownerProcess;
  unsigned long nBlocksonDisk;
  unsigned long *listBlocks;
  Boolean_t onMemory; /* True on memory */
} MemorySegment;

#endif
