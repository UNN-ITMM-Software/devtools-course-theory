/* Copyright 2013 Anna Zhbanova */
#include <Triangle.h>

#include <stdio.h>
#include <cstdlib>

#pragma pack(push, 1)
struct Expression {
    PointXY A;
    PointXY B;
    PointXY C;
    PointXY parameter;
    char nameOfStartVertex;
    char nameOfEndVertex;
    int operation;
    Expression(): A(PointXY()), B(PointXY()), C(PointXY()),
                  parameter(PointXY()), nameOfStartVertex('a'),
                  nameOfEndVertex('b'), operation(0) {
    }
};
#pragma pack(pop)

extern const char* operations[11];

const char* operations[11] = {"Set", "Get", "Length",
                              "IsCorrect", "IsEquilateral", "IsIsosceles",
                          "AngleA", "AngleB", "AngleC", "Square", "Perimeter"};

void help(const char* appname);
float parseFloat(const char* arg);
int parseInteger(const char* arg);
Expression parseArguments(int argc, char** argv);

void help(const char* appname) {
    printf("\n\nThis is an application ");
    printf("that calculates the basic parameters of the triangle(ABC)\n\n");
    printf("Please provide arguments in the following format:\n\n");
    printf("The fractional part is introduced through the point.\n\n");

    printf("  $ %s <x1> <y1> <nameOfVertex> <operation>\n\n", appname);
    printf("Where both arguments are float numbers, ");
    printf("<nameOfVertex> is one of 'a', 'b' or 'c' ");
    printf("and <operation> is \n");
    printf("<%d>%s\n\n", 0, operations[0]);

    printf("  $ %s <x1> <y1> <x2> <y2> <x3> <y3> <nameOfVertex> <operation>",
                                                                    appname);
    printf("\n\nWhere all arguments are float numbers, ");
    printf("<nameOfVertex> is one of 'a', 'b' or 'c' ");
    printf("and <operation> is \n");
    printf("<%d>%s\n", 1, operations[1]);

    printf("  $ %s <x1> <y1> <x2> <y2> <x3> <y3>", appname);
    printf("<nameStartVertex> <nameEndVertex> <operation>");
    printf("\n\nWhere all arguments are float numbers, ");
    printf("<nameStartVertex> and <nameEndVertex> is one of 'a', 'b' or 'c' ");
    printf("and <operation> is \n");
    printf("<%d>%s\n", 2, operations[2]);

    printf("\n  $ %s <x1> <y1> <x2> <y2> <x3> <y3> <operation>\n\n", appname);
    printf("Where all arguments are float numbers, ");
    printf("and <operation> is one of\n");
    for (int i = 3; i < 11; i++)
        printf("<%d>%s\n", i, operations[i]);
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
    } else if (argc != 5 && argc != 9 && argc != 8 && argc != 10) {
        printf("ERROR: Should be 4, 7 8 or 9 arguments.\n\n");
        help(argv[0]);
        exit(1);
    }

    Expression expression;
    if (argc == 8 || argc == 9 || argc == 10) {
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
        } }
    if (argc == 8) {
        try {
            expression.operation = parseInteger(argv[7]);
            if ((expression.operation > 12) ||
                (expression.operation < 2)) {
                printf("%s - Wrong operation!\n", argv[7]);
                exit(3);
            } else {
                printf("%s is valid operation\n", argv[7]);
            }
        }
        catch(...) {
            printf("Wrong operation format!\n");
            exit(3);
        }
    } else if (argc == 5) {
        try {
            expression.parameter.x = parseFloat(argv[1]);
            expression.parameter.y = parseFloat(argv[2]);
        }
        catch(...) {
            printf("Wrong number format!\n");
            exit(2);
        }
        try {
            expression.nameOfStartVertex = *argv[3];
        if (expression.nameOfStartVertex != 'a' &&
               expression.nameOfStartVertex != 'b' &&
               expression.nameOfStartVertex != 'c') {
               printf("Wrong name of vertex!\n");
               exit(2);
            } else {
                printf("%s is valid name of vertex\n", argv[3]);
            }
        }
        catch(...) {
            printf("Wrong name of vertex!\n");
            exit(2);
        }
        try {
            expression.operation = parseInteger(argv[4]);
            if (expression.operation != 0) {
                printf("%s - Wrong operation!\n", argv[4]);
                exit(3);
            } else {
                printf("%s is valid operation\n", argv[4]);
            }
        }
        catch(...) {
            printf("Wrong operation format!\n");
            exit(3);
        } } else if (argc == 9) {
        try {
            expression.nameOfStartVertex = *argv[7];
            if (expression.nameOfStartVertex != 'a' &&
               expression.nameOfStartVertex != 'b' &&
               expression.nameOfStartVertex != 'c') {
               printf("Wrong name of vertex!\n");
               exit(2);
            } else {
                printf("%s is valid name of vertex\n", argv[7]);
            }
        }
        catch(...) {
            printf("Wrong name of vertex!\n");
            exit(2);
        }
        try {
            expression.operation = parseInteger(argv[8]);
            if (expression.operation != 1) {
                printf("%s - Wrong operation!\n", argv[8]);
                exit(3);
            } else {
                printf("%s is valid operation\n", argv[8]);
            }
        }
        catch(...) {
            printf("Wrong operation format!\n");
            exit(3);
        }
    } else if (argc == 10) {
        try {
            expression.nameOfStartVertex = *argv[7];
            expression.nameOfEndVertex = *argv[8];
            if ((expression.nameOfStartVertex != 'a' &&
               expression.nameOfStartVertex != 'b' &&
               expression.nameOfStartVertex != 'c') ||
               (expression.nameOfEndVertex != 'a' &&
               expression.nameOfEndVertex != 'b' &&
               expression.nameOfEndVertex != 'c')) {
               printf("Wrong name of vertex!\n");
               exit(2);
            } else {
                printf("%s is valid name of vertex\n", argv[7]);
            }
        }
        catch(...) {
            printf("Wrong name of vertex!\n");
            exit(2);
        }
        try {
            expression.operation = parseInteger(argv[9]);
            if (expression.operation != 5) {
                printf("%s - Wrong operation!\n", argv[9]);
                exit(3);
            } else {
                printf("%s is valid operation\n", argv[9]);
            }
        }
        catch(...) {
            printf("Wrong operation format!\n");
            exit(3);
        }
    }
    return expression;
}

int main(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);
    Triangle triangle(expr.A, expr.B, expr.C);
    PointXY result;
    switch (expr.operation) {
    case 0:
        triangle.Set(expr.nameOfStartVertex, expr.parameter);
        result = triangle.Get(expr.nameOfStartVertex);
        printf("Result %c = (%.2f, %.2f)\n", expr.nameOfStartVertex,
                                             result.x, result.y);
        break;
    case 1:
        result = triangle.Get(expr.nameOfStartVertex);
        printf("Result %c = (%.2f, %.2f)\n", expr.nameOfStartVertex,
                                             result.x, result.y);
        break;
    case 2:
        if (triangle.IsCorrect())
            printf("Result = Is correct\n");
        else
            printf("Result = Isn't correct\n");
        break;
    case 3:
        if (triangle.IsEquilateral() == 1)
            printf("Result = Is equilateral\n");
        else if (triangle.IsEquilateral() == -1)
            printf("Result = Isn't correct triangle\n");
        else
            printf("Result = Isn't equilateral\n");
        break;
    case 4:
        if (triangle.IsIsosceles() == 1)
            printf("Result = Is isosceles\n");
        else if (triangle.IsIsosceles() == -1)
            printf("Result = Isn't correct triangle\n");
        else
            printf("Result = Isn't isosceles\n");
        break;
    case 5:
        printf("Result Length %c%c = %.2f\n",
                expr.nameOfStartVertex, expr.nameOfEndVertex,
                triangle.Length(expr.nameOfStartVertex, expr.nameOfEndVertex));
        break;
    case 6:
        printf("Result Angle A = %.2f\n", triangle.AngleA());
        break;
    case 7:
        printf("Result Angle B = %.2f\n", triangle.AngleB());
        break;
    case 8:
        printf("Result Angle C = %.2f\n", triangle.AngleC());
        break;
    case 9:
        printf("Result square = %.2f\n", triangle.Square());
        break;
    case 10:
        printf("Result perimeter = %.2f\n", triangle.Perimeter());
        break;
    }

    return 0;
}
