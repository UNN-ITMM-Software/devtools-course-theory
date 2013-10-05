Мошков Юрий: Рассчет расстояний между float векторами
====================================

Класс ``DistanseBetweenVectors`` предназначен для расчета расстояний между векторами. Он предоставляет методы для расчета расстояний между векторами L1, L2, L3, L4, LInfinity метрики.


.. code-block:: cpp

 enum VectorSize{L1, L2, L3, L4, LInfinity};

class DistanseBetweenVectors
{
public:
	static float CalculateDistance(float *vector1, float *vector2, VectorSize vectorSize, int sizeVector = 0);
};
	
Пример использования:
---------------------

.. code-block:: cpp

DistanseBetweenVectors::CalculateDistance(new float[2], new float[2], L2);