//Autor: Francisco Paiva da Silva Neto
//Data: 07/10/2021
//Objetivo: Indicar a luminosidade e colocar as informacoes no lcd

#include <LiquidCrystal.h>

#define pinPhoto A0

//Portas dos leds
const int ledVermelho = 10;
const int ledAmarelo = 9;
const int ledVerde = 8;

//Guarda valor do sensor
int valor;

//Cria objetos já com todas as funções
LiquidCrystal tela_lcd (7, 6, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  
  //Configura porta dos leds
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT); 

  //Configuracao foto resistor
  pinMode(pinPhoto, INPUT);

  //Configura tela lcd
  tela_lcd.begin(16,2);
}

void loop() {
  //Leitura e impressao do valor do sensor
  valor = analogRead(pinPhoto);
  Serial.println(valor); //Usei para calibrar o acionamento dos leds
  
  //Condicao para acionamento dos leds
  //Led vermelho
  if (valor >= 0 && valor < 227) {
    digitalWrite(ledVermelho, HIGH); //Poderia deixar fora do if, já que fica sempre ligado
    tela_lcd.print("Escuro");
  }

  //Led Amarelo
  if(valor >= 227 && valor < 600) {
    digitalWrite(ledAmarelo, HIGH);
    tela_lcd.print("Clareando...");
  }
  else if (valor < 227) {
    digitalWrite(ledAmarelo, LOW);
  }

  //Led verde
  if (valor >= 600){
    digitalWrite(ledVerde, HIGH);
    tela_lcd.print("Claro");
  }
  else if (valor < 600) {
    digitalWrite(ledVerde, LOW);
  }
  delay(700);
  tela_lcd.clear();
}
