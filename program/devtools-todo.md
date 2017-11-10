# TODO

- 2017
    - fix code coverage
    - questions to Vlad
        - can we fail after cpplint failure?
    - python script that updates hall-of-fame colours based on pull-requests
    - check clion

- slides devtools course todo
    - _начинать с демонстрации, слайды оставлять на домашнее изучение_
    - strange waterfall (replace it with something)
    - DVCS: implicit backup copying
    - pre-commit or pre-merge?
    - select and send books
    - semver

- control questions
    - update, automate coherency check
    - select must-know questions
    - setup automated check that validates correctness
      (or better adds another commit like with HTML pages)

  - строить курс вокруг (1) инструментов и (2) практик разработки

  - проект-шаблон
    - реализовать оператор сравнения
    - вынести функцию `parseArguments`
    - добавить методы вычисления модуля и аргумента

- practice
    - подготовить инфраструктуру для лабы по документации
    - implement a simple package manager with students, or use a real one
    - Поговорить с Владом про возможную организацию практики (CTest)

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

  - Отладить проверку, отвергающую пулл-реквесты по именам

  - Лабы
    - Try doxygen at gh-pages
    - Try MkDocs at the Read the docs

  - Code coverage
    - _Reach 100% code coverage_
    - Disable spam from coveralls (?)

  - Общая организация
    - Потребовать более качественной документации на выходе
    - Можно организовать работу как написание общей С++ библиотеки (boost, dlib)
    - Build and publish Debian packages (использование CPack)
    - Переориентировать курс на QtCreator или CLion

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

  - Docs
    - Change license to something more sane

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
