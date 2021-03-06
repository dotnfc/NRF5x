/*====================================================================================================*/
/*====================================================================================================*/
#include "drivers\nrf5x_system.h"
#include "drivers\nrf5x_rng.h"
#include "modules\module_serial.h"

#include "nrf51dk.h"
/*====================================================================================================*/
/*====================================================================================================*/
void NRF51_Init( void )
{
  NRF51_CKOCK_Config();
  NRF51_GPIO_Config();
  NRF51_UART_Config();
  NRF51_RNG_Config();
}
/*====================================================================================================*/
/*====================================================================================================*/
#define RANDOM_BUF_LENS 16

void NRF51_Loop( void )
{
  uint8_t randomBuf[RANDOM_BUF_LENS] = {0};
  uint8_t lens = 0;

  while(1) {
    lens = RNG_vectGenerate(randomBuf, RANDOM_BUF_LENS);
    printf("vect : ");
    for(uint8_t i = 0; i < lens; i++) {
      printf(" %3d", (int32_t)randomBuf[i]);
    }
    printf("\n\r");
    delay_ms(100);
  }
}
/*====================================================================================================*/
/*====================================================================================================*/
