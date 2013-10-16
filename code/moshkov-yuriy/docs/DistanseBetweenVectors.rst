Мошков Юрий: Рассчет расстояний между float векторами
====================================

Класс ``DistanseBetweenVectors`` предназначен для расчета расстояний между векторами. Он предоставляет методы для расчета расстояний между векторами L1, L2, L3, L4, LInfinity метрики.


.. code-block:: cpp

 enum TypeMetric{L1, L2, L3, L4, LInfinity};

 class DistanseBetweenVectors
 {
 public:
	 static float CalculateDistance(float *vector1, float *vector2, TypeMetric typeMetric, int sizeVector = 0);
 };
	
Пример использования:
---------------------

.. code-block:: cpp

 float vector1[2] = {1, 0};
 float vector2[2] = {2, 1};
 float distance = DistanseBetweenVectors::CalculateDistance(vector1, vector2, L2);