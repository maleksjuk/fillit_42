# fillit_42

Учебный проект Школы 21.

Некоторые нормы написания кода:
* Имена функций и переменных пишутся в нижнем регистре и могут разделяться знаком подчёркивания '_';
* Каждая функция может иметь не более 25 строк и 5 локальных переменных, может принимать не более 4 аргументов;
* Локальные переменные объявляются (без присваивания значений) в начале функций. После объявлений следует пустая строка.
---
Задание:

На вход подаются тетраминки (фигура из 4 блоков), вписанные в поле 4х4, разделённые одной пустой строкой.
Последовательно каждая тетраминка именуется буквой латинского алфавита (A, B, C...). Может быть не более 26 фигур.

На выходе получить квадрат с минимальной площадью, в который вписаны все тетраминки. Если таких квадратов несколько,
то выдать тот, у которого первые фигуры находится ближе к верхнему левому углу.

Формат ввода:

>.#..<br/>
>.#..<br/>
>.#..<br/>
>.#..<br/>
><br/>
>..##<br/>
>..##<br/>
>....<br/>
>....

Формат вывода:

>ABB.<br/>
>ABB.<br/>
>A...<br/>
>A...
