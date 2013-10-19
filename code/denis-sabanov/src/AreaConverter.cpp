#include "AreaConverter.h"

double AreaConverter::GetValue()
{
	return value;
};

AreaType AreaConverter::GetAreaType()
{
	return curType;
};

void AreaConverter::SetValue(double newValue)
{
	value=newValue;
};

void AreaConverter::SetAreaType(AreaType newType)
{
	curType=newType;
}; 

double AreaConverter::Convert(AreaType newType)
{
	switch (GetAreaType())
	{
	case sKilometer:
		{
			value=value*1000000;
			break;
		}
	case sMeter:
		{
			break;
		}
	case sFoot:
		{
			value=value*0.0929;
			break;
		}
	case acre:
		{
			value=value*4047;
			break;
		}
	case ar:
		{
			value=value*100;
			break;
		}
	case hectare:
		{
			value=value*10000;
			break;
		}
	}
	switch(newType)
	{
	case sMeter:
		{
			curType=newType;
			return value;
		}
	case sKilometer:
		{
			curType=newType;
			return value=value/1000000;
		}
	case sFoot:
		{
			curType=newType;
			return value=value/0.0929;
		}
	case ar:
		{
			curType=newType;
			return value=value/100;
		}
	case acre:
		{
			curType=newType;
			return value=value/4047;
		}
	case hectare:
		{
			curType=newType;
			return value=value/10000;
		}
	}

}