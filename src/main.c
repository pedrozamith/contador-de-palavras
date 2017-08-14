#include <stdio.h>

int main (){

	int  n_palavra = 0 , dentro_palavra = 0, flag_num = 0, flag_ponto = 0, esteve_float = 0;
	char frase;

	while (frase != '\n'){
	  scanf ("%c", &frase);
	  frase = frase + NULL;
	  
		if (frase > 64) {   				//verifica se o caractere é especial ou letra. 
			dentro_palavra = 1;			//caso seja letra, flag ativada
			flag_num = 0;
			flag_ponto = 0;
		}
		
		else if (flag_num == 1){			//trata o caso de ponto flutuante 
		if (!((frase > 47)&&(frase < 58))){
			if ((frase == 44)||(frase == 46)){	//Se for . ou , ativa flag de ponto flutuante
				flag_ponto++;
				esteve_float = 1;
			}
		
		n_palavra++;
		dentro_palavra = 0;
		flag_num = 0;
		flag_ponto = 0;	
	
		}
		
		else if (flag_ponto > 1){		//trata o caso de pontuação em seguida do ponto flutuante
					n_palavra++;
					dentro_palavra = 0;
					flag_num = 0;
					flag_ponto = 0;	
					esteve_float = 1;
		}
		
		else {
			flag_num = 1;
			dentro_palavra = 1;
		}
							
			}
			

		else if ((frase > 47)&&(frase < 58)){		//trata o caso de numeros
			flag_num = 1;				//caso apareça algum numero, a verificação ocorre até aparecer um
			dentro_palavra = 1;			//caractere especial. Se for . ou , não conta mais mas se for espaço
		}								//ele conta como mais uma palavra
	  
	  	else { 
			if (dentro_palavra == 1){
		 	 	n_palavra++;
		 		dentro_palavra = 0;
				flag_num = 0;
				flag_ponto = 0;
			}
	  	}
	}
	
	if (esteve_float == 1){
		n_palavra--;
		
	}
printf ("%d",n_palavra);
	return 0;
}
