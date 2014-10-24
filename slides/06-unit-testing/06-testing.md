# Тестирование

![](./pix/Software-testing-trends-2013.jpg)

Кирилл Корняков (Itseez, ННГУ)\
Октябрь 2014

<!-- TODO
  - Стоит показать пример юнит-теста в самом начале
  - Стоит показать примеры юнит-тестов на разных языках
  - Нужно рассмотреть наивную реализацию юнит-тестов,
    когда функции руками добавляются в main
  - Всю непрерывную интеграцию стоит отрезать
  - В содержании третий пункт должен быть полностью про GoogleTest
-->

# Содержание

  1. Введение в тестирование
  1. Фреймворки для Unit-тестирования
  1. Google Test

# Классификация тестов: по уровню автоматизации

  1. Ручные
     - __Тест__ — проверка, осуществляемая "руками"
     - __Тест-план__ — документ со списком тестов.
     - Используется все меньше в самом процессе разработки
        - Чаще всего GUI и UX
        - Бета-тестирование с реальными пользователями
  1. Автоматические
     - __Тест__ — это "обычная" функция, реализующая некоторый сценарий
       использования программных сущностей.
     - __Тестовая сборка (test suite)__ — приложение с тестами (обычно
       консольное).

# Классификация тестов: по масштабу

  - Модульные (Unit)
  - Инфраструктурные (Infrastructure)
  - Системные (System)
    - Приемочные (acceptance), функциональные (functional)

# Классификация тестов: по назначению

  - Функциональные требования
    - На задымление (smoke)
    - Регрессионные (regression)
    - На точность (accuracy)
    - Соответствие/совместимость (conformance/compliance)
    - Приемочные (acceptance)
    - Функциональные (functional)
  - Нефункциональные требования
     - На производительность (performance)
     - Стресс (stress)
     - Нагрузочные (load)
     - Качество кода (code quality)

# Современная стратегия тестирования

  - Фокус на максимальную автоматизацию
    - Полное тестирование требуется несколько раз в день, каждому члену команды
  - __Тесты пишутся самими разработчиками, одновременно с реализацией__
    - Тесты это лучшая документация, которая всегда актуальна (компилятор!)
    - Тесты это первые сэмплы, показывающие простые примеры использования
    - Test-Driven Development
  - Код тестируется __непрерывно__
    - Это делается локально на машине разработчика
    - Это делается на сервере до того, как добавить его в репозиторий
    - Без "зеленых" тестов нет уверенности в работоспособности кода

# Современная стратегия тестирования (2)

  - Автоматические тесты замещают отладку
     - Предсказуемость времени разработки
     - __Пойманный баг документируется в виде теста__
  - Тесты — это "first-class citizens"
     - Стоит отдавать код вместе с тестами
     - Нужно заботиться о качестве кода тестов
     - Метафора тестов: скелет, позволяющий организму двигаться

# Несколько примеров

  - Работа с legacy-кодом
  - Портирование ПО на новые платформы
  - Тестирование новых платформ

# Содержание

  1. Введение в тестирование
  1. <font color=red>Фреймворки для Unit-тестирования</font>
  1. Google Test

# Пример тестов на Java c использованием JUnit

```cpp
@Test
public void canAddNumbers()
{
    // Arrange
    ComplexNumber z1 = new ComplexNumber(1, 2);
    ComplexNumber z2 = new ComplexNumber(3, 4);

    // Act
    ComplexNumber sum = z1.add(z2);

    // Assert
    assertEquals(new ComplexNumber(4, 6), sum);
}

@Test
public void canMultiplyNumbers()
{
    // Arrange
    ComplexNumber z1 = new ComplexNumber(1, 2);
    ComplexNumber z2 = new ComplexNumber(3, 4);

    // Act
    ComplexNumber sum = z1.multiply(z2);

    // Assert
    assertEquals(new ComplexNumber(-5, 10), sum);
}
```

# Фреймворки для Unit-тестирования

  1. Значительно упрощают создание и запуск unit-тестов,\
     позволяют придерживаться единого стиля.
  1. xUnit — общее обозначение для подобных фреймворков.
  1. Бесплатно доступны для большинства языков:
     - C/C++: CUnit, CPPUnit, GoogleTest
     - Java: JUnit
     - .NET: NUnit
  1. Встроены в некоторые языки:
     - D, Python, Go

# Типичные возможности

  1. Удобное добавление тестов
    - Простая регистрация новых тестов
    - Набор функций-проверок (`assert`)
    - Общие инициализации и деинициализации
  1. Удобный запуск тестов
    - Пакетный режим
    - Возможность фильтрации тестов по именам
  1. Часто допускают интеграцию с IDE
  1. Генерация отчета в стандартном XML-формате
    - Возможность последующего автоматического анализа
    - Публикация на web-страницах проекта

# Критерии хорошего теста

  1. AAA: Arrange, Act, Assert
  1. Сфокусированный (только один assert)
  1. Быстрый
  1. Независим от порядка исполнения и окружения

Ну и конечно же тест должен быть _автоматическим_ и иметь _чистый код_.

# Содержание

  1. Введение в тестирование
  1. Фреймворки для Unit-тестирования
  1. <font color=red>Google Test</font>

# Google Test

  1. Популярный фреймворк для написания модульных тестов на С++, разработанный
     Google.
  1. [Open-source](gtest) проект c лицензией BSD (допускает использование в
     закрытых коммерческих проектах).
  1. Используется в целом ряде крупных проектов
     - Chromium, LLVM компилятор, OpenCV
  1. Написан на C++, строится при помощи CMake
     - Поддерживает: Linux, Mac OS X, Windows, Cygwin, Windows CE, и Symbian
  1. Как правило используется в консольном режиме,
     но существует вспомогательное GUI [приложение](gtest_bar).

# Базовые концепции

![](./pix/gtest_concepts.png)

  - Каждый тест реализован как функция, с использованием макроса `TEST()` или
    `TEST_F()`.
  - `TEST()` не только определяет, но и "регистрирует" тест.

# Пример 1

```cpp
#include <gtest/gtest.h>

TEST(MathTest, TwoPlusTwoEqualsFour) {
  EXPECT_EQ(2 + 2, 4);
}
```

# Пример 2

Функция

```cpp
int Factorial(int n); // Returns the factorial of n
```

Тесты

```cpp
// Tests factorial of 0.
TEST(FactorialTest, HandlesZeroInput) {
  EXPECT_EQ(1, Factorial(0));
}

// Tests factorial of positive numbers.
TEST(FactorialTest, HandlesPositiveInput) {
  EXPECT_EQ(1, Factorial(1));
  EXPECT_EQ(2, Factorial(2));
  EXPECT_EQ(6, Factorial(3));
  EXPECT_EQ(40320, Factorial(8));
}
```

# Пример 3

```cpp
#include <gtest/gtest.h>
#include <vector>

using namespace std;

// A new one of these is created for each test
class VectorTest : public testing::Test {
public:
  vector<int> m_vector;

  virtual void SetUp() {
    m_vector.push_back(1);
    m_vector.push_back(2);
  }

  virtual void TearDown() {}
};

TEST_F(VectorTest, testElementZeroIsOne) {
  EXPECT_EQ(m_vector[0], 1);
}

TEST_F(VectorTest, testElementOneIsTwo) {
  EXPECT_EQ(m_vector[1], 2);
}

TEST_F(VectorTest, testSizeIsTwo) {
  EXPECT_EQ(m_vector.size(), (unsigned int)2);
}
```

# Консольный лог Google Test

```txt
[mlong@n6-ws2 x86]$ bin/hellotest
Running main() from gtest_main.cc
[==========] Running 4 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 3 tests from VectorTest
[ RUN      ] VectorTest.testElementZeroIsOne
[       OK ] VectorTest.testElementZeroIsOne (0 ms)
[ RUN      ] VectorTest.testElementOneIsTwo
[       OK ] VectorTest.testElementOneIsTwo (0 ms)
[ RUN      ] VectorTest.testSizeIsTwo
[       OK ] VectorTest.testSizeIsTwo (0 ms)
[----------] 3 tests from VectorTest (0 ms total)

[----------] 1 test from MathTest
[ RUN      ] MathTest.Zero
[       OK ] MathTest.Zero (0 ms)
[----------] 1 test from MathTest (0 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 4 tests.
```

# Возможности Google Test

  - Automatic test discovery
  - Rich set of assertions, user-defined assertions
  - Death tests
  - Fatal and non-fatal failures
  - Value- and type-parameterized tests
  - Various options for running the tests
  - XML test report generation

# Порядок использования Google Test

## Начальная стадия

  1. Скомпилировать Google Test в библиотеку.
  1. Создать новое консольное приложение (test suite)\
     и прилинковать к нему библиотеку Google Test.
  1. Добавить тесты.
  1. Скомпилировать приложение с тестами и запустить его.

## Основная стадия

  - Новые тесты добавляются в тот же test suite, их могут быть тысячи.
  - При необходимости test suite разбивается на несколько
    - Корректность и производительность
    - Быстрый (pre-commit) и полный (ночной)

# Ключевые моменты

  1. Создание тестов — это составляющая самого процесса программирования.
  1. Без тестов нет уверенности в работоспособности кода.
  1. Весь продуктовый код должен быть покрыт автоматическими модульными тестами.
  1. Автоматические unit-тесты должны прогоняться при каждом новом добавлении
     кода.
  1. Ежедневно должно проводиться полное тестирование проекта, желательно с
     публикацией тестовых дистрибутивов (nightly builds).

# Контрольные вопросы

  1. Классификация тестов по назначению.
  1. Современная стратегия тестирования (основные 5 утверждений).
  1. Основные возможности фреймворков модульного тестирования.
  1. Критерии хорошего теста.
  1. Возможности Google Test.
  1. Порядок использования Google Test.

# Ссылки

  1. [GTest](gtest)
  1. [Google Test Talk](gtest_talk)

# Спасибо!

Вопросы?

<!-- LINKS -->

[wiki_testing]: http://ru.wikipedia.org/wiki/Тестирование_программного_обеспечения
[gtest]:        http://code.google.com/p/googletest/
[gtest_bar]:    http://code.google.com/p/gtest-gbar/
[gtest_talk]:   https://docs.google.com/presentation/d/1miS-qttABKfkIT9TG_HU6Kn3FrxZ9VNHD7nHIL4_3wE/present#slide=id.i81
