# Robot Servo Kontrol ve Melodi Projesi

Bu proje, Arduino kullanarak bir robotun servo motorlarıyla çeşitli hareketler yapmasını ve aynı zamanda buzzer ile farklı melodiler çalmasını sağlar. Bluetooth üzerinden komut gönderilerek robot yönlendirilebilir.

[![Proje Videosu](https://img.youtube.com/vi/VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=VIDEO_ID)


## Özellikler

- 4 farklı servo motor kontrolü (sağ bilek, sol bilek, sağ kasık, sol kasık)
- Buzzer ile 9 farklı melodi çalma (hazır ol, rahat ol, dans, sağa dön, sola dön, yürü, mutlu ol yeter, enerjik melodi vb.)
- Bluetooth seri bağlantı üzerinden kontrol
- Her komut için özel bir melodi ve hareket

## Gerekli Donanımlar

- Arduino UNO veya benzeri
- 4x Servo motor
- Buzzer
- Bluetooth modülü (HC-05/HC-06)
- Jumper kablolar

## Kurulum

1. `bedo.ino` dosyasını Arduino IDE ile açın.
2. Gerekli bağlantıları yapın (servo pinleri ve buzzer için A0).
3. Kodu Arduino'ya yükleyin.
4. Bluetooth üzerinden seri bağlantı ile komut gönderin (1-9 arası karakterler).

## Kullanım

| Komut | Açıklama         |
|-------|------------------|
| 1     | Hazır Ol         |
| 2     | Rahat Ol         |
| 3     | Dans Et          |
| 4     | Sağa Dön         |
| 5     | Sola Dön         |
| 6     | Eğlenceli Yürü   |
| 7     | İlerle           |
| 8     | Enerjik Melodi   |
| 9     | Mutlu Ol Yeter   |

## Lisans

Bu proje kişisel ve eğitim amaçlıdır. İzin almadan ticari olarak kullanılamaz.
