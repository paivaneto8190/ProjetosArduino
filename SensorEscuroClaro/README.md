# Sensor de detecção de luminosidade

Neste projeto usamos um sensor de luz para detectar a luminosidade do ambiente e imprimir as informações em uma tela de lcd 16x2 indicando se está escuro, clarenado ou se já está claro.

## Materiais
1. Arduíno UNO
2. 1 protoboard pequena (no nosso caso foi usada uma de 420 pinos)
3. 1 LED vermelho
4. 1 LED amarelo
5. 1 LED verde
6. 1 fotoresistor
7. 1 tela LCD 16x2
8. 3 resistências de 200 omhs
9. 1 resistência de 500 omhs
10. 1 resistência de 1000 omhs

## Montagem do circuito
Para a montagem do circuito, conectamos primeiramente a alimentação de 5v e o GND do arduíno alimentando as duas fileiras da protoboard para facilitar as conexões. 

### Montagem dos leds
Conectamos os leds nas portas 8 (LED verde), 9 (LED amarelo) e 10 (LED vermelho) do arduíno, todas ligadas a um resistor de 200 omhs cada para controlar a luminosidade, e colocamos os polos negativos dos LEDs na fileira ligada do GND.

### Montagem do LCD
No LCD, as duas primeiras portas usamos para alimentação, a terceira porta conectamos no GND já que não queremos mudar o nível de brilho das letras, a quarta porta conectamos na porta 7 do arduíno para controlar os comandos ao visor, a quinta porta conectamos no GND já que vamos setar apenas para escrita no visor, a sexta porta conectamos na porta 6. Após isso, pulamos 4 portas e setamos as portas DB4, DB5, DB6 e DB7 para envio de dados. As últimas duas portas referentes a iluminação do visor colocamos o positivo ligado a um resistor de 500 omhs e o negativo ao GND.

### Montagem do fotoresistor
No fotoresistor, alimentamos o sensor com 5 volts no terminal 2 e no terminal 1 colocamos um resistor de 1000 omhs para controlar a sensibilidade e ligamos a porta analógica A0 do arduíno.

Abaixo uma foto do circuito montado:
(COLOCAR FOTO AQUI)

## Código
O código completo está no arquivo "EscuroClaro_sensor.ino"

Na primeira parte do código incluímos a biblioteca para controlar o LCD, definimos a porta analógica do sensor de luz e as portas digitais dos LEDs, criamos a variável para armazenar o valor do sensor e criamos um objeto para facilitar a utilização das funções da biblioteca LiquidCrystal.h.

Na segunda parte do código, definimos as configurações do visor e do sensor, além de iniciarmos a comunicação serial para acompanhar os dados recebidos pelo fotoresistor.

Na terceira parte do código colocamos os comandos de ligar e desligar dos LEDs em estruturas condicionais, bem como os textos a serem exibidos na tela do visor. Configuramos também o sensor para recebimento e tratamento dos dados.

Obs: Os comandos dos LEDs estão em blocos cada um com um if e um else if, para podermos controlar o acionamento de cada um de forma independente.