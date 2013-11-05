Мошков Юрий: Рассчет расстояний между float векторами
====================================

Класс ``DistanseBetweenVectors`` предназначен для расчета расстояний между векторами. Он предоставляет методы для расчета расстояний между векторами L1, L2, L3, L4, LInfinity метрики.


.. code-block:: cpp

 #include <math.h>

 enum TypeMetric{L1 = 1, L2, L3, L4, LInfinity};

 class DistanseBetweenVectors
 {
 public:
	 static float CalculateDistance(float *vector1, float *vector2, TypeMetric typeMetric, int sizeVector);
 };
	
Пример использования:
---------------------

.. code-block:: cpp

 const int sizeVector = 2;
 float vector1[sizeVector] = {1, 0};
 float vector2[sizeVector] = {2, 1};
 float distance = DistanseBetweenVectors::CalculateDistance(vector1, vector2, L2, sizeVector);