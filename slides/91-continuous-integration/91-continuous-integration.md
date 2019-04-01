# Непрерывная интеграция

![](./pix/ci-title.png)

Кирилл Корняков (Intel, ННГУ)\
Александр Сморкалов (Intel)\
Апрель 2018

<!-- TODO
  - Написать ключевые моменты
  - Отдельный слайд про Jenkins
  - Написать подробнее про BuildBot
  - Рассмотреть конфиги Travis
  - Рассмотреть построение других артефактов (документация, дистрибы)
-->

# Содержание

  1. Практика непрерывной интеграции
  1. Инструменты автоматического анализа
  1. Системы непрерывной интеграции
  1. Travis CI
  1. BuildBot

# Жизненный цикл ПО

![](./pix/waterfall.jpg)

- Проблемы при интеграции ([Conway's law](https://en.wikipedia.org/wiki/Conway%27s_law))
- Экспоненциальный рост стоимости ошибок, медленная обратная связь
- В реальности с выходом в релиз жизнь ПО не заканчивается, а только начинается
- Критерий: максимально быстрый вывод новых требований в продукт!

# Современные тенденции

1. **Взаимопроникновение** процессов разработки, тестирования и развертывания
1. Глубокая **автоматизация** процессов
    - Everything-as-Code
    - Все участники процесса являются программистами (Software Engineer in Test, DevOps)

![](./pix/continuous-delivery.png)

# Сращивание разработки и тестирования ПО

 1. Тестировщики — тоже программисты. Автоматизация тестирования;
 1. Программист не только кодирует по ТЗ, но и отвечает за качество, пишет тесты;
 1. Тестовые фреймворки GTest, JUnit, PyUnit, etc;
 1. Удобный для тестирования код. Моки (mocks), заглушки (stubs) и эмуляция;
 1. TDD и подобные практики в разработке.

# Эволюция подходов к интеграции

Можно условно представить в виде следующих практик:

  - __Waterfall__: разделить на компоненты, реализовать, интеграция — отдельная фаза
  - __Nightly build ('90s)__: интегрироваться часто, ночной билд (heartbeet of the project)
  - __Continuous Integration ('00s)__: интегрироваться непрерывно, тестирование каждого вливания
  - __Pre-commit Testing ('10s)__: интегрироваться непрерывно, но после проверки стабильности
  - __Continuous Deployment ('10s)__: развертываться непрерывно, сразу после проверки стабильности

Если рассмотреть модель ветвления GitHub Flow, то куда перемещалось тестирование?

# Непрерывная интеграция

> __Непрерывная интеграция (англ. Continuous Integration)__ — практика разработки программного обеспечения, которая заключается в постоянном слиянии рабочих копий в общую основную ветвь разработки (до нескольких раз в день) и выполнении частых автоматизированных сборок проекта для скорейшего выявления потенциальных дефектов и решения интеграционных проблем.

![](./pix/continuous-integration.png)

Непрерывная сборка — это __сердцебиение__ вашего проекта.

# Задачи CI-сервера

  1. Ожидание триггера: git push, schedule, manual
  1. Получение исходного кода из репозитория
  1. Выполнение тестов и автоматических проверок
  1. Отправка отчетов (хранение истории и статистики)
  1. Сборка проекта (в том числе построение дистрибутивов)
  1. Развёртывание готового проекта

<center>![](./pix/bbot-overview.png)</center>

# Практики непрерывной интеграции

1. Поддержка системы контроля версий (СКВ);
1. Полностью автоматическая сборка ПО;
1. Самотестирующийся код. Тесты разрабатываются вместе с ПО;
1. Частые, небольшие изменения в репозитории;
1. Каждое измение собирается и тестируется;
1. Построение и тестирование должно быть быстрым;
1. Тестирование в таком же окружении как и "боевое";
1. Каждый видит результаты билда;
1. Продукты билда и тестов легко доступны.

# Влияние CI на процесс разработки

 1. CI — часть процесса разработки. Входит в список Agile практик;
 1. CI диктует специфические требования к архитектуре ПО и подходам разработке:
    - хорошая модульность;
    - быстрая автоматическая сборка и тестирование;
    - тесты разрабатываются вместе с ПО, возможно TDD.
 1. CI требует инструментальной поддержки:
    - СКВ с поддержкой удобного ветвления и слияния;
    - Инструменты автоматизации сборки и тестирования;
    - CI сервер и автоматизированная платформа для тестирования ПО.

# Автоматические проверки: Статический анализ

  - Проверки на корректность
    - Максимальный уровень предупреждений компилятора (нескольких компиляторов!)
    - Автоматический поиск ошибок (PVS-Studio, cppcheck, Coverity Scan)
    - Соответстиве стандартам (стандарт ASIL - инструмент LDRA)
  - Стиль кодирования (lint, vera++, cpplint.py)
    - Чистый код (именование, форматирование)
    - Анализ сложности кода
  - Специальные инструменты
    - [ABI compliance checker][abi]
    - Поиск IP проблем, например GPL кода

[Статический анализ кода][static-analysis] на Wikipedia

# Автоматические проверки: Динамический анализ

  - Анализ покрытия кода тестами (gcov, BullseyeCoverage)
  - Утечки памяти, гонки данных (Valgrind, BoundsChecker)
  - Анализ производительности (GoogleTest)
  - Intel Parallel Studio

# Google

![](./pix/how-google-tests-software.jpeg)

# Google Test Certified Program

![](./pix/google-test-certified.png)

<!-- TOC -->

# DevOps

![](./pix/Devops.png)

# DevOps

+----------------------+-----------------------------------------------------------------------------------------+
|![](./pix/devops2.png)| - Code — Code Development and Review, continuous integration tools                      |
|                      | - Build — Version control tools, code merging, Build status                             |
|                      | - Test — Test and results determine performance                                         |
|                      | - Package — Artifact repository, Application pre-deployment staging                     |
|                      | - Release — Change management, Release approvals, release automation                    |
|                      | - Configure — Infrastructure configuration and management, Infrastructure as Code tools |
|                      | - Monitor — Applications performance monitoring, End user experience                    |
+----------------------+-----------------------------------------------------------------------------------------+

<https://en.wikipedia.org/wiki/DevOps>

# Примеры CI-систем

  - **Cloud**
    - Travis CI
    - AppVeyor
    - [Drone.IO](https://drone.io)
  - **On-premises**
    - Hudson > Jenkins
    - BuildBot
    - CruiseControl (CruiseControl.NET)
    - TeamCity

# Travis CI

+---------------------+------------------------------------------------------------+
|![](./pix/travis.png)| - Официальный сайт проекта: <http://travis-ci.org>         |
|                     | - Веб-сервис для сборки и тестирования ПО                  |
|                     |   ([open-source](<https://github.com/travis-ci/travis-ci>))|
|                     | - Важными особенностями являются интеграция с GitHub       |
|                     |   и возможность бесплатного использования                  |
|                     | - Поддерживает большое количество языков: C, C++,          |
|                     |   Clojure, Erlang, Go, Groovy, Haskell, Java,              |
|                     |   JavaScript, Perl, PHP, Python, Ruby и Scala              |
|                     | - Тестирование происходит на виртуальных Linux-машинах,    |
|                     |   запускаемых в облаке Amazon (Amazon S3)                  |
+---------------------+------------------------------------------------------------+

# `devtools-course-practice / .travis.yml`

```YAML
language: cpp
compiler:
  - gcc
  - clang
install:
  - sudo pip install cpp-coveralls
before_script:
  - if [ "$CXX" = "g++" ]; then sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y; fi
  - if [ "$CXX" = "g++" ]; then sudo apt-get update -qq; fi
  - if [ "$CXX" = "g++" ]; then sudo apt-get install -qq g++-4.8; fi
  - if [ "$CXX" = "g++" ]; then export CXX="g++-4.8" CC="gcc-4.8"; fi
script:
  - cd ./code && ./build-and-test.sh
after_success:
  - coveralls --exclude code/3rdparty -E ".*\.cpp" --extension cxx --root ../ --build-root ../build_cmake
notifications:
  email: false
```

# `agile-course-practice / .travis.yml`

```YAML
language: java
jdk:
  - oraclejdk8
script:
  - cd code
  - TERM=dumb
  - gradle check
notifications:
  email: false
```

# `rubinius / .travis.yml`

```YAML
language: cpp
compiler:
  - gcc
  - clang
before_install:
  - echo $LANG
  - echo $LC_ALL
  - if [ $TRAVIS_OS_NAME == linux ]; then sudo apt-get install -y llvm-3.4 llvm-3.4-dev; fi
  - if [ $TRAVIS_OS_NAME == osx ]; then brew update && brew install llvm && brew link --force llvm; fi
  - rvm use $RVM --install --binary --fuzzy
  - gem update --system
  - gem --version
before_script:
  - travis_retry bundle
  - if [ $TRAVIS_OS_NAME == linux ]; then travis_retry ./configure --llvm-config llvm-config-3.4; fi
  - if [ $TRAVIS_OS_NAME == osx ]; then travis_retry ./configure --llvm-config /usr/local/opt/llvm/bin/llvm-config; fi
script: rake
branches:
  only:
    - master
    - 1.8.7
notifications:
  email:
    recipients:
      - brixen@gmail.com
      - d.bussink@gmail.com
    on_success: change
    on_failure: always
  irc:
    channels:
      - "chat.freenode.net#rubinius"
    template:
      - "%{repository}/%{branch} (%{commit} - %{author}): %{message}"
env:
  - RVM=2.0.0 LANG="en_US.UTF-8"
os:
  - linux
  - osx
osx_image: xcode61
```

# BuildBot

+------------------------+----------------------------------------------------------+
|![](./pix/bbot-logo.png)| - Официальный сайт проекта: <http://buildbot.net>        |
|                        | - Инструмент непрерывной интеграции                      |
|                        | - Используется в ряде крупных проектов: Chromium, WebKit,|
|                        |   Firefox, Python, OpenCV                                |
|                        | - Реализован на Python, как результат переносим и        |
|                        |   допускает кастомизацию (программирование билдеров)     |
|                        | - Проект разрабатывается на                              |
|                        |   [GitHub](<https://github.com/buildbot/buildbot>),      |
|                        |   тестируется при помощи                                 |
|                        |   [Travis CI](https://travis-ci.org/buildbot/buildbot/)  |
+------------------------+----------------------------------------------------------+

# BuildBot

<center>![](./pix/bbot-overview.png)</center>

# BuildBot

<center>![](./pix/bbot-console.png)</center>

# Ключевые моменты

1. Крайне важно минимизировать время от постановки задачи, до ее появления в готовом продукте
1. Это требует слаженного взаимодействия всех участников процесса, в особенности инженерной части
1. Как следствие, процессы проникают друг в друга, объедияясь в один
1. Параллельно, все автоматизируется и становится непрерывным конвейером
1. Практики и инструменты CI, CD и DevOps крайне полезны в этом процессе

# Контрольные вопросы

1. Определение непрерывной интеграции
1. Задачи выделенного сервера
1. Эволюция взглядов на непрерывную интеграцию
1. Travis CI, преимущества и недостатки
1. BuildBot, преимущества и недостатки

# Спасибо!

Вопросы?

<!--
# Преимущества автоматического развертывания

Процедуры инсталляции, обновления, восстановления, удаления требуют особого
внимания и важны не менее (а может и более), чем корректность собственно
приложения.

<center>![](./pix/production-readiness.png)</center>
-->

<!-- LINKS -->

[abi]: http://ispras.linuxbase.org/index.php/ABI_compliance_checker
[static-analysis]: https://ru.wikipedia.org/wiki/Статический_анализ_кода
