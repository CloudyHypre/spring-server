#ifndef PERIODIC_H
#define PERIODIC_H 1

#define PERIODIC_ARGS       void
#define PERIODIC_RETURN     void

typedef PERIODIC_RETURN (*prdFunctionType)(PERIODIC_ARGS);

void periodic_init(void);
void periodic_add(prdFunctionType);
void periodic_exec(void);

#endif
