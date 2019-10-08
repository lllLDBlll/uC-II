#include "usart.h"

char bufferRX[tam_bufferRX];				// buffer para a recepção
volatile uint32_t contRX=0;

//-------------------------------------------------------------------------------------------
void USART_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/* Enable peripheral clock    *
	 * USART 3 is in PORTB */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);

	/* Enable tx IRQ */
	NVIC_InitTypeDef NVIC_InitStructure;

	/* Enable the USARTz Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	/* Configure USART3 Rx as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	/* Configure USARTy Tx as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART3, &USART_InitStructure);

	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);

	/* Enable USART3 */
	USART_Cmd(USART3, ENABLE);
}
//-------------------------------------------------------------------------------------------
void USART3_IRQHandler()
{

	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
	{
		if(contRX < tam_bufferRX)
		{
			bufferRX[contRX++] = USART_ReceiveData(USART3);		// leitura do dado recebido
		}
		else
			contRX=0;
	}

}
//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------
void limpa_bufferRX_USART()						// limpa buffer e libera nova escrita de dados
{
	//memset(bufferRX, 0,sizeof(bufferRX));		// limpa buffer

	contRX=0;			// só apaga referencia
}
//-------------------------------------------------------------------------------------------
char * return_bufferRX_USART()
{
	return bufferRX;
}
//-------------------------------------------------------------------------------------------
uint32_t return_nr_bytes_stored_bufferRx_USART()
{
	return contRX;
}
//-------------------------------------------------------------------------------------------
void escreve_caracter_USART (uint8_t c)
{
	while (!(USART3->SR & USART_FLAG_TXE));
	USART3->DR = (c & 0xFF);
}
//-------------------------------------------------------------------------------------------
void escreve_msg_USART(char * msg)
{
	for (; *msg!=0; msg++)
		escreve_caracter_USART(*msg);
}
//-------------------------------------------------------------------------------------------
void escreve_bufferRX_USART()						// se houver dados no buffer, escreve
{
	uint32_t i=0;

	while(i<contRX)
		escreve_caracter_USART(bufferRX[i++]);
}
//-------------------------------------------------------------------------------------------
void escreve_bufferRX_USART_limpa()
{
	escreve_bufferRX_USART();
	limpa_bufferRX_USART();
}
//-------------------------------------------------------------------------------------------

