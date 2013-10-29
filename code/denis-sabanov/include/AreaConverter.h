/* Copyright 2013 Denis Sabanov */
#ifndef CODE_DENIS_SABANOV_INCLUDE_AREACONVERTER_H_
#define CODE_DENIS_SABANOV_INCLUDE_AREACONVERTER_H_

enum AreaType {sKilometer, hectare, ar, acre, sMeter, sFoot};

class AreaConverter {
 public:
    AreaConverter(double _value, AreaType _type);
    virtual ~AreaConverter(void);

    double ConvertToNewType(AreaType newType);

    void SetValue(double newValue);
    void SetAreaType(AreaType newType);
    double GetValue();
    AreaType GetAreaType();
 private:
    double value;
    AreaType curType;

    void ConvertToMeters();
};

#endif  // CODE_DENIS_SABANOV_INCLUDE_AREACONVERTER_H_
