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

int notaSayisi = 8;
int kdo = 262;
int re = 294;
int mi = 330;
int fa = 349;
int sol = 392;
int la = 440;
int si = 494;
int ido = 523;

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
        calEglenceliMelodi();
        yuru();
        break;

      case '7':
      calYuruMelodi();
        ilerle();
        break;

      case '8':
      calEnerjikMelodi();
      break;

      case '9':
      mutluOlYeter();
      salin();
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
  for (int i = 0; i <= 10; i++){
  hareketliAyarlama(sagBilek, 70);
  hareketliAyarlama(solBilek, 70);
  hareketliAyarlama(solKasik, 70);
  hareketliAyarlama(sagKasik, 70);

  hareketliAyarlama(sagBilek, 100);
  hareketliAyarlama(solBilek, 100);
  hareketliAyarlama(solKasik, 100);
  hareketliAyarlama(sagKasik, 100);
  }


  Serial.println("Sağa dönüş tamamlandı.");
}

void ilerle(){
  for (int i = 0; i <= 10; i++){
  hareketliAyarlama(sagBilek, 100);
  hareketliAyarlama(solBilek, 100);
  hareketliAyarlama(solKasik, 100);
  hareketliAyarlama(sagKasik, 100);

  hareketliAyarlama(sagBilek, 80);
  hareketliAyarlama(solBilek, 80);
  hareketliAyarlama(solKasik, 80);
  hareketliAyarlama(sagKasik, 80);
  }
}

void solaDon() {
  Serial.println("Sola dönülüyor...");

  // Sola dönme hareketi
  hareketliAyarlama(sagBilek, 60);
  hareketliAyarlama(solBilek, 20);
  hareketliAyarlama(sagKasik, 70);
  hareketliAyarlama(solKasik, 50);
  delay(500);
  hareketliAyarlama(solBilek, 60);

  Serial.println("Sola dönüş tamamlandı.");
}

void sagAyakUstundeDur() {

  // Sola dönme hareketi
  hareketliAyarlama(sagBilek, 20);
  hareketliAyarlama(solBilek, 60);
  hareketliAyarlama(sagKasik, 50);
  hareketliAyarlama(solKasik, 70);
  delay(500);
  hareketliAyarlama(sagBilek, 60);

  Serial.println("Sola dönüş tamamlandı.");
}

void tekAyak(){
  for(int i = 0; i<= 1 ; i++){
  hareketliAyarlama(sagBilek, 40);
  hareketliAyarlama(solBilek, 110);
  hareketliAyarlama(sagKasik, 80);
  hareketliAyarlama(solKasik, 110);

  hareketliAyarlama(sagBilek, 110);
  hareketliAyarlama(solBilek, 40);
  hareketliAyarlama(sagKasik, 110);
  hareketliAyarlama(solKasik, 80);
}
  hareketliAyarlama(sagKasik, 40);
  hareketliAyarlama(sagBilek, 90);
}

void salin(){
  for(int i = 0; i<= 1 ; i++){
  hareketliAyarlama(sagBilek, 40);
  hareketliAyarlama(solBilek, 110);

  hareketliAyarlama(sagBilek, 110);
  hareketliAyarlama(solBilek, 40);
}
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

void calMutluMelodi() {
  // Mutlu melodi
  int frekanslar[] = {330, 349, 392, 440}; // E, F, G, A
  int sureler[] = {300, 300, 300, 400};

  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calHuzunluMelodi() {
  // Hüzünlü melodi
  int frekanslar[] = {392, 349, 330, 294}; // G, F, E, D
  int sureler[] = {400, 400, 400, 500};

  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calEnerjikMelodi() {
  // Enerjik melodi
  int frekanslar[] = {440, 494, 523, 440}; // A, B, C, A
  int sureler[] = {200, 200, 200, 300};

  for (int i = 0; i < 5; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  for (int i = 0; i < 5; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calGizemliMelodi() {
  // Gizemli melodi
  int frekanslar[] = {294, 330, 349, 330}; // D, E, F, E
  int sureler[] = {300, 300, 300, 400};

  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
}

void calEglenceliMelodi() {
  // Eğlenceli melodi
  int frekanslar[] = {392, 440, 494, 440}; // G, A, B, A
  int sureler[] = {250, 250, 250, 300};

  for (int i = 0; i < 4; i++) {
    tone(buzzerPin, frekanslar[i], sureler[i]);
    delay(sureler[i] + 50);
  }
  noTone(buzzerPin);
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

void mutluOlYeter(){
  tone(buzzerPin, mi);
    delay(1000);
    noTone(buzzerPin);
    delay(140); 








  
    tone(buzzerPin, mi);
    delay(233);
    noTone(buzzerPin);
    delay(140);  
      
    tone(buzzerPin, sol);
    delay(248);
    noTone(buzzerPin);
    delay(140);  
      
    tone(buzzerPin, si);
    delay(270);
    noTone(buzzerPin);
    delay(120);  

    tone(buzzerPin, sol);
    delay(250);
    noTone(buzzerPin);
    delay(180);  
   
    tone(buzzerPin, la);
    delay(690);
    noTone(buzzerPin);
    delay(30);  
      

    tone(buzzerPin, si);
    delay(200);
    noTone(buzzerPin);
    delay(500);  









    
   
    tone(buzzerPin, mi);
    delay(230);
    noTone(buzzerPin);
    delay(190);  

    tone(buzzerPin, sol);
    delay(130);
    noTone(buzzerPin);
    delay(220);  
   
    tone(buzzerPin, si);
    delay(230);
    noTone(buzzerPin);
    delay(135);  

    tone(buzzerPin, sol);
    delay(238);
    noTone(buzzerPin);
    delay(125);  
   
    tone(buzzerPin, la);
    delay(340);
    noTone(buzzerPin);
    delay(10);  

    tone(buzzerPin, si);
    delay(396);
    noTone(buzzerPin);
    delay(10);  
   
    tone(buzzerPin, sol);
    delay(144);
    noTone(buzzerPin);
    delay(34);  

    tone(buzzerPin, fa);
    delay(146);
    noTone(buzzerPin);
    delay(20);  
   
    tone(buzzerPin, mi);
    delay(225);
    noTone(buzzerPin);
    delay(145);  







    tone(buzzerPin, mi);
    delay(233);
    noTone(buzzerPin);
    delay(140);  
      
    tone(buzzerPin, sol);
    delay(248);
    noTone(buzzerPin);
    delay(140);  
      
    tone(buzzerPin, si);
    delay(270);
    noTone(buzzerPin);
    delay(120);  

    tone(buzzerPin, sol);
    delay(250);
    noTone(buzzerPin);
    delay(180);  
   
    tone(buzzerPin, la);
    delay(690);
    noTone(buzzerPin);
    delay(30);  
      

    tone(buzzerPin, si);
    delay(200);
    noTone(buzzerPin);
    delay(500);  
    
    
    
    
    
    
    
    
    tone(buzzerPin, mi);
    delay(230);
    noTone(buzzerPin);
    delay(190);  

    tone(buzzerPin, sol);
    delay(130);
    noTone(buzzerPin);
    delay(220);  
   
    tone(buzzerPin, si);
    delay(230);
    noTone(buzzerPin);
    delay(135);  

    tone(buzzerPin, sol);
    delay(238);
    noTone(buzzerPin);
    delay(125);  
   
    tone(buzzerPin, la);
    delay(340);
    noTone(buzzerPin);
    delay(10);  

    tone(buzzerPin, si);
    delay(396);
    noTone(buzzerPin);
    delay(10);  
   
    tone(buzzerPin, sol);
    delay(144);
    noTone(buzzerPin);
    delay(34);  

    tone(buzzerPin, fa);
    delay(146);
    noTone(buzzerPin);
    delay(20);  
   
    tone(buzzerPin, mi);
    delay(225);
    noTone(buzzerPin);
    delay(420);















   
   
    tone(buzzerPin, mi);
    delay(670);
    noTone(buzzerPin);
    delay(15);  

    tone(buzzerPin, la);
    delay(460);
    noTone(buzzerPin);
    delay(25);  
   
    tone(buzzerPin, sol);
    delay(636);
    noTone(buzzerPin);
    delay(50);  

    tone(buzzerPin, fa);
    delay(573);
    noTone(buzzerPin);
    delay(158);  
   
    tone(buzzerPin, fa);
    delay(1080);
    noTone(buzzerPin);
    delay(20);  

    tone(buzzerPin, si);
    delay(410);
    noTone(buzzerPin);
    delay(60);  
   
    tone(buzzerPin, la);
    delay(563);
    noTone(buzzerPin);
    delay(40);  

    tone(buzzerPin, sol);
    delay(385);
    noTone(buzzerPin);
    delay(336);  










   
    tone(buzzerPin, si);
    delay(896);
    noTone(buzzerPin);
    delay(50);  

    tone(buzzerPin, si);
    delay(147);
    noTone(buzzerPin);
    delay(55);  
   
    tone(buzzerPin, la);
    delay(112);
    noTone(buzzerPin);
    delay(75);  

    tone(buzzerPin, la);
    delay(934);
    noTone(buzzerPin);
    delay(87);  
   
    tone(buzzerPin, la);
    delay(169);
    noTone(buzzerPin);
    delay(66);  

    tone(buzzerPin, sol);
    delay(164);
    noTone(buzzerPin);
    delay(60);  
   
    tone(buzzerPin, si);
    delay(724);
    noTone(buzzerPin);
    delay(82);  

    tone(buzzerPin, si);
    delay(156);
    noTone(buzzerPin);
    delay(49);  
   
    tone(buzzerPin, la);
    delay(126);
    noTone(buzzerPin);
    delay(60);  

    tone(buzzerPin, la);
    delay(705);
    noTone(buzzerPin);
    delay(257);  
   
    tone(buzzerPin, la);
    delay(142);
    noTone(buzzerPin);
    delay(68);  

    tone(buzzerPin, sol);
    delay(106);
    noTone(buzzerPin);
    delay(79);  
   
    tone(buzzerPin, sol);
    delay(874);
    noTone(buzzerPin);
    delay(25);  

    tone(buzzerPin, la);
    delay(309);
    noTone(buzzerPin);
    delay(46);  
   
    tone(buzzerPin, fa);
    delay(642);
    noTone(buzzerPin);
    delay(25);  

    tone(buzzerPin, mi);
    delay(285);
    noTone(buzzerPin);
    delay(431);  













    tone(buzzerPin, mi);
    delay(670);
    noTone(buzzerPin);
    delay(15);  

    tone(buzzerPin, la);
    delay(460);
    noTone(buzzerPin);
    delay(25);  
   
    tone(buzzerPin, sol);
    delay(636);
    noTone(buzzerPin);
    delay(50);  

    tone(buzzerPin, fa);
    delay(573);
    noTone(buzzerPin);
    delay(158);  
   
    tone(buzzerPin, fa);
    delay(1080);
    noTone(buzzerPin);
    delay(20);  

    tone(buzzerPin, si);
    delay(410);
    noTone(buzzerPin);
    delay(60);  
   
    tone(buzzerPin, la);
    delay(563);
    noTone(buzzerPin);
    delay(40);  

    tone(buzzerPin, sol);
    delay(385);
    noTone(buzzerPin);
    delay(336);  

  






  
   
    tone(buzzerPin, si);
    delay(896);
    noTone(buzzerPin);
    delay(50);  

    tone(buzzerPin, si);
    delay(147);
    noTone(buzzerPin);
    delay(55);  
   
    tone(buzzerPin, la);
    delay(112);
    noTone(buzzerPin);
    delay(75);  

    tone(buzzerPin, la);
    delay(934);
    noTone(buzzerPin);
    delay(87);  
   
    tone(buzzerPin, la);
    delay(169);
    noTone(buzzerPin);
    delay(66);  

    tone(buzzerPin, sol);
    delay(164);
    noTone(buzzerPin);
    delay(60);  
   
    tone(buzzerPin, si);
    delay(724);
    noTone(buzzerPin);
    delay(82);  

    tone(buzzerPin, si);
    delay(156);
    noTone(buzzerPin);
    delay(49);  
   
    tone(buzzerPin, la);
    delay(126);
    noTone(buzzerPin);
    delay(60);  

    tone(buzzerPin, la);
    delay(705);
    noTone(buzzerPin);
    delay(257);  
   
    tone(buzzerPin, la);
    delay(142);
    noTone(buzzerPin);
    delay(68);  

    tone(buzzerPin, sol);
    delay(106);
    noTone(buzzerPin);
    delay(79);  
   
    tone(buzzerPin, sol);
    delay(874);
    noTone(buzzerPin);
    delay(25);  

    tone(buzzerPin, la);
    delay(309);
    noTone(buzzerPin);
    delay(46);  
   
    tone(buzzerPin, fa);
    delay(642);
    noTone(buzzerPin);
    delay(25);  

    tone(buzzerPin, mi);
    delay(285);
    noTone(buzzerPin);
    delay(340);  









 

    tone(buzzerPin, mi);
    delay(126);
    noTone(buzzerPin);
    delay(20);  
   
    tone(buzzerPin, fa);
    delay(100);
    noTone(buzzerPin);
    delay(30);  

    tone(buzzerPin, sol);
    delay(75);
    noTone(buzzerPin);
    delay(20);  
   
    tone(buzzerPin, fa);
    delay(68);
    noTone(buzzerPin);
    delay(25);  

    tone(buzzerPin, mi);
    delay(994);
    noTone(buzzerPin);
    delay(377);  
   
    tone(buzzerPin, re);
    delay(317);
    noTone(buzzerPin);
    delay(87);  

    tone(buzzerPin, mi);
    delay(284);
    noTone(buzzerPin);
    delay(49);  
   
    tone(buzzerPin, fa);
    delay(328);
    noTone(buzzerPin);
    delay(150);  

    tone(buzzerPin, sol);
    delay(1480);
    noTone(buzzerPin);
  

}

