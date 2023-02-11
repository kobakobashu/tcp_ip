#ifndef INTR_H
#define INTR_H

#include <pthread.h>
#include <stddef.h>
#include <signal.h>
#include <string.h>

#define INTR_IRQ_SHARED 0x0001

int intr_request_irq(unsigned int irq, int (*handler)(unsigned int irq, void *dev), int flags, const char *name, void *dev);
int intr_raise_irq(unsigned int irq);
int intr_run(void);
void intr_shutdown(void);
int intr_init(void);

#endif