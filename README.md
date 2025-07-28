
Progetto di Riconoscimento Vocale "Sì/No" con TinyML su ESP32
https://img.shields.io/badge/License-MIT-blue.svg
https://img.shields.io/badge/Edge%2520Impulse-TinyML-important
https://img.shields.io/badge/Platform-ESP32-green

Un progetto TinyML che riconosce le parole "sì" e "no" tramite un modello addestrato con Edge Impulse, eseguito su ESP32.
Non ho scritto l'SDK da zero, ma ho integrato il codice generato da Edge Impulse e compreso il suo funzionamento.

📌 Panoramica

Obiettivo: Classificare in tempo reale le parole "sì" e "no" usando un microcontrollore ESP32.
Tecnologie:
Edge Impulse per l'addestramento del modello TinyML.
ESP-IDF (o Arduino Core) per il firmware.
C++/C per l'integrazione dell'SDK.
Dataset: Registrazioni audio personalizzate (o dataset open-source).
🛠️ Struttura del Codice

Il progetto include:

Modello addestrato (model.h):
Esportato da Edge Impulse come array C (tflite_learn_4_tflite).
Include i pesi della rete neurale e la configurazione TFLite Micro.
Integrazione SDK (main.cpp):
Configurazione del segnale audio (signal_t).
Callback per l'acquisizione dati (get_data_callback).
Esecuzione dell'inferenza (run_classifier).
Logica principale:
Elaborazione audio e stampa dei risultati sulla seriale.
🔧 Funzionamento

Acquisizione Audio:
Il segnale viene campionato dal microfono (simulato nell'esempio con un array statico).
cpp
static float fake_audio[16000];  // Buffer fittizio (sostituire con dati reali)
Pre-Processing:
Edge Impulse applica automaticamente filtri (FFT, MFCC) prima dell'inferenza.
Classificazione:
Il modello TinyML eseguito sull'ESP32 restituisce la probabilità per "sì" e "no".
cpp
ei_impulse_result_t result;
run_classifier(&signal, &result, false);
Output:
Risultati stampati su seriale:
text
Risultato: sì (95.2%)
📚 Cosa Ho Imparato

Integrazione SDK: Come collegare un modello TinyML a un firmware embedded.
Ottimizzazione: Vincoli di memoria e potenza di calcolo su microcontrollori.
Workflow TinyML: Da dataset → addestramento → deployment su dispositivo.
Debugging: Analisi dei risultati e calibrazione del modello.
🚀 Come Replicare il Progetto

1. Addestramento del Modello (Edge Impulse)

Registrati su Edge Impulse.
Carica un dataset di audio "sì" e "no" (o usa il dataset pubblico).
Crea un modello con Impulse Design (blocchi di preprocessing + NN).
Esporta il modello come C++ Library.
2. Deployment su ESP32

Clona questo repository:
bash
git clone https://github.com/tuo-username/esp32-si-no-recognition.git
Apri il progetto con PlatformIO o ESP-IDF.
Sostituisci model.h con il tuo modello esportato.
Collega un microfono reale (es. INMP441) e modifica get_data_callback().
3. Monitoraggio

Apri il monitor seriale (115200 baud) per vedere i risultati.
📌 Note Importanti

Il codice usa dati simulati: Per un progetto reale, integra un microfono e un driver I2S.
Performance: L'accuratezza dipende dal dataset e dalla qualità dell'audio.
Ottimizzazioni: Riduci la dimensione del modello per adattarlo alla RAM dell'ESP32.
🤝 Contributi



Edge Impulse Documentation
ESP32 Audio Input Guide
#TinyML #EmbeddedAI #ESP32 #EdgeImpulse
