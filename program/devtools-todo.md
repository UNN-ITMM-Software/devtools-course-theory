# Cache
  - Послать задание на вторую лабу
    - Try MkDocs at the Read the docs
    - Consider CLion as recommended IDE

  - Спланировать следующую лабораторную
  - Имена всех CTest-тестов сливаются, вероятно нужно добавить префикс в виде
    фамилии
  - Нужно ли искать копипасту?
  - Нужно продумать план практики, если считается покрытие, то нужно его сразу
    требовать. Но может все будет нормально если первый проект собирается
    Makefile.

  - Rewrite testing bash script to Python

  - Code coverage
    - _Reach 100% code coverage_
    - Disable spam from coveralls (?)

# Practice
  - QA
    - Update `cpplint.py` script
      - Allow CXX extension
      - Git submodule as in Atom ?
    - <https://semaphoreapp.com>
    - Check interesting stuff <https://github.com/atom/atom-shell/blob/master/.travis.yml>
      - Enable testing on OSX

  - Docs
    - Change license to something more sane

# Theory
  - Сделать сайт для курса в виде `gh-pages` (можно, со всякими +1)

  - Add `COPYRIGHT` file, может все-таки назвать его `AUTHORS`
  - Нужно подумать над живыми демо.
    - Их хочется делать много, вероятно нужно выделить время на лекциях.
      Например через лекцию по 15-30 минут.
    - Или вообще отдельные пары посвящать практике.

  - Нужна лекция про скриптовые языки
  - Вероятно нужна отдельная лекция про UNIX и shell, подобно тому как сделано
    в курсе
  - Обновить лекцию про автоматизацию
    - Все про текст унести в текст
    -

# General
  - Можно организовать работу как написание своей С++ библиотеки (boost, dlib)
  - Build and publish Debian packages
  - Попросить помощи у студентов с мелкими задачами из этого списка
  - Разработать программу курса, явно выписать цели и задачи курса
  - Видеозапись лекций, видеозапись демо

# Cache
  - Automatic test case generation with tool bu upstream-checker authors
  - <https://www.coursera.org/course/startup>
  - Разделение на несколько репозиториев
    - devtools-course, devtools-course-practice, devtools-course-practice-2014
  - Обратную связь собирать в виде Google Form
  - Примеры shell команд
    - `find ./ | xargs file -I  | grep iso- | sed 's/:.*//g' | xargs -I{} recode windows-1251..u8 {}`
    - `find . -type f -name *.m | xargs sed -i '' 's/http:\/\/www.packtpub.com\/to-build-real-time%20computer%20vision%20applications%20for-ios-using-opencv\/book/http:\/\/bit.ly\/OpenCV_for_iOS_book/g'`

# Заметки для лекций

  - Реогранизация
    - Вынести программирование и метапрограммирование из лекции про проекты
    - Разделить лекцию по VCS на 2: общую и более Git-специфичную

  - Добавить материалы
    - Управление конфигурациями (версионирование, пакетирование, развертывание)
    - Автоматизация тестирования GUI, сюда же mock
    - По всей видимости нужна лекция по стилю, проектированию интерфейса. Это не
      совсем вписывается в инструменты, но это важная тема. Вероятно это можно
      совместить с документированием, пакетированием, управлением
      конфигурациями и так далее.

  - Взять материал из книг:
    - Включить главу про портабельность, см. книгу "Practice of Programming",
      вообще посмотреть на разбиение по главам оттуда
    - Инструменты тестирования по главе Физерса
    - Походный набор инструментов из прагматика
    - Что-то из Нила Форда
    - Посмотреть что было у Макконнелла (найти книгу)
    - Полистать Гудлифа

  - Представить курс в двух разрезах:
    - Приоритетность API > тестов > реализации (нарисовать диаграмму)
    - В целом нужно придумать логику преподнесения теории, отдельно продумать
      практику, а потом согласовать их.
    - я - код, я - команда, я - внешний мир
    - каскадная модель

  - Посмотреть на курс
    - <http://www.cs.drexel.edu/~kschmidt/CS265/index.html>
    - <https://www.cs.drexel.edu/~jjohnson/2004-05/winter/cs265.html>

# Лабораторные работы
  - Write Lab5 description
  - Переориентировать курс на QtCreator, CLion
  - Сделать так, чтобы тестирующий скрипт работал на Windows (переписать на Python)
  - CMake подключить как Git подмодуль
    - Вероятно лучше использовать нативный CMake вместо фреймворка Андрея

  - Sphinx
    - Понять как добавить индекс в Sphinx
    - Обеспечить возможность писать математические формулы в Sphinx, как здесь
      <http://theoretical-physics.net/0.1/_sources/src/relativity/chaptertwo.txt>

  - Экранировать точки и скобки в CTest
  - Потребовать более качественной документации на выходе
  - Развитие практики
    - Создание Python интерфейса (потом тесты и массовые эксперименты)
    - Использование CPack (сколько и какие пакеты?)
  - Запускать статический анализатор
    - cppcheck, <https://scan.coverity.com>, <http://en.wikipedia.org/wiki/SonarQube>
    - Add other linters: `cppcheck`, `oclint`

  - Собрать это все на Android, и запустить тесты
  - Doxygen
    - Поднять построение Doxygen документации
    - Можно ли проверять консистентность?
    - Можно ли автоматически публиковать ее куда-нибудь?

  - Следующий тест падает в проекте-примере:

```
add_test(
    NAME is_Show_Error_On_Very_Large_Numbers
    COMMAND ${appname} 10000000000 1 +
)
set_tests_properties (is_Show_Error_On_Very_Large_Numbers
  PROPERTIES PASS_REGULAR_EXPRESSION "Wrong number format!")
```
