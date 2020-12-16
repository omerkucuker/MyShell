## Myshell Programı Hakkında
Bu projede kendi komutlarımızı oluşturduğumuz, fork ve exec yapısını kullanarak farklı
programları çağırabileceğimiz C dilinde Shell programlanması amaçlanmaktadır. Projede beş
adet programımız bulunmaktadır; myshell.c, işlem.c, topla.c, cikar.c ve tekrar.c
Ana programımız olan myshell üzerinden komut listesi ve diğer programlar çağrılmaktadır.
Komut dizimizde help, exit, tekrar ve işlem komutları yer almaktadır. Help komutu
çağrıldığında Shell’de yer alan komutlar sıralanmaktadır. Exit komutu çağrılana kadar Shell
çalışmaya devam etmektedir. Exit çağrıldığında Shell’den çıkılmaktadır.

**Tekrar** komutu iki parametre almaktadır. İlk parametre terminale yazılacak olanı, ikincisi ise
ilk parametrenin kaç defa yazılacağını bildirmektedir. Myshell üzerinden tekrar komutu
çağrıldığında fork yapılarak yeni process oluşturulur ve tekrar.c programı çağrılır.

**İşlem** komutu üç parametre almaktadır. İlk parametre topla veya cikar, ikinci ve üçüncü
parametreler ise toplama/çıkarma işleminde kullanılacak olan sayıların girilmesidir. Topla
komutu çağrıldığında myshell.c üzerinden fork yapılarak topla.c programına parametreler
gönderilir ve topla işlemi yapılarak ekrana sonucu döndürülür. Aynı şekilde cikar komutu
çağrıldığında ana programdan fork yapılarak cikar.c programına parametre olarak iki sayı
gönderilir ve işlemin sonucu terminalde gösterilir.

**Clear** komutu çağrıldığında Linux işletim siteminde yer alan bin klasörünün altında bulunan
clear komutu çağrılır ve terminaldeki kodlar temizlenir. Cat komutu çağrıldığında da aynı
şekilde bin klasörünün altından komut çağrılır ve cat komutuyla birlikte girilen parametredeki
dosyanın içindeki metin terminalde gösterilir. Echo komutu da benzer şekilde girilen
parametreyi terminalde göstermektedir.
Programın her defasında bütün dosyaları tek tek derlemesini kolaylaştırmak adına makefile
dosyası hazırlanmış olup, program makefile üzerinden çalıştırılabilir.

Birden fazla parametrenin çalıştırılması amacıyla satır okuma fonksiyonu olan readLine[*]
fonksiyonunda while döngüsüne | koşulu da eklenmiş olup böylelikle iki komut parametleriyle
birlikte | işaretiyle ayrı yazıldığında birlikte çalışmaktadır.
Terminal ekranında girilen parametreler arasındaki boşlukları kontrol için splitLine[*]
fonksiyonunda tokenize işlemi yapılmıştır.

![SS1](https://github.com/omerkucuker/MyShell/blob/main/screens/myshell_ss.png?raw=true)
![SS2](https://github.com/omerkucuker/MyShell/blob/main/screens/myshell_catkomutu.PNG?raw=true)


