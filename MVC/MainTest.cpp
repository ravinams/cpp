#include <fstream>
#include <iostream>

#include "GaussianModel.h"
#include "SineModel.h"
#include "GaussianView.h"
#include "SineView.h"
#include "Controller.h"

using namespace std;

int main(void)
{
	double dataValue = 0;

	GaussianParams aGaussian(5.0, 2.0, 100, "test.dat");
	GaussianModel aGaussModel(aGaussian);
	GaussianView aGaussView(aGaussModel);
	aGaussModel.GenerateData();

	while (aGaussModel.NextData(dataValue))
		cout << dataValue << endl;

	
	SineParams aSinewave(10, 1000, 0.0, 0.00001, 100, "test.dat");
	SineModel aSineModel(aSinewave);

	aSineModel.GenerateData();

	while (aSineModel.NextData(dataValue))
		cout << dataValue << endl;
 
	ofstream foData("test.dat");	// create normal output file

	if (!foData)
	{
		foData << "Cannot open output file." << endl;

	}
	else
	{
		foData << aSineModel;
		foData.close();

	}

	string file = aSineModel.GetFileName();
	ifstream fiData(file);

	if (!fiData)
	{
		cout << "Cannot open output file." << endl;

	}
	else
	{
		fiData >> aSineModel;
		fiData.close();

	}

	while (aSineModel.NextData(dataValue))
		cout << dataValue << endl;

	SineView aSineView(aSineModel);
	Controller aController(aSineModel, aSineView);

   
	/// Simulate the triggering of the OS .On_load event
	aController.OnLoad();

	/// Display 45 sinewave values
	aController.Render(45);
	/// Now, re-assign the controller to the Gaussian model and view

	aController.SetModel(aGaussModel);
	aController.SetView(aGaussView);

   
	/// Simulates the triggering of the OS ‘On_load()’ event’
	aController.OnLoad();

	/// Display 23 Gaussian (Normal) values
	aController.Render(23); 

	return 0;
}