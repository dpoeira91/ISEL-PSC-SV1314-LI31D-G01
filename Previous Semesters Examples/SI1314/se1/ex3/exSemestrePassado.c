typedef struct floatbits {
	unsigned significand : 23; unsigned exponent : 8; unsigned sign : 1;
} floatbits_t; 

float s2f(short int s) {
	floatbits_t f = { 0x7FFFFF, 0xFF, 0x1 };
	int aux = s;
	int mask;
	int count=0;
	
	
	// sign
	f.sign = (s>=0)? 0 : 1;
	
	
	//significand
	while(aux!=0){
		++count;
		aux= aux >>1;
	}
	count = (count==0)? 0 : count-1;
	mask = 1<<count;
	mask = ~(mask);
	aux = s & mask;
	aux = aux<<(31-count);
	f.significand = aux;	
	
	
	//exponent
	f.exponent = (s==0)? 0 : 127 + count;
	
	return *(float*)&f;
}
