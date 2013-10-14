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
 private:
	double value;
 	AreaType curType;		
 public:
	double ConvertToSMeter(double value,AreaType type);
	double ConvertToSKilometer(double value,AreaType type);
	double ConvertToHectare(double value,AreaType type);
	double ConvertToAr(double value,AreaType type);
	double ConvertToAcre(double value,AreaType type);
	double ConvertToSFoot(double value,AreaType type);
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
 Converter.ConvertToAcre(100,Converter.GetAreaType());
 
 
 
