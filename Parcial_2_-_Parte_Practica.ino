//Incluimos Variales Globales
//Ultrasonico
const int Trigger = 2;
const int Eco = 3;
int x = 0; 

//Leds
int Rojo = 9;
int Ama = 8;
int Verde = 7;

//Potenciometro
const int potenciometro = A3;
int valorPotenciometro;

void setup() {

  //Iniciamos Puerto de Comunicacion Serial
  Serial.begin(9600);

  //Entradas y Salidas del Modulo y Leds
  pinMode(Trigger, OUTPUT);
  pinMode(Eco, INPUT);

  pinMode(Rojo, OUTPUT);
  pinMode(Ama, OUTPUT);
  pinMode(Verde, OUTPUT);

  digitalWrite(Rojo, LOW);
  digitalWrite(Ama, LOW);
  digitalWrite(Verde, LOW);
  
  digitalWrite(Trigger,LOW);

}

void loop() {

  //Obtener Distancia de Objetos del Ultrasónico
  long t;
  long d;
  
  digitalWrite(Trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);
  
  t = pulseIn(Eco,HIGH);
  d = t / 59;

  //Mostramos en puerto Serial la distancia
  Serial.print("La distancia del objeto es de: ");
  Serial.print(d);
  Serial.print(" centrimetros ////////////// ");


  // Lee el valor del potenciómetro y lo envía a Processing a través del puerto serie
  valorPotenciometro = analogRead(potenciometro);
  Serial.print(" El Valor del Potenciómetro es: ");
  Serial.println(valorPotenciometro);
  delay(50); // Pequeña pausa para evitar una transmisión muy rápida de datos por el puerto serie

  if(valorPotenciometro > 30 && valorPotenciometro < 400){ //Encender Led Roja
    digitalWrite(Rojo,HIGH);
    digitalWrite(Ama,LOW);
    digitalWrite(Verde,LOW);
  }

  if(valorPotenciometro > 401 && valorPotenciometro < 800){ //Encender Led Amarilla
    digitalWrite(Rojo,LOW);
    digitalWrite(Ama,HIGH);
    digitalWrite(Verde,LOW);
  }

  if(valorPotenciometro > 801 && valorPotenciometro < 1200){ //Encender Led Verde
    digitalWrite(Rojo,LOW);
    digitalWrite(Ama,LOW);
    digitalWrite(Verde,HIGH);
  }

  
  
}
