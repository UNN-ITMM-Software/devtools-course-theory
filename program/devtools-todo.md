# TODO

  - organizational
    - перенести занятия (_позвонить Жидкову_)
    - запросить списки групп

  - practice
    - Поговорить с Владом про возможную организацию практики
    - Определиться с порядком лаб
    - Подготовить задание для первой лабы
    - Ask Ilya
      - Поднять AppVeyor билд
      - Rewrite testing bash script to Python and test in on windows
    - приготовиться к первому живому демо
      - создать проект-шаблон для использования студентами

# Theory

  - Infrastructure
    - Add `COPYRIGHT` file, может все-таки назвать его `AUTHORS`
    - Собирать обратную связь в виде Google Form

  - Нужно подумать над живыми демо
    - Их хочется делать много, вероятно нужно выделить время на лекциях.
      Например через лекцию по 15-30 минут.
    - Или вообще отдельные пары посвящать практике.
    - Видеозапись демо (микрофон)

  - Материалы лекций
    - Вынести программирование и метапрограммирование из лекции про проекты
    - Вероятно нужна отдельная лекция про UNIX и shell,
      подобно тому как сделано в курсе
    - Нужна отдельная лекция про скриптовые языки
    - Лекцию про автоматизацию построить на основе книг
    - Все про текст унести в текст

  - Разработать программу курса, явно выписать цели и задачи курса
    - Представить курс в различных разрезах:
    - В целом нужно придумать логику преподнесения теории, отдельно продумать
      практику, а потом согласовать их.
    - я - код, я - команда, я - внешний мир
    - каскадная модель

  - Взять материал из книг:
    - Включить главу про портабельность, см. книгу "Practice of Programming",
      вообще посмотреть на разбиение по главам оттуда
    - Инструменты тестирования по главе Физерса
    - Походный набор инструментов из прагматика
    - Что-то из Нила Форда
    - Посмотреть что было у Макконнелла (найти книгу)
    - Полистать Гудлифа

  - Добавить материалы
    - Управление конфигурациями (версионирование, пакетирование, развертывание)
    - Автоматизация тестирования GUI, сюда же mock
    - По всей видимости нужна лекция по стилю, проектированию интерфейса. Это
      не совсем вписывается в инструменты, но это важная тема. Вероятно это
      можно совместить с документированием, пакетированием, управлением
      конфигурациями и так далее.

  - Посмотреть на курсы
    - <http://www.cs.drexel.edu/~kschmidt/CS265/index.html>
    - <https://www.cs.drexel.edu/~jjohnson/2004-05/winter/cs265.html>
    - <https://www.coursera.org/course/startup>

# Practice

  - Лабы
    - использовать чистый cmake
    - Try MkDocs at the Read the docs
    - Try doxygen at gh-pages

  - Имена всех CTest-тестов сливаются, вероятно нужно добавить префикс в виде
    фамилии
  - Можно организовать работу как написание своей С++ библиотеки (boost, dlib)
  - Build and publish Debian packages

  - QA
    - Update `cpplint.py` script
      - Allow CXX extension
      - Git submodule as in Atom ?
    - Check interesting stuff
      - <https://github.com/atom/atom-shell/blob/master/.travis.yml>
      - Enable testing on OSX

  - Code coverage
    - _Reach 100% code coverage_
    - Disable spam from coveralls (?)

  - Docs
    - Change license to something more sane

  - Переориентировать курс на QtCreator или CLion
  - Сделать так, чтобы тестирующий скрипт работал на Windows (переписать на Python)
  - Потребовать более качественной документации на выходе
  - Doxygen
    - Поднять построение Doxygen документации
    - Можно ли проверять консистентность?
    - Можно ли автоматически публиковать ее куда-нибудь?

  - Запускать статические анализаторы
    - cppcheck, <https://scan.coverity.com>, <http://en.wikipedia.org/wiki/SonarQube>
    - Add other linters: `cppcheck`, `oclint`

  - Возможное развитие практики
    - Экранировать точки и скобки в CTest (?)
    - Использование CPack (сколько и какие пакеты?)
    - Создание Python интерфейса (потом тесты и массовые эксперименты)
    - Собрать это все на Android, и запустить тесты
    - Нужно ли искать копипасту?
    - Нужно продумать план практики, если считается покрытие, то нужно его
      сразу требовать. Но может все будет нормально если первый проект
      собирается Makefile.

  - Следующий тест падает в проекте-примере:

```
add_test(
    NAME is_Show_Error_On_Very_Large_Numbers
    COMMAND ${appname} 10000000000 1 +
)
set_tests_properties (is_Show_Error_On_Very_Large_Numbers
  PROPERTIES PASS_REGULAR_EXPRESSION "Wrong number format!")
```

# Optional

  - Automatic test case generation with tool by upstream-checker authors
  - Примеры shell команд
    - `find ./ | xargs file -I  | grep iso- | sed 's/:.*//g' | xargs -I{} recode windows-1251..u8 {}`
    - `find . -type f -name *.m | xargs sed -i '' 's/http:\/\/www.packtpub.com\/to-build-real-time%20computer%20vision%20applications%20for-ios-using-opencv\/book/http:\/\/bit.ly\/OpenCV_for_iOS_book/g'`
  - Sphinx
    - Понять как добавить индекс в Sphinx
    - Обеспечить возможность писать математические формулы в Sphinx, как здесь
      <http://theoretical-physics.net/0.1/_sources/src/relativity/chaptertwo.txt>
