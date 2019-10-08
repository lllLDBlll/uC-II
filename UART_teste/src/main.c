#include "defPrincipais.h"
#include "usart.h"

int main(void)
{
	SystemInit();
	USART_init();

    escreve_msg_USART("READY TO GO!\n");

    while (1)
    {
			if(return_nr_bytes_stored_bufferRx_USART()!=0)
			{
				escreve_caracter_USART(return_nr_bytes_stored_bufferRx_USART() + 48);
				escreve_bufferRX_USART_limpa();
			}

			atraso_ms(1000);

    }
}
