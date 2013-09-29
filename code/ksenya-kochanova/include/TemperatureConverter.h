class Temperature—onverter
{
public:
    Temperature—onverter();
    virtual ~Temperature—onverter();

    double CelsiyToKelvin(double temp);
    double CelsiyToFarengate(double temp);
	double CelsiyToNewton(double temp);

	double KelvinToCelsiy(double temp);
	double FarengateToCelsiy(double temp);
	double NewtonToCelsiy(double temp);


};