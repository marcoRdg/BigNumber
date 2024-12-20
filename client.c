#include <stdio.h>
#include <stdlib.h>

#include "bignumber.h"

void lerEquacao(){
  
  char caracter1='0';
  
  while(1){
    
    BigNumber num1 = lerNumero();
    if(num1==NULL){
      break;
    }
    BigNumber num2 = lerNumero();
    //printBigNum(num1);
    //printBigNum(num2);

    BigNumber result;
    
    caracter1 = getchar();
    getchar();

    switch(caracter1){
      case '+':
        result = somar(num1,num2,'+');
        printBigNum(result);
        break;
      case '-':
        result = somar(num1,num2,'-');
        printBigNum(result);
        break;
      case '/':
        result = dividir(num1,num2,1);
        printBigNum(result);
        break;
      case '*':
        result = multiplicar(num1,num2);
        printBigNum(result);
        break;
      case '%':
        result = dividir(num1,num2,0);
        printBigNum(result);
        break;
      case '^':
        result = exponencial(num1,num2);
        printBigNum(result);
        break;
    }
    
    liberaMemoria(num1);
    liberaMemoria(num2);
    liberaMemoria(result);
    
  }
}

int main(){
  
  lerEquacao();
  return 0;
}
