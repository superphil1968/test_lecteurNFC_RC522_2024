#include "mbed.h"
#include "MFRC522.h"


#define SPI_MOSI    PB_15
#define SPI_MISO    PB_14
#define SPI_SCLK    PB_13
#define SPI_CS      PB_12


#define MF_RESET    PA_0

MFRC522    RfChip   (SPI_MOSI, SPI_MISO, SPI_SCLK, SPI_CS, MF_RESET);


  


int main(void) {



  RfChip.PCD_Init();
 while (true) {



   if (  RfChip.PICC_IsNewCardPresent())
    {
     //wait_ms(500);
      if (  RfChip.PICC_ReadCardSerial())
        {
         // wait_ms(500);
         printf("Card UID: ");
         for (uint8_t i = 0; i < RfChip.uid.size; i++)
         {
       printf(" %02X", RfChip.uid.uidByte[i]);
         }
        printf("\n\r");
       
    }
    }

    

     
     



    //wait_ms(1000);
}
 }