Илья Удалов: Поиск в тексте регулярных выражений (упрощенные)
=============================================================

Функця ``match`` предназначена для проверки соответствия входной строки паттерну.
Функция ``find`` для поиска подстроки в строке.

.. code-block:: cpp
    
    
    // 1 - строка соответстует паттерну
    // 0 - не соответствует паттерну
    int match(const std::string& regex, const std::string& text);

    
    // возвращается либо позиция первого вхождение подстроки,
    // либо 0, если подстрока отсутствует в строке
    int find(const std::string& substring, const std::string& text);

Пример использования функции match:

.. code-block:: cpp

        std::string regex, text;
        // инициализация переменных regex и text
        // ...

        // ...
        // применение регулярного выражения regex к text
        std::cout << "Is match: " << match(regex, text) << std::endl;

Пример использования функции find:

.. code-block:: cpp

        std::string substr, text;
        // инициализация переменных substr к text
        // ...

        // ...
        // поиск подстроки substr в text
        std::cout << "Is find:  " << find(substr, text) << std::endl;
