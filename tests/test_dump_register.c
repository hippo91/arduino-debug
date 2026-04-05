#include "serial_debug.h"

void test_dump_register(void)
{
  USART_Init(COMPUTE_UBRR(F_CPU, BAUD));
  DDRD |= (1<<PD6)|(1<<PD4)|(1<<PD1)|(1<<PD0);
  USART0DumpRegister(DDRD);
}

int main(void)
{
  test_dump_register();
  return 0;
}
