Павел Коротаев: Калькулятор весов
=================================

Класс ``WeightConvertor`` предназначен для конвертации одной единицы измерения весов в другую. Каждый метод конвертирует введенную величину весов в указанную.


.. code-block:: cpp

	enum Unit {Ounce, Pound, Stone, Grams, Kilograms, Hundredweight, Ton};
	struct Weight
	{
    		double value;
    		Unit UnitInput;
    		Unit UnitOutput;
	};
	class WeightConvertor
	{
	public:
		WeightConvertor();
		virtual ~WeightConvertor(void);
		static Weight Convertor(Weight data);
	};


Пример использования класса


.. code-block:: cpp

	WeightConvertor Conv;
	Weight WeightConv;
	WeightConv.value = 100;
	WeightConv.UnitInput = Pound;
	WeightConv.UnitOutput = Stone;
	Conv.Convertor(WeightConv);