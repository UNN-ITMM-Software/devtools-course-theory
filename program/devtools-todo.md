# DevTools TODO

- infrastructure
    - python script that updates hall-of-fame colours based on pull-requests (move it to the slidy repo)
    - automate coherency check using travis-ci

- template project
    - fix code coverage (achieve 100%)
    - questions to Vlad
        - can we fail after cpplint failure?
    - реализовать оператор сравнения
    - вынести функцию `parseArguments`
    - добавить методы вычисления модуля и аргумента
  - practice
      - подготовить инфраструктуру для лабы по документации
      - add continuous deployment step (with semver!!)
      - implement a simple package manager with students, or use a real one

- theory
    - _продумать и проводить демонстрации, слайды оставлять на домашнее изучение_
    - replace waterfall picture
    - DVCS: implicit backup copying
    - pre-commit or pre-merge - find the right term?
    - books: add section to every lecture
    - строить курс вокруг (0) навыков, (1) инструментов и (2) практик разработки
    - introduce semver somewhere
      - binary
      - release/configuration management

# Theory

  - Infrastructure
    - Add `COPYRIGHT` file, можно назвать его `AUTHORS`
    - Собирать обратную связь в виде Google Form (освобождая от контрольной)

  - Нужно подумать над живыми демо
    - Их хочется делать много, вероятно нужно выделить время на лекциях.
      Например через лекцию по 15-30 минут.
    - Или вообще отдельные пары посвящать практике.
    - Видеозапись демо (микрофон)

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

  - Отладить проверку, отвергающую пулл-реквесты по именам

  - Лабы
    - Try doxygen at gh-pages
    - Try MkDocs at the Read the docs

  - Code coverage
    - _Reach 100% code coverage_
    - Disable spam from coveralls (?)

  - Общая организация
    - Можно организовать работу как написание общей С++ библиотеки (boost, dlib)
    - Build and publish Debian packages (использование CPack)
    - Потребовать более качественной документации на выходе
    - Переориентировать курс на Visual Studio Code (QtCreator или CLion)

  - Запускать статические анализаторы
    - cppcheck, <https://scan.coverity.com>, <http://en.wikipedia.org/wiki/SonarQube>
    - Add other linters: `cppcheck`, `oclint`

  - QA
    - Enable testing on OSX
    - Update `cpplint.py` script
      - Allow CXX extension
      - Git submodule as in Atom ?
    - Check interesting stuff
      - <https://github.com/atom/atom-shell/blob/master/.travis.yml>

  - Doxygen
    - Поднять построение Doxygen документации
    - Можно ли проверять консистентность?
    - Можно ли автоматически публиковать ее куда-нибудь?

  - Возможное развитие практики
    - Создание Python интерфейса (потом тесты и массовые эксперименты)
    - Собрать это все на Android, и запустить тесты
    - Экранировать точки и скобки в CTest (?)
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
