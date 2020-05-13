// Define os pinos
const int pinoPiezo = A4;
const int pinoLedFixo = 9;
const int pinoLedAlternativo = A5;
const int pinoLDR = A3;

// Função que retorna o valor da luminosidade.
int checkLuminosity() {
  //Map converte os valores para trabalhar de 0 a 100.
   return map(analogRead(pinoLDR), 921, 25, 0, 100);
}

// Função que interage com a porta do Piezo.
void beep() {
  return digitalWrite(pinoBeep, 1);
}

// Funcão que interage com a porta do Led.
void led(int active) {
  return digitalWrite(pinoLed, active);
}


// Funcão que interage com a porta do Led Fixo.
void ledFixed(int active) {
  return digitalWrite(pinoLedFixo, active);
}

// Função que reinicia o estado.
void reset() {
  beep(0);
  led(0);
}
  

void setup() {
	// Liga o led fixo.
  ledFixed(1);
	// Define os pinos
  pinMode(pinoPiezo, OUTPUT);
  pinMode(pinoLDR, INPUT);
  pinMode(pinoLedFixo, OUTPUT);
  pinMode(pinoLedAlternativo, OUTPUT);
}   

void loop(){
	// Reinicia o estado.
  reset();
	// Verfica se a luminosidade é diferente de 100
  if(checkLuminosity() != 100) {
		// Interage com o Piezo
    beep(1);
		// Interage com o led
    led(1);
		// espera um 500ms
    delay(500);
		// reincia o estado
    reset();
		// espera um 500ms
    delay(500);
  }
}
