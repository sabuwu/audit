# Fase 1 — Sensor de Ruído (Operário)

Objetivo:
Transformar o sinal analógico do microfone em um nível de ruído confiável.

---

## Captura do Áudio

- Ler o pino analógico A0.
- Não utilizar leitura única.
- Utilizar janela de amostragem.

Processo:

1. Capturar valores durante 50~100ms.
2. Encontrar:
    - Valor máximo.
    - Valor mínimo.

3. Calcular:

Vpp = máximo - mínimo

---

## Tratamento do Sinal

Aplicar Média Móvel Exponencial (EMA).

Objetivos:

- Remover oscilações rápidas.
- Evitar falsos positivos.
- Detectar tendência real do ambiente.

Configuração inicial:

alpha = 0.1

---

## Calibração

Criar modo de calibração:

- Medir silêncio da sala.
- Medir aula normal.
- Medir conversa.
- Medir ruído extremo.

Salvar limites:

BAIXO
MÉDIO
ALTO
CRÍTICO

---

## Classificação

Entrada:

EMA do Vpp

Saída:

Estado do ambiente:

NORMAL
ALTO
CRÍTICO


Mapeamento:

NORMAL:
LED Verde

ATENÇÃO:
LED Amarelo

ALTO:
LED Vermelho

CRÍTICO:
LED Roxo


---

# Fase 2 — Máquina de Estados

Substituir classificação simples por estados:

NORMAL

↓

VERMELHO

↓

ROXO

↓

OBSERVAÇÃO

↓

NORMAL


Cada mudança de estado gera um evento.

---

# Fase 3 — Eventos

O sensor não envia valores constantemente.

Enviar apenas:

- Entrada em vermelho.
- Saída do vermelho.
- Entrada em roxo.
- Saída do roxo.
- Silêncio detectado.
- Infração.
- Diretoria acionada.

---

# Fase 4 — Integração Colmeia

Adicionar:

- Wi-Fi.
- MQTT.
- Comunicação com Rainha.

O Operário:

Detecta evento

↓

Envia para Rainha

↓

Continua monitorando

---

# Fase 5 — Otimização

Adicionar:

- Filtro melhorado.
- Sleep de Wi-Fi.
- Heartbeat.
- Economia de energia.
- Configuração remota dos thresholds.