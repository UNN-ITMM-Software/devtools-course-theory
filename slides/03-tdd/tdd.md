# Test-Driven Development

Кирилл Корняков\
Антон Бевзюк (Dodo Pizza)\
Март 2020

<!-- TODO:

  - Red-Green-Refactor table is UGLY, need to be solved later

-->

# Содержание

  - Введение
  - TDD: что это такое и зачем?
  - Демонстрация
  - Мифы о TDD
  - Полезные советы
  - Паттерны TDD

# Контуры обратной связи

  0. No code
  1. Test-Driven Development (TDD)
  2. Unit Testing
  3. Continuous Integration (pre-merge, post-merge, nightly, weekly, etc)
  4. Quality Assurance / Validation Team
  5. Customers

TDD — "**Т**ише е**Д**ешь, **Д**альше будешь" (С) KK

# Test-Driven Development

  - Тесты __до__ кода
  - Практика __разработки__
  - Практика __дизайна__

Была популяризована как часть методологии Extreme Programming в начале 2000х.

В настоящее время популярна и вне Agile методологий, сама по себе.

<!--
  - TDD - это легковесная методология программирования, которая основана на
    написании тестов до кода.
  - TDD - это не методолгия тестирования. Это методология разработки ПО.
  - Главная цель TDD - не покрытие тестами. Это побочный эффект.
  - Главная цель TDD - помочь разработчикам и заказчикам разрабатывать ПО в
    условиях изменяющихся требований.
-->

# <font color=red>RED</font> / <font color=green>GREEN</font> / REFACTOR

+-------------------------+---------------------------------------------------------------------------+
| ![](./images/tdd_2.jpg) |  1. Подумай, напиши тест                                                  |
|                         |  2. Скомпилируй                                                           |
|                         |  3. Исправь ошибки компиляции                                             |
|                         |  4. <font color=red>Запусти все тесты и убедись, что они упали</font>     |
|                         |  5. Напиши код (простейший, который заставит тест пройти)                 |
|                         |  6. <font color=green>Запусти все тесты и убедись, что они прошли</font>  |
|                         |  7. Рефакторинг                                                           |
|                         |  8. <font color=green>Запусти все тесты и убедись, что они прошли</font>  |
+-------------------------+---------------------------------------------------------------------------+

# Демонстрация

Реализация класса рационального числа (дроби)

  - Подготовка окружения
    - Перейти в проект mp2-lab-set, проверить git remote, обновить master
    - Создать директорию build и убедиться, что тесты строятся и ходят
    - Создать ветку tdd-demo
    - Создать файл с тестом 2+2, убедиться что работает, послать pull request
      - изменить travis.yml, чтобы тесты реально запускались
  - Изложение плана реализации
    - класс для корректного хранения
    - приведение знаков (сначала оба, потом знаменатель, потом рефакторинг)
    - приведение (НОД, алгоритм Евклида)
    - Арифметические операции
  - Хранение
    - Создать ctor без аргументов
    - проверить num, den
    - потом со значениями
    - потом set
    - потом ругаться на 0
  - Приведение знаков
  - НОД
  - Арифметические операции

# Что это даёт?

 - Актуальное описание намерений, дизайна и использования системы
 - Легкое обнаружение слабых мест в дизайне
 - Автоматическое регрессионное тестирование
 - Безопасный рефакторинг
 - Быстрое обнаружение дефектов

# Uncle Bob on Debugging

> “If you're good at the debugger it means you spent a lot of time debugging.\
I don't want you to be good at the debugger.”

 —  Robert C. Martin

![](./images/uncle-bob.jpg)

# Debuggers are a wasteful Timesink

by Robert C. Martin\
November 29, 2003

As debuggers have grown in power and capability, they have become more and more harmful to the process of software development.

```code
Debuggers have become immensely powerful. A good debugger is a very capable tool. With it, an experienced developer can step through very complex code, look at all the variables, data structures, and stack frames; even modify the code and continue. And yet, for all their power, debuggers have done more to damage software development than help it.

Since I started using Test Driven Development in 1999, I have not found a serious use for a debugger. The kinds of bugs I have to troubleshoot are easily isolated by my unit tests, and can be quickly found through inspection and a few judiciously placed print statements.

I teach a lot of classes in C++, Java, C#, TDD, XP, Patterns, etc. In those classes I often have the students write code. It is not unusual for me to find a student with his or her nose buried in a debugger, painstakingly stepping from line to line, examining variables, setting breakpoints, and generally wasting time. The bug they are tracking could be found through simple inspection of the code.

I consider debuggers to be a drug -- an addiction. Programmers can get into the horrible habbit of depending on the debugger instead of on their brain. IMHO a debugger is a tool of last resort. Once you have exhausted every other avenue of diagnosis, and have given very careful thought to just rewriting the offending code, *then* you may need a debugger.
```

[Source](https://www.artima.com/weblogs/viewpost.jsp?thread=23476)

# Мифы о TDD

  - Unit testing = TDD
  - TDD - практика тестирования
  - TDD удваивает объем работы
  - Главная цель - 100% покрытие кода тестами
  - Все, что требуется - юнит тесты

# Как начать писать тест?

  - Уверен, что сможешь написать реализацию
  - Знаешь, каким будет следующий шаг

# Что нужно тестировать?

+-------------------------------+-------------------------+
| Нужно:\                       | ![](./images/tdd_4.jpg) |
|                               |                         |
|   - Все, что может поломаться |                         |
|                               |                         |
| Не нужно:\                    |                         |
|                               |                         |
|   - set; get                  |                         |
|   - private                   |                         |
|   - GUI                       |                         |
+-------------------------------+-------------------------+

# Вещи, которые нужно делать всегда

+--------------------------------------------+-------------------------+
| - Сначала тест, потом код                  | ![](./images/tdd_5.jpg) |
| - Вести список TODO                        |                         |
| - Новый код только, если есть красный тест |                         |
| - Запускать все тесты                      |                         |
| - Поддерживать качество кода тестов        |                         |
| - Рефакторинг                              |                         |
+--------------------------------------------+-------------------------+

# Вещи, которые делать нельзя никогда

+-------------------------------------+-------------------------+
| - Check-in кода с падающими тестами |                         |
| - Несколько красных тестов          | ![](./images/tdd_6.jpg) |
| - Новый тест до рефакторинга        |                         |
+-------------------------------------+-------------------------+

# Хороший unit test

+--------------------------------------------+-------------------------+
| - Сфокусированый (1 assert)                | ![](./images/tdd_7.jpg) |
| - Быстрый                                  |                         |
| - Автоматический (легкий запуск)           |                         |
| - Независимый от                           |                         |
|   - Других тестов                          |                         |
|   - Окружения                              |                         |
|   - Порядка запуска                        |                         |
| - Такого же качества, как и продуктовый код|                         |
+--------------------------------------------+-------------------------+

# Плохие тесты

+------------------------------------------+-------------------------+
| - Длинная инициализация            | ![](./images/tdd_8.jpg) |
|   - Порочный дизайн                |                         |
|   - Слишком большие классы         |                         |
| - Медленные тесты                  |                         |
|   - \>10 минут для запуска тестов  |                         |
| - Хрупкие тесты                    |                         |
|   - Высокая вязкость               |                         |
+------------------------------------------+-------------------------+

# TDD Patterns

  - Test List
  - Test First
  - AAA: Arrange Act Assert
  - Assert First
  - Isolated Test
  - Test Data
  - Evident Data

<!--
  - Isolated test: how should the running of tests affect each other? Not at all.
  - Test list: what should you test? Before you begin, write a list of all the tests you know you will have to write.
  - Test First: when should you write your tests? Before you write the code that is to be tested.
  - Assert First: when should you write the asserts? Try writing them first.
  - Test Data: what data do you use for test-first tests? Use data that makes the tests easy to read and follow.
  - Evident Data: how do you represent the intent of the data? Include expected and actual results in the test itself, and try to make their relationship apparent.
-->

# <font color=green>Green Test Patterns</font>

  - Fake it
  - Obvious Implementation
  - Triangulation

<!--
  - Fake It: What is your first implementation once you have a broken test?
    Return a constant. Once you have the test running, gradually transform the
    constant into an expression using variables.
  - Obvious Implementation: How do you implement simple operations? Just
    implement them. One to Many: How do you implement an operation that works
    with collections of objects? Implement it without the collections first,
    then make it work with collections.
  - Triangulation: How do you most conservatively drive abstraction with tests?
    Only abstract when you have two or more examples.
-->

# <font color=red>Red Test Patterns</font>

  - One Step Test
  - Starter Test
  - Explanation Test
  - Learning Test
  - Another Test
  - Regression Test

More [Test Patterns](https://wiki.c2.com/?TestingPatterns)

<!--
 - One Step Test
   - Which test should you pick next from the list? Pick a test that will teach
     you something and that you are confident you can implement.
 - Starter Test
   - Which test should you start with? Start by testing a variant of an
     operation that doesn’t do anything.
 - Explanation Test
   - How do you spread the use of automated testing? Ask for and give
     explanations in terms of tests.
 - Learning Test
   - When do you write tests for externally produced software? Before the first
     time you are going to use a new facility in the package.
 - Another Test
   - How do you keep a technical discussion from straying off topic? When a
     tangential idea arises, add a test to the list and go back to the topic.
 - Regression Test
   - What’s the first thing you do when a defect is reported? Write the smallest
     possible test that fails, and that once it runs, the defect will be
     repaired.
-->

# 7 стадий юнит-тестера

  1. "У меня нет на это времени".
  1. Начинает писать юнит тесты и писать в блоге,\
     как это здорово, и что каждый должен следовать TDD.
  1. Тестирует всё подряд - private, get, set. Доводит покрытие до 100%.\
     Злоупотребляет атрибутом `InternalsVisibleTo`.
  1. Пишет хрупкие тесты, по сути являющиеся интеграционными.
  1. Открывает для себя средства, облегчающие тестирование.
  1. Подменяет абсолютно всё, что можно подменить.
  1. Начинает писать эффективные юнит тесты.

# Контрольные вопросы

  1. Что такое TDD, его назначение
  1. Мифы о TDD
  1. Цикл разработки по TDD (в виде рисунка и с максимумом деталей)
  1. Атрибуты хорошего unit-теста (включая AAA)

# Спасибо!

Вопросы?

![](./images/tdd_9.jpg)
