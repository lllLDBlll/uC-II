#ifndef USART_H_
#define USART_H_

#include "defPrincipais.h"

#define tam_bufferRX 10		// define nr de bytes para armazenamento no buffer de recepção

//----------------------------------------------------------------------------------
void USART_init();
void USART3_IRQHandler();
//----------------------------------------------------------------------------------
void limpa_bufferRX_USART();
char * return_bufferRX_USART();
uint32_t  return_nr_bytes_stored_bufferRx_USART();
void escreve_caracter_USART (uint8_t c);
void escreve_msg_USART(char * msg);
void escreve_bufferRX_USART();
void escreve_bufferRX_USART_limpa();

#endif
