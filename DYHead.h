#ifndef DYHEAD_H_INCLUDED
#define DYHEAD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <math.h>
#include <time.h>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib> // for exit function
#include <sstream>
#include <string>

#ifndef RANDOMC_H
#define RANDOMC_H

const int nx=3;//simulation space is divided into nx x ny gridcells for efficiency. sim size (U) divided by nx must >=max(LA,LB,LRho,LM) - best to choose nx,ny = U/max of these
const int ny=3;

using namespace std;

const double PI=3.14159265;



	struct totals //A container for the global totals of all the various entities involved in the simulation.
	{
		int J;
		int M;
		int HegM;
		int Un;
		int Ho;
		int Ov;
		int Breed_d;
		int Breed_e;
		int Breed_w;
		int FeedSites;
		int comp;
		int mate;
		double Hmove;
		int Hfeed;
		double Omove;
		int Oovi;
		double house_dense;
		int samples;
	};


	struct initials //Initial conditions, set values in main
	{
		int JX,JY,U,M,O,H;//absolute number
		double Feed, Breed;//density - i.e. multiply by U^2 to get absolute number
		char dist;
		int heg;
		int heg_time;
		int num_sites;
	};

	struct HostSeekers
	{
		double x;
		double y;
		int hum_hab;
		double jump_rate;
		char genotype;
	};

	struct Ovipositers
	{
		double x;
		double y;
		int larv_hab;
		double jump_rate;
		char genotype;
		int eggs;
	};

	struct sample //Holds the x and y positions of a sample point. Not sure what house_dense is!
	{
		double x;
		double y;
		double house_dense;
	};

	struct BreedSite
	{
		double x;
		double y;
		int juvX;
		int juvY;
		int juvW;
		int maleY;
		int maleW;
		int unmated_females;
		int mate_Y_rate;
		int mate_W_rate;
		int comp;
		char status;
	};

	struct FeedSite //This is a container for the x and y coordinates of a feedsite
	{
		double x;
		double y;
	};

	struct Individuals//indiv is an array of nx by ny structs, each struct is a set of vectors, each vector is a list of the individuals in a given class, e.g. HostSeekers
	{
		vector<HostSeekers> Ho[nx][ny];
		vector<Ovipositers> Ov[nx][ny];
		vector<BreedSite> Breed[nx][ny];
		vector<FeedSite> Feed[nx][ny]; //This is a vector of FeedSites
		vector<sample> sa[nx][ny];
	};

	struct PerCell // A struct which contains a list of variables which hold the total number of individuals in each square
	{
		int Juv[nx][ny];
		int Ma[nx][ny];
		int Un[nx][ny];
		int Ho[nx][ny];
		int Ov[nx][ny];
		int Breed[nx][ny];
		double house_dense[nx][ny];
		int samples[nx][ny];
		int Feed[nx][ny];
		int J_comp[nx][ny];
		int U_mate[nx][ny];
		double H_move[nx][ny];
		double O_move[nx][ny];
		int H_gam[nx][ny];
        int O_ovi[nx][ny];
	};

	struct Times //Contains all the parameters necessary for simulation time
	{
		double interval;
		double totalruntime;
		double maxT;
		double landscape_initiation;
		int rec;
		int N;
	};

struct Pars // Container for various parameters involved in the simulation.
	{
		double omega,kappa,nu,alpha,gammaJ,gammaH,muJ,muU,muM,muH,muO,m,e,rH,betaH,rO,betaO,LM,LRH,LRO,Lrho,LA,LB,thetaA,thetaB,sigmaA,sigmaB,U;
		double thetaC,sigmaC,rho;
		double chiB, etaB, thetaB_mean; //All variables to do with the Ornstein-Uhlenbeck process
		int set;
	};


    //A struct to hold a breedsite (which holds Heg) along with the coordinates of the large square it is in.
	struct Breedsite_plus
	{
        int x_abs, y_abs; //Store this information as we need it!
        double distance_to_release;
	};

    //Ben Struct to hold vector of breedsite_plus and the number of breedsites at each time step
    struct heg_vector
    {
        int number_heg;
        vector<Breedsite_plus> heg_vec;
    };

    //Vector of heg_vectors which holds the information of the Heg breedsites at all times
    struct Heg_breedsites
    {

        vector<heg_vector> heg_holder;

    };

//---------------------------------Functions in simulation code---------------------------------------------------------
		void RunOnceInt(double);
		void RunMaxT(int);
		void RunNReps(int);
		void initiate(int);
		double OneStep();
		int modulo (int,char);
		double dmodulo (double,double);
		int random_poisson(double);
		double random_exp(double);
		double dist(double,double,double,double);
		int UpdateCompLay(int,int,double,double,int);
		void UpdateComp(int,int, int,char);
		void UpdateHabHab(int,int, int,char);
		void UpdateHabInd(int,int, int,char);
		void UpdateMateU(int,int, int,char);
		void UpdateMateM(int,int, int,char,char);
		void UpdateSample(int,int, int);
		void record(int,Individuals&,PerCell&);
		void testfunc(char,int);
	   	int* SelectEggs(char);
		void LayEggs();
		void JuvDie();
		void JuvEmerge();
		void JuvCreate(char);
		void MaleDie();
		void UnmatedDie();
		void Mate();
		void HDie();
		void HFeed();
		void HJump();
		void ODie();
		void OJump();
		void FeedCreate();
		void FeedDestroy();
		void BreedCreate();
		void BreedDestroy();
		void sampCreate();
		void sampDestroy();
		void PutHeg (char);
		int pick(double*,int,double);
	   	int* pick2Ddub(double[][ny],double);
		int* pick2D(int[][ny],int);

		//Functions for rainfall seasonality
		double OrsteinUhlenbeck(double, double);
		void parameter_txt_generator();
		string make_filename( const string& basename, int index, const string& ext );


//------------------------------------------------------------------------------------------------------------------------------



//Below is some necessary header code from a random number generator that the simulation uses (not written by me!)---------------




// Define 32 bit signed and unsigned integers.
// Change these definitions, if necessary, to match a particular platform
#if defined(_WIN16) || defined(__MSDOS__) || defined(_MSDOS)
   // 16 bit systems use long int for 32 bit integer
   typedef long int           int32;   // 32 bit signed integer
   typedef unsigned long int  uint32;  // 32 bit unsigned integer
#else
   // Most other systems use int for 32 bit integer
   typedef int                int32;   // 32 bit signed integer
   typedef unsigned int       uint32;  // 32 bit unsigned integer
#endif

// Define 64 bit signed and unsigned integers, if possible
#if (defined(__WINDOWS__) || defined(_WIN32)) && (defined(_MSC_VER) || defined(__INTEL_COMPILER))
   // Microsoft and other compilers under Windows use __int64
   typedef __int64            int64;   // 64 bit signed integer
   typedef unsigned __int64   uint64;  // 64 bit unsigned integer
   #define INT64_DEFINED               // Remember that int64 is defined
#elif defined(__unix__) && (defined(_M_IX86) || defined(_M_X64))
   // Gnu and other compilers under Linux etc. use long long
   typedef long long          int64;   // 64 bit signed integer
   typedef unsigned long long uint64;  // 64 bit unsigned integer
   #define INT64_DEFINED               // Remember that int64 is defined
#else
   // 64 bit integers not defined
   // You may include definitions for other platforms here
#endif


/***********************************************************************
System-specific user interface functions
***********************************************************************/

//void EndOfProgram(void);               // System-specific exit code (userintf.cpp)

//void FatalError(char * ErrorText);     // System-specific error reporting (userintf.cpp)


/***********************************************************************
Define random number generator classes
***********************************************************************/



class CRandomMersenne {                // Encapsulate random number generator
#if 0
   // Define constants for type MT11213A:
#define MERS_N   351
#define MERS_M   175
#define MERS_R   19
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   17
#define MERS_A   0xE4BD75F5
#define MERS_B   0x655E5280
#define MERS_C   0xFFD58000
#else
   // or constants for type MT19937:
#define MERS_N   624
#define MERS_M   397
#define MERS_R   31
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   18
#define MERS_A   0x9908B0DF
#define MERS_B   0x9D2C5680
#define MERS_C   0xEFC60000
#endif
public:
   CRandomMersenne(uint32 seed) {      // Constructor
      RandomInit(seed); LastInterval = 0;}
   void RandomInit(uint32 seed);       // Re-seed
//   void RandomInitByArray(uint32 seeds[], int length); // Seed by more than 32 bits
   int IRandom (int min, int max);     // Output random integer - Outputs random integer in the interval min <= x <= max
//   int IRandomX(int min, int max);     // Output random integer, exact
   double Random();                    // Output random float number in the interval 0 <= x < 1
   uint32 BRandom();                   // Generate 32 random bits
private:
   void Init0(uint32 seed);            // Basic initialization procedure
   uint32 mt[MERS_N];                  // State vector
   int mti;                            // Index into mt
   uint32 LastInterval;                // Last interval length for IRandomX
   uint32 RLimit;                      // Rejection limit used by IRandomX
   enum TArch {LITTLE_ENDIAN1, BIG_ENDIAN1, NONIEEE}; // Definition of architecture
   TArch Architecture;                 // Conversion to float depends on architecture
};


class CRandomMother {             // Encapsulate random number generator
public:
   void RandomInit(uint32 seed);       // Initialization
   int IRandom(int min, int max);      // Get integer random number in desired interval
   double Random();                    // Get floating point random number
   uint32 BRandom();                   // Output random bits
   CRandomMother(uint32 seed) {   // Constructor
      RandomInit(seed);}
protected:
   uint32 x[5];                        // History buffer
};

#endif

// body file: mersenne.cpp  // I have added relevant parts to the simulaiton code


#endif // DYHEAD_H_INCLUDED
