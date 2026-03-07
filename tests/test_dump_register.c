#include "serial_debug.h"

void test_dump_register(void)
{
  USART_Init(COMPUTE_UBRR(F_CPU, BAUD));
  // QEMU emulated avr do not have GPIO ports.
  // Emulate one through unsigned char
  unsigned char fake_ddrd = 0;
  fake_ddrd |= (1<<PD6)|(1<<PD4)|(1<<PD1)|(1<<PD0);
  USART0DumpRegister(fake_ddrd);
}

int main(void)
{
  test_dump_register();
  return 0;
}
