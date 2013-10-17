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

	class Triangle
	{
	public:
		Triangle(PointXY a_ = 0, PointXY b_ = 0, PointXY c_ = 0);
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
	
		float Length (PointXY point1, PointXY point2);
		float Angle (PointXY end_point1, PointXY vertex_of_angle, PointXY end_point2);
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