#include "DYHead.h"

int main(void) {

	int i_params = 7;

	vector<double> v_thetaA(i_params);
	vector<double> v_thetaB(i_params);

	for(int i = 0; i < i_params; i++)
	{
		v_thetaA[i] = pow(2,0.5*i + 1);
		v_thetaB[i] = pow(2,0.5*i + 4);
	}

	int k = 1;
	    for(int i = 0; i<i_params; i++)
	    {
		for(int j = 0; j<i_params; j++)
		{
		    string a = "spatial-parameters";
		    string c = ".txt";

		    string final;
		    final = make_filename(a,k,c);

		    ofstream myfile;

		    myfile.open( final.c_str());
		    if (myfile.is_open())
		    {
		        myfile<< v_thetaA[i]<<"\n";
		        myfile<< v_thetaB[j]<<"\n";
		        myfile.close();
		    }
		    k = k + 1;
		}
	    }

	return 0;

}


string make_filename( const string& basename, int index, const string& ext )
  {
  ostringstream result;
  result << basename << index << ext;
  return result.str();
  }

