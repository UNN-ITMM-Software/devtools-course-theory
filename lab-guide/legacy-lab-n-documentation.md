  1. Задокументируйте свой класс в стиле Sphinx, см. заготовку:
     [исходник](https://raw.github.com/UNN-VMK-Software/devtools-course/master/code/kirill-kornyakov/docs/simplecalc.rst),
     [результат](https://devtools.readthedocs.org/ru/latest/code/kirill-kornyakov/docs/simplecalc.html).
     - Необходимо создать rst-файл и поместить его в свою директорию `docs`.
     - Необходимо заполнить его, подробно описав (1) назначение класса, (2)
       сигнатуры публичных методов, (3) приведя примеры использования класса
       в пользовательском С++ коде.
     - Когда файл будет готов, его нужно будет включить в
       [корневой файл](https://raw.github.com/UNN-VMK-Software/devtools-course/master/docs/source/index.rst)
       с документацией.
  1. Проверить корректность построения документации можно двумя способами:
     - Локально. Вам нужно будет [установить Sphinx](http://sphinx-doc.org/latest/install.html),
       после чего построить документацию,
       пользуясь файлами из директории
       [docs](https://github.com/UNN-VMK-Software/devtools-course/tree/master/docs).
     - Онлайн. Вы можете индивидуально
       [подключить](https://read-the-docs.readthedocs.org/en/latest/getting_started.html#import-your-docs)
       свой репозиторий к сервису ReadTheDocs. Тогда вы сможете увидеть свою
       документацию подобно тому, как это сделано для всего проекта
       [devtools](https://devtools.readthedocs.org).
