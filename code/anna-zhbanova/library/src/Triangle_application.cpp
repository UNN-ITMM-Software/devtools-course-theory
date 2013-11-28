/* Copyright 2013 Anna Zhbanova */

#include "library/Triangle_application.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "library/Triangle.hpp"

extern const char* operations[9];

const char* operations[9] = {"Set", "Get", "Angle", "Length",
                              "IsCorrect", "IsEquilateral", "IsIsosceles",
                              "Square", "Perimeter"};

TriangleApplication::TriangleApplication() : message("") {}

void TriangleApplication::help(const char* appname) {
    message += std::string("\n\nThis is an application ")
            + "that calculates the basic parameters of the triangle(ABC)\n\n"
            + "Please provide arguments in the following format:\n\n"
            + "The fractional part is introduced through the point.\n\n"

            + "  $ " + appname + " <x1> <y1> <nameOfVertex> <operation>\n\n"
            + "Where both arguments are float numbers, "
            + "<nameOfVertex> is one of 'A', 'B' or 'C' "
            + "and <operation> is \n"
            + "<";
    char ch[10];
    itoa(0, ch, 10);
    message += std::string(ch) + ">" + operations[0] + "\n\n"

            + "  $ " + appname + " <x1> <y1> <x2> <y2> <x3> <y3>"
            + " <nameOfVertex> <operation>"
            + "\n\nWhere all arguments are float numbers, "
            + "<nameOfVertex> is one of 'A', 'B' or 'C' and <operation> is \n";
    for (int i = 1; i < 3; i++) {
        itoa(i, ch, 10);
        message += std::string("<") + ch + ">" + operations[i] + "\n";
    }

    message += std::string("  $ ") + appname + " <x1> <y1> <x2> <y2> <x3> <y3>"
            + "<nameStartVertex> <nameEndVertex> <operation>"
            + "\n\nWhere all arguments are float numbers, "
            + "<nameStartVertex> and <nameEndVertex> is one of 'A', 'B' or 'C'"
            + " and <operation> is \n"
            + "<";
    itoa(3, ch, 10);
    message += std::string(ch) + ">" + operations[3] + "\n"

            + "\n  $ " + appname
            + " <x1> <y1> <x2> <y2> <x3> <y3> <operation>\n\n"
            + "Where all arguments are float numbers, "
            + "and <operation> is one of\n";
    for (int i = 4; i < 9; i++) {
         itoa(3, ch, 10);
         message += std::string("<") + ch + ">" + operations[i] + "\n";
    }
}

float TriangleApplication::parseFloat(const char* arg) {
    char* end;
    float value = static_cast<float>(strtod(arg, &end));

    if (end[0]) {
        throw "wrong number format";
    }

    return value;
}

int TriangleApplication::parseInteger(const char* arg) {
    char* end;
    int value = static_cast<int>(strtol(arg, &end, 10));

    if (end[0]) {
        throw "wrong number format";
    }

    return value;
}

NameOfVertex TriangleApplication::parseEnum(const char arg) {
    NameOfVertex value = static_cast<NameOfVertex>(arg-65);
    if (value == A || value == B || value == C) {
    } else {
        throw "wrong name of vertex";
    }
    return value;
}

bool TriangleApplication::parseArguments(int argc, const char** argv,
                                         Expression* expression) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5 && argc != 8 && argc != 9 && argc != 10) {
        message = ("ERROR: Should be 4, 7, 8 or 9 arguments.\n\n");
        help(argv[0]);
        return false;
    }

    if (argc == 8 || argc == 9 || argc == 10) {
        try {
            expression->A.x = parseFloat(argv[1]);
            expression->A.y = parseFloat(argv[2]);
            expression->B.x = parseFloat(argv[3]);
            expression->B.y = parseFloat(argv[4]);
            expression->C.x = parseFloat(argv[5]);
            expression->C.y = parseFloat(argv[6]);
        }
        catch(...) {
            message = ("Wrong number format!\n");
            return false;
        } }
    if (argc == 8) {
        try {
            expression->operation = parseInteger(argv[7]);
            if ((expression->operation > 8) ||
                (expression->operation < 4)) {
                message = std::string(argv[7]) + " - Wrong operation!\n";
                return false;
            }
        }
        catch(...) {
            message = ("Wrong operation format!\n");
            return false;
        }
    } else if (argc == 5) {
        try {
            expression->parameter.x = parseFloat(argv[1]);
            expression->parameter.y = parseFloat(argv[2]);
        }
        catch(...) {
            message = ("Wrong number format!\n");
            return false;
        }
        try {
            expression->nameOfStartVertex = parseEnum(*argv[3]);
        }
        catch(...) {
            message = ("Wrong name of vertex!\n");
            return false;
        }
        try {
            expression->operation = parseInteger(argv[4]);
            if (expression->operation != 0) {
                message = std::string(argv[4]) + " - Wrong operation!\n";
                return false;
            }
        }
        catch(...) {
            message = ("Wrong operation format!\n");
            return false;
        } } else if (argc == 9) {
        try {
            expression->nameOfStartVertex = parseEnum(*argv[7]);
        }
        catch(...) {
            message = ("Wrong name of vertex!\n");
            return false;
        }
        try {
            expression->operation = parseInteger(argv[8]);
            if (expression->operation < 1 || expression->operation > 2) {
                message = std::string(argv[8]) + " - Wrong operation!\n";
                return false;
            } else {
            }
        }
        catch(...) {
            message = ("Wrong operation format!\n");
            return false;
        }
    } else if (argc == 10) {
        try {
            expression->nameOfStartVertex = parseEnum(*argv[7]);
            expression->nameOfEndVertex = parseEnum(*argv[8]);
        }
        catch(...) {
            message = "Wrong name of vertex!\n";
            return false;
        }
        try {
            expression->operation = parseInteger(argv[9]);
            if (expression->operation != 3) {
                message = std::string(argv[9]) + " - Wrong operation!\n";
                return false;
            }
        }
        catch(...) {
           message = "Wrong operation format!\n";
            return false;
        }
    }
    return true;
}

std::string TriangleApplication::operator()(int argc, const char** argv) {
    const char *enum_name[] = {"A", "B", "C"};
    Expression expr;
    bool returnCode = parseArguments(argc, argv, &expr);
    if (returnCode != true)
         return message;

    if (message != "")
        return message;

    Triangle triangle(expr.A, expr.B, expr.C);
    PointXY result;
    std::ostringstream stream;
    stream << "Result ";
    stream.precision(3);
    switch (expr.operation) {
    case 0:
        triangle.Set(expr.nameOfStartVertex, expr.parameter);
        result = triangle.Get(expr.nameOfStartVertex);
        stream << enum_name[expr.nameOfStartVertex] << " = ("
               << result.x << ", " << result.y << ")\n";
        break;
    case 1:
        result = triangle.Get(expr.nameOfStartVertex);
        stream << enum_name[expr.nameOfStartVertex] << " = ("
        << result.x << ", " << result.y << ")\n";
        break;
    case 2:
        stream << "Angle " << enum_name[expr.nameOfStartVertex] << " = "
        << triangle.Angle(expr.nameOfStartVertex) << "\n";
        break;
    case 3:
        stream << "Length " << enum_name[expr.nameOfStartVertex]
        << enum_name[expr.nameOfEndVertex] << " = "
        << triangle.Length(expr.nameOfStartVertex, expr.nameOfEndVertex)
        << "\n";
        break;
    case 4:
        if (triangle.IsCorrect())
            stream << "= Is correct\n";
        else
            stream << "= Isn't correct\n";
        break;
    case 5:
        if (triangle.IsEquilateral() == 1)
            stream << "= Is equilateral\n";
        else if (triangle.IsEquilateral() == -1)
            stream << "= Isn't correct triangle\n";
        else
            stream << "= Isn't equilateral\n";
        break;
    case 6:
        if (triangle.IsIsosceles() == 1)
            stream << "= Is isosceles\n";
        else if (triangle.IsIsosceles() == -1)
            stream << "= Isn't correct triangle\n";
        else
            stream << "= Isn't isosceles\n";
        break;
    case 7:
        stream << "square = " << triangle.Square() << "\n";
        break;
    case 8:
        stream << "perimeter = " << triangle.Perimeter() << "\n";
        break;
    }

    message = stream.str();

    return message;
}
