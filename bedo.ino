#include <Servo.h>

// Servo nesneleri
Servo sagBilek;
Servo solBilek;
Servo sagKasik;
Servo solKasik;

// Servo pinleri
const int sagBilekPin = 5;
const int solBilekPin = 10;
const int sagKasikPin = 11;
const int solKasikPin = 12;
const int buzzerPin = A0;

void setup() {
  // Bluetooth haberleşme başlatılıyor
  Serial.begin(9600);

  // Buzzer pinini çıkış olarak ayarlıyoruz
  pinMode(buzzerPin, OUTPUT);

  // Servolar tanımlanıyor
  sagBilek.attach(sagBilekPin);
  solBilek.attach(solBilekPin);
  sagKasik.attach(sagKasikPin);
  solKasik.attach(solKasikPin);

  // Servolar başlangıç pozisyonlarına ayarlanıyor
  sagBilek.write(90);
  solBilek.write(90);
  sagKasik.write(90);
  solKasik.write(90);

  Serial.println("Servo kontrolü hazır. Bluetooth bağlantısı bekleniyor...");
}

void loop() {
  // Bluetooth'tan gelen veri kontrol ediliyor
  if (Serial.available()) {
    char komut = Serial.read();
    
    switch (komut) {
      case '1':
        calHazirOlMelodi();
        hazirOl();
        break;

      case '2':
        calRahatOlMelodi();
        rahatOl();
        break;

      case '3':
        calDansMelodi();
        dansEt();
        break;

      case '4':
        calSagaDonMelodi();
        sagaDon();
        break;

      case '5':
        calSolaDonMelodi();
        solaDon();
        break;

      case '6':
        calYuruMelodi();
        yuru();
        break;

      default:
        Serial.println("Geçersiz komut!");
        break;
    }
  }
}

void calHazirOlMelodi() {
  // Hazır ol melodisi
  int frekanslar[] = {440, 494, 523}; // A, B, C
  int sureler[] = {200, 200, 400};

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calRahatOlMelodi() {
  // Rahat ol melodisi
  int frekanslar[] = {330, 349, 392}; // E, F, G
  int sureler[] = {300, 300, 500};

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calDansMelodi() {
  // Dans melodisi
  int frekanslar[] = {262, 294, 330}; // C, D, E
  int sureler[] = {200, 200, 300};

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calSagaDonMelodi() {
  // Sağa dön melodisi
  int frekanslar[] = {349, 392, 440}; // F, G, A
  int sureler[] = {250, 250, 400};

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calSolaDonMelodi() {
  // Sola dön melodisi
  int frekanslar[] = {440, 392, 349}; // A, G, F
  int sureler[] = {250, 250, 400};

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calYuruMelodi() {
  // Yürüme melodisi
  int frekanslar[] = {262, 294, 330, 294}; // C, D, E, D
  int sureler[] = {200, 200, 300, 200};

  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void hazirOl() {
  Serial.println("Hazır ol pozisyonuna geçiliyor...");

  // "Hazır ol" pozisyonu için servo açıları sırayla ayarlanıyor
  hareketliAyarlama(sagBilek, 110);
  hareketliAyarlama(solBilek, 70);
  hareketliAyarlama(sagKasik, 80);
  hareketliAyarlama(solKasik, 80);

  Serial.println("Hazır ol pozisyonu tamamlandı.");
}

void rahatOl() {
  Serial.println("Rahat pozisyonuna geçiliyor...");

  // "Rahat ol" pozisyonu için servo açıları sırayla ayarlanıyor
  hareketliAyarlama(sagBilek, 90);
  hareketliAyarlama(solBilek, 90);
  hareketliAyarlama(sagKasik, 60);
  hareketliAyarlama(solKasik, 120);

  Serial.println("Rahat pozisyonu tamamlandı.");
}

void dansEt() {
  Serial.println("Dans etmeye başlıyor...");

  // Basit bir dans hareketi
  for (int i = 0; i < 5; i++) {
    hareketliAyarlama(sagBilek, 60);
    hareketliAyarlama(solBilek, 120);
    hareketliAyarlama(sagKasik, 70);
    hareketliAyarlama(solKasik, 110);

    hareketliAyarlama(sagBilek, 120);
    hareketliAyarlama(solBilek, 60);
    hareketliAyarlama(sagKasik, 110);
    hareketliAyarlama(solKasik, 70);
  }

  Serial.println("Dans hareketi tamamlandı.");
}

void sagaDon() {
  Serial.println("Sağa dönülüyor...");

  // Sağa dönme hareketi
  hareketliAyarlama(sagBilek, 120);
  hareketliAyarlama(solBilek, 120);
  hareketliAyarlama(sagKasik, 120);
  hareketliAyarlama(solKasik, 120);

  Serial.println("Sağa dönüş tamamlandı.");
}

void solaDon() {
  Serial.println("Sola dönülüyor...");

  // Sola dönme hareketi
  hareketliAyarlama(sagBilek, 60);
  hareketliAyarlama(solBilek, 60);
  hareketliAyarlama(sagKasik, 60);
  hareketliAyarlama(solKasik, 60);

  Serial.println("Sola dönüş tamamlandı.");
}

void yuru() {
  Serial.println("Yürüme hareketine geçiliyor...");

  // Sadece sağ bilek hareketi ile itme hareketi simülasyonu
  for (int i = 0; i < 4; i++) {
    hareketliAyarlama(sagBilek, 60); // Sağ bileği iter
    delay(300);

    hareketliAyarlama(sagBilek, 120); // Sağ bileği geri çeker
    delay(300);
  }

  Serial.println("Yürüme hareketi tamamlandı.");
}

void hareketliAyarlama(Servo &servo, int hedefAci) {
  int mevcutAci = servo.read();
  int adim = (hedefAci > mevcutAci) ? 1 : -1;

  while (mevcutAci != hedefAci) {
    mevcutAci += adim;
    servo.write(mevcutAci);
    delay(10); // Hareketin yavaş olması için kısa bir bekleme
  }
}