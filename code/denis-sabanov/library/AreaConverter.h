/* Copyright 2013 Denis Sabanov */
#ifndef CODE_DENIS_SABANOV_LIBRARY_AREACONVERTER_H_
#define CODE_DENIS_SABANOV_LIBRARY_AREACONVERTER_H_

enum AreaType {sKilometer, hectare, ar, acre, sMeter, sFoot};

class AreaConverter {
 public:
    AreaConverter(double _value = 0, AreaType _type = sMeter);
    virtual ~AreaConverter(void);

    void ConvertToMeters();
    double ConvertToNewType(AreaType newType);

    double GetValue();
    AreaType GetAreaType();
    void SetValue(double newValue);
    void SetAreaType(AreaType newType);
 private:
    double value;
    AreaType curType;
};
#endif  // CODE_DENIS_SABANOV_LIBRARY_AREACONVERTER_H_
