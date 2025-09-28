#include <stdio.h>

#include "serial_debug.h"

void test_send_date(void)
{
  USART_Init(COMPUTE_UBRR(F_CPU, BAUD));
  char msg[45];
  sprintf(msg, "Uptime %02u:%02u:%02u", 11, 29, 8);
  USART0SendData((uint8_t *)msg);
}

void shutdown(void)
{
  SMCR = (1<<SM2)|(1<<SM1)|(1<<SM0);
  SMCR |= (1<<SE);
}

int main(void)
{
  test_send_date();
  shutdown();
}
