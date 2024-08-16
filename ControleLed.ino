// O código será executado com base nos dados que estão sendo gerados e enviados pelo Python via porta serial.

#define led1 3
#define led2 5
#define led3 6
#define led4 9
#define led5 10

int incomingByte = 0; // para dados recebidos na porta Serial --> As informações geradas pelo Python passarão por essa variável

void setup() {
  Serial.begin(9600); //Inicializei a porta serial com a taxa de transmissão padrão de 9600 bps
  //Inicializei pinos pwm (para conseguir realizar o efeito de controle de luminosidade) como saída para cada LED
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  
  
}
void loop() {
  
  char serialInfo[1];
  // Serial.available retorna o número de bytes (caracteres) disponíveis para leitura da porta serial
  // Enviar resposta apenas quando receber dados:
  if (Serial.available() > 0) {
    // Lê caracteres da porta serial e os move para um buffer. A função termina se a quantidade de bytes determinada foi lida.
    // Retorna o NÚMERO de caracteres colocados no buffer, no qual 0 indica que os dados não foram encontrados
    // Parâmetros: 
    // Buffer (o buffer para se armazenar os bytes, podendo ser char[] ou byte[]) e length (número de bytes a serem lidos, devendo ser int)
    
    incomingByte = Serial.readBytes(serialInfo, 1); // Exemplo: serialInfo --> ['1','0','2']. Retorna 3 que foi a quantidade de caracteres colocados no buffer

    // Quando rodamos Serial.read() ou Serial.readBytes() há um retorno de um dígito.
    // Exemplo: Se o valor lido for 560, o primeiro Serial.read() irá retornar apenas 5, o segundo 6 e o terceiro 0

    // Abaixo irei converter o valor em char em cada uma das posições e converter para int:

    int d1 = serialInfo[0]-'0';

    // preciso verificar se o incomingByte não está vazio
    if(incomingByte > 0) {
      switch(d1)
      {
        case 0:
          digitalWrite(led1, LOW);
          digitalWrite(led2, LOW);
          digitalWrite(led3, LOW);
          digitalWrite(led4, LOW);
          digitalWrite(led5, LOW);
          break;
  
        case 1:
          analogWrite(led1, 64);
          analogWrite(led2, 64);
          analogWrite(led3, 64);
          analogWrite(led4, 64);
          analogWrite(led5, 64);
          break;
  
        case 2:
          analogWrite(led1, 128);
          analogWrite(led2, 128);
          analogWrite(led3, 128);
          analogWrite(led4, 128);
          analogWrite(led5, 128);
          break;
  
        case 3:
          analogWrite(led1, 192);
          analogWrite(led2, 192);
          analogWrite(led3, 192);
          analogWrite(led4, 192);
          analogWrite(led5, 192);
          break;
  
        case 4:
          digitalWrite(led1, HIGH);
          digitalWrite(led2, HIGH);
          digitalWrite(led3, HIGH);
          digitalWrite(led4, HIGH);
          digitalWrite(led5, HIGH);
          break;
       }
        delay(1);
      }
    }
 }
