/* Copyright 2013 Anna Zhbanova */

#include "library/Triangle_application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>

#include "library/Triangle.h"

extern const char* operations[9];

const char* operations[9] = {"Set", "Get", "Angle", "Length",
                              "IsCorrect", "IsEquilateral", "IsIsosceles",
                              "Square", "Perimeter"};

void help(const char* appname);
float parseFloat(const char* arg);
int parseInteger(const char* arg);
NameOfVertex parseEnum(const char arg);
Expression parseArguments(int argc, char** argv);

void TriangleApplication::help(const char* appname) {
    message += std::string("\n\nThis is an application ")
    + std::string("that calculates the basic parameters of the triangle(ABC)\n\n")
    + std::string("Please provide arguments in the following format:\n\n")
    + std::string("The fractional part is introduced through the point.\n\n")

    + std::string("  $ ") + appname + std::string(" <x1> <y1> <nameOfVertex> <operation>\n\n")
    + std::string("Where both arguments are float numbers, ")
    + std::string("<nameOfVertex> is one of 'A', 'B' or 'C' ")
    + std::string("and <operation> is \n")
    + "<";
    char ch[10];
    itoa(0, ch, 10);
    message += ch + std::string(">") + operations[0]+std::string("\n\n")

    + std::string("  $ ") +appname + std::string(" <x1> <y1> <x2> <y2> <x3> <y3> <nameOfVertex> <operation>")
    + ("\n\nWhere all arguments are float numbers, ")
    + ("<nameOfVertex> is one of 'A', 'B' or 'C' ")
    + ("and <operation> is \n");
    for (int i = 1; i < 3; i++)
    {
        itoa(i, ch, 10);
        message += std::string("<") + ch + std::string(">") + operations[i]+std::string("\n");
    }

    message += std::string("  $ ") + appname + std::string(" <x1> <y1> <x2> <y2> <x3> <y3>")
    + ("<nameStartVertex> <nameEndVertex> <operation>")
    + ("\n\nWhere all arguments are float numbers, ")
    + ("<nameStartVertex> and <nameEndVertex> is one of 'A', 'B' or 'C' ")
    + ("and <operation> is \n")
    + "<";
    itoa(3, ch, 10);
    message += ch + std::string(">") + operations[3]+std::string("\n")

    + std::string("\n  $ ") + appname + std::string(" <x1> <y1> <x2> <y2> <x3> <y3> <operation>\n\n")
    + ("Where all arguments are float numbers, ")
    + ("and <operation> is one of\n");
    for (int i = 4; i < 9; i++)
    {
         itoa(3, ch, 10);
         message += std::string("<") + ch + std::string(">") + operations[i]+std::string("\n");
    }
}

float TriangleApplication::parseFloat(const char* arg) {
    char* end;
    float value = static_cast<float>(strtod(arg, &end));

    if (!end[0]) {
       // message = arg + std::string(" is valid\n");
    } else {
        message = arg + std::string(" is invalid\n");
        throw "wrong number format";
    }

    return value;
}

int TriangleApplication::parseInteger(const char* arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (!end[0]) {
    } else {
        message = arg + std::string(" is invalid\n");
        throw "wrong number format";
    }

    return value;
}

NameOfVertex TriangleApplication::parseEnum(const char arg) {
    NameOfVertex value = static_cast<NameOfVertex>(arg-65);
    if (value == A || value == B || value == C) {
    } else {
        message = arg + std::string(" is invalid\n");
        throw "wrong name of vertex";
    }
    return value;
}
Expression TriangleApplication::parseArguments(int argc, char** argv) {
    Expression expression;
    if (argc == 1) {
        help(argv[0]);
        return expression;
    } else if (argc != 5 && argc != 8 && argc != 9 && argc != 10) {
        message = ("ERROR: Should be 4, 7, 8 or 9 arguments.\n\n");
        help(argv[0]);
        return expression;
    }

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
            message = ("Wrong number format!\n");
            return expression;
        } }
    if (argc == 8) {
        try {
            expression.operation = parseInteger(argv[7]);
            if ((expression.operation > 8) ||
                (expression.operation < 4)) {
                message = std::string(argv[7]) + " - Wrong operation!\n";
                exit(3);
            } else {
                //message = std::string(argv[7]) + " is valid operation\n";
            }
        }
        catch(...) {
            message = ("Wrong operation format!\n");
            return expression;
        }
    } else if (argc == 5) {
        try {
            expression.parameter.x = parseFloat(argv[1]);
            expression.parameter.y = parseFloat(argv[2]);
        }
        catch(...) {
            message = ("Wrong number format!\n");
            return expression;
        }
        try {
            expression.nameOfStartVertex = parseEnum(*argv[3]);
            //message = std::string(argv[3]) + " is valid name of vertex\n";
        }
        catch(...) {
            message = ("Wrong name of vertex!\n");
            return expression;
        }
        try {
            expression.operation = parseInteger(argv[4]);
            if (expression.operation != 0) {
                message = std::string(argv[4]) + " - Wrong operation!\n";
                return expression;
            } else {
                //message = std::string(argv[4]) + " is valid operation\n";
            }
        }
        catch(...) {
            message = ("Wrong operation format!\n");
            return expression;
        } } else if (argc == 9) {
        try {
            expression.nameOfStartVertex = parseEnum(*argv[7]);
            //message = std::string(argv[7]) + " is valid name of vertex\n";
        }
        catch(...) {
            message = ("Wrong name of vertex!\n");
            return expression;
        }
        try {
            expression.operation = parseInteger(argv[8]);
            if (expression.operation < 1 || expression.operation > 2) {
                message = std::string(argv[8]) + " - Wrong operation!\n";
                return expression;
            } else {
                //message = std::string(argv[8]) + " is valid operation\n";
            }
        }
        catch(...) {
            message = ("Wrong operation format!\n");
            return expression;
        }
    } else if (argc == 10) {
        try {
            expression.nameOfStartVertex = parseEnum(*argv[7]);
            expression.nameOfEndVertex = parseEnum(*argv[8]);
            //message = std::string(argv[7]) + " is valid name of vertex\n";
            //message = std::string(argv[8]) + " is valid name of vertex\n";
        }
        catch(...) {
            message = "Wrong name of vertex!\n";
            return expression;
        }
        try {
            expression.operation = parseInteger(argv[9]);
            if (expression.operation != 3) {
                message = std::string(argv[9]) + " - Wrong operation!\n";
                return expression;
            } else {
                //message = std::string(argv[9]) + " is valid operation\n";
            }
        }
        catch(...) {
           message = "Wrong operation format!\n";
            return expression;
        }
    }
    return expression;
}

TriangleApplication::TriangleApplication() : message("") {}

std::string TriangleApplication::operator()(int argc, char** argv) {
    Expression expr = parseArguments(argc, argv);

    if(message != "")
        return message;
    Triangle triangle(expr.A, expr.B, expr.C);
    PointXY result;
    const int MAX_LEN = 256;
    char buff[MAX_LEN];

    switch (expr.operation) {
    case 0:
        triangle.Set(expr.nameOfStartVertex, expr.parameter);
        result = triangle.Get(expr.nameOfStartVertex);
        snprintf(buff, MAX_LEN, "Result %c = (%.2f, %.2f)\n", expr.nameOfStartVertex,
                 result.x, result.y);
        break;
    case 1:
        result = triangle.Get(expr.nameOfStartVertex);
        snprintf(buff, MAX_LEN, "Result %c = (%.2f, %.2f)\n", expr.nameOfStartVertex,
                                             result.x, result.y);
        break;
    case 2:
        snprintf(buff, MAX_LEN, "Result Angle %c = %.2f\n", expr.nameOfStartVertex,
                                       triangle.Angle(expr.nameOfStartVertex));
        break;
    case 3:
        snprintf(buff, MAX_LEN, "Result Length %c%c = %.2f\n",
                expr.nameOfStartVertex, expr.nameOfEndVertex,
                triangle.Length(expr.nameOfStartVertex, expr.nameOfEndVertex));
        break;
    case 4:
        if (triangle.IsCorrect())
            snprintf(buff, MAX_LEN, "Result = Is correct\n");
        else
            snprintf(buff, MAX_LEN, "Result = Isn't correct\n");
        break;
    case 5:
        if (triangle.IsEquilateral() == 1)
            snprintf(buff, MAX_LEN, "Result = Is equilateral\n");
        else if (triangle.IsEquilateral() == -1)
            snprintf(buff, MAX_LEN, "Result = Isn't correct triangle\n");
        else
            snprintf(buff, MAX_LEN, "Result = Isn't equilateral\n");
        break;
    case 6:
        if (triangle.IsIsosceles() == 1)
            snprintf(buff, MAX_LEN, "Result = Is isosceles\n");
        else if (triangle.IsIsosceles() == -1)
            snprintf(buff, MAX_LEN, "Result = Isn't correct triangle\n");
        else
            snprintf(buff, MAX_LEN, "Result = Isn't isosceles\n");
        break;
    case 7:
        snprintf(buff, MAX_LEN, "Result square = %.2f\n", triangle.Square());
        break;
    case 8:
        snprintf(buff, MAX_LEN, "Result perimeter = %.2f\n", triangle.Perimeter());
        break;
    }

    return std::string(buff);
}
