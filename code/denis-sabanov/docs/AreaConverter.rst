Сабанов Денис: Конвертер площадей
====================================

Класс ``AreaConverter`` предназначен для конвертации площадей. Он предоставляет методы для перевода разных типов площадей.
Конвертер поддерживает следующие типы площадей:квадратный километр,гектар,ар(сотка),акр,квадратный метр,квадратный фут.


.. code-block:: cpp
 class AreaConverter
 {
 private:
	double value;
 	AreaType curType;		
 public:
	double ConvertToAll(double value,AreaType type);
	double GetValue();
	AreaType GetAreaType();
	void SetValue(double value);
	void SetAreaType(AreaType type);	
 };
	
Пример использования:
---------------------

.. code-block:: cpp

 AreaConverter Converter;
 Converter.SetAreaType(sMeter);
 Converter.ConvertToAll(100,Converter.GetAreaType());
