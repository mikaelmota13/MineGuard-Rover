# MineGuard-Rover

# MineGuard Rover

O **MineGuard Rover** é um carro controlado remotamente desenvolvido para monitoramento de variáveis ambientais em minas subterrâneas, com o objetivo de garantir a segurança dos trabalhadores. Equipado com um ESP8266, o dispositivo coleta dados de diversas variáveis, como pressão atmosférica, temperatura, fluxo de ar, concentração de metano e CO2, altura em relação ao nível do ar e umidade relativa do ar. Esses dados são enviados para uma interface, onde são exibidos em tempo real no formato de dashboards, permitindo o monitoramento contínuo e a análise das condições da mina.

## Funcionalidades

- **Monitoramento Ambiental**: Coleta de dados em tempo real sobre:
  - Pressão atmosférica
  - Temperatura do ambiente
  - Fluxo de ar
  - Concentração de metano (CH₄)
  - Concentração de monóxido de carbono (CO)
  - Altura em relação ao nível do ar
  - Umidade relativa do ar
- **Interface de Visualização**: Envio de dados para uma interface web (Blynk) onde são exibidos dashboards interativos para monitoramento contínuo.
- **Controle Remoto**: O rover é controlado remotamente, via celular ou computador, para se deslocar pela mina e realizar medições em pontos estratégicos.
  
## Componentes

- **ESP8266** e **ESP32 DevKit V1**  : Usado para controle e comunicação com a interface web.
- **BME280**: Altitude em relção ao nivel d mar, pressão atmosférica, umidade e temperatura relativa do ar.
- **Anemometro arduino, com enconder ótico**: Para aferição de fluxo de ar.
- **Sensores MQ**: Para medir as cocetrações de gases no ambiente.
- **Estrutura do Rover**: Veículo controlado remotamente com capacidades de movimentação em ambientes subterrâneos.
- **Interface Web**: Dashboard para visualização dos dados coletados em tempo real ultilizando a plataforma Blynk.io.

## Tecnologias Utilizadas

- **Hardware**: ESP8266, ESP32 DevKit V1, BME280, MQ2, MQ9, Disco encoder e sensor ótico.
- **Software**: 
  - Programação em C/C++, Arduino IDE.
  - Blynk.io (para criação do dashboard).
  - Postgresql(para armazenamento dos dados coletados).
  - Comunicação via Wi-Fi para envio de dados em tempo real

## Como Funciona

1. **Coleta de Dados**: O MineGuard Rover, ao ser acionado, coleta dados de diversas variáveis ambientais utilizando os sensores integrados.
2. **Envio de Dados**: Esses dados são transmitidos via Wi-Fi utilizando o ESP32 para uma interface web.
3. **Exibição de Dados**: Na interface, os dados são organizados em dashboards interativos, permitindo o acompanhamento em tempo real da condição do ambiente subterrâneo.
