# Test-Driven Development

Антон Бевзюк\
Июль 2014

<!-- TODO:

  - Red-Green-Refactor table is UGLY, need to be solved later

-->

# О чем будем говорить?

  - Мифы о TDD
  - TDD: что это такое и зачем?
  - <font color=red>RED</font>/<font color=green>GREEN</font>/REFACTOR
  - Демо
  - Полезные советы
  - Паттерны TDD

На примере C# / MS Visual Studio

# Что такое TDD?

# Мифы о TDD

  - Unit testing = TDD
  - TDD - практика тестирования
  - TDD удваивает объем работы
  - Главная цель - 100% покрытие кода тестами
  - Все, что требуется - юнит тесты

# Test-Driven Development

  - Тесты **до** кода
  - Методология **разработки**
  - Практика **дизайна**

<!--
  - TDD - это легковесная методология программирования, которая основана на
    написании тестов до кода.
  - TDD - это не методолгия тестирования. Это методология разработки ПО.
  - Главная цель TDD - не покрытие тестами. Это побочный эффект.
  - Главная цель TDD - помочь разработчикам и заказчикам разрабатывать ПО в
    условиях изменяющихся требований.
-->

# Что это даёт?

+------------------------------------------------------------------+------------------------+
| - Актуальное описание намерений, дизайна и использования системы | ![](./images/tdd_1.jpg)|
| - Легкое обнаружение слабых мест в дизайне                       |                        |
| - Автоматическое регрессионное тестирование                      |                        |
| - Безопасный рефакторинг                                         |                        |
| - Быстрое обнаружение дефектов                                   |                        |
+------------------------------------------------------------------+------------------------+

# Отладка
> Отладка - это трата времени

Роберт Мартин

# <font color=red>RED</font> / <font color=green>GREEN</font> / REFACTOR

+---------------------------------------------------------------------+---------------------------------------------------------------------+------------------------------------------------------------------+
|=> Подумай, напиши тест                                              |Скомпилируй                                                          |Исправь ошибки                                                    |
+---------------------------------------------------------------------+---------------------------------------------------------------------+------------------------------------------------------------------+
|<font color=green>Запусти все тесты и убедись, что они прошли</font> |![](./images/tdd_2.jpg)                                              |<font color=red>Запусти все тесты и убедись, что они упали</font> |
+---------------------------------------------------------------------+---------------------------------------------------------------------+------------------------------------------------------------------+
|Рефакторинг                                                          |<font color=green>Запусти все тесты и убедись, что они прошли</font> |Напиши код                                                        |
+---------------------------------------------------------------------+---------------------------------------------------------------------+------------------------------------------------------------------+

# Демонстрация

# Как начать писать тест?

+-------------------------------------+-------------------------+
| - Сможешь написать реализацию       | ![](./images/tdd_3.jpg) |
| - Знаешь, каким будет следующий шаг |                         |
+-------------------------------------+-------------------------+

# Что нужно тестировать?

+-------------------------------+-------------------------+
| ## Нужно                      | ![](./images/tdd_4.jpg) |
|   - Все, что может поломаться |                         |
|                               |                         |
| ## Не нужно                   |                         |
|   - set; get                  |                         |
|   - GUI                       |                         |
|   - private                   |                         |
+-------------------------------+-------------------------+

# Вещи, которые нужно делать всегда

+--------------------------------------------+-------------------------+
| - Сначала тест, потом код                  | ![](./images/tdd_5.jpg) |
| - Список todo                              |                         |
| - Новый код только, если есть красный тест |                         |
| - Запускать все тесты                      |                         |
| - Поддерживать качество кода тестов        |                         |
| - Рефакторинг                              |                         |
+--------------------------------------------+-------------------------+

# Вещи, которые делать нельзя никогда

+-------------------------------------+-------------------------+
| - Несколько красных тестов          | ![](./images/tdd_6.jpg) |
| - Новый тест до рефакторинга        |                         |
| - Check-in кода с падающими тестами |                         |
+-------------------------------------+-------------------------+

# Хороший unit test

+------------------------------------------+-------------------------+
| - Сфокусированый (1 assert)              | ![](./images/tdd_7.jpg) |
| - Быстрый                                |                         |
| - Автоматический (легкий запуск)         |                         |
| - Независимый от                         |                         |
|   - Других тестов                        |                         |
|   - Окружения                            |                         |
|   - Порядка запуска                      |                         |
| - Такого же качества как и код приложения|                         |
+------------------------------------------+-------------------------+

# Плохие тесты

+------------------------------------------+-------------------------+
| - Длинная инициализация                  | ![](./images/tdd_8.jpg) |
|   - Порочный дизайн                      |                         |
|   - Слишком большие классы               |                         |
| - Медленные тесты                        |                         |
|   - \> 10 минут для запуска тестов       |                         |
| - Хрупкие тесты                          |                         |
|   - Высокая вязкость                     |                         |
+------------------------------------------+-------------------------+

# TDD patterns
  - AAA: Arrange Act Assert
  - Isolated test
  - Test list
  - Test First
  - Assert First
  - Test Data
  - Evident Data

<!--
  - Isolated test: how should the running of tests affect each other? Not at
    all.
  - Test list: what should you test? Before you begin, write a list of all the
    tests you know you will have to write.
  - Test First: when should you write your tests? Before you write the code that
    is to be tested.
  - Assert First: when should you write the asserts? Try writing them first.
  - Test Data: what data do you use for test-first tests? Use data that makes
    the tests easy to read and follow.
  - Evident Data: how do you represent the intent of the data? Include expected
    and actual results in the test itself, and try to make their relationship
    apparent.
-->

# Green Test Patterns
  - <font color=green>Fake it</font>
  - <font color=green>Obvious Implementation</font>
  - <font color=green>Triangulation</font>

<!--
  - Fake It: What is your first implementation once you have a broken test?
    Return a constant. Once you have the test running, gradually transform the
    constant into an expression using variables.
  - Obvious Implementation: How do you implement simple operations? Just
    implement them. One to Many How do you implement an operation that works
    with collections of objects? Implement it without the collections first,
    then make it work with collections.
  - Triangulation: How do you most conservatively drive abstraction with tests?
    Only abstract when you have two or more examples.
-->

# Red Test Patters
  - <font color=red>One Step Test</font>
  - <font color=red>Starter Test</font>
  - <font color=red>Explanation Test</font>
  - <font color=red>Learning Test</font>
  - <font color=red>Another Test</font>
  - <font color=red>Regression Test</font>

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
