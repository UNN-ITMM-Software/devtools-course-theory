/* Copyright 2013 Anna Zhbanova */
#include <Triangle.h>

#include <stdio.h>

int main() {
    // некорректные данные
    PointXY a1(0, 6), b1(0, 5), c1(0, 0);
    // корректные данные
    PointXY a2(0, 0), b2(0, 3), c2(4, 0);

    Triangle incorrect_triangle_obj(a1, b1, c1);
    Triangle correct_triangle_obj(a2, b2, c2);

    if ( !incorrect_triangle_obj.IsCorrect() ) {
        printf("Incorrect data!\n");
        printf("A(%.2f; %.2f), \nB(%.2f; %.2f), \nC(%.2f; %.2f).\n\n",
            a1.x, a1.y, b1.x, b1.y, c1.x, c1.y);
    } else {
        printf("Correct data! \n");
        printf("A(%.2f; %.2f), \nB(%.2f; %.2f), \nC(%.2f; %.2f).\n\n",
            a1.x, a1.y, b1.x, b1.y, c1.x, c1.y);
    }

    if ( correct_triangle_obj.IsCorrect() ) {
        printf("Triangle: \n");
        printf("A(%.2f; %.2f), \nB(%.2f; %.2f), \nC(%.2f; %.2f)\n\n",
            correct_triangle_obj.GetA().x, correct_triangle_obj.GetA().y,
            correct_triangle_obj.GetB().x, correct_triangle_obj.GetB().y,
            correct_triangle_obj.GetC().x, correct_triangle_obj.GetC().y);

        printf("Length of the side AB = %.2f\n", correct_triangle_obj.AB());
        printf("Length of the side BC = %.2f\n", correct_triangle_obj.BC());
        printf("Length of the side AC = %.2f\n\n", correct_triangle_obj.AC());

        printf("Angle A = %.2f\n", correct_triangle_obj.AngleA());
        printf("Angle B = %.2f\n", correct_triangle_obj.AngleB());
        printf("Angle C = %.2f\n\n", correct_triangle_obj.AngleC());

        printf("Square of a triangle = %.2f\n",
            correct_triangle_obj.Square());
        printf("Perimeter of a triangle = %.2f\n\n",
            correct_triangle_obj.Perimeter());

        if ( correct_triangle_obj.IsEquilateral() )
            printf("Triangle is equilateral.");
        else
            printf("Triangle is not equilateral.\n");

        if ( correct_triangle_obj.IsIsosceles() )
            printf("Triangle is isosceles.\n");
        else
            printf("Triangle is not isosceles.\n\n");
    } else {
        printf("Incorrect data!\n");
        printf("A(%.2f; %.2f), \nB(%.2f; %.2f), \nC(%.2f; %.2f).\n\n",
            a2.x, a2.y, b2.x, b2.y, c2.x, c2.y);
    }

    return 0;
}
