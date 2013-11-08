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
    case sKilometer: {
        value = value*1000000;
        break;
        }
    case sMeter: {
        break;
        }
    case sFoot: {
        value = value*0.0929;
        break;
        }
    case acre: {
        value = value*4047;
        break;
        }
    case ar: {
        value = value*100;
        break;
        }
    case hectare: {
        value = value*10000;
        break;
        }
    }
}

double AreaConverter::ConvertToNewType(AreaType newType) {
    ConvertToMeters();
    switch (newType) {
    case sMeter: {
        curType = newType;
        return value;
        }
    case sKilometer: {
        curType = newType;
        return value = value/1000000;
        }
    case sFoot: {
        curType = newType;
        return value = value/0.0929;
        }
    case ar: {
        curType = newType;
        return value = value/100;
        }
    case acre: {
        curType = newType;
        return value = value/4047;
        }
    case hectare: {
        curType = newType;
        return value = value/10000;
        }
    }
    return 0;
}
