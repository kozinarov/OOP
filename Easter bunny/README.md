Както всички знаем идва Великден, а покрай Великден зайците имат много работа... Заекът Ставри е 3-кратен сребърен медалист по събиране на яйца и тази година е решен да спечели златото. От вас той иска да му направите кошница за състезанието (само с най-добрата кошница може горкият Ставри да се надява да триумфира).

По регламент всяко яйце се описва от уникален низ с точна дължина и неговата големина. Тъй като е състезание и всичко си има правила, той не може да използва каква да е кошница... Всяка кошница си има име и то е името на нейният собственик. Кошницата, която ще му направите трябва да може да променя размера си според това колко яйца има в нея - а това както сами предполагате е доста трудно. За това във всеки един момент, ако в нея има N яйца, то тя може да има свободно място за най-много още N яйца. Кошницата, която ще му осигурите трябва да позволява добавянето на ново яйце и премахването на яйце по даден низ, който го описва.

Всяка вечер кошниците на участниците трябва да се виртуализират някъде, затова от вашата програма, Ставри иска да може да сериализира кошницата си в бинарен формат (масив), като заеманото място е минимално, тоест низовете заемат точно толкова, колкото са дълги или константно число байтове повече. А на сутринта прогамата ви ще трябва да десериализира кошницата от бинарния формат.

В края на състезанието съдиите трябва да могат да преценят кой печели, затова трябва да предоставите функция която по зададена кошница генерира репорт за нейното съдържание. Ще трябва да го запишете в текстов файл с име : "report_nameOfBasket.txt", където nameOfBasket е името на кошницата за която генерирате репорт в момента. Вътре трябва да са описани всички яйца (чрез уникалния низ и тяхната големина). Всяко яйце трябва да се намира на нов ред.

С вашите кошници по вашата глава...

Добре познатият ви Ставри спечели това пусто злато. Той искрено ви благодари. Но... сега реши да отвори бизнес, защото чул, че от математиката се правели добри пари. Ще продава математически кошници, представете си... И разбира се пак вие трябва да спасявате положението - Той ви моли да добавите следните оператори към кошницата, която му направихте:

Оператор [] - който по зададен индекс, ако той е валиден, връща яйцето, което се намира там.
Оператор [] - който по зададен символен низ, връща първото яйце, което го съдържа, ако има такова.
Оператори +, += - които конкатенират 2 кошници (работят върху аргументи две кошници).
Оператори +, += - които конкатенират низ с всички яйца в дадена кошницата. (два аргумента - кошница и низ)
Оператори *, *=  - приемат цяло число и умножават всички размери на яйца в кошницата по това число. (аргументи кошница и число)
Оператори /, /= - приемат цяло число и делят всички размери на яйца в кошницата на даденото число. (аргументи кошница и число)
Оператори %, %= - които пресмятат сечението на кошници (работят върху аргументи две кошници).
Оператори (==, !=, <, <=, >=) - сравнява две кошници, като две кошници са равни, когато всеки елемент на позиция i в първата кошница е равен на елемента на същата позиция във втората. А първата кошница е по-малка от втората, когато слещнете елемент в първата, който е по-малък от съответния във втората и до момента не сте срещнали по-голям елемент в първата. Две яйца са равни едно на друго ако низовете в тях са еднакви, а едно яйде е по-малко от друго яйце, ако низа на първото яйце е по-малък в лексикографски смисъл от низа във второто.
За яйцата трябва да дефинирате поне 10 оператора, по ваш избор. Подберете ги така, че да улеснят максимално реализацията на кошница.
Напишете и програма (main и други функции) с която да покажете използването на операторите.

Весели Великденски празници, 

Ставри Дългоухов

