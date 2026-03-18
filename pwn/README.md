# Pwn - Gemaa

## Deskripsi
Gemaa adalah soal yang membutuhkan _netcat service_. Jalankan file `files/gema` yang merupakan hasil kompilasi dari `files/gema.cpp` sehingga dapat diakses dengan menggunakan `netcat` melalui jaringan di luar container. Anda dapat menggunakan `socat` atau program lain yang Anda ketahui.

Soal ini akan di-deploy menggunakan instancer dengan dynamic flag. Dynamic flag merupakan flag yang stringnya akan berbeda untuk setiap instance yang di-spawn. Dynamic flag yang digunakan oleh challenge ini memiliki format `COMPFEST18{tc_pwm_<random_16>}` dimana `<random_16>` merupakan bagian dari flag yang akan berbeda di setiap instance. Plugin instancer yang digunakan sudah terintegrasi dengan ctfd dan dokumentasinya dapat dilihat [disini](https://github.com/ctf-compfest-18/ctfd/blob/main/CTFd%2Fplugins%2Fcontainers%2FREADME.md)

Instancer tersebut akan menyimpan flag dalam env variable `FLAG`, maka anda juga harus membuat init script yang akan menuliskan isi `FLAG` ke dalam file `flag.txt`
_Service_ dinyatakan berhasil dipasang apabila saat dilakukan `nc <IP SERVER> <MACHINE PORT>` (Windows: `netcat <IP SERVER> <MACHINE PORT>`) akan mengembalikan respon berikut:
```
WELCOME WELCome Welcome welcome...
FLAG: COMPFEST18{tc_pwm_<random_4_char_hex>}
Enter 'exit' if you want to exit.
>>
```

## Spesifikasi Dockerfile
- OS: Ubuntu 18.04
- User: compfest18
- Container port: 4321
- Working directory: /home/compfest18
- Gunakan container port sebagai listening port untuk `socat` atau program sejenis


## Referensi
- [Netcat](https://en.wikipedia.org/wiki/Netcat)
- [Socat](https://www.redhat.com/sysadmin/getting-started-socat)
