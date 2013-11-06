/* Copyright 2013 Anna Zhbanova */
#include <Triangle.h>

#include <stdio.h>
#include <cstdlib>

#pragma pack(push, 1)
typedef struct Expression {
    PointXY A;
    PointXY B;
    PointXY C;
    PointXY parameter;
    int operation;
    Expression(): A(PointXY()), B(PointXY()), C(PointXY()) {
    }
};
#pragma pack(pop)

extern const char* massOperations[17];

const char* massOperations[17] = {"SetA", "SetB", "SetC", "GetA", "GetB",
                                 "GetC", "IsCorrect", "IsEquilateral",
                                 "IsIsosceles", "AB", "BC", "AC", "AngleA",
                                 "AngleB", "AngleC", "Square", "Perimeter"};

void help(const char* appname);
float parseFloat(const char* arg);
int parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("\n\nThis is an application ");
    printf("that calculates the basic parameters of the triangle(ABC)\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("The fractional part is introduced through the point.");
    printf("  $ %s <x1> <y1> <operation>\n\n", appname);
    printf("Where both arguments are float numbers, ");
    printf("and <operation> is one of\n");
    for (int i = 0; i < 3; i++)
        printf("<%d>%s\n", i, massOperations[i]);
    printf("\n  $ %s <x1> <y1> <x2> <y2> <x3> <y3> <operation>\n\n", appname);
    printf("Where all arguments are float numbers, ");
    printf("and <operation> is one of\n");
    for (int i = 3; i < 17; i++)
        printf("<%d>%s\n", i, massOperations[i]);
}

float parseFloat(const char* arg) {
    char* end;
    float value = static_cast<float>(strtod(arg, &end));

    if (!end[0]) {
        printf("%s is valid\n", arg);
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }

    return value;
}

int parseInteger(const char* arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (!end[0]) {
    } else {
        printf("%s is invalid\n", arg);
        throw "wrong number format";
    }

    return value;
}

Expression parseArguments(int argc, char** argv) {
    if (argc == 1) {
        help(argv[0]);
        exit(0);
    } else if (argc != 8 && argc != 4) {
        printf("ERROR: Should be 7 or 3 arguments.\n\n");
        help(argv[0]);
        exit(1);
    }

    Expression expression;
    if (argc == 8) {
        try {
            expression.A.x = parseFloat(argv[1]);
            expression.A.y = parseFloat(argv[2]);
            expression.B.x = parseFloat(argv[3]);
            expression.B.y = parseFloat(argv[4]);
            expression.C.x = parseFloat(argv[5]);
            expression.C.y = parseFloat(argv[6]);
        }
        catch(...) {
            printf("Wrong number format!\n");
            exit(2);
        }
        expression.operation = parseInteger(argv[7]);
        if ((expression.operation > 16) ||
            (expression.operation < 0)) {
            printf("%s - Wrong operation!\n", argv[7]);
            exit(3);
        } else {
            printf("%s is valid operation\n", argv[7]);
        }
    } else if (argc == 4) {
        try {
            expression.parameter.x = parseFloat(argv[1]);
            expression.parameter.y = parseFloat(argv[2]);
        }
        catch(...) {
            printf("Wrong number format!\n");
            exit(2);
        }

        expression.operation = parseInteger(argv[3]);
        if ((expression.operation >= 3) ||
            (expression.operation < 0)) {
            printf("%s - Wrong operation!\n", argv[3]);
            exit(3);
        } else {
            printf("%s is valid operation\n", argv[3]);
        }
    }
    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    Triangle triangle_obj(expr.A, expr.B, expr.C);
    PointXY result;
    switch (expr.operation) {
    case 0:
        triangle_obj.SetA(expr.parameter);
        result = triangle_obj.GetA();
        printf("Result A = (%.2f, %.2f)\n", result.x, result.y);
        break;
    case 1:
        triangle_obj.SetB(expr.parameter);
        result = triangle_obj.GetB();
        printf("Result B = (%.2f, %.2f)\n", result.x, result.y);
        break;
    case 2:
        triangle_obj.SetC(expr.parameter);
        result = triangle_obj.GetC();
        printf("Result C = (%.2f, %.2f)\n", result.x, result.y);
        break;
    case 3:
        result = triangle_obj.GetA();
        printf("Result A = (%.2f, %.2f)\n", result.x, result.y);
        break;
    case 4:
        result = triangle_obj.GetB();
        printf("Result B = (%.2f, %.2f)\n", result.x, result.y);
        break;
    case 5:
        result = triangle_obj.GetC();
        printf("Result C = (%.2f, %.2f)\n", result.x, result.y);
        break;
    case 6:
        if (triangle_obj.IsCorrect())
            printf("Result = Is correct\n");
        else
            printf("Result = Isn't correct\n");
        break;
    case 7:
        if (triangle_obj.IsEquilateral() == 1)
            printf("Result = Is equilateral\n");
        else if (triangle_obj.IsEquilateral() == -1)
            printf("Result = Isn't correct triangle\n");
        else
            printf("Result = Isn't equilateral\n");
        break;
    case 8:
        if (triangle_obj.IsIsosceles() == 1)
            printf("Result = Is isosceles\n");
        else if (triangle_obj.IsIsosceles() == -1)
            printf("Result = Isn't correct triangle\n");
        else
            printf("Result = Isn't isosceles\n");
        break;
    case 9:
        printf("Result AB = %.2f\n", triangle_obj.AB());
        break;
    case 10:
        printf("Result BC = %.2f\n", triangle_obj.BC());
        break;
    case 11:
        printf("Result AC = %.2f\n", triangle_obj.AC());
        break;
    case 12:
        printf("Result Angle A = %.2f\n", triangle_obj.AngleA());
        break;
    case 13:
        printf("Result Angle B = %.2f\n", triangle_obj.AngleB());
        break;
    case 14:
        printf("Result Angle C= %.2f\n", triangle_obj.AngleC());
        break;
    case 15:
        printf("Result square = %.2f\n", triangle_obj.Square());
        break;
    case 16:
        printf("Result perimeter = %.2f\n", triangle_obj.Perimeter());
        break;
    }

    return 0;
}
