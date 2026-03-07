#ifndef SERIAL_DEBUG_H
#define SERIAL_DEBUG_H

#define REGISTER_SIZE 8

#include <avr/io.h>

/**
 * @brief Compute the value of the USART Baud Rate Register
 * 
 * @param FREQ : cpu frequency
 * @param BAUDRATE : transmission rate
 */
#define COMPUTE_UBRR(FREQ, BAUDRATE) (((FREQ / (16UL * BAUDRATE)) - 1))

/*--------------------------------------------------------*/
/**
 * @brief Initialize the USART communication by
 *        setting the baud rate inside the UBRR register
 * 
 * @param ubrr: the value to put in the UBRR register
 * @note: the value to put in the UBRR register is linked 
 *        to the frequency and the baud rate thanks to the
 *        following formula:
 *         \f$((F_{CPU} / (16UL * BAUD)) - 1)\f$ 
 * @note: the frame format is set to 8 data bits and 1 stop bit
 */
/*--------------------------------------------------------*/
void USART_Init(unsigned int ubrr);

/*--------------------------------------------------------*/
/**
 * @brief Send the byte in argument through the serial port 
 * 
 * @param byte : data to transmit
 */
/*--------------------------------------------------------*/
void USART0SendByte(const unsigned char byte);

/*--------------------------------------------------------*/
/**
 * @brief Send the data in argument through the serial port
 * 
 * @param data : data to transmit
 */
/*--------------------------------------------------------*/
void USART0SendData(const unsigned char* data);

/*--------------------------------------------------------*/
/**
 * @brief Send the binary representation of the register
 *        through serial output
 * 
 * @param reg : register to be represented as a binary string
 */
/*--------------------------------------------------------*/
void USART0DumpRegister(const uint8_t reg);

#endif  // SERIAL_DEBUG_H
