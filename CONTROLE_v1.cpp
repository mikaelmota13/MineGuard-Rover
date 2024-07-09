#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define IN1 D0  // GPIO5 (D0)
#define IN2 D3  // GPIO4 (D3)
#define IN3 D4  // GPIO0 (D4)
#define IN4 D8  // GPIO2 (D8)
#define ENA D6 // GPIO14 (D6)
#define ENB D7 // GPIO12 (D7)

int v = 80;  // Controla a velocidade (0-255)

const char* ssid = "brisa-3805226";
const char* password = "4rgg8y40";

ESP8266WebServer server(80);

void frente( int v){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, v);
  analogWrite(ENB, v);
  }

void tras(int v){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, v); 
  analogWrite(ENB, v);
  }

void para(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  analogWrite(ENA, 0); 
  }

void direita(int v){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 80);
  analogWrite(ENA, 0); // Controla a velocidade (0-255)
  delay(2000);
  }

void esquerda(int v){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  analogWrite(ENA, 80);
  }


void direcao(float x, float y, int b){
  if(x<= 1900 && y == 4095){
    Serial.println("direita");
    direita(v);
  }else if(x>1800 && y == 0){
    Serial.println("esquerda");
    esquerda(v);
  }else if(x>4000 && y <=2000){
    Serial.println("frente");
    frente(v);
  }else if(x==0 && y >=1800){
    Serial.println("atras");
    tras(v);
  }else if(b == 0){
    Serial.println("freia");
    para();
  }else{
    para();
  }
}

void handleUpdate() {
  if (server.hasArg("x") && server.hasArg("y") && server.hasArg("button")) {
    String xValue = server.arg("x");
    String yValue = server.arg("y");
    String buttonState = server.arg("button");

    float xEixo = xValue.toFloat();
    float yEixo = yValue.toFloat();
    int botao = buttonState.toInt();
    direcao(xEixo, yEixo, botao);
   
    Serial.print("X: ");
    Serial.print(xValue);
    Serial.print(" Y: ");
    Serial.print(yValue); 
    Serial.print(" Button: ");
    Serial.println(buttonState);

    // Aqui você pode adicionar o código para controlar dispositivos conectados ao ESP8266
    // com base nos valores recebidos.

    server.send(200, "text/plain", "Dados recebidos");
  } else {
    server.send(400, "text/plain", "Dados ausentes");
  }
}

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");
  Serial.println(WiFi.localIP());
  server.on("/update", handleUpdate);
  server.begin();

   // Configura os pinos de controle como saída
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Inicializa os pinos com valores baixos
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void loop() {
  server.handleClient();
}
