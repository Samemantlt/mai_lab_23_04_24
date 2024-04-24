# Отчет по практической работе N 8 по курсу
# "Фундаментальная информатика"

Студент группы: M8О-115Б, Самарский Ярослав Вадимович\
Контакты: yaroslav.samarskij@mail.ru \
Работа выполнена: 25.04.2024\
Преподаватель: Чеснов Илья Игоревич

## 1. Тема

Линейные списки.

## 2. Цель работы

Составить и отладить программу на языке Си для обработки линейного списка заданной организации.

## 3. Задание

Вариант 22.
Тип элемента: 7. Беззнаковое целое.
Вид списка: 6. Линейный двунаправленный с барьерным элементом
Нестандартное действие: 8. Дополнить список копиями заданного значения до указанной длины k. Если в списке уже имеется не менее k элементов, то не менять его

## 4. Оборудование

Процессор: Intel Core i5-8265U @ 8x 3.9GH\
ОП: 7851 Мб\
НМД: 1024 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **18.10 cosmic**\
Интерпретатор команд: **bash**, версия **4.4.19**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **--**

## 6. Идея, метод, алгоритм решения задачи

Пока длина меньше k, добавляем заданный элемент в конец

## 7. Сценарий выполнения работы

План:
1. Получать длину списка
2. Если она меньше чем k, то добавляем заданный элемент в конец
3. Если она больше или равна чем k, то завершаем выполнение действия

## 8. Распечатка протокола

```
abc@d2d3eecc79b4:~/workspace/mai_lab_23_04_24$ ./a.out 

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 2
Index: 0
Value: 5
Appended at: 0!
List: 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 2
Index: 0
Value: 4
Appended at: 0!
List: 4, 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 2
Index: 0
Value: 3
Appended at: 0!
List: 3, 4, 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 2
Index: 0
Value: 2
Appended at: 0!
List: 2, 3, 4, 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 2
Index: 0
Value: 1
Appended at: 0!
List: 1, 2, 3, 4, 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 3
Index: 1
Removed at: 1!
List: 1, 3, 4, 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 3
Index: 2
Removed at: 2!
List: 1, 3, 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 5
Target length: 5
Value: 10
List: 1, 3, 5, 10, 10
List length: 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 4
List length: 5

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 3
Index: 4
Removed at: 4!
List: 1, 3, 5, 10

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 4
List length: 4

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 1
List: 1, 3, 5, 10

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 5
Target length: 3
Value: 77
List: 1, 3, 5, 10
List length: 4

[0] - Exit
[1] - Print list
[2] - Append
[3] - Remove
[4] - Count
[5] - Repeat to length
Enter command index: 0
```

## 9. Дневник отладки

| № | Лаб. или дом. | Дата       | Время     | Событие                  | Действие по исправлению | Примечание  |
|---|---------------|------------|-----------|--------------------------|-------------------------|-------------|
|1  | Дом           | 19.04.2023 | 13:50     | Неправильно написал вставку, была ошибка, когда вставлял элемент на 0й индекс | Стал переподвязывать header | Нужно быть внимательнее |
|2  | Дом           | 19.04.2023 | 02:50     | Не очищал память после удаления ноды | free(ptr) | Забыл |

## 10. Замечания автора по существу работы

Было очень интересно разобраться с работой линейных списков и вспомнить, как работать со ссылками.

## 11. Выводы

Я научился реализовывать линейный список и простейшие операции с ним.

