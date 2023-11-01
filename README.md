## **Const**
*const* bir tür niteleyicisi olarak kullanıldığı o değerin değiştirilmemesini sağlar.

    const char a = 'a'; //değiştirilemez.
### **const char * / char const * farkı**
*const char \** bir 'const char'ı işaret eder yani burda değiştirilemez olan şey işaretlenen değerimizken *char const \** ise normal 'char'ı işaret eder ve burda da değiştirilemez olan şey işaretçinin kendisidir.

## **Type Casting**
Veri tipi dönüşümü normalde otomatik olarak(Impilict Type Casting) yapılır fakat bunun bir kuralı vardır. Düşük boyutlu veri tipinden büyük boyutlu veri tipine göre olur. Sebebi ise büyük boyutlu veri tiplerin aralığı daha geniştir ve tersi bir durumda veri kaybına sebep olabilir.
Eğer biz büyük veri tipini küçük bir veri tipine dönüştürmek istersek girilen değeri küçük veri tipinin sınırları içerine girene kadar çıkartır. Örneğin

	int	i;
	char a;
	i = 289;
	a = (char)i;
şeklinde bir dönüşüm yaparsak 289 sayısını charın değer aralığına girene kadar 256 ile çıkartır.(Bu diğer verilede onların max aralığı olarak değişir.)
Başka bir örnekse float->int baklılabilir. Çünkü bu durumda biz ondalık kısmı kaybederiz.
([bknz.](https://www.geeksforgeeks.org/type-conversion-c/)) 

## **Pointer Aritmatiği**
Pointer aritmatiği aslında adres kaydırma diyebiliriz. Örnek olarak 

    char *ptr = "aritmatik";
    ptr++;
***aritmatik*** diye bir char array oluşturduk. Bu arrayin ilk harfinin adresi 1001 olsun. Bu ptr değişkenin(pointerın) içinde **1001** sayısını bulunacaktır. Ardından **ptr++** ile biz adresi kaydırarak ptrnin içine **1002** yazdırmış oluruz.
Burda karıştırılmaması gereken kısım adresin artış miktarının her zaman bir olmamasıdır. Biz **ptr++** ile 1 eleman kaydır demiş olduk charlar ise 1 byte olduğundan adres de 1 artmış oldu(bir adres bloğu = bir byte). Eğer bir integer array ile bu işlemi yapsaydık 1002 değil **1005** olacaktı(int 4 byte).
***Pointer kaç bytetır?***
## **File Descriptor**
Dosya Tanımlayıcısı, dosyalara veya diğer input/output kaynaklarına erişmek için kullanılan bir tamsayıdır(Birnevi kimlik). Fd'nin bazı default atamaları vardır.
	
	0 = Standart Giriş - Klavyeden okuma
	1 = Standart Çıkış - Ekrana yazdırma
	2 = Standart Hata - Hata mesajı yazdırma
Bu fd'leri 'open()' tarzı fonksiyonlarla elde edebiliriz.
### **Open**
Open fonksiyonun tanımı şu şekildedir:

	int open(const char *path, int flags, mode_t mode);
Buradaki path argümanı dosyanın açılacağı dizini ve adını belirler, flags parametresi dosyanın açılma modunu ve ne türde erişim yapılacağını belirtir, mode parametresi içe dosya açıldığında izinlerin belirlenmesini sağlar(chmod fonksiyonundaki parametreler gibi). (Detaylı açıklama için [bknz.](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/#opening_or_creating_a_file_in_c)) Aşağıdakiler genel olarak kullanılan flags parametreleridir.

    O_RDONLY: Dosyayı sadece okuma modunda açar. Dosyanın içeriği değiştirilemez, sadece okunabilir.

    O_WRONLY: Dosyayı sadece yazma modunda açar. Dosyanın içeriği okunamaz, sadece değiştirilebilir.

    O_RDWR: Dosyayı hem okuma hem de yazma modunda açar. Dosya içeriğini okuyabilir ve değiştirebilirsiniz.

    O_CREAT: Eğer dosya yoksa, yeni bir dosya oluşturur. Bu bayrak, dosya açma işleminin yeni bir dosya oluşturma işlemi için kullanılacağını belirtir.

    O_TRUNC: Dosya varsa, içeriğini temizler (sıfırlar). Dosyayı açarken içeriği silmek ve dosyayı boşaltmak için kullanılır.

    O_APPEND: Dosya varsa, dosyanın sonuna ekler. Yani, her yazma işlemi dosyanın sonuna eklenir, varolan içeriği değiştirmez.

    O_EXCL: Dosya varsa, hata döndürür. Bu bayrak, O_CREAT bayrağıyla birlikte kullanılır ve eğer dosya zaten varsa hata döndürür.

## **Mem ve Str Fonksiyonları**
Bu iki fonksiyon arasıdaki genel farklardan en temeli 'str'ler char veya char arrayler üzerinde işlem yapılabilir şekilde ayarlanmıştır(null-terminated olduğu için). 'mem' fonksiyonları ise tek tek memory blocklarını kontrol eder. 2 farklı int bir değeri cmp yaptığınızda her bir byte bloğu aynıysa eşit çıktısını verir.(4 byte'ı tek tek kontrol eder.)

## **Overlap**
Overlap durumu kısaca srctan dstye kopyalama yaparken srcnin değişmesidir. "merhaba" kelimesinde src 'm' harfinde başlarken dst 'h' harfinde başlasın. Bu durumda sırayla *mermaba* -> *mermeba* -> *mermera* şeklinde devam edicektir. Memmove fonksiyonunda yapılan adres sırası kontrolünün sebebi de budur.

## **Listeler**
Listeleri birbirine bağlanmış blok serileri olarak düşünebilirsiniz. Her bir blokta bir sonraki bloğun adresini tutan bir pointer bulunur ve bu şekilde bağlanmış olur. **Bu bağlam ramde ardaşık olmak zorunda değildir.** 
[bknz.](https://www.youtube.com/playlist?list=PLh9ECzBB8tJN9bckI6FbWB03HkmogKrFT)
### **Struct**
Structlar halihazırda bulunan veri tipleri ile sizin bir veri bloğu(kendi veri tipiniz) oluşturmanızı sağlar.

	struct s_blok
	{
		int	x;
		char a;
	}
s_blok struct'ı artık ramde ardaşık sıralar ile int x ve char a tutan bir bloktur(x'in ilk adresi 1010 ise a'nın adresi 1014'tür)
### **Typedef**
Typedef ifadesi bir veri tipine ad atama(tanımlama) işlemini sağlar. Örneğin bir int veri tipini tam_sayı adını atamak istersek

	typedef int tam_sayı; //typedef eski_ad yeni_ad;
şeklinde kullanabaliriz. Structlarsa kendisi bir veri tipi sayıldığından typedef ile daha çağrılabilir bir ad verebiliriz.
Yukardaki structı bir yerde kullanmamız gerekirse

	struct s_blok ilk;
şeklinde çağırmamız gerekir. Biz ise

	typedef struct s_blok
	{
		int	x;
		char a;
	}	v_blok;
yaparak structtımızı kullanmamız gerektiğinde uzun şeklinden ziyade

	v_blok ilk;
dememiz yeterli olacaktır.

## **Malloc/Free**
Malloc fonksiyonu bize Heap bellek ([bknz. bellek hakkında bilgiler](https://medium.com/@memrekaraaslan/nedir-bu-memory-stack-heap-memory-leak-memory-management-c3c14d1c3e6e)[bknz. bellek 
hakkında genel bilgiler(2)](https://www.geeksforgeeks.org/memory-layout-of-c-program/)) üzerinden yer tahsili sağlar. Free fonksiyonu ile de bize tahsil edilen belleği serbest bırakırız ama içindeki değere karışmayız.
### **Malloc**
Malloc normal durumda size void pointer döndürür. Biz bunu baştaki parantez ile type casting yaparak istediğim veri tipine atarız. Fonksiyonun tanımı ise

	(dönüştürülecek veri tipi)malloc(ayrılacak byte sayısı)
şeklindedir.
#### **Sizeof**
Sizeof fonksiyonu ise içine girilen şeyin kaç byte olduğunu döndüren bir fonksiyondur.
Eğer sizeof(int) dersek bize 4 döndürecektir.
### **Free**
Free fonksiyonu bellekte tahsil ettiğimiz(bir nevi özelleştirdiğimiz) bölgeyi geri serbest bırakıyoruz diyebiliriz. Bunu yaparken ise içindeki değere dokunmuyoruz sadece o blok tekrardan tahsil edilebilir ve değiştirilebilir oluyor.
