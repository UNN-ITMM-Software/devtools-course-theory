Сабанов Денис: Конвертер площадей
====================================

Класс ``AreaConverter`` предназначен для конвертации площадей. Он предоставляет методы для перевода разных типов площадей.
Конвертер поддерживает следующие типы площадей:квадратный километр,гектар,ар(сотка),акр,квадратный метр,квадратный фут.
В данной программе используемые типы площадей обозначены следующим образом:
 * квадратный километр - ``sKilometer``
 * гектар - ``hectare``
 * ар(сотка) - ``ar``
 * акр - ``acre``
 * квадратный метр - ``sMeter``
 * квадратный фут - ``sFoot``


.. code-block:: cpp
 
 class AreaConverter
 {
 public:
	double Convert(double value,AreaType type);
	double GetValue();
	AreaType GetAreaType();
	void SetValue(double value);
	void SetAreaType(AreaType type);	
 };
	
Пример использования:
---------------------
В данном примере программа переводит 100 квадратных метров в акры 

.. code-block:: cpp

 AreaConverter Converter;
 Converter.SetAreaType(sMeter);
 Converter.Convert(100,Converter.GetAreaType());
 
 
 
