Павел Коротаев: Калькулятор весов
=================================

Класс ``WeightConvertor`` предназначен для конвертации одной единицы измерения весов в другую.
Каждый метод конвертирует введенную величину весов в указанную.


.. code-block:: cpp

	enum WeightUnit {Ounce, Pound, Stone, Grams, Kilograms, Hundredweight, Ton};
	struct Weight
	{
    		double value;
    		WeightUnit unit;
	};
	class WeightConvertor
	{
	public:
		WeightConvertor(void);
		virtual ~WeightConvertor(void);
		Weight ConvertTo(Weight weight, WeightUnit UnitOutput);
	};


Пример использования класса


.. code-block:: cpp

	WeightConvertor Conv;
	Weight weight;
	weight.value = 100;
	weight.unit = Pound;
	WeightUnit UnitOutput = Stone;
	Weight OutWeight = Conv.ConvertTo(weight, UnitOutput);