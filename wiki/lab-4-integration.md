-----

  - [Цели](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#Цели)
  - [Задачи](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#Задачи)
  - [Инструкции](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#Инструкции)
     - [Предварительная работа](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#Предварительная-работа)
     - [CMake](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#cmake)
     - [CTest](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#ctest)
     - [Консольная утилита](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#Консольная-утилита)
  - [Заключение](https://github.com/UNN-VMK-Software/devtools-course/wiki/Лабораторная-работа-%234-Интеграция#Заключение)

-----

## Цели

  1. Ознакомиться с инструментом CMake, опробовать его на примере построения
     кросс-платформенных библиотек и консольных утилит.
  1. Ознакомиться с инструментом тестирования CTest, узнать его основные
     возможности.
  1. Приобрести навыки создания кросс-платформенных утилит командной строки.

## Задачи

  1. Написать скрипты для построения своего проекта при помощи CMake.
  1. Переделать свое тестовое приложение в консольную утилиту,
     решающую поставленную задачу.
  1. Написать тесты на утилиту при помощи инструмента CTest. Эти тесты должны
     проверять поведение приложения как в случае корректных, так и некорректных
     входных аргументов.

## Инструкции

### Предварительная работа

  1. Скачайте последнее состояние upstream.
```
$ cd <devtools-course>
$ git checkout master
$ git fetch upstream
$ git merge upstream/master
```
  1. Создайте новую ветку.
```
$ git checkout -b lab4-SOMETHING
```
  1. Запустите имеющиеся тесты и убедитесь, что все они проходят.
```
$ cd ./code
$ ./build-and-test.sh
```

Все тесты должны проходить, и в конце вы должны увидеть вывод от CTest, который
запустит все тесты из проекта-примера.

### CMake

Первым шагом предстоит перевести свой проект на построение при помощи CMake.

  1. В своей директории нужно завести файл `CMakeLists.txt`.
  1. Затем его нужно заполнить подобно тому, как это сделано в проекте-примере
     (`kirill-kornyakov-lab4`). По сути вы должны объявить статическую
     библиотеку, затем консольное приложение, которое должно использовать эту
     библиотеку. На этом этапе тесты писать еще не нужно, поэтому последнюю
     строку (`include("CTestTests.txt")`) с подключением файла с тестами можно
     опустить.
  1. Когда файл будет готов, вы можете запустить тестирование и убедиться, что и
     библиотека, и консольное приложение собираются. Для этого нужно снова
     запустить скрипт `build-and-test.sh`. Библиотека должна появиться в
     директории `devtools-course/build_cmake/lib/`, а приложение в 
     `devtools-course/build_cmake/bin/`.
  1. Если компиляция проходит успешно, стоит сделать первый коммит и оправить
     пулл-реквест на предварительное тестирование на Travis:
```
$ cd <your-folder>
$ git add CMakeLists.txt
$ git commit -a -m "Added CMake script"
$ git push origin HEAD
```
  1. После этого заходим на GitHub, создаем пулл-реквест и ждем результатов
     тестирования на Travis. **Внимание:** огромная просьба дать пулл-реквесту
     адекватное название, например _"Корняков - Лабораторная работа #4"_. Если
     есть какие-то проблемы, исправляем их и обновляем пулл-реквест в той же
     последовательности: `git commit`, затем `git push`. Когда тесты будут
     проходить успешно, переходим к следующему шагу.

### CTest

Далее предстоит переделать свой сэмпл в консольную утилиту, и написать для нее
ряд тестов при помощи CTest.

  1. Создаем файл `CTestTests.txt` и кладем его в корне своей директории рядом 
     с `CMakeLists.txt`. Затем включаем этот файл в свой CMake путем добавления
     команды `include("CTestTests.txt")` как сделано в проекте-примере.
  1. После этого стоит написать простейший тест, проверяющий что ваше приложение
     вообще запускается. На этом этапе ваш файл `CTestTests.txt` должен
     выглядеть следующим образом:
```
enable_testing()

add_test( 
    NAME can_Run
    WORKING_DIRECTORY ${bin_dir}
    COMMAND ${appname}
)
```
  1. Уже сейчас можно выполнить повторное тестирование, снова запустив команду
     `build-and-test.sh`. Также рекомендуется снова сделать коммит и обновить
     пулл-реквест с целью тестирования.

### Консольная утилита

Далее начинается основная работа, во время которой собственно будет происходить
переделка утилиты и написание тестов для нее.

  1. Первым делом стоит сделать так, чтобы приложение, будучи запущенным без
     параметров, выводило небольшую инструкцию для пользователя. Затем стоит
     написать на этот случай тест, см. проект-пример.
  1. Далее стоит научить приложение разбирать корректно введенные аргументы,
     и реализовать тест, проверяющий это. Здесь же можно добавить еще несколько
     тестов на другие значения.
  1. После этого стоит заняться обработкой нестандартных ситуаций, таких как
     неправильное число аргументов или их неверный формат. И на каждый такой
     случай следует создать свой тест. Следует исходить из специфики своего
     приложения, тестировать следует тщательно, типичные сценарии можно
     подсмотреть в проекте-примере.
  1. Когда все разумные, и не очень, случаи будут покрыты, можно делать
     последний коммит и отправлять все на финальное тестирование. Когда все
     тесты будут запускаться и проходить, стоит оставить комментарий в своем
     пулл-реквесте, например "Готово к проверке". **Внимание:** это должен быть
     именно комментарий, а не описание или название пулл-реквеста.

## Заключение

На этом все. При поступлении замечаний просьба использовать тот же пулл-реквест,
добавляя в него коммиты и делая `git push` в свой форк.