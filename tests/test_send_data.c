#include <stdio.h>

#include "serial_debug.h"

void test_send_data(void)
{
  USART_Init(COMPUTE_UBRR(F_CPU, BAUD));
  char msg[45];
  sprintf(msg, "Uptime %02u:%02u:%02u", 11, 29, 8);
  USART0SendData((uint8_t *)msg);
}

int main(void)
{
  test_send_data();
  return 0;
}
