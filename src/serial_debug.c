#include <avr/io.h>

#include "serial_debug.h"

void USART_Init(unsigned int ubrr)
{
  /*Set baud rate */
  UBRR0H = (unsigned char)(ubrr>>8);
  UBRR0L = (unsigned char)ubrr;
  UCSR0B = 0x00;
  UCSR0C = 0x00;
  /* Enable transmitter */
  UCSR0B = (0<<RXEN0)|(1<<TXEN0);
  /* Set frame format: 8data, 1stop bit */
  UCSR0C = (0<<USBS0)|(0<<UCSZ02)|(1<<UCSZ01)|(1<<UCSZ00);
}

void USART0SendByte(const unsigned char byte)
{
    //wait while previous byte is completed
    while(!(UCSR0A&(1<<UDRE0))){};
    // Transmit data
    UDR0 = byte;
}

void USART0SendData(const unsigned char* data)
{
  while(*data != 0) {
    USART0SendByte(*data);
    data++;
  }
  USART0SendByte('\n');
  USART0SendByte('\r');
}

void USART0DumpRegister(const uint8_t reg)
{
  uint8_t reg_brep[REGISTER_SIZE+1]; // +1 For null terminated string
  for (uint8_t index=0; index < REGISTER_SIZE; ++index) {
    if (reg & (1<<index)) {
      reg_brep[REGISTER_SIZE-1-index] = '1';
    } else {
      reg_brep[REGISTER_SIZE-1-index] = '0';
    }
  }
  reg_brep[REGISTER_SIZE] = 0;
  USART0SendData(reg_brep);
}
