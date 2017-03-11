/*******************************************************
*(C) Tsubasa Kato 2017.3.11
*Sample script for Saving Array as String passed from Arrayfire
*Referenced: http://www.cplusplus.com/doc/tutorial/files/
*            https://github.com/arrayfire/arrayfire/issues/230
********************************************************/

#include <arrayfire.h>
#include <ios>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace af;
using namespace std;

int main(int argc, char *argv[])
{
	try {
		//int device = argc > 1 ? atoi(argv[1]) : 0;
		//af::setDevice(device);
		//af::info();

		//Just sample to show stuff.
		af::array a = af::range(10);  // [0,  9]
		a = a + 1;                    // [1, 10]
		af_print(a);


		//This is where the actual saving / calculation starts.
		std::ofstream myfile;
		myfile.open("example2.txt");

		af::array b = randu(3, f32);
		float *host_b = new float[3];
		b.host(host_b);


		for (unsigned int a = 0; a < sizeof(host_b); a = a + 1)
		{

			myfile << host_b[a];
			myfile << "\n";


			printf("host_b = %f\n", host_b[a]);
		}
		myfile.close();


		delete[] host_b;




	}
	catch (af::exception& e) {

		fprintf(stderr, "%s\n", e.what());
		throw;
	}

	return 0;
}
