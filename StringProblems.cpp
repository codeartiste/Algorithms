

int getMinimalNonRepeatingString(char *str, int len){

	char * end = str;

	int lut[256];
	for( int i = 0 ; i < 100 ; i++){
		lut[i] = 0;
	}
	//int max = -1 ;
	int start = 0 ;
	int i = 0 ;
	while(*end){
		if(lut[*end] >= start){

		}
		else{
			lut[*end] = i ;
		}


		end++;
	}




	return 1;
}
