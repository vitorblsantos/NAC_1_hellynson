// Define os pinos
const int pinoBeep = A5;
const int pinoLed = 9;
const int pinoLDR = A4;

// Função que retorna o valor da luminosidade.
int checkLuminosity() {
  //Map converte os valores para trabalhar de 0 a 100.
   return map(analogRead(pinoLDR), 921, 25, 0, 100);
}

// Função que interage com a porta do Piezo.
void beep(int active) {
  return digitalWrite(pinoBeep, active);
}

// Funcão que interage com a porta do Led.
void led(int active) {
  return digitalWrite(pinoLed, active);
}

// Função que reinicia o estado.
void reset() {
	beep(0);
}
  

void setup() {
  // Liga o led fixo.
  led(1);
  // Define os pinos
  pinMode(pinoBeep, OUTPUT);
  pinMode(pinoLed, OUTPUT);
  pinMode(pinoLDR, INPUT);
}   

void loop(){
  // Reinicia o estado.
  reset(); 
  
  // Verfica se a luminosidade é diferente de 100
  if(checkLuminosity() != 100) {
  	// Interage com o Piezo
    beep(1);
  }
}

