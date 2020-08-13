#include <stdio.h>
#include <stdlib.h>

/* Função: aplicação que faz conversões entre as duas escalas de temperaturas, Celsius e Kelvin, e que apresenta todas as temperaturas inseridas e a respetiva conversão.
			Apresenta também a maior e a menor temperatura na escala original e de conversão, assim como a media de temperaturas.
   Autor:  Luís Filipe */
   
   
//Declaração de subrotinas
void mostrarCelsius(float *temperaturas, int numeroElementos, float *temperaturaCelsius);
void mostraKelvin(float *temperaturas, int numeroElementos, float *temperaturaKelvin);
float MaiorTemperaturaNaoConvertida(float *temperaturas, int numeroElementos);
float MaiorTemperaturaConvertidaKelvin(float *temperaturaKelvin, int numeroElementos);
float MaiorTemperaturaConvertidaCelsius(float *temperaturaCelsius, int numeroElementos);
float MenorTemperaturaNaoConvertida(float *temperaturas, int numeroElementos);
float MenorTemperaturaConvertidaKelvin(float *temperaturaKelvin, int numeroElementos);
float MenorTemperaturaConvertidaCelsius(float *temperaturaCelsius,int numeroElementos);
void MediaNaoConvertidas(float *temperaturas,int numeroElementos);
void mostraMediaConvertidaKelvin(float *temperaturasKelvin, int numeroElementos);
void mostraMediaConvertidaCelsius(float *temperaturasCelsius, int numeroElementos);

int main(int argc, char *argv[]) {
		
	//Declarar Variaveis
	float temperatura, temperaturas[500], temperaturaKelvin[500], temperaturaCelsius[500],maiorNaoConvertida, maiorConvertidaKelvin, maiorConvertidaCelsius,
	menorTemperaturaNaoConvertida, menorTemperaturaConvertidaKelvin, menorTemperaturaConvertidaCelsius;
	int i;
	char escala;
	
	//limpar ecra
	system("cls");
	
	// solicitar a escala ao utilizador
	printf("Insira a escala para a qual pretende converter(C/K): ");
	scanf(" %c", &escala);
	
	if (escala == 'K' || escala == 'k')
	{
		//Informar acerca da condição de paragem
		puts("Insira uma temperatura igual ou superior a 500 para terminar o programa");
		
		//Solicitação da temperatura
		printf("Insira a temperatura em Celsius: ");
		scanf(" %f", &temperatura);		
		
		while (temperatura <= 500)
		{
			//guardar a temperatura como elemento no array
			temperaturas[i] = temperatura;
			
			//guardar a temperatura convertida como elemento no array
			temperaturaKelvin[i] = temperatura + 273;	//Conversão da temperatura em Celsius para Kelvin
			
			//incrementar i
			i++;
			
			//Solicitação da temperatura
			printf("Insira a temperatura em celsius: ");
			scanf(" %f", &temperatura);
		}
		
		//Apresentação das temperaturas convertidas para Kelvin
		mostraKelvin(temperaturas,i,temperaturaKelvin);
		
		maiorNaoConvertida = MaiorTemperaturaNaoConvertida(temperaturas,i);
		//Apresentação da maior temperatura inserida pelo utilizador
		printf("\nA maior temperatura nao convertida e: %.2f", maiorNaoConvertida);
		
		maiorConvertidaKelvin = MaiorTemperaturaConvertidaKelvin(temperaturaKelvin,i);
		//Escrever a maior temperatura convertida em Kelvin
		printf("\nA maior temperatura convertida e: %.2f", maiorConvertidaKelvin);
		
		menorTemperaturaNaoConvertida = MenorTemperaturaNaoConvertida(temperaturas,i);
		//Apresentação da menor temperatura inserida pelo utilizador
		printf("\nA menor temperatura nao convertida e : %.2f", menorTemperaturaNaoConvertida);
		
		menorTemperaturaConvertidaKelvin = MenorTemperaturaConvertidaKelvin(temperaturaKelvin,i);	
		//Apresentação da menor temperatura convertida em Kelvin
		printf("\nA menor temperatura convertida e : %.2f", menorTemperaturaConvertidaKelvin);
		
		//Apresentação da media das temperaturas não convertidas
		MediaNaoConvertidas(temperaturas,i);
		
		//Apresentação da media das temperaturas convertidas para Kelvin
		mostraMediaConvertidaKelvin(temperaturaKelvin,i);
		

	}
	
	else if (escala == 'C' || escala == 'c')
	{
		//Informar acerca da condição de paragem
		puts("Insira uma temperatura igual ou superior a 500 para terminar o programa");
		
		//Solicitação da temperatura
		printf("Insira a temperatura em Kelvin: ");
		scanf(" %f", &temperatura);
		
		while (temperatura <= 500)
		{
			//guardar a temperatura como elemento no array
			temperaturas[i] = temperatura;
			
			//guardar a temperatura convertida como elemento no array
			temperaturaCelsius[i] = temperatura - 273; //Conversão da temperatura em Kelvin para Celsius		
			
			//incrementar i
			i++;
	
			//Solicitação da temperatura
			printf("Insira a temperatura em kelvin: ");
			scanf(" %f", &temperatura);
		}
		
		//Apresentação das temperaturas convertidas para Celsius
		mostrarCelsius(temperaturas,i,temperaturaCelsius);
		
		maiorNaoConvertida = MaiorTemperaturaNaoConvertida(temperaturas,i);
		//Apresentação da maior temperatura inserida pelo utilizador
		printf("\nA maior temperatura nao convertida e: %.2f", maiorNaoConvertida);
		
		maiorConvertidaCelsius = MaiorTemperaturaConvertidaCelsius(temperaturaCelsius,i);
		//Apresentação da maior temperatura convertida em Celsius
		printf("\nA maior temperatura convertida e: %.2f", maiorConvertidaCelsius);
		
		menorTemperaturaNaoConvertida = MenorTemperaturaNaoConvertida(temperaturas,i);
		//Apresentação da menor temperatura inserida pelo utilizador
		printf("\nA menor temperatura nao convertida e : %.2f", menorTemperaturaNaoConvertida);
		
		menorTemperaturaConvertidaCelsius = MenorTemperaturaConvertidaCelsius(temperaturaCelsius,i);
		//Apresentação da menor temperatura convertida em Celsius
		printf("\nA menor temperatura convertida e : %.2f", menorTemperaturaConvertidaCelsius);
		
		//Apresentação da media das temperaturas não convertidas
		MediaNaoConvertidas(temperaturas,i);
		
		//Apresentação da media das temperaturas convertidas para Celsius
		mostraMediaConvertidaCelsius(temperaturaCelsius,i);
		
	}
	
	else
		printf("Escala invalida!!");
}




/*
	Este procedimento mostra as temperaturas inseridas em Kelvin e a sua conversão para Celsius
*/
void mostrarCelsius(float *temperaturas, int numeroElementos, float *temperaturaCelsius)
{
	//Declarar Variaveis locais
	int i;
	
	//limpar ecra
	system("cls");
	
	//rodapé
	printf("\n");
	printf("        Kelvin         |         Celsius         \n");
	
	//Mostrar temperaturas
	for (i = 0; i < numeroElementos; i++)
	{
		printf("\t%.2f         |         %.2f          \n", temperaturas[i], temperaturaCelsius[i]);
	}
}



/*
	Este procedimento mostra as temperaturas inseridas em Celsius e a sua conversão para Kelvin
*/
void mostraKelvin(float *temperaturas, int numeroElementos, float *temperaturaKelvin)
{
	//Declarar Variaveis locais
	int i;
	
	//limpar ecra
	system("cls");
	
	//rodapé
	printf("\n");
	printf("       Celsius        |         Kelvin         \n");
	
	//Mostrar temperaturas
	for (i = 0; i < numeroElementos; i++)
	{
		printf("\t%.2f         |         %.2f          \n", temperaturas[i], temperaturaKelvin[i]);
	}
}



/*
	Esta função calcula a maior temperatura inserida pelo utilizador
*/	
float MaiorTemperaturaNaoConvertida(float *temperaturas, int numeroElementos)
{
	//Declarar Variaveis locais
	int i;
	float maiorTemperatura;
	
	//Inicializar variaveis
	maiorTemperatura = temperaturas[0]; //maiorTemperatura fica com o valor da 1 temperatura do array, sendo essa a usada para a verificação da maior
	
	//Verificar a maior temperatura inserida pelo utilizador
	for (i = 1; i < numeroElementos; i++)
	{
		if (temperaturas[i] > maiorTemperatura)
		{
			maiorTemperatura = temperaturas[i];
		}
	}
	
	//retornar a maior temperatura inserida pelo utilizador
	return maiorTemperatura;
	
}



/*
	Esta função calcula a maior temperatura convertida em Kelvin
*/	
float MaiorTemperaturaConvertidaKelvin(float *temperaturaKelvin, int numeroElementos)
{
	//Declarar Variaveis locais
	int i;
	float maiorTemperaturaConvertida;
	
	//Inicializar variaveis
	maiorTemperaturaConvertida = temperaturaKelvin[0]; //maiorTemperaturaConvertida fica com o valor da 1 temperatura do array, sendo essa a usada para a verificação da maior
	
	//Verificar a maior temperatura 
	for (i = 1; i < numeroElementos; i++)
	{
		if (temperaturaKelvin[i] > maiorTemperaturaConvertida)
		{
			maiorTemperaturaConvertida = temperaturaKelvin[i];
		}
	}

	//retornar a maior temperatura Convertida para Kelvin
	return maiorTemperaturaConvertida;
}



/*
	Esta função calcula a maior temperatura convertida em Celsius
*/	
float MaiorTemperaturaConvertidaCelsius(float *temperaturaCelsius, int numeroElementos)
{
	//Declarar Variaveis locais
	int i;
	float maiorTemperaturaConvertida;
	
	//Inicializar variaveis
	maiorTemperaturaConvertida = temperaturaCelsius[0]; //maiorTemperaturaConvertida fica com o valor da 1 temperatura do array, sendo essa a usada para a verificação da maior
	
	//Verificar a maior temperatura
	for (i = 1; i < numeroElementos; i++)
	{
		if (temperaturaCelsius[i] > maiorTemperaturaConvertida)
		{
			maiorTemperaturaConvertida = temperaturaCelsius[i];
		}
	}

	//retornar a maior temperatura Convertida para Celsius
	return maiorTemperaturaConvertida;
}



/*
	Esta função calcula a menor temperatura inserida pelo utilizador
*/	
float MenorTemperaturaNaoConvertida(float *temperaturas, int numeroElementos)
{
	//Declarar Variaveis locais
	int i; 
	float menorTemperaturaConvertida;
	
	//Inicializar variaveis
	menorTemperaturaConvertida = temperaturas[0];
	
	//Verificar a menor temperatura
	for (i = 1; i < numeroElementos; i++)
	{
		if (temperaturas[i] < menorTemperaturaConvertida)
		{
			menorTemperaturaConvertida = temperaturas[i];
		}
	}
	
	//retornar a menor temperatura inserida pelo utilizador
	return menorTemperaturaConvertida;
}



/*
	Esta função calcula a menor temperatura convertida para Kelvin
*/	
float MenorTemperaturaConvertidaKelvin(float *temperaturaKelvin,int numeroElementos)
{
	//Declarar Variaveis locais
	int i;
	float menorTemperaturaConvertida;
	
	//Inicializar variaveis
	menorTemperaturaConvertida = temperaturaKelvin[0];
	
	//Verificar a menor temperatura
	for (i = 1; i < numeroElementos; i++)
	{
		if (temperaturaKelvin[i] < menorTemperaturaConvertida)
		{
			menorTemperaturaConvertida = temperaturaKelvin[i];
		}
	}
	
	//retornar a menor temperatura convertida para Kelvin
	return menorTemperaturaConvertida;	
}


/*
	Esta função calcula a menor temperatura convertida para Celsius
*/	
float MenorTemperaturaConvertidaCelsius(float *temperaturaCelsius,int numeroElementos)
{
	//Declarar Variaveis locais
	int i;
	float menorTemperaturaConvertida;
	
	//Inicializar variaveis
	menorTemperaturaConvertida = temperaturaCelsius[0];
	
	//Verificar a menor temperatura
	for (i = 1; i < numeroElementos; i++)
	{
		if (temperaturaCelsius[i] < menorTemperaturaConvertida)
		{
			menorTemperaturaConvertida = temperaturaCelsius[i];
		}
	}
	
	//retornar a menor temperatura convertida para Celsius
	return menorTemperaturaConvertida;	
}



/*
	Este procedimento calcula a media das temperaturas inseridas pelo utilizador
*/		
void MediaNaoConvertidas(float *temperaturas,int numeroElementos)
{
	//Declarar Variaveis locais
	int i, soma, contador;
	float media;
	
	//Inicializar variaveis
	soma = 0;
	contador = 0;
	
	//Percorrer todas as temperaturas, contar e somar todas
	for (i = 0; i < numeroElementos; i++)
	{
		soma += temperaturas[i];
		contador++;
	}
	
	//Calculo da media das temperaturas inseridas pelo utilizador
	media = soma / contador;
	
	//Mostrar Media 
	printf("\nA media das temperaturas nao convertidas e: %.2f", media);

}




/*
	Este procedimento calcula a media das temperaturas convertidas para Kelvin
*/	
void mostraMediaConvertidaKelvin(float *temperaturasKelvin, int numeroElementos)
{
	//Declarar Variaveis locais
	int i, soma, contador;
	float media;
	
	//Inicializar variaveis
	soma = 0;
	contador = 0;
	
	//Percorrer todas as temperaturas, contar e somar todas 
	for (i = 0; i < numeroElementos; i++)
	{
		soma += temperaturasKelvin[i];
		contador++;
	}
	
	// calcular a media das temperaturas convertidas
	media = soma / contador;
	
	// mostrar a media
	printf("\nA media das temperaturas convertidas e: %.2f", media);
}





/*
	Este procedimento calcula a media das temperaturas convertidas para Celsius
*/	
void mostraMediaConvertidaCelsius(float *temperaturasCelsius, int numeroElementos)
{
	//Declarar Variaveis locais
	int i, soma, contador;
	float media;
	
	//Inicializar variaveis
	soma = 0;
	contador = 0;
	
	//Percorrer todas as temperaturas, contar e somar todas
	for (i = 0; i < numeroElementos; i++)
	{
		soma += temperaturasCelsius[i];
		contador++;
	}
	
	// calcular a media das temperaturas convertidas
	media = soma / contador;
	
	// mostrar a media
	printf("\nA media das temperaturas convertidas e: %.2f", media);
}



