Домашно №1
Забележка: Ако не сте сигурни как да подходите към домашното, изчакайте да вземем нужния материал, срокът е достатъчно дълъг.

 

Напишете програма, която ще представлява интерфейс към файлова база от данни за играчи на Magic The Gathering.

Имате 3 бинарни файла:

Файл с Играчи (players.dat):
Всеки играч си има име и уникално ID. Името на играча е не повече от 127 символа.
Файл с Карти (cards.dat):
Всяка карта има име, ID и цвят. Името на картата е не повече от 63 символа, а цвета е един от { Red, Black, Blue, White, Green }.
Файл с Тестета (decks.dat):
Всяко тесте има ID на притежател (играч), цвят и ID-та на картите. Цвета е един от { Red, Black, Blue, White, Green }; има точно 60 на брой ID-та на карта.
Във всеки един от файловете ID е цяло неотрицателно число, по малко от 2^15. За цвета на картите и тестетата изберете подходящ тип!

Програмата дава възможност за изпълнение на следните команди (ако се въведе невалидна команда програмата приключва):

Създаване на ново тесте (команда cd) като са нужни име на притежател и 60 имена на картите в тестето, цвета на тестето автоматично е цвета, който най много се среща сред избраните карти. Операцията е успешна ако има играч с подаденото име и всички подадени имена на карти са валидни (съществува запис за тях). Пример
cd
The Almighty Dragon
Stream of Life
Tranquility
Tsunami
Forcefield
Swamp
...
Lord of the Pit
Създава нов играч (команда cp) по подадено име, ID-то на играча се генерира така че да няма друг играч с такова ID. Пример:
cp
The Almighty Dragon
Създава нова карта (команда cc) по подаден цвят и имe, ID-то се генерира така че да няма друга карта със същото. Пример:
cc
White Celestial Crusader
Генерира текстов файл (команда report) с данни за всчиките тестета групирани по цвят и накрая извежда най-често използваната карта както и нейният цвят. Данните за тестетата са името на притежателя, името на първата карта и цвета и. Всяко тесте се принтира на нов ред. Пример:
report
При приключване на програмата бинарните файлове остават в адекватно (не счупено) състояние. Създадените играчи, карти и тестета се записват в съответните файлове преди програмата да приключи. При стартиране на програмата, се проверява за наличност на 3те бинарни файла и командите за създаване на играчи и карти взимат под внимание вече наличните такива!

Примерен report файл:

Red
Black
    Owner: Swamp Reacher Card: Syndicate Enforcer Color: Black
    Owner: Swamp Reacher Card: Dying Wish Color: Back
    Owner: Swamp Reacher Card: Basilica Guards Color: White
Blue
White
Green
    Owner: _*PeaceMaker*_ Card: Borderland Range Color: Green
    Owner: PiCkAcHu!11!one!one!1eleven! Card: Phyrexian Rebirth Color: White
    Owner: Swamp Reacher Card: Forest Color: Green

Most common card: Island Color: Blue
