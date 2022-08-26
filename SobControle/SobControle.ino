
/*
 * ------------ PROJETO DE FÍSICA EXPERIMENTAL 3 ----------------
 * -------- AUTOMAÇÃO RESIDENCIAL COM CONTROLE REMOTO -----------
 * -------------- AUTOR: MARLON CAMPOS PEREIRA ------------------
*/

// Inclusão da biblioteca do Infravermelho
#include <IRremote.h>

// Definição e inicialização das variáveis
int const PIN_LAMP = 6;
int const PIN_VENT = 9;
int PIN_REC = 11;

// Variáveis de controle
bool STATUS_LAMP = false;
bool STATUS_VENT = false;

// Passando o pino correspondente ao receptor na função
IRrecv irrecv(PIN_REC);

// Instanciando a variável responsável pela recepção dos comandos
decode_results results;

// Configuração inicial 
void setup()
{
  Serial.begin(9600);               // Iniciando o monitor serial
  pinMode(PIN_LAMP, OUTPUT);        // Definindo o pino da lâmpada (6) como saída
  pinMode(PIN_VENT, OUTPUT);        // Definindo o pino do ventilador (9) como saída
  irrecv.enableIRIn();              // Habilitando o sensor para recebimento de comandos

  Serial.println("Olá, querido cliente!");
  delay(1000);
  Serial.println("Seja bem-vindo ao sistema SobControle");
  Serial.println(" ");
  delay(1000);
  Serial.println("Pressione o botão VERMELHO para LIGAR/DESLIGAR a LAMPADA");
  delay(1000);
  Serial.println("E o botão CINZA para LIGAR/DESLIGAR o VENTILADOR.");
  Serial.println(" ");
}

// Parte principal do código
void loop() {

  // Verificação da recepção do sinal pelo infravermelho
  if (irrecv.decode(&results)) {


   // ********** LÂMPADA **********

   // CONTROLE
    if(results.value == 0x807F02FD){
        if(STATUS_LAMP == false){
          STATUS_LAMP = true;
          digitalWrite(PIN_LAMP, HIGH);
          Serial.println("Lampada LIGADA");
        }else{
          STATUS_LAMP = false;
          digitalWrite(PIN_LAMP, LOW);
          Serial.println("Lampada DESLIGADA");
      }
    }

   // CELULAR
    if(results.value == 0x807FC03F){
        if(STATUS_LAMP == false){
          STATUS_LAMP = true;
          digitalWrite(PIN_LAMP, HIGH);
          Serial.println("Lampada LIGADA");
        }else{
          STATUS_LAMP = false;
          digitalWrite(PIN_LAMP, LOW);
          Serial.println("Lampada DESLIGADA");
      }
    }


     // ********** VENTILADOR **********

     // CONTROLE
     if(results.value == 0x807F8F70){
        if(STATUS_VENT == false){
          STATUS_VENT = true;
          digitalWrite(PIN_VENT, HIGH);
          Serial.println("Ventilador LIGADO");
        }else{
          STATUS_VENT = false;
          digitalWrite(PIN_VENT, LOW);
          Serial.println("Ventilador DESLIGADO");
      }
    }

      // CELULAR
       if(results.value == 0x807FF00F){
        if(STATUS_VENT == false){
          STATUS_VENT = true;
          digitalWrite(PIN_VENT, HIGH);
          Serial.println("Ventilador LIGADO");
        }else{
          STATUS_VENT = false;
          digitalWrite(PIN_VENT, LOW);
          Serial.println("Ventilador DESLIGADO");
      }
    }

    irrecv.resume(); // Reseta o receptor para a próxima leitura
  }
  delay(100);
}
