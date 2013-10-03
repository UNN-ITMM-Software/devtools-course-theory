Мошков Юрий: Рассчет расстояний между float векторами
====================================

Класс ``DistanseBetweenVectors`` предназначен для расчета расстояний между векторами. Он предоставляет методы для расчета расстояний между векторами L1, L2, L3, L4, LInfinity метрики.


.. code-block:: cpp

    class DistanseBetweenVectors
	{
	public:
		static float LInfinityVectors(float *vector1, float *vector2, int sizeVector);
		static float L1Vectors(float vector1, float vector2);
		static float L2Vectors(float vector1[2], float vector2[2]);
		static float L3Vectors(float vector1[3], float vector2[3]);
		static float L4Vectors(float vector1[4], float vector2[4]);
	}