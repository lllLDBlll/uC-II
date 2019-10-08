#ifndef DEFPRINCIPAIS_H_
#define DEFPRINCIPAIS_H_

//---------------------------------------------------------------------------------
#include "stm32f10x.h"
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include "atraso.h"

/* *********************************************************************************
 * CUIDADO AO EMPREGAR AS FUN��ES DA BIBLIOTECA DE ATRASO
 *
 * A frequ�ncia de trabalho do ARM deve ser a mesma ajustada abaixo!
 * Outro cuidado � saber exatamente se o n�cleo esta executando sem atrasos devido a leitura da FLASH!
 * Em cada la�os s�o gastos 3 ciclos para fechar o calculo do tempo de atraso desejado.
 * Havendo d�vida a fun��o deve ser depurada com o computo do n�mero de ciclos gastos.
 */

 //defini��es para a biblioteca de atraso
 #define FCPU 72000000							//define a frequencia da CPU - 84 MHz - ALTERAR TB NA LINHA DE BAIXO!
 asm (".equ fcpu, 72000000 \n\t");				//define a frequencia para o uso em c�digo assembly
/* *********************************************************************************/


//Defini��es de macros para o trabalho com bits

#define	set_bit(y,bit)	(y|=(1<<bit))			//coloca em 1 o bit x da vari�vel Y
#define	clr_bit(y,bit)	(y&=~(1<<bit))			//coloca em 0 o bit x da vari�vel Y
#define cpl_bit(y,bit) 	(y^=(1<<bit))			//troca o estado l�gico do bit x da vari�vel Y
#define tst_bit(y,bit) 	(y&(1<<bit))			//retorna 0 ou 1 conforme leitura do bit

//----------------------------------------------------------------------------------

#endif /* DEFPRINCIPAIS_H_ */


