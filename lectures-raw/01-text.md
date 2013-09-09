# Обработка текста

![](./lectures-raw/01-text/Image_carpenters_1.jpg)

Кирилл Корняков (Itseez, ННГУ)  
Сентябрь 2013

# Содержание

- Сравнение бинарного и текстового форматов
- Примеры использования текстового формата
- Современные языки разметки, используемые программистами
- Примеры использования Markdown

<!--
01. Обработка текста / Текстовые редакторы
  - Преимущества plain-text формата (diff)
    - Также недостатки и сравнение с бинарным форматом
    - GraphVis, PlantUML, latex, Документация (reference manual), scripts
    - Современные языки разметки: Markdown, Textile, MediaWiki
    - Wiki, книги, Slides, Web-publishing (блоггинг с Jekyll?)
  - Обработка текста / Текстовые редакторы
    - Редакторы: Sublime, vim, Emacs
    - Манипуляции (навигация, сортировка, сниппеты и макросы)
    - Regular expressions
-->

# Форматы

**Текстовый файл** — компьютерный файл, содержащий текстовые данные, как 
правило, организованные в виде строк.

Пример CSV-файла:

```
1997,Ford,E350,"ac, abs, moon",3000.00
1999,Chevy,"Venture ""Extended Edition""","",4900.00
1996,Jeep,Grand Cherokee,"MUST SELL!
air, moon roof, loaded",4799.00
```

# Форматы

**Двоичный (бинарный) файл** — в широком смысле: последовательность произвольных
байтов. В узком смысле слова двоичные файлы противопоставляются текстовым файлам.

```
00000000  89 50 4e 47 0d 0a 1a 0a  00 00 00 0d 49 48 44 52  |.PNG........IHDR|
00000010  00 00 00 87 00 00 00 a0  08 03 00 00 00 11 90 8f  |................|
00000020  b6 00 00 00 04 67 41 4d  41 00 00 d6 d8 d4 4f 58  |.....gAMA.....OX|
00000030  32 00 00 00 19 74 45 58  74 53 6f 66 74 77 61 72  |2....tEXtSoftwar|
00000040  65 00 41 64 6f 62 65 20  49 6d 61 67 65 52 65 61  |e.Adobe ImageRea|
00000050  64 79 71 c9 65 3c 00 00  03 00 50 4c 54 45 22 22  |dyq.e<....PLTE""|
00000060  22 56 56 56 47 47 47 33  33 33 30 30 30 42 42 42  |"VVVGGG333000BBB|
00000070  4b 4b 4b 40 40 40 15 15  15 4f 4f 4f 2c 2c 2c 3c  |KKK@@@...OOO,,,<|
00000080  3c 3c 3e 3e 3e 3a 39 39  04 04 04 1d 1d 1d 35 35  |<<>>>:99......55|
00000090  35 51 50 50 37 37 37 11  11 11 25 25 25 0d 0d 0d  |5QPP777...%%%...|
000000a0  27 27 27 1a 1a 1a 38 38  38 2a 2a 2a 08 08 08 20  |'''...888**... |
000000b0  20 20 17 17 17 2e 2e 2e  13 13 13 bb bb bb 88 88  |  ..............|
```

# Преимущества бинарного формата

> 1. Минимальный размер — не содержат "разметки", часто являются сжатыми.
  1. "Нативное" представление данных, иногда допускают прямую (а значит быструю)
     загрузку в оперативную память.
  1. Эффективность некоторых операций: поиск элементов, иногда вставка и удаление.

# Преимущества текстового формата

> 1. Воспринимаемость человеком — просто понять структуру и содержание, даже через много лет.
  1. Простота — формат крайне удобен и его можно изменять огромным количеством инструментов.
  1. Версионируемость — изменения в текстовых файлах очень просто найти.
  1. Переносимость — текстовый файл может быть прочитан на любой системе или ОС.
  1. Устойчивость — каждое слово и символ в таком файле самодостаточны и, если случится повреждение байтов в таком файле, то обычно можно восстановить данные или продолжить обработку остального содержимого.

# Примеры файлов: TXT

BSD 3-Clause License

```
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

    (1) Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer. 

    (2) Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in
    the documentation and/or other materials provided with the
    distribution.  
```

# Примеры файлов: XML

GoogleTest output

```
<?xml version="1.0" encoding="UTF-8"?>
<testsuites tests="1682" failures="0" disabled="0" errors="0" timestamp="2013-09-09T09:42:14" time="19.139" cv_version="2.4.6.1" cv_vcs_version="2.4.6.1-389-g6ebfa87" cv_parallel_framework="gcd" cv_cpu_features="sse sse2 sse3 ssse3" cv_module_name="core" cv_implementation="plain" cv_num_threads="-1" name="AllTests">
  <testsuite name="Size_MatType_abs" tests="16" failures="0" disabled="0" errors="0" time="3.522">
    <testcase name="abs/0" value_param="(640x480, 8SC1)" status="run" time="0.05" classname="Size_MatType_abs" bytesIn="307200" bytesOut="307200" term="0" samples="100" outliers="3" frequency="1000000000" min="459070" median="479775" gmean="484118" gstddev="0.049859" mean="484726" stddev="24937" />
    <testcase name="abs/1" value_param="(640x480, 8SC4)" status="run" time="0.209" classname="Size_MatType_abs" bytesIn="1228800" bytesOut="1228800" term="0" samples="100" outliers="1" frequency="1000000000" min="1845350" median="1916669" gmean="2025727" gstddev="0.139772" mean="2047351" stddev="329475" />
    <testcase name="abs/2" value_param="(640x480, 32SC1)" status="run" time="0.015" classname="Size_MatType_abs" bytesIn="1228800" bytesOut="1228800" term="0" samples="100" outliers="3" frequency="1000000000" min="127433" median="128503" gmean="131656" gstddev="0.052733" mean="131844" stddev="7356" />
    <testcase name="abs/3" value_param="(640x480, 32FC1)" status="run" time="0.014" classname="Size_MatType_abs" bytesIn="1228800" bytesOut="1228800" term="0" samples="100" outliers="4" frequency="1000000000" min="121615" median="123016" gmean="126257" gstddev="0.069440" mean="126578" stddev="9673" />
    <testcase name="abs/4" value_param="(1280x720, 8SC1)" status="run" time="0.144" classname="Size_MatType_abs" bytesIn="921600" bytesOut="921600" term="0" samples="100" outliers="2" frequency="1000000000" min="1380084" median="1415141" gmean="1428763" gstddev="0.035451" mean="1429665" stddev="51832" />
    <testcase name="abs/5" value_param="(1280x720, 8SC4)" status="run" time="0.728" classname="Size_MatType_abs" bytesIn="3686400" bytesOut="3686400" term="0" samples="100" outliers="0" frequency="1000000000" min="5582443" median="6556922" gmean="7039714" gstddev="0.205895" mean="7193720" stddev="1551553" />
    <testcase name="abs/6" value_param="(1280x720, 32SC1)" status="run" time="0.078" classname="Size_MatType_abs" bytesIn="3686400" bytesOut="3686400" term="0" samples="100" outliers="1" frequency="1000000000" min="589331" median="666260" gmean="684319" gstddev="0.110956" mean="688650" stddev="80689" />
    <testcase name="abs/7" value_param="(1280x720, 32FC1)" status="run" time="0.07" classname="Size_MatType_abs" bytesIn="3686400"
```

# Примеры файлов: YAML

TravisCI configuration file

```
language: cpp
compiler:
  - gcc
  - clang
before_script:
  - ./configure --enable-version=18
script: rake travis
branches:
  only:
    - master
    - compiler
notifications:
  recipients:
    - evan+notify@phx.io
    - brixen@gmail.com
    - d.bussink@gmail.com
  email:
    on_success: change
    on_failure: always
rvm:
  - 1.8.7
  - 1.9.3
```

# Graphviz

+-------------------------------------+----------------------------------------+
|```                                  |![](./lectures-raw/01-text/cluster.png) |   
|digraph G {                          |                                        |
|                                     |                                        |
|  subgraph cluster_0 {               |                                        |
|    style=filled;                    |                                        |
|    color=lightgrey;                 |                                        |
|    node [style=filled,color=white]; |                                        |
|    a0 -> a1 -> a2 -> a3;            |                                        |
|    label = "process #1";            |                                        |
|  }                                  |                                        |
|                                     |                                        |
|  subgraph cluster_1 {               |                                        |
|    node [style=filled];             |                                        |
|    b0 -> b1 -> b2 -> b3;            |                                        |
|    label = "process #2";            |                                        |
|    color=blue                       |                                        |
|  }                                  |                                        |
|  start -> a0;                       |                                        |
|  start -> b0;                       |                                        |
|  a1 -> b3;                          |                                        |
|  b2 -> a3;                          |                                        |
|  a3 -> a0;                          |                                        |
|  a3 -> end;                         |                                        |
|  b3 -> end;                         |                                        |
|                                     |                                        |
|  start [shape=Mdiamond];            |                                        |
|  end [shape=Msquare];               |                                        |
|}                                    |                                        |
|```                                  |                                        |
+-------------------------------------+----------------------------------------+

# PlantUML

+------------------------------------+--------------------------------------------+
|```                                 |                                            |
|@startuml                           | ![](./lectures-raw/01-text/classes_012.png)|
|                                    |                                            |
|abstract class AbstractList         |                                            |
|abstract AbstractCollection         |                                            |
|interface List                      |                                            |
|interface Collection                |                                            |
|                                    |                                            |
|List <|-- AbstractList              |                                            |
|Collection <|-- AbstractCollection  |                                            |
|                                    |                                            |
|Collection <|- List                 |                                            |
|AbstractCollection <|- AbstractList |                                            |
|AbstractList <|-- ArrayList         |                                            |
|                                    |                                            |
|class ArrayList {                   |                                            |
|  Object[] elementData              |                                            |
|  size()                            |                                            |
|}                                   |                                            |
|                                    |                                            |
|enum TimeUnit {                     |                                            |
|  DAYS                              |                                            |
|  HOURS                             |                                            |
|  MINUTES                           |                                            |
|}                                   |                                            |
|                                    |                                            |
|annotation SuppressWarnings         |                                            |
|                                    |                                            |
|@enduml                             |                                            |
|```                                 |                                            |
+------------------------------------+--------------------------------------------+