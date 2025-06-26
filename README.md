Arduino Cafe: Sistem Kontrol Lampu Cerdas untuk Kafe Anda

Selamat datang di Arduino Cafe, sebuah proyek inovatif yang menghadirkan kecerdasan ke dalam sistem pencahayaan kafe atau ruang hiburan Anda! Dengan memanfaatkan kekuatan ESP8266, proyek ini memungkinkan Anda mengontrol lampu secara nirkabel dan bahkan mengirimkan data ke server backend untuk analisis lebih lanjut.

✨ Fitur Unggulan

•
Kontrol Lampu Nirkabel: Nyalakan atau matikan lampu dengan mudah melalui antarmuka web.

•
Integrasi Backend: Kirim data sensor (misalnya, suhu dan kelembaban) ke server backend untuk pemantauan dan analisis.

•
Mudah Dikustomisasi: Sesuaikan ID lampu dan pin GPIO sesuai kebutuhan tata letak kafe Anda.

•
Konektivitas Wi-Fi: Terhubung ke jaringan Wi-Fi lokal untuk kontrol jarak jauh.

•
MDNS Support: Akses perangkat dengan nama host yang mudah diingat (misalnya, esp8266.local).

🛠️ Teknologi yang Digunakan

•
ESP8266: Mikrokontroler Wi-Fi yang kuat dan hemat biaya.

•
Arduino IDE: Lingkungan pengembangan untuk memprogram ESP8266.

•
ESP8266WiFi Library: Untuk konektivitas Wi-Fi.

•
ESP8266WebServer Library: Untuk membuat server web lokal.

•
ESP8266mDNS Library: Untuk penemuan perangkat melalui nama host.

•
ESP8266HTTPClient Library: Untuk komunikasi dengan server backend.

•
ArduinoJson Library: Untuk serialisasi dan deserialisasi data JSON.

🚀 Cara Memulai

Prasyarat

•
Papan pengembangan ESP8266 (misalnya, NodeMCU, ESP-01S).

•
Arduino IDE terinstal dengan dukungan papan ESP8266.

•
Library berikut terinstal di Arduino IDE:

•
ESP8266WiFi

•
ESP8266WebServer

•
ESP8266mDNS

•
ESP8266HTTPClient

•
ArduinoJson



Konfigurasi

1.
Buka file billiard_light_control_esp8266.ino di Arduino IDE.

2.
Ubah kredensial Wi-Fi Anda:

3.
Sesuaikan alamat IP dan port server backend jika Anda menggunakannya:

4.
Konfigurasi ID lampu dan pin GPIO sesuai dengan koneksi hardware Anda:

Unggah Kode

1.
Pilih papan ESP8266 yang benar dari menu Tools > Board.

2.
Pilih port serial yang benar dari menu Tools > Port.

3.
Unggah kode ke papan ESP8266 Anda.

💡 Penggunaan

Setelah kode berhasil diunggah dan ESP8266 terhubung ke Wi-Fi, Anda dapat mengontrol lampu melalui browser web atau aplikasi HTTP client:

•
Nyalakan Lampu: http://<IP_ESP8266>/lighton?lightid=<ID_Lampu>
Contoh: http://192.168.1.100/lighton?lightid=1

•
Matikan Lampu: http://<IP_ESP8266>/lightoff?lightid=<ID_Lampu>
Contoh: http://192.168.1.100/lightoff?lightid=1

Anda juga dapat menggunakan nama host MDNS http://esp8266.local jika diaktifkan di jaringan Anda.

🤝 Kontribusi

Kami menyambut kontribusi Anda untuk mengembangkan proyek ini! Silakan ajukan pull request atau laporkan issue jika Anda menemukan bug atau memiliki ide fitur baru.

📄 Lisensi

Proyek ini dilisensikan di bawah MIT License.

