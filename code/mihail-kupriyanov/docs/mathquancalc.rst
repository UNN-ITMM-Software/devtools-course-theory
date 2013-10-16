Куприянов Михаил: Калькулятор математических величин
====================================================

Класс ``MathQuanCalc`` предназначен для подсчета математических величин. Он предоставляет методы для вычислений: матожидания, дисперсии, начальных и центральных моментов различных порядков.

.. code-block:: cpp

	class MathQuanCalc{
	public:
		MathQuanCalc();
		MathQuanCalc(const MathQuanCalc&);
		virtual ~MathQuanCalc();

		// структура описывающая значение принимаемое случайной величиной и его вероятность 
		struct SelQuan{
			double value;
			double chance;
		};

		bool PutSelection(const std::vector<SelQuan>& in_selection); 
		std::vector<SelQuan> GetSelection();

		bool GetExpectedValue(double* value);
		bool GetDispertion(double* value);
		bool GetPrimaryMoment(double* value, int level);
		bool GetCentralMoment(double* value, int level);

		// проверяет правильность добавленной выборки 
		bool GetSelectionStatus();
	};

Пример использования класса:

.. code-block:: cpp

	MathQuanCalc mqCalc;

	MathQuanCalc::SelQuan selQuan;
	std::vector<SelQuan> vSelQuan; // создание ряда распределения
	
	selQuan.value = 1;
	selQuan.chance = 1/2;
	vSelQuan.push_bask(selQuan); // добавление значения и вероятности

	selQuan.value = 2;
	selQuan.chance = 1/2;
	vSelQuan.push_bask(selQuan); // добавление значения и вероятности

	mqCalc.PutSelection(vSelQuan); // добавление ряда распределения в калькулятор

	if( mqCalc.GetSelectionStatus() == false ){
		// ряд распределения некорректен 
	}
	double expVal;
	if( mqCalc.GetExpectedValue(&expVal) == true ){
		// получено мат.ожидание
	}
	double dispertion;
	if( mqCalc.GetDispertion(&dispertion) == true ){
		// получена дисперсия
	}
