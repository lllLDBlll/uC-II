#ifndef DEFPRINCIPAIS_H_
#define DEFPRINCIPAIS_H_

//---------------------------------------------------------------------------------
#include "stm32f10x.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "atraso.h"

/* *********************************************************************************
 * CUIDADO AO EMPREGAR AS FUNÇÕES DA BIBLIOTECA DE ATRASO
 *
 * A frequência de trabalho do ARM deve ser a mesma ajustada abaixo!
 * Outro cuidado é saber exatamente se o núcleo esta executando sem atrasos devido a leitura da FLASH!
 * Em cada laços são gastos 3 ciclos para fechar o calculo do tempo de atraso desejado.
 * Havendo dúvida a função deve ser depurada com o computo do número de ciclos gastos.
 */

 //definições para a biblioteca de atraso
 #define FCPU 72000000							//define a frequencia da CPU - 84 MHz - ALTERAR TB NA LINHA DE BAIXO!
 asm (".equ fcpu, 72000000 \n\t");				//define a frequencia para o uso em código assembly
/* *********************************************************************************/


//Definições de macros para o trabalho com bits

#define	set_bit(y,bit)	(y|=(1<<bit))			//coloca em 1 o bit x da variável Y
#define	clr_bit(y,bit)	(y&=~(1<<bit))			//coloca em 0 o bit x da variável Y
#define cpl_bit(y,bit) 	(y^=(1<<bit))			//troca o estado lógico do bit x da variável Y
#define tst_bit(y,bit) 	(y&(1<<bit))			//retorna 0 ou 1 conforme leitura do bit

//----------------------------------------------------------------------------------

#endif /* DEFPRINCIPAIS_H_ */


