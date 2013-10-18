Горохов Дмитрий: Решение квадратного уравнения
==============================================

Класс ``QuadraticEquation`` предназначен для решения квадратных уравнений.
Он предоставляет методы задания коэффициентов уравнения и решения уравнения.
Метод решения возвращает код, описывающий количество корней уравнения или 
сообщение о неправильных коэффициентах уравнения.

.. code-block:: cpp

    enum RootCount {TWOROOTS, ONEROOT, NOREALROOT, ILLEGALEQUATIONFORM};

    class QuadraticEquation
    {
    public:
	QuadraticEquation();
	QuadraticEquation(double _a, double _b, double _c);
	virtual ~QuadraticEquation();

	void SetCoefficients(double _a, double _b, double _c);
	int Solve(double &root1, double &root2);

    private:
	double a, b, c;
    };

Пример использования класса:

.. code-block:: cpp

    double r1, r2;
    int returnCode;
    QuadraticEquation Sample(1, 2, 1);
    returnCode = Sample.Solve(r1, r2);
    if(returnCode != NOREALROOT)
    {
        printf("Root 1: %.3f\n", r1);
	printf("Root 2: %.3f\n", r2);
    }
    else
    	printf("No real roots\n");