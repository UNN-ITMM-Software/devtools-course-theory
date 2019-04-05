# Рабочее окружение

![](./pix/unix-power-tools.jpg)

Кирилл Корняков (Intel, ННГУ)\
Апрель 2019

<!-- TODO
    - избежать повторений с лекцией про Automation
    - Демонстрация
-->

# Содержание

1. Базовое окружение
1. UNIX
1. Инструменты командной строки
1. Обработка текста

# Основные инструменты программиста

1. __Командная строка__
1. Текстовый редактор
1. Файловый менеджер
1. __Браузер__
1. Почтовый клиент
1. Мессенджеры

# Полезные инструменты

1. Глубокие буферы обмена (Clipy)
1. Синхронизация файлов (Google Drive, Dropbox)
1. Лаунчеры (Spotlight)
1. PuntoSwitcher (в пассивном режиме!!)

# История \*nix

UNIX появился в 70е годы. Создавался и разрабатывался инженерным и научным сообществом.

Примеры:

- SysV (from AT&T), BSD (from Berkeley), Solaris (Sun), IRIX (SGI), AIX (IBM), OSF1 (DEC)
- Linux (free software)
- macOS

# Философия UNIX

> This is the Unix philosophy:\
    — Write programs that do one thing and do it well.\
    — Write programs to work together.\
    — Write programs to handle text streams, because that is a universal interface.

 — Doug McIlroy

> The use of pipes and other features to combine “small, sharp tools” to accomplish larger tasks

 — Ken Thompson (father of Unix)

> “...at its heart is the idea that the power of a system comes more from the relationship among programs than from the programs themselves.”

 — Brian Kernighan & Rob Pike

# Примеры

Общая схема:

```bash
    $ program1 | program2 | program3
```

Занимаемое место в директории:

```bash
    $ du -sh * | sort -hr
```

Удаление пробелов в конце строки и замена tab'ов на 4 пробела:

```bash
    $ cp main.cpp main.cpp.bak && cat main.cpp.bak | sed 's/\t/    /g' | sed 's/\s*$//' > main.cpp
```

Количество просмотров видео на YouTube:

```bash
    $ curl "https://www.youtube.com/watch?v=M9ycFnR_V4I" 2>/dev/null | \
    sed -n 's/\(.*\)"view_count":"\([^"]*\)"\(.*\)/\2/p'
```

Удаление всех ветвей, влитых в `master`

```bash
alias git_delete_merged="git branch --merged | grep -v \"*\" | xargs -n 1 git branch -d"
```

# Навигация

Базовая

```bash
    $ cd # enter Home directory
    $ cd ..
    $ pwd
    $ ls # Files that start with a . are, by default, hidden
    $ ls -l
    $ ls -1
```

Продвинутая

```bash
    $ cd -- # https://github.com/aseetharam/common_scripts/blob/master/acd_func.sh
    $ j # autojump, Сила и мощь!!
```

# Базовые команды

```bash
    $ cp, rm, mv
    $ mkdir, rmdir
    $ find
```

# Полезные команды

```bash
    $ man ls
    $ top, htop
    $ kill
    $ cron
    $ wget, curl
    $ date
    $ time
    $ who, whoami
    $ yes
```

# Составные команды

```bash
    $ cmd1 | cmd2
    $ cmd1; cmd2
    $ cmd1 && cmd2
    $ cmd1 || cmd2
    $ { cmd1 ; cmd2 ; cmd2 ; }
    $ ( cmd1 ; cmd2 ; cmd2 )
```

# Работа с командами

- ↑, ↓, git ↑, git ↓ (но включите сперва историю команд)
- git TAB
- ctrl+u, ctrl+w, ctrl+k

```bash
    $ history
    # !n executes the nth command
    # !! executes the last command
    # !-n works backwards, from last command
    # !str – last command that starts w/str
    # ^src^targ^ substitute targ for src in last command
```

# Конфигурация ОС

- Концепция dotfiles <https://dotfiles.github.io>
    - Это крайне важно!!
- Что полезно сделать
    - Настройка приглашения
    - Создать алиасы под себя
    - Сохранить конфигурации bash, git, vim, emacs, etc

# Обработка текста

1. Просмотр
    - `cat/tac`, `head/tail`, `less`
1. Поиск
    - `grep`, `ack`, The Silver Searcher
1. TBD
    - `sort`, `uniq`, `wc`, `cut`
1. Обработка
    - `sed`, `awk`

# Grep examples

- `grep -nIHR "^#" --include=*.md ./`
    - Вывод всех заголовков в Markdown файлах ("`| wc -l`" добавит их подсчет)
- `grep -nIHR "class.*Matcher" --include=*.hpp -B1 ./`
    - Печать деклараций всех классов, содержащих слово Matcher (+одна строка до)

# Sed examples

Stream editor

  - `sed 's/foo/bar/g'` — заменяет foo на bar
  - `sed '/baz/s/foo/bar/g'` — то же самое, но если строка содержит baz
  - `sed 's/[ \t]*$//'` — удалить "висячие" пробельные символы
  - `sed '/regex/G'` — вставить пустую строку под каждой, содержащей "regex"
  - `sed 'n;n;n;n;G;'` — вставить пустую строку через каждые 5
  - `sed -n '$='` — посчитать количество строк
  - `sed '1,10d'` — удалить первые 10 строк файла

# Awk examples

> awk — pattern-directed scanning and processing language

Authors: Aho, Weinberger, Kernighan

Примеры:

  - `awk '{print NR "\t" $0}'` — распечатать файл с номерами строк
  - `awk 'END{print NR}'` — вывести число строк в файле
  - `awk '{print $2, $1}'` — распечатать второе и первое поле в обратном порядке
  - `awk '{s=0; for (i=1; i<=NF; i++) s=s+$i; print s}'` — вывести сумму полей для каждой строки
  - `awk '{sub(/[ \t]+$/, "")};1'` — удалить "висячие" пробельные символы
  - `awk '{l=length();s=int((79-l)/2); printf "%"(s+l)"s\n",$0}' filename` — центрировать и распечатать файл

# Составные примеры

  - Суммировать проценты в определенных строках лога

```bash
$ grep -nIHR "HPWL impr" ./vlsi.log | sed -n '1,5p' |
 awk '{ print $NF }' | awk '{for (i=1; i<=NF; i++) s=s+$i}; END{print s}'
```
 - Слить два текстовых файла в один отсортированный.\
   Попутно обрезать в одном файле все `.0` у координат

```bash
$ cat coords1.dat coords2.dat | sort | sed 's/.0//g' > output.dat
```

# Скриптовые языки

- Bash
- Perl
    - Practical Extraction and Report Language
    - Создан Ларри Уоллом, лингвистом по образованию
    - Замена для `awk` и `sed`
    - Богатые возможности по работе с текстом, встроенная в синтаксис поддержка регулярных выражений
- Python
    - Есть мнение, что он все-таки победил как язык общего назначения

# https://bash.im/quote/436725 (18+)

xxx: У нас тут YYY (билд инженера) сманили. Чел принципиально жил только в консоли и vim, диаграммы рисовал скриптами в dot, доки писал в wiki маркдауном, если что-либо требовало больше чем 1.5 минуты писал скрипт. Сидим разбираем его наследие.

xxx: Из прекрасного

xxx: smack-my-bitch-up.sh - шлет видимо его жене "Задержался на работе" и генерит отмазки из списка. Поставлено в cron, стреляет после 9 вечера если на рабочей станции висят интерактивные сессии по ssh с его логином.

xxx: kumar-mudak.sh - сканит почту, ищет письма от Кумара (заграничный ДБА с говорящей фамилией) с ключевыми словами (sorry, help и т.д.) откатывает упомянутую базу стейджинга на последний бэкап и отписывается типа не вопрос будь аккуратнее в следующий раз. Зело заколебал его Кумар вестимо.

xxx: badun.sh - поставлен на cron на определенные даты, шлет письма "плохо себя чувствую, поработаю из дома" опять же если к 8-45 утра не обнаружилось интерактивных сессий на рабочей станции.

xxx: И наконец первый приз: coffe-blyat.sh - ждет 17 сек (!!!) логинится по ssh в кофе-машину (епрст, мы и понятия не имели что она в сетке да и еще что на ней sshd поднят) и засылает туда какую-то абракадабру. Экспериментальным путем выяснили что ЭТО запускает процесс варения half-caf chai latte среднего размера, которое начинает выливаться в чашку как раз к тому моменту когда неспеша идущий человек добирается от его офиса до автомата.

<https://github.com/NARKOZ/hacker-scripts>

# Ключевые моменты

1. Установите и изучите инструменты командной строки
    - cat, less, head/tail
    - grep, sed, awk
1. Установите себе Linux, и проживите на нем несколько лет. Потом купите MacBook и живите нормальной жизнью :-)

# Контрольные вопросы

1. Предложите командную строку для:
    - Печати всех заголовков первого и второго уровня в файле Markdown (#-нотация)
    - Объявлений виртуальных методов в директории с исходниками

# Спасибо!

Вопросы?

# Демонстрация

1. Демонстрация `.dotfiles`
1. Переход в директорию с opencv
    - find . | wc -l
    - find . | awk -F . '{print $NF}' | sort | uniq -c | sort -r | head -n30
1. Переход в директорию со слайдами devtools
    - ag git
    - ag "\bGit\b"
    - ag "\bSublime\b"
1. Навигация по директориям
    - j между opencv и devtools c разными вариантами написания
1. Поиск файлов и внутри файлов
    - анализ лога из VLSI

# UNIX — OS для разработчиков

- Огромное количество утилит на любой случай жизни
    - find, cron, tar, sed, wget, curl
- Вместе со скриптовыми языками (Bash, Perl, Python, etc)\
  предоставляет широчайшие возможности для автоматизации

_Замечание: У любителей Windows нет поводов для расстройств!_
