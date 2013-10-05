Жбанова Анна: Треугольник, расчет основных параметров 
=====================================================

Класс ``Triangle`` предназначен  для расчета основных параметров треугольника
Он предоставляет методы:  
 *  проверки существования треугольника  
 *  проверки на равнобедренность
 *  проверки на равносторонность

расчета:  
 *  длин сторон   
 *  углов  
 *  площади  
 *  периметра   

.. code-block:: cpp

	struct PointXY 
	{
		float x;
		float y; 
	
		PointXY (float x_=0, float y_=0)
		{
			x = x_;
			y = y_;
		}
	};

	class Triangle
	{
	public:
		Triangle();
		Triangle(PointXY a_, PointXY b_, PointXY c_);
		virtual ~Triangle(void);
		
		float AB();
		float BC();
		float AC();

		float AngleA();
		float AngleB();
		float AngleC();

		float Square();
		float Perimeter();

		bool IsCorrect();
		bool IsEquilateral();
		bool IsIsosceles();

		PointXY GetA();
		PointXY GetB();
		PointXY GetC();

		void SetA(PointXY a_);
		void SetB(PointXY b_);
		void SetC(PointXY c_);
	private:
		PointXY a;
		PointXY b;
		PointXY c;
	};

Пример использования:  
---------------------
.. code-block:: cpp

	PointXY a(2,6),b(0,5),c(0,0);

	Triangle triangle_obj(a,b,c);

	if (triangle_obj.IsCorrect())
	{
		printf("Длина стороны AB %f\n", triangle_obj.AB());

		float AngleA = triangle_obj.AngleA();
					 
		float Square = triangle_obj.Square();
		
		bool Equilateral = triangle_obj.IsEquilateral();
		
	}
	else
		printf("Такого треугольника не существует!");