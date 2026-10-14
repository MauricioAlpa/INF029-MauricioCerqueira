// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Mauricio Cerqueira Cerqueira Santos    
//  email:mauriciocerqueira04@gmail.com
//  Matrícula:20261160032
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include <trabalho1.h> 


DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  bool isBissexto = false, anoInvalido = false;
  int nBarras = 0, dia = 0, mes = 0, ano = 0;

  //quebrar a string data em strings sDia, sMes, sAno
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] != '/') {
            
            if (nBarras == 0) {
                dia = (dia * 10) + (data[i] - '0');
            } else if (nBarras == 1) {
                mes = (mes * 10) + (data[i] - '0');
            } else if (nBarras == 2) {
                ano = (ano * 10) + (data[i] - '0');
            }
        } else {
            nBarras++;
        }
    }

    if (ano == 0) {
    anoInvalido = true;
    }

    if(ano < 100){
        if (    ano <= 29 ) {
            ano += 2000;  
        } else {
            ano += 1900;  
        }
    }

    if (ano >= 100 && ano <= 999) {
        anoInvalido = true;
    }

    if(nBarras != 2 || anoInvalido){
        datavalida = 0;
    }else{
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            isBissexto = true;
        }

        switch(mes){
            case 1:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;

            case 2:

                if (isBissexto) {
                    if (dia <= 0 || dia > 29) { datavalida = 0; }
                } else {
                    if (dia <= 0 || dia > 28) { datavalida = 0; }
                }
                break;

            case 3:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;

            case 4:

                if(dia <= 0 || dia > 30){
                    datavalida = 0;
                }
                break;

            case 5:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;

            case 6:

                if(dia <= 0 || dia > 30){
                    datavalida = 0;
                }
                break;

            case 7:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;

            case 8:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;

            case 9:

                if(dia <= 0 || dia > 30){
                    datavalida = 0;
                }
                break;

            case 10:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;

            case 11:

                if(dia <= 0 || dia > 30){
                    datavalida = 0;
                }
                break;

            case 12:

                if(dia <= 0 || dia > 31){
                    datavalida = 0;
                }
                break;
            
            default:

                datavalida = 0;
                break;

        }
        
    }


    //printf("%s\n", data);

    if (datavalida)
        return 1;
    else
        return 0;
    }



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
        DataQuebrada dI = {0}, dF = {0};
        int nBarras = 0;
        for (int i = 0; i < strlen(datainicial); i++) {
            if (datainicial[i] != '/') {
                
                if (nBarras == 0) {
                    dI.iDia = (dI.iDia * 10) + (datainicial[i] - '0');
                } else if (nBarras == 1) {
                    dI.iMes = (dI.iMes * 10) + (datainicial[i] - '0');
                } else if (nBarras == 2) {
                    dI.iAno = (dI.iAno * 10) + (datainicial[i] - '0');
                }
            } else {
                nBarras++;
            }
        }

        if(dI.iAno < 100){
            if (dI.iAno <= 29) {
                dI.iAno += 2000;  
            } else {
                dI.iAno += 1900;  
            }
        }

        dI.valido = 1;

        nBarras = 0;

        for (int i = 0; i < strlen(datafinal); i++) {
            if (datafinal[i] != '/') {
                
                if (nBarras == 0) {
                    dF.iDia = (dF.iDia * 10) + (datafinal[i] - '0');
                } else if (nBarras == 1) {
                    dF.iMes = (dF.iMes * 10) + (datafinal[i] - '0');
                } else if (nBarras == 2) {
                    dF.iAno = (dF.iAno * 10) + (datafinal[i] - '0');
                }
            } else {
                nBarras++;
            }
        }

        if(dF.iAno < 100){
            if (dF.iAno <= 29) {
                dF.iAno += 2000;  
            } else {
                dF.iAno += 1900;  
            }
        }

        dF.valido = 1;

      //verifique se a data final não é menor que a data inicial

        if(dF.iAno < dI.iAno || (dF.iAno == dI.iAno && dF.iMes < dI.iMes) || (dF.iAno == dI.iAno && dF.iMes == dI.iMes && dF.iDia < dI.iDia)){
            dma.retorno = 4;
            return dma;
        }
      //calcule a distancia entre as datas
    
        dma.qtdDias = dF.iDia - dI.iDia;
        dma.qtdMeses = dF.iMes - dI.iMes;
        dma.qtdAnos = dF.iAno - dI.iAno;

        
        int mesAnterior = dF.iMes - 1;
        int anoAnterior = dF.iAno;

        while (dma.qtdDias < 0)
        {
            dma.qtdMeses--;

            if (mesAnterior == 0)
            {
                mesAnterior = 12;
                anoAnterior--;
            }

            dma.qtdDias += diasNoMes(mesAnterior, anoAnterior);

            mesAnterior--;
        }

        
        while (dma.qtdMeses < 0)
        {
            dma.qtdAnos--;
            dma.qtdMeses += 12;
        }




      //se tudo der certo
      dma.retorno = 1;
      return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive == 1){

        for(int i = 0; texto[i] != '\0'; i++){
            if(texto[i] == c){
                qtdOcorrencias++;
            }
        }
    }else{

        char copia[strlen(texto) + 1];
        strcpy(copia, texto);

        toLowerCase(copia);

        if (c >= 'A' && c <= 'Z') {
            c = c + 32;
        }   

        for(int i = 0; copia[i] != '\0'; i++){
            if(copia[i] == c){
                qtdOcorrencias++;
            }
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int tamBusca = strlen(strBusca);

    if (tamBusca == 0) return 0;

    for (int i = 0; strTexto[i] != '\0'; i++) {
        int corresponde = 0;
        int k = i, j = 0;

        
        while (strTexto[k] != '\0' && strBusca[j] != '\0' && strTexto[k] == strBusca[j]) {
            corresponde++;
            j++;
            k++;
        }

            
        if (corresponde == tamBusca) {
            int posicaoInicial = i + 1; 
            int posicaoFinal = k;       

        
            posicoes[qtdOcorrencias * 2] = posicaoInicial;
            posicoes[qtdOcorrencias * 2 + 1] = posicaoFinal;

            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;

}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou;
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}


int diasNoMes(int mes, int ano)
{
    switch (mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))
                return 29;
            else
                return 28;
    }

    return 0;
}


void toLowerCase(char string[]){ // Função para mudar todas as letras para lowercase

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32; //Faço +32 pois qualquer Letra maiuscula na tabela ASCII tem seu equivalente minusculo adicioonando 32 Ex: 'A' = 65 e 'a' = 97.
        }
    }
}
