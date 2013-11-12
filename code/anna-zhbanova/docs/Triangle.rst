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

	class Triangle {
	public :
	    Triangle(PointXY a, PointXY b, PointXY c);
	    Triangle();
	    virtual ~Triangle(void);

	    float Length(char nameOfStartVertex, char nameOfEndVertex);
	    float Angle(char nameOfVertexAngle);

	    float Square();
	    float Perimeter();

	    bool IsCorrect();
	    int IsEquilateral();
	    int IsIsosceles();

	    PointXY Get(char nameVertex);
	    void Set(char nameVertex, PointXY coordinates);
	 private :
	    PointXY a;
	    PointXY b;
	    PointXY c;

	    float Length(PointXY point1, PointXY point2);
	    float Angle(PointXY endP1, PointXY vertexOfAngle, PointXY endP2);
	};


Пример использования:  
---------------------
.. code-block:: cpp

	PointXY a(2,6),b(0,5),c(0,0);

	Triangle triangle_obj(a,b,c);

	if (triangle_obj.IsCorrect())
	{
		printf("Длина стороны AB %f\n", triangle_obj.Length('a', 'b'));

		float AngleA = triangle_obj.AngleA();
					 
		float Square = triangle_obj.Square();
		
		int Equilateral = triangle_obj.IsEquilateral();
		
	}
	else
		printf("Такого треугольника не существует!");