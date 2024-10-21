#include <Arduino.h>
#include "BLEDevice.h"

#define DEVICE_NAME "CTS Client" // De advertentienaam van de PSoC 6
#define PSoC_ADDRESS "43:43:A1:12:1F:AC" // Het Bluetooth-adres van de PSoC 6
#define SERVICE_UUID "1800" // De UUID van de service
#define CHARACTERISTIC_UUID "2A01" // De UUID van het kenmerk

// Functie declaratie voor het lezen van een kenmerk
void readCharacteristic(BLEClient* pClient);

void setup() {
    Serial.begin(9600);
    BLEDevice::init("");

    // Maak een BLE-client aan
    BLEClient* pClient = BLEDevice::createClient();

    // Maak een BLEAddress object van de string
    BLEAddress address(PSoC_ADDRESS); // Omzetten naar BLEAddress

    // Probeer verbinding te maken met het opgegeven adres
    if (pClient->connect(address)) {
        Serial.println("Verbonden met PSoC 6!");

        // Hier kun je gegevens lezen
        readCharacteristic(pClient); // Voorbeeld om een kenmerk te lezen
    } else {
        Serial.println("Verbinding mislukt!");
    }
}

void loop() {
    // Loop logica hier
}

// Functie om een kenmerk te lezen
void readCharacteristic(BLEClient* pClient) {
    BLERemoteService* pRemoteService = pClient->getService(SERVICE_UUID);
    if (pRemoteService != nullptr) {
        BLERemoteCharacteristic* pRemoteCharacteristic = pRemoteService->getCharacteristic(CHARACTERISTIC_UUID);
        if (pRemoteCharacteristic != nullptr) {
            std::string value = pRemoteCharacteristic->readValue();
            Serial.print("Waarde gelezen: ");
            Serial.println(value.c_str());
        } else {
            Serial.println("Kenmerk niet gevonden!");
        }
    } else {
        Serial.println("Service niet gevonden!");
    }
}
