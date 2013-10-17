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
		struct Event{
			double value;
			double probability;
		};

		bool PutSample(const std::vector<Event>& in_sample);
		std::vector<Event> GetSample();

		double GetExpectedValue();
		double GetDispersion();
		double GetPrimaryMoment(int level);
		double GetCentralMoment(int level);

		// проверяет правильность добавленной выборки 
		bool GetSampleStatus();
	};

Пример использования класса:

.. code-block:: cpp

	MathQuanCalc mqCalc;

	MathQuanCalc::Event event;
	std::vector<MathQuanCalc::Event> sample; // создание ряда распределения
	
	event.value = 1;
	event.probability = 1/2;
	sample.push_bask(event); // добавление значения и вероятности

	event.value = 2;
	event.probability = 1/2;
	sample.push_bask(event); // добавление значения и вероятности

	if(mqCalc.PutSample(sample)){ // добавление ряда распределения в калькулятор
		try{
			double expVal = mqCalc.GetExpectedValue(); // пробуем получить мат.ожидание
			// мат. ожидание полученно 
		}
		catch(std::string& str){
			// что-то пошло не так
		}
		try{
			double dispertion = mqCalc.GetDispertion(); // пробуем получить дисперсию
			// дисперсия получена
		}
		catch(std::string& str){
			// что-то пошло не так
		}
	}
