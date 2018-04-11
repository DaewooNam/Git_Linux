#define CONFREG *(volatil unsigned int*)0x56000000
#define DATREG *(volatil unsigned short*)0x56004000

#define CONFREGB *(volatil unsigned int*)0x58000000
#define DATREGB *(volatil unsigned short*)0x57000000

void init(){
	CONFRdEG &= ~(1<<5);
	CONFREG |= 1<<4;
}

void init(){
	//컨피그레이서 7:6 비트 00 설정
	CONFREGB &= ~(3<<6);
	//NFREGB &= ~(1<<3);

}


void main(){
	init();
	for(;;){
		DATREG &= ~(1<<2);
		sleep(1);
		DATREG |= 1<<2;
		sleep(1);
	}

	for(;;){
	
		DATREGB |= 1<<3;
		
		if((DATREG>>3)&1){
			printf("");
		}
		/*
		if (DATREGB & 0x4){
			printf("스위치 on");
		}

		if(DATREGB & 0x4){
			printf("스위치 off");
		}
		*/
		

	}



}
