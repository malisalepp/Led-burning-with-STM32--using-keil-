#include "stm32f10x.h"                  // Device header 


static void gpioConfig(){

	GPIO_InitTypeDef GPIOInitStructure;                    //GPIO'nun konfigürasyonlarinin saklandigi TypeDef structure'ina bir degisken atadik
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);   //clock'lar kapali geliyor . burada kullanacagimiz portun clock'unu aciyoruz.
	
	GPIOInitStructure.GPIO_Mode = GPIO_Mode_Out_PP;          //cikisimizi output sectik ve direncimizi push pull olarak ayarladik
	GPIOInitStructure.GPIO_Pin = GPIO_Pin_0;                 //kullanacagimiz pini girdik
	GPIOInitStructure.GPIO_Speed = GPIO_Speed_50MHz;         //iletim hizimizi ayarladik
	
	GPIO_Init(GPIOB,&GPIOInitStructure);                   //yukarda tanimladigimiz tüm structure'lari GPIOB portunun içine attik.

}


int main(){

	gpioConfig();
	
	 while(1) {
		 
    GPIO_SetBits(GPIOB,GPIO_Pin_0);
	
	 }

}



