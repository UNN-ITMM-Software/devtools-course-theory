/* Copyright 2013 Denis Sabanov */
#include <AreaConverter.h>

AreaConverter::AreaConverter(double value_, AreaType type_)
: value(10), curType(sMeter) {
    value = value_;
    curType = type_;
}

AreaConverter::~AreaConverter(void) {}

double AreaConverter::GetValue() {
    return value;
}

AreaType AreaConverter::GetAreaType() {
    return curType;
}

void AreaConverter::SetValue(double newValue) {
    value = newValue;
}

void AreaConverter::SetAreaType(AreaType newType) {
    curType = newType;
}

void AreaConverter::ConvertToMeters() {
    switch (GetAreaType()) {
    case sKilometer:
        value = value*1000000;
        break;
    case sMeter:
        break;
    case sFoot:
        value = value*0.0929;
        break;
    case acre:
        value = value*4047;
        break;
    case ar:
        value = value*100;
        break;
    case hectare:
        value = value*10000;
        break;
    }
}

double AreaConverter::ConvertToNewType(AreaType newType) {
    ConvertToMeters();
    switch (newType) {
    case sMeter:
        curType = newType;
        break;
    case sKilometer:
        curType = newType;
        value = value/1000000;
        break;
    case sFoot:
        curType = newType;
        value = value/0.0929;
        break;
    case ar:
        curType = newType;
        value = value/100;
        break;
    case acre:
        curType = newType;
        value = value/4047;
        break;
    case hectare:
        curType = newType;
        value = value/10000;
        break;
        }
    return value;
}
