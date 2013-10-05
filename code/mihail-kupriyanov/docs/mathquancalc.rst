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

		bool GetMathWaiting(double& value);
		bool GetDispertion(double& value);
		bool GetPrimaryMoment(double& value, int level);
		bool GetCentralMoment(double& value, int level);

		// проверяет правильность добавленной выборки 
		bool GetSelectionStatus();
	};
