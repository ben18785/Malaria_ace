#include "DYHead.h"

	double U=1500;// simulation is run in square of U by U

//-----------------------------------------------------Declare Global variables----------------------------------------------------------------------------------------------------------------------

	int32 seed = (int32)time(0);// seed for random number generator
	CRandomMersenne rg(seed);// random number generator
	Pars pa;//parameters, set values in main
	initials in; //initial conditions, set values in main
	Individuals indiv;//indiv is an array of nx by ny structs, each struct corresponds to a particular large square and is a set of vectors, each vector is a list of the individuals in a given class, e.g. HostSeekers
	PerCell cell; //cell is an array of nx by ny structs, each struct contains the total of each entity type for the given square
	totals to; //struct of the global totals of each entity type
	ostringstream os;ofstream run,param;// for writing output files
	Times ti;// simulation time parameters
	std::clock_t star;//start absolute time
	double totalruntime;
	double dx,dy;//x and y lengths of a gridcell
	int N;// how simulation many replicates to run
	double landscape_initiation =0;// how long to run the landscape dynamics pre-mosquitoes. This only needs to be done if there is feedsite/breedsite covariance (rho not=1)

	int main(void){

            //Definition of parameters used in model. They are all defined to belong to a struct.
            // ti is an instance of a 'Times' struct. It contains all the parameters necessary for simulation time
            //in is an example of the 'initials' struct which contains initial conditions
            // pa is an instance of 'Pars' - container for various parameters involved in the simulation.
            ti.interval=1;
			ti.totalruntime=10000;
			ti.maxT=300;
			ti.rec=500;
			ti.landscape_initiation=50;
			ti.N=100;
			in.heg=1000;
			in.dist='p';
			in.heg_time=500;
			in.num_sites=1;
			pa.set=1;
			in.JX=5000;
			in.JY=5000;
			in.U=1000;
			in.M=1000;
			in.H=1000;
			in.O=1000;
			pa.omega=40;
			pa.kappa=120;
			pa.nu=0.12;
			pa.alpha=.05;
			pa.gammaJ=0.1;
			pa.gammaH=0.015;
			pa.muJ=0.1;
			pa.muU=0.1;
			pa.muM=0.1;
			pa.muH=0.1;
			pa.muO=0.1;
			pa.m=0.01;
			pa.e=0.8;
			pa.rH=10;
			pa.betaH=0.001;
			pa.rO=10;
			pa.betaO=0.001;
			pa.LM=300;
			pa.LRH=300;
			pa.LRO=300;
			pa.Lrho=500;
			pa.LA=500;
			pa.LB=150;
			pa.thetaA=0.000008;
			pa.thetaB=0.000016;
			pa.thetaC=0.0001;
			pa.sigmaA=0;
			pa.sigmaB=0.05;
			pa.sigmaC=0.02;
			pa.rho=1;


            pa.thetaB_mean = pa.thetaB; // The mean of the Orstein-Uhlenbeck process
//            pa.chiB = 0.0111; // The rate of reversal to the mean of the Orstein-Uhlenbeck process for the breedsite theta
//            pa.etaB = 0.567; // The magnitude of the error process

            // Generate the necessary txt files with parameters
            //parameter_txt_generator();


//            ifstream myfile ("parameters64.txt");
//            if (myfile.is_open())
//            {
//                myfile>> pa.chiB;
//                myfile>> pa.etaB;
//                myfile.close();
//            }

                int num_sim;

                cin>>pa.chiB;
                cin>>pa.etaB;
                cin>>num_sim;

                cout<<pa.chiB<<"\n";
                cout<<pa.etaB<<"\n";



//			cin>>ti.interval;// time interval between recordings of population statistics
//			cin>>ti.totalruntime;// maximum number of real seconds the simulation can run for, if it goes over it will be aborted
//			cin>>ti.maxT;// max simulation time for each replicate
//			cin>>ti.rec;// time intervals between recording files with spatial data
//			cin>>ti.landscape_initiation;// how long to run the landscape dynamics pre-mosquitoes. This only needs to be >0 if there is feedsite/breedsite covariance (i.e. rho not=1)
//			cin>>ti.N;// Number of replicates
//			cin>>in.heg;// How many HEG males to be released
//			cin>>in.dist;// how to distribute the hegs, can be 'p' - point (divided among in.num_sites sites) or 'u' - uniformly
//			cin>>in.heg_time;// simulation time when Hegs are released
//			cin>>in.num_sites;//if dist='p', heg release divided among this many sites
//			cin>>pa.set;//parameter set, useful for labelling output files
//			cin>>in.JX;// initial number of female juveniles
//			cin>>in.JY;// initial number of wildtype male juveniles
//			cin>>in.U; // initial unmated females
//			cin>>in.M;// initial males
//			cin>>in.H;// initial hostseekers
//			cin>>in.O;// initial ovipositers
//			cin>>pa.omega;//mean number of eggs deposited each oviposition event
//			cin>>pa.kappa;//mean number of eggs per gonotrophic cycle
//			cin>>pa.nu;//egg laying rate
//			cin>>pa.alpha;//juvenile mortality from competition
//			cin>>pa.gammaJ;// rate of juvenile maturation
//			cin>>pa.gammaH;//feeding rate
//			cin>>pa.muJ;// juvenile background mortality rate
//			cin>>pa.muU;// unmated background mortality rate
//			cin>>pa.muM;// male background mortality rate
//			cin>>pa.muH;// hostseeker background mortality rate
//			cin>>pa.muO;// ovipositer background mortality rate
//			cin>>pa.m;// mating rate
//			cin>>pa.e;// HEG cleavage rate
//			cin>>pa.rH; // basic jump rate for hostseekers
//			cin>>pa.betaH; //strengh of reduction in movement near feedsite
//			cin>>pa.rO;// basic jump rate for ovipositers
//			cin>>pa.betaO;//strengh of reduction in movement near breedsite
//			cin>>pa.LM;//max mating distance
//			cin>>pa.LRH;//hostseeker jump radius
//			cin>>pa.LRO;//ovipositer jump radius
//			cin>>pa.Lrho;	//dist from patch to house (spatial scale of breedsite/feedsite covariance)
//			cin>>pa.LA;//feedsite detection radius
//			cin>>pa.LB;//breedsite detection radius
//			cin>>pa.thetaA;// density of feedsites
//			cin>>pa.thetaB;// density of breedsites
//			cin>>pa.sigmaA;// turnover of feedsites (typically set to 0)
//			cin>>pa.sigmaB;// turnover of breedsites
//			cin>>pa.thetaC;// density of sample points (for landscapes with covariance)
//			cin>>pa.sigmaC;// turnover of sample points
//			cin>>pa.rho;// covariance between feed and breedsites: 1= no covariance, <1 = negative, >1 = positive

            cout<<"The width of the square is: "<<U<<"\n";
			pa.U=U;//Width of the square used. N.B. in.U is different = initial number of unmated females.


            cout<<"The value of nx is: "<<nx<<"\n";
			in.Breed=pa.thetaB;//this is the equilibrium density of breeding sites
			dx=pa.U/(double)nx;//x_length of a gridcell
			dy=pa.U/(double)ny;//x_length of a gridcell
			star = std::clock();// set star = clock time of now

            cout<<"The value of U is: "<<pa.U<<"\n";
			cout<<"The value of dx is: "<<dx<<"\n";

			os<<"Param"<<pa.set<<".txt";// make a file and put the parameters in it
			param.open(os.str().c_str());
			param<<"omega   "<<pa.omega<<endl;
			param<<"kappa   "<<pa.kappa<<endl;
			param<<"nu      "<<pa.nu<<endl;
			param<<"alpha   "<<pa.alpha<<endl;
			param<<"gammaJ  "<<pa.gammaJ<<endl;
			param<<"gammaH  "<<pa.gammaH<<endl;
			param<<"muJ     "<<pa.muJ<<endl;
			param<<"muU     "<<pa.muU<<endl;
			param<<"muM     "<<pa.muM<<endl;
			param<<"muH     "<<pa.muH<<endl;
			param<<"muO     "<<pa.muO<<endl;
			param<<"m     "<<pa.m<<endl;
			param<<"e     "<<pa.e<<endl;
			param<<"rH     "<<pa.rH<<endl;
			param<<"betaH     "<<pa.betaH<<endl;
			param<<"rO     "<<pa.rO<<endl;
			param<<"betaO     "<<pa.betaO<<endl;
			param<<"LM     "<<pa.LM<<endl;
			param<<"LRH     "<<pa.LRH<<endl;
			param<<"LRO     "<<pa.LRO<<endl;
			param<<"Lrho     "<<pa.Lrho<<endl;
			param<<"LA     "<<pa.LA<<endl;
			param<<"LB     "<<pa.LB<<endl;
			param<<"thetaA     "<<pa.thetaA<<endl;
			param<<"thetaB     "<<pa.thetaB<<endl;
			param<<"sigmaA     "<<pa.sigmaA<<endl;
			param<<"sigmaB     "<<pa.sigmaB<<endl;
			param<<"thetaC     "<<pa.thetaC<<endl;
			param<<"sigmaC     "<<pa.sigmaC<<endl;
			param<<"rho    "<<pa.rho<<endl;
			param.close();
			os.str("");

//            ostringstream ostr1, ostr2;
//            ostr1<<pa.chiB;
//            ostr2<<pa.etaB;
//            string str1, str2, sstr1, sstr2;
//            str1 = ostr1.str();
//            str2 = ostr2.str();
//            sstr1 = str1.substr(2,3);
//            sstr2 = str2.substr(2,3);

            ostringstream o_sim_num;
            o_sim_num<<num_sim;
            string str_sim;
            str_sim = o_sim_num.str();

            cout<<"The simulation number is : "<<str_sim<<"\n";

            os<<"/data/ace-north/bclambert/temporal-sim/Results"<<str_sim<<"a.txt";
//            os<<"Results"<<sstr1<<sstr2<<".txt";

            run.open(os.str().c_str());// Use this if want to write output to file instead of cout
			RunNReps(ti.N);
			run.close();os.str("");
		return 0;};


	void RunNReps(int N)
	      {
		cout<<"RN0"<<endl;
		for(int i=0;i<N;i++)
		{
//		    cout<<"Running Initiate, iteration: "<<i<<"\n";
			initiate(i);
//			cout<<"Running RunMaxT"<<"\n";

            cout<<"\n";
			cout<<"TT"<<"      "<<"to.J"<<"       "<<"to.M-to.HegM"<<"       "<<"to.HegM"<<"       "<<"to.Un"<<"     "<<"to.Ho"<<"     "<<"to.Ov"<<"      "<<"to.FeedSites"<<"     "<<"pa.thetaB"<<"     "<<"to.Breed_w"<<"     "<<"to.Breed_e"<<"    "<<"to.mate"<<"      "<<"to.comp"<<"     "<<"to.Hfeed"<<"     " <<"to.Oovi"<<"     "<<"to.samples"<<"     "<<"to.house_dense"<<endl;//write global densiies into output
			RunMaxT(i);
		};
		return;};

	void RunMaxT(int i)//Run 1 replicate
		{
		double TT=0;
		double TTT=0;
		int swit=0;
		while (TT<ti.maxT)//loop for running between one time interval
			{ //Record the various totals of different species to the consol

            cout<<TT<<"      "<<pa.thetaB<<endl;
//write global densiies into output
			run<<TT<<"      "<<to.J<<"       "<<to.M-to.HegM<<"       "<<to.HegM<<"       "<<to.Un<<"     "<<to.Ho<<"     "<<to.Ov <<"      "<<to.FeedSites<<"     "<<pa.thetaB<<"     "<<to.Breed_w<<"     "<<to.Breed_e<<"    "<<to.mate<<"      "<<to.comp<<"     "<<to.Hfeed<<"     " <<to.Oovi<<"     "<<to.samples<<"     "<<to.house_dense<<endl;//write global densiies into output			TT+=ti.interval;
			TT+=ti.interval;
			TTT+=ti.interval;
			if(swit==0 && TT>in.heg_time && to.J>0)
				{
				swit=1;PutHeg(in.dist);
				};
			if(TTT>=ti.rec)
				{
				    cout<<"Recording...\n";
				record(10000*(i+1)+int(TT),indiv,cell);// make a file of spatial data
				TTT-=ti.rec;
				};
			RunOnceInt(ti.interval);
			};
cout<<TT<<"      "<<to.J<<"       "<<to.M-to.HegM<<"       "<<to.HegM<<"       "<<to.Un<<"     "<<to.Ho<<"     "<<to.Ov <<"      "<<to.FeedSites<<"     "<<to.Breed_w<<"     "<<to.Breed_e<<"    "<<to.mate<<"      "<<to.comp<<"     "<<to.Hfeed<<"     " <<to.Oovi<<"     "<<to.samples<<"     "<<to.house_dense<<endl;
	return;};


	void RunOnceInt(double interval)
	{
	    double T;
	    T=0;
	    double dt;
	    while(T<interval)
		    {
			dt=OneStep();
			T+=dt;

			pa.thetaB = OrsteinUhlenbeck(dt,pa.thetaB);

			if((std::clock() - star)/ (double)CLOCKS_PER_SEC>ti.totalruntime)exit(1);// abort if simulation exceeds allotted real time
		    };
	return;}


	void initiate(int i){

        pa.thetaB=pa.thetaB_mean;
		int num,index;
		//to is an instance of 'Totals' - a struct of the global totals of each entity type
		to.J=0;to.Ho=0;to.Ov=0;
		to.M=0;to.Un=0;
		to.Breed_d=0;to.Breed_w=0;to.Breed_e=0;to.FeedSites=0;to.mate=0;to.comp=0;to.Hmove=0;to.Hfeed=0;to.Omove=0;to.Oovi=0;
		to.house_dense=0;
		to.HegM=0;
		to.samples=0;
		FeedSite apv;//This is a struct which contains the x and y coordinates of the feedsite.
//		cout<<"The width of the grid is: "<<nx<"\n";
		for(int nxx=0;nxx<nx;nxx++)
			{
				for(int nyy=0;nyy<ny;nyy++)
				{
				cell.Juv[nxx][nyy]=0;cell.Ma[nxx][nyy]=0; //Cell is an example of a PerCell struct which contains other data structures. It is initiated before main is called.
				cell.Un[nxx][nyy]=0;//More specifically cell: a struct which contains a list of variables which hold the total number of individuals in each square
				cell.Ho[nxx][nyy]=0;cell.Ov[nxx][nyy]=0;
				cell.Feed[nxx][nyy]=0;cell.Breed[nxx][nyy]=0;cell.house_dense[nxx][nyy]=0;
				cell.J_comp[nxx][nyy]=0; cell.U_mate[nxx][nyy]=0;
				cell.H_move[nxx][nyy]=0; cell.O_move[nxx][nyy]=0;
				cell.H_gam[nxx][nyy]=0;  cell.O_ovi[nxx][nyy]=0;
				cell.samples[nxx][nyy]=0;
				indiv.Ho[nxx][nyy].clear();//indiv is an array of nx by ny structs, each struct is a set of vectors, each vector is a list of the individuals in a given class, e.g. HostSeekers
				indiv.Ov[nxx][nyy].clear();//I think this just clears each element of the vectors in turn
				indiv.Feed[nxx][nyy].clear();
				indiv.Breed[nxx][nyy].clear();
				indiv.sa[nxx][nyy].clear();
				};
			};

            //num is the number of feeding sites which there will be in the entire space
			num = int(pa.U*pa.U*pa.thetaA);
			cout<<"The value of the number of feedsites is: "<<num<<"\n";
			to.FeedSites+=num;//Add this to a variable which holds the total number of feeding sites.

			cout<<"Randomly selecting the initial feeding site locations out of each of the large squares then within that square...\n";
			for(index=0;index<num;index++)// place feed sites randomly by first selecting the large square randomly then placing the feeding site at random within that square.
			{
			    // For each of the feeding sites we first need to randomly choose its location.
			    // Firstly this needs to be done by selecting a large square at random from the set.

				int nxx=rg.IRandom(0,nx-1);// rg. is an instance of a random number generator with a particular seed. Output random integer in the interval min <= x <= max
				int nyy=rg.IRandom(0,ny-1);
				cout<<"Feeding site "<<index<<" is located in the following large square coordinates "<<nxx<<", "<<nyy<<"\n";
				cell.Feed[nxx][nyy]++; //This designates the particular large square in which the

                //Select the coordinates within each square where a feeding site will be placed.
                //pa.U/nx is the size of the domain in each of the nx by ny squares. The idea is that for each square we keep tabs on the number of things in it.
				apv.x = (pa.U/nx)*rg.Random();
				apv.y=(pa.U/ny)*rg.Random();
				indiv.Feed[nxx][nyy].push_back(apv); //push_back is equivalent to .add() in python. It adds a component to that particular large square's list of feeding sites.
			};

            // This is the number of sample points in the total area. Sample points are houses
			num = int(pa.U*pa.U*pa.thetaC);
				for(index=0;index<num;index++) sampCreate();//place sample points

            // This is the total number of breeding sites in the total area.
			num = int(pa.U*pa.U*pa.thetaB);
				for(index=0;index<num;index++) BreedCreate();//place breeding sites


		//------------------------ run landscapes without mosquitoes for a while to establish covariance structure---
		double T;
		T=0;
		double dt;
		while(T<landscape_initiation)
		    {
			dt=OneStep();
			T+=dt;
		    };

		//-----------------------------remainder of this function places initial wildtype mosquitoe--------------------

			num = int(in.JX+in.JY+in.U+in.H+in.O+in.M);

			for(index=0;index<num;index++)
				  {


                        if(double(index)<=double(num*in.JX)/double(in.JX+in.JY))
                        {
                            JuvCreate('X');
                        }
                      else
                          {
                              JuvCreate('W');
                          }
				  };
				  cout<<"End of initiate...\n";
			num = int(in.U+in.H+in.O+in.M);
				for(index=0;index<num;index++)
				{ if(to.J>0)JuvEmerge();};


			num = int(in.H+in.O);
				for(index=0;index<num;index++)
				{if(to.mate>0) Mate();};
			num = int(in.O);
				for(index=0;index<num;index++)
				{if(to.Hfeed>0) HFeed();};

		//----------------------------------------------------------------------------------------------------------
	return;};

	double OneStep()//Simulate a single event, and output time increment
	{
		double rate[17];// set the rates of each event type
		rate[0] = pa.nu*to.Oovi; //Oviposition
		rate[1] = to.J*pa.muJ+to.comp*pa.alpha; //JuvDie
		rate[2] = pa.gammaJ*to.J; //JuvEmerge
		rate[3] = pa.muM*to.M; //Male die;
		rate[4] = pa.muU*to.Un; //unmated die
		rate[5] = to.mate*pa.m; //unmated mates
		rate[6] = pa.muH*to.Ho; //H dies
		rate[7] = to.Hfeed*pa.gammaH; //H feeds
		rate[8] = to.Hmove*pa.rH; //H jumps
		rate[9] = pa.muO*to.Ov; //O dies
		rate[10]= to.Omove*pa.rO;//O jumps
		rate[11] = pa.sigmaA*pa.thetaA*pa.U*pa.U;//Feed create
		rate[12] = pa.sigmaA*to.FeedSites;//Feed destroy
		rate[13]= pa.sigmaB*to.Breed_w;//Breed destroy
		rate[14] =  pa.sigmaB*pa.thetaB*pa.U*pa.U;//Breed create
		rate[15]= pa.sigmaC*to.samples;//samp destroy
		rate[16] =  pa.sigmaC*pa.thetaC*pa.U*pa.U;//samp create
		double sum=rate[0]+rate[1]+rate[2]+rate[3]+rate[4]+rate[5]+rate[6] +rate[7]+rate[8]+rate[9]+rate[10]+rate[11]+rate[12]+rate[13]+rate[14]+rate[15]+rate[16];
		double dt=random_exp(sum);// time increment
		int i= pick(rate,16,sum);// choose event based on relative rates
		if(i==0) LayEggs();
		else if(i==1) JuvDie();
		else if(i==2) JuvEmerge();
		else if(i==3) MaleDie();
		else if(i==4) UnmatedDie();
		else if(i==5) Mate();
		else if(i==6) HDie();
		else if(i==7) HFeed();
		else if(i==8) HJump();
		else if(i==9) ODie();
		else if(i==10) OJump();
		else if(i==11) FeedCreate();
		else if(i==12) FeedDestroy();
		else if(i==13) BreedDestroy();
		else if(i==14) BreedCreate();
		else if(i==15) sampDestroy();
		else if(i==16) sampCreate();
//	testfunc('o',i);   this is a debugging function! useful if something is going wrong after modification:)
	return dt;};



	void LayEggs()
	      {
		int* ii=pick2D(cell.O_ovi,to.Oovi);//pick the cell based on relative rates of oviposition in each cell
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int test=0;
		int ind;
		while(test==0)// this loops picks an individual in the choosen cell (xi,yi) based on relative oviposition rates of the individuals in that cell
		{
		ind=rg.IRandom(0,cell.Ov[xi][yi]-1);
		if(rg.Random()*cell.O_ovi[xi][yi]<indiv.Ov[xi][yi][ind].larv_hab)test=1;
		};

		//------------------- Following part of function selects a breedsite from those breeding sites within detection distance (pa.LB) of choosen individual--------------------------

		double ra=indiv.Ov[xi][yi][ind].larv_hab*rg.Random();// find a patch containing ind
		int pxx,pyy,index;
		double dx1,dx2,dy1,dy2;
		int runpat=0;
		int k=0;int kk=0;
		while(k<3 && ra>runpat)
		{
			while(kk<3 && ra> runpat)
			{
			      if(k==0){pxx=modulo(xi-1,'X'); dx1=0;dx2=dx;};
			      if(k==1){pxx=xi;dx1=0;dx2=0;};
			      if(k==2){pxx=modulo(xi+1,'X');dx1=dx;dx2=0;};
			      if(kk==0){pyy=modulo(yi-1,'Y');dy1=0;dy2=dy;};
			      if(kk==1){pyy=yi;dy1=0;dy2=0;};
			      if(kk==2){pyy=modulo(yi+1,'Y');dy1=dy;dy2=0;};
				index=0;
				while(index<cell.Breed[pxx][pyy] && ra> runpat)
				  {
				  if(indiv.Breed[pxx][pyy][index].status!='d' &&
						  dist(dx1+indiv.Breed[pxx][pyy][index].x, dy1+indiv.Breed[pxx][pyy][index].y, dx2+indiv.Ov[xi][yi][ind].x, dy2+indiv.Ov[xi][yi][ind].y)-pa.LB<0)runpat++;
				  index++;
				};
				kk++;
			};
			k++;
			kk=0;
		};
		index--;
		//------------------(chosen breed site is indiv.Breed[pxx][pyy][index])-----------------------------------------------------------------------------------------------------------

		char gen=indiv.Ov[xi][yi][ind].genotype;// genotype of ovipositer

		//------------this part draws a random number of eggs of each type based on gen----------------------------------------------------
		int* eggnum=SelectEggs(gen);
		int fe=*eggnum;
		int wt=*(eggnum+1);
		int heg=*(eggnum+2);
		delete[] eggnum;
		int num_eggs=fe+wt+heg;
		//---------------------------------------------------------------------------------------------------------------------------------
		if(num_eggs>=indiv.Ov[xi][yi][ind].eggs)//if the number of eggs is more than she has
			{
			int cc;
			while(fe+wt+heg>indiv.Ov[xi][yi][ind].eggs)// reduce egg number in proportion to the types
				{
				test=0;
				while(test==0){
						cc=rg.IRandom(1,3);
						if(cc==1 &&rg.Random()<fe/(double)(fe+wt+heg)){test=1;fe--;}
						else if(cc==2 &&rg.Random()<wt/(double)(fe+wt+heg)){test=1;wt--;}
						else if(cc==3 &&rg.Random()<heg/(double)(fe+wt+heg)){test=1;heg--;};
						};
				};
			//-------------- she lays all her eggs and become a hostseeker at the breedsite---------------------
			num_eggs=indiv.Ov[xi][yi][ind].eggs;
			double x =indiv.Breed[pxx][pyy][index].x;
			double y =indiv.Breed[pxx][pyy][index].y;
			cell.Ov[xi][yi]--;
			cell.O_ovi[xi][yi]-=indiv.Ov[xi][yi][ind].larv_hab;
			cell.O_move[xi][yi]-=indiv.Ov[xi][yi][ind].jump_rate;
			to.Oovi-=indiv.Ov[xi][yi][ind].larv_hab;
			to.Omove-=indiv.Ov[xi][yi][ind].jump_rate;
			to.Ov--;
			HostSeekers aj;
			aj.x = x;
			aj.y = y;
			aj.hum_hab=0;
			aj.jump_rate=1;
			aj.genotype=gen;
			indiv.Ov[xi][yi].erase(indiv.Ov[xi][yi].begin()+ind);
			indiv.Ho[pxx][pyy].push_back(aj);
			cell.Ho[pxx][pyy]++;
			UpdateHabInd(pxx,pyy,cell.Ho[pxx][pyy]-1,'h');
			to.Ho++;
			//---------------------------------------------------------------------------------------------------
			}
		else{
		//she lays num_eggs eggs and remains an ovipositer with her total eggs reduced by this amount. She moves to location of breedsite
			Ovipositers aj;
			aj.x = indiv.Breed[pxx][pyy][index].x;
			aj.y = indiv.Breed[pxx][pyy][index].y;
			aj.eggs=indiv.Ov[xi][yi][ind].eggs-num_eggs;
			aj.genotype=gen;
			aj.larv_hab=0;
			aj.jump_rate=1;
			cell.Ov[xi][yi]--;
			cell.O_ovi[xi][yi]-=indiv.Ov[xi][yi][ind].larv_hab;
			to.Oovi-=indiv.Ov[xi][yi][ind].larv_hab;
			cell.O_move[xi][yi]-=indiv.Ov[xi][yi][ind].jump_rate;
			to.Omove-=indiv.Ov[xi][yi][ind].jump_rate;
			indiv.Ov[xi][yi].erase(indiv.Ov[xi][yi].begin()+ind);
			indiv.Ov[pxx][pyy].push_back(aj);
			cell.Ov[pxx][pyy]++;
			UpdateHabInd(pxx,pyy,cell.Ov[pxx][pyy]-1,'o');
		};
		if(indiv.Breed[pxx][pyy][index].status=='e')// If there were no juveniles previously at the breed site (status ='e'), the status will change to 'w'
                        {
                        if(num_eggs>0)
                                {
                                indiv.Breed[pxx][pyy][index].status='w';
                                to.Breed_e--;
                                };
                        };
		//----------update the breedsite information to account for new eggs---------------------------------
		indiv.Breed[pxx][pyy][index].juvX+=fe;
		indiv.Breed[pxx][pyy][index].juvY+=heg;
		indiv.Breed[pxx][pyy][index].juvW+=wt;
		to.J+=num_eggs;
		cell.Juv[pxx][pyy]+=num_eggs;
		int extracomp=(2*(indiv.Breed[pxx][pyy][index].juvX+indiv.Breed[pxx][pyy][index].juvY+indiv.Breed[pxx][pyy][index].juvW)-num_eggs)*num_eggs;
		indiv.Breed[pxx][pyy][index].comp+=extracomp;
		cell.J_comp[pxx][pyy]+=extracomp;
		to.comp+=extracomp;
		//--------------------------------------------------------------------------------------------------
			if(cell.Ov[xi][yi]==0)
			{
			//these 2 lines should not be necessary but because of rounding erros and double arithmetic, cell.O_move[xi][yi] may not be *Exactly* zero, which it should be!
			//	if(cell.O_move[xi][yi]!=0)cout<<cell.O_move[xi][yi]<<endl;// to see this, uncomment this line
				cell.O_move[xi][yi]=0;
				if(to.Ov==0)to.Omove=0;
			};
		return;};

int* SelectEggs (char gen)
	{
		int *ii = new int[3];//ii[0] is wildtype number, ii[1]is heterozygote, ii[2] heg homozygote
		ii[0]=0;
		ii[1]=0;
		ii[2]=0;
		if(gen=='W'){
				ii[0]=random_poisson(pa.omega/2);
				ii[1]=random_poisson(pa.omega/2);
				}
		else if(gen=='Y') {
				ii[0]=random_poisson(((1-pa.e)/2)*pa.omega);
				ii[2]=random_poisson(((1+pa.e)/2)*pa.omega);
				}
		return ii;
	};


	void JuvDie()
	    {
	      int xi,yi,ind;
	        if((to.comp*pa.alpha+to.J*pa.muJ)*rg.Random() >=to.comp*pa.alpha)
		      {
			int* ii=pick2D(cell.Juv,to.J);//die from dens indepence - all juveniles weighted equally - select cel based on numbers of juveniles in each
			xi=*ii;
			yi=*(ii+1);
			delete[] ii;
			int test=0;
			while(test==0)
			{
			ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
			if(rg.Random()*cell.Juv[xi][yi]<indiv.Breed[xi][yi][ind].juvX+ indiv.Breed[xi][yi][ind].juvY+ indiv.Breed[xi][yi][ind].juvW)test=1;
			};
		      }
		else//die from dens dep
		      {
			int* ii=pick2D(cell.J_comp,to.comp);// select cell based on amount of competition in each
			xi=*ii;
			yi=*(ii+1);
			delete[] ii;
			int test=0;
			while(test==0)
			{
			ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
			if(rg.Random()*cell.J_comp[xi][yi]<indiv.Breed[xi][yi][ind].comp)test=1;
			};
		      };
		//having chosen breedsite, now choose genotype of individual based on relative proportions-----------------
		double ran=(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW)*rg.Random();
		if(ran<indiv.Breed[xi][yi][ind].juvX) indiv.Breed[xi][yi][ind].juvX--;
		else if (ran<indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY) indiv.Breed[xi][yi][ind].juvY--;
		else indiv.Breed[xi][yi][ind].juvW--;
		//---------------------------------------------------------------------------------------------------------
		cell.Juv[xi][yi]--;
		to.J--;
		int extracomp=(2*(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW)+1);
		indiv.Breed[xi][yi][ind].comp-=extracomp;
		cell.J_comp[xi][yi]-=extracomp;
		to.comp-=extracomp;
		if(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW ==0)//if no juvs left in breedsite, change status to 'e'
			 {indiv.Breed[xi][yi][ind].status='e';to.Breed_e++;};
	   return;};

	void JuvEmerge()
	  {
		int xi,yi,ind;
		int* ii=pick2D(cell.Juv,to.J);
		xi=*ii;
		yi=*(ii+1);
		delete[] ii;
		int test=0;
		while(test==0)
		{
		ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
		if(rg.Random()*cell.Juv[xi][yi]<indiv.Breed[xi][yi][ind].juvX+ indiv.Breed[xi][yi][ind].juvY+ indiv.Breed[xi][yi][ind].juvW)test=1;
		};
		cell.Juv[xi][yi]--;
		to.J--;
		double ran=(indiv.Breed[xi][yi][ind].juvX +indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW)*rg.Random();
		if(ran<indiv.Breed[xi][yi][ind].juvX)
			{
			indiv.Breed[xi][yi][ind].juvX--;
			indiv.Breed[xi][yi][ind].unmated_females++;
			cell.Un[xi][yi]++;
			to.Un++;
			UpdateMateU(xi,yi,ind,'b');
			}
		else if(ran<indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY)
			{
			indiv.Breed[xi][yi][ind].juvY--;
			indiv.Breed[xi][yi][ind].maleY++;
			cell.Ma[xi][yi]++;
			to.M++;to.HegM++;
			UpdateMateM(xi,yi,ind,'b','Y');
			}
		else 	{
			indiv.Breed[xi][yi][ind].juvW--;
			indiv.Breed[xi][yi][ind].maleW++;
			cell.Ma[xi][yi]++;
			to.M++;
			UpdateMateM(xi,yi,ind,'b','W');
			};

		int oldcomp=indiv.Breed[xi][yi][ind].comp;
	int newcomp=(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW)*(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW);
		indiv.Breed[xi][yi][ind].comp=newcomp;
		cell.J_comp[xi][yi]+=newcomp-oldcomp;
		to.comp+=newcomp-oldcomp;
		      if( indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW ==0)
		      {indiv.Breed[xi][yi][ind].status='e';to.Breed_e++;
		      };
	return;};



	void MaleDie()
	      {
		int* ii=pick2D(cell.Ma,to.M);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int test=0;
		int ind;
		while(test==0)
			{
			ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
			if(rg.Random()*cell.Ma[xi][yi]<indiv.Breed[xi][yi][ind].maleW+ indiv.Breed[xi][yi][ind].maleY)test=1;
			};
		if((indiv.Breed[xi][yi][ind].maleW+indiv.Breed[xi][yi][ind].maleY)*rg.Random()<indiv.Breed[xi][yi][ind].maleW)
		  {
		    indiv.Breed[xi][yi][ind].maleW--;
		    UpdateMateM(xi,yi,ind,'d','W');
		  }
		else
		  {
		    indiv.Breed[xi][yi][ind].maleY--;
		    UpdateMateM(xi,yi,ind,'d','Y');
		    to.HegM--;
		  }
		cell.Ma[xi][yi]--;
		to.M--;
		if(indiv.Breed[xi][yi][ind].status=='d' && indiv.Breed[xi][yi][ind].maleW+indiv.Breed[xi][yi][ind].maleY+indiv.Breed[xi][yi][ind].unmated_females==0)
		    {indiv.Breed[xi][yi].erase(indiv.Breed[xi][yi].begin()+ind);
		    cell.Breed[xi][yi]--;
		    to.Breed_d--;};
      return;};

	void UnmatedDie()
	      {
		int* ii=pick2D(cell.Un,to.Un);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind;
		int test=0;
		while(test==0)
			{
			ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
			if(rg.Random()*cell.Un[xi][yi]<indiv.Breed[xi][yi][ind].unmated_females)test=1;
			};
		indiv.Breed[xi][yi][ind].unmated_females--;
		cell.Un[xi][yi]--;
		to.Un--;
		UpdateMateU(xi,yi,ind,'d');
		if(indiv.Breed[xi][yi][ind].status=='d' && indiv.Breed[xi][yi][ind].maleW+indiv.Breed[xi][yi][ind].maleY+indiv.Breed[xi][yi][ind].unmated_females==0)
		    {indiv.Breed[xi][yi].erase(indiv.Breed[xi][yi].begin()+ind);
		    cell.Breed[xi][yi]--;
		    to.Breed_d--;};
	    return;};

	void Mate()
	      {
		char mater;
		int* ii=pick2D(cell.U_mate,to.mate);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind;
		int test=0;
		while(test==0)
			{
			ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
			if(rg.Random()*cell.U_mate[xi][yi]<indiv.Breed[xi][yi][ind].mate_Y_rate+indiv.Breed[xi][yi][ind].mate_W_rate)test=1;
			};
		if(indiv.Breed[xi][yi][ind].mate_W_rate+indiv.Breed[xi][yi][ind].mate_Y_rate*rg.Random()>indiv.Breed[xi][yi][ind].mate_W_rate) mater='Y';//Y type is the mater
		else mater='W';
		HostSeekers aj;
		aj.genotype=mater;
		aj.hum_hab=0;
		aj.jump_rate=1;
		aj.x=indiv.Breed[xi][yi][ind].x;
		aj.y=indiv.Breed[xi][yi][ind].y;
		indiv.Ho[xi][yi].push_back(aj);
		cell.Ho[xi][yi]++;
		to.Ho++;
		UpdateHabInd(xi,yi,cell.Ho[xi][yi]-1,'h');
		UpdateMateU(xi,yi,ind,'d');
		indiv.Breed[xi][yi][ind].unmated_females--;
		cell.Un[xi][yi]--;
		to.Un--;
		if(indiv.Breed[xi][yi][ind].status=='d' && indiv.Breed[xi][yi][ind].maleW+indiv.Breed[xi][yi][ind].maleY+indiv.Breed[xi][yi][ind].unmated_females==0)
		    {indiv.Breed[xi][yi].erase(indiv.Breed[xi][yi].begin()+ind);
		    cell.Breed[xi][yi]--;
		    to.Breed_d--;};
	    return;}

	void HDie()
	      {
		int* ii=pick2D(cell.Ho,to.Ho);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind=rg.IRandom(0,cell.Ho[xi][yi]-1);
		cell.Ho[xi][yi]--;
		cell.H_gam[xi][yi]-=indiv.Ho[xi][yi][ind].hum_hab;
		to.Hfeed-=indiv.Ho[xi][yi][ind].hum_hab;
		cell.H_move[xi][yi]-=indiv.Ho[xi][yi][ind].jump_rate;
		to.Hmove-=indiv.Ho[xi][yi][ind].jump_rate;
		indiv.Ho[xi][yi].erase(indiv.Ho[xi][yi].begin()+ind);
		to.Ho--;
		if(cell.Ho[xi][yi]==0)
		{
			cell.H_move[xi][yi]=0;
			if(to.Ho==0)to.Hmove=0;
		};
	      return;};


	void HFeed()
	      {
		int* ii=pick2D(cell.H_gam,to.Hfeed);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind;
		int test=0;
		while(test==0)
			{
			ind=rg.IRandom(0,cell.Ho[xi][yi]-1);
			if(rg.Random()*cell.H_gam[xi][yi]<indiv.Ho[xi][yi][ind].hum_hab)test=1;
			};
//----find a feedsite within detection distance-----------------------------------------
		double ra=indiv.Ho[xi][yi][ind].hum_hab*rg.Random();
		int pxx,pyy,index;
		double dx1,dx2,dy1,dy2;
		int runpat=0;
		int k=0;int kk=0;
		while(k<3 && ra>runpat)
		{
			while(kk<3 && ra> runpat)
			{
			      if(k==0){pxx=modulo(xi-1,'X'); dx1=0;dx2=dx;};
			      if(k==1){pxx=xi;dx1=0;dx2=0;};
			      if(k==2){pxx=modulo(xi+1,'X');dx1=dx;dx2=0;};
			      if(kk==0){pyy=modulo(yi-1,'Y');dy1=0;dy2=dy;};
			      if(kk==1){pyy=yi;dy1=0;dy2=0;};
			      if(kk==2){pyy=modulo(yi+1,'Y');dy1=dy;dy2=0;};
				index=0;
				while(index<cell.Feed[pxx][pyy] && ra> runpat)
				  {
				  if(dist(dx1+indiv.Feed[pxx][pyy][index].x, dy1+indiv.Feed[pxx][pyy][index].y, dx2+indiv.Ho[xi][yi][ind].x, dy2+indiv.Ho[xi][yi][ind].y)-pa.LA<0)runpat++;
				  index++;
				};
				kk++;
			};
			k++;
			kk=0;
		};
		index--;
//----------------------------------------------------------------------------------------
		Ovipositers aj;
		aj.eggs=random_poisson(pa.kappa);
		aj.x = indiv.Feed[pxx][pyy][index].x;
		aj.y = indiv.Feed[pxx][pyy][index].y;
		aj.larv_hab=0;
		aj.genotype=indiv.Ho[xi][yi][ind].genotype;
		aj.jump_rate=1;
		indiv.Ov[pxx][pyy].push_back(aj);
		cell.Ov[pxx][pyy]++;
		to.Ov++;
		cell.Ho[xi][yi]--;
		to.Ho--;
		cell.H_gam[xi][yi]-=indiv.Ho[xi][yi][ind].hum_hab;
		to.Hfeed-=indiv.Ho[xi][yi][ind].hum_hab;
		cell.H_move[xi][yi]-=indiv.Ho[xi][yi][ind].jump_rate;
		to.Hmove-=indiv.Ho[xi][yi][ind].jump_rate;
		indiv.Ho[xi][yi].erase(indiv.Ho[xi][yi].begin()+ind);
		UpdateHabInd(pxx,pyy,cell.Ov[pxx][pyy]-1,'o');
		if(cell.Ho[xi][yi]==0)
		{
			cell.H_move[xi][yi]=0;
			if(to.Ho==0)to.Hmove=0;
		};
	    return;};


	void HJump()
	      {
		int* ii=pick2Ddub(cell.H_move,to.Hmove);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int test=0;
		int ind;
		while(test==0)
			{
			ind=rg.IRandom(0,cell.Ho[xi][yi]-1);
			if(rg.Random()*cell.H_move[xi][yi]<indiv.Ho[xi][yi][ind].jump_rate)test=1;
			};
		double dis = sqrt(rg.Random()) * pa.LRH; //top hat kernel dispersal, LRH max disp
		double ang = 2*PI*rg.Random();
		double xjump= dis*cos(ang);
		double yjump= dis*sin(ang);
		double xdis = indiv.Ho[xi][yi][ind].x+xjump;
		double ydis = indiv.Ho[xi][yi][ind].y+yjump;
		int xinew,yinew;
		if(xdis>0)xinew=(xi+int(xdis/dx)) % nx;
		if(xdis<=0)xinew=modulo(xi+int(xdis/dx)-1,'X');
		if(ydis>0)yinew=(yi+int(ydis/dy)) % ny;
		if(ydis<=0)yinew=modulo(yi+int(ydis/dy)-1,'Y');
		double xnew = dmodulo(xdis,dx);
		double ynew = dmodulo(ydis,dy);
		HostSeekers aj;
		aj.x = xnew;
		aj.y = ynew;
		aj.jump_rate=1;
		aj.genotype=indiv.Ho[xi][yi][ind].genotype;
		aj.hum_hab=0;
		cell.H_gam[xi][yi]-=indiv.Ho[xi][yi][ind].hum_hab;
		to.Hfeed-=indiv.Ho[xi][yi][ind].hum_hab;
		cell.H_move[xi][yi]-=indiv.Ho[xi][yi][ind].jump_rate;
		to.Hmove-=indiv.Ho[xi][yi][ind].jump_rate;
		cell.Ho[xi][yi]--;
		indiv.Ho[xi][yi].erase(indiv.Ho[xi][yi].begin()+ind);
		indiv.Ho[xinew][yinew].push_back(aj);
		cell.Ho[xinew][yinew]++;
		UpdateHabInd(xinew,yinew,cell.Ho[xinew][yinew]-1,'h');
		if(cell.Ho[xi][yi]==0)
		{
			cell.H_move[xi][yi]=0;
			if(to.Ho==0)to.Hmove=0;
		};
	return;};


	void ODie()
	    {
		int* ii=pick2D(cell.Ov,to.Ov);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind=rg.IRandom(0,cell.Ov[xi][yi]-1);
		cell.Ov[xi][yi]--;
		cell.O_ovi[xi][yi]-=indiv.Ov[xi][yi][ind].larv_hab;
		to.Oovi-=indiv.Ov[xi][yi][ind].larv_hab;
		cell.O_move[xi][yi]-=indiv.Ov[xi][yi][ind].jump_rate;
		to.Omove-=indiv.Ov[xi][yi][ind].jump_rate;
		indiv.Ov[xi][yi].erase(indiv.Ov[xi][yi].begin()+ind);
		to.Ov--;
		if(cell.Ov[xi][yi]==0)
		{
			cell.O_move[xi][yi]=0;
			if(to.Ov==0)to.Omove=0;
		};
	return;};


	void OJump()
	      {
		int* ii=pick2Ddub(cell.O_move,to.Omove);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind;
		int test=0;
		while(test==0)
		{
		ind=rg.IRandom(0,cell.Ov[xi][yi]-1);
		if(rg.Random()*cell.O_move[xi][yi]<indiv.Ov[xi][yi][ind].jump_rate)test=1;
		};
		double dis = sqrt(rg.Random()) * pa.LRO; //top hat kernel dispersal, LRH max disp
		double ang = 2*PI*rg.Random();
		double xjump= dis*cos(ang);
		double yjump= dis*sin(ang);
		double xdis = indiv.Ov[xi][yi][ind].x+xjump;
		double ydis = indiv.Ov[xi][yi][ind].y+yjump;
		int xinew,yinew;
		if(xdis>0)xinew=(xi+int(xdis/dx)) % nx;
		if(xdis<=0)xinew=modulo(xi+int(xdis/dx)-1,'X');
		if(ydis>0)yinew=(yi+int(ydis/dy)) % ny;
		if(ydis<=0)yinew=modulo(yi+int(ydis/dy)-1,'Y');
		double xnew = dmodulo(xdis,dx);
		double ynew = dmodulo(ydis,dy);
		int num_eggs = indiv.Ov[xi][yi][ind].eggs;
		Ovipositers aj;
		aj.x = xnew;
		aj.y = ynew;
		aj.eggs=num_eggs;
		aj.genotype=indiv.Ov[xi][yi][ind].genotype;
		aj.larv_hab=0;
		aj.jump_rate=1;
		cell.Ov[xi][yi]--;
		cell.O_ovi[xi][yi]-=indiv.Ov[xi][yi][ind].larv_hab;
		to.Oovi-=indiv.Ov[xi][yi][ind].larv_hab;
		cell.O_move[xi][yi]-=indiv.Ov[xi][yi][ind].jump_rate;
		to.Omove-=indiv.Ov[xi][yi][ind].jump_rate;
		indiv.Ov[xi][yi].erase(indiv.Ov[xi][yi].begin()+ind);
		indiv.Ov[xinew][yinew].push_back(aj);
		cell.Ov[xinew][yinew]++;
		UpdateHabInd(xinew,yinew,cell.Ov[xinew][yinew]-1,'o');
		if(cell.Ov[xi][yi]==0)
		{
			cell.O_move[xi][yi]=0;
			if(to.Ov==0)to.Omove=0;
		};
	  return;};




	void JuvCreate(char gen)
	      {
		int* ii=pick2D(cell.Breed,to.Breed_w);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
		if(gen=='X') {indiv.Breed[xi][yi][ind].juvX++;}
		else if(gen=='Y'){indiv.Breed[xi][yi][ind].juvY++;}
		else if(gen=='W'){indiv.Breed[xi][yi][ind].juvW++;};
		cell.Juv[xi][yi]++;
		to.J++;
		int oldcomp=indiv.Breed[xi][yi][ind].comp;
		int newcomp=(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW)*(indiv.Breed[xi][yi][ind].juvX+indiv.Breed[xi][yi][ind].juvY+indiv.Breed[xi][yi][ind].juvW);
		indiv.Breed[xi][yi][ind].comp=newcomp;
		cell.J_comp[xi][yi]+=newcomp-oldcomp;
		to.comp+=newcomp-oldcomp;
		if(indiv.Breed[xi][yi][ind].status=='e')
                        {
                                indiv.Breed[xi][yi][ind].status='w';
                                to.Breed_e--;
                        };

	    return;};


	void FeedCreate()
	      {
		FeedSite apv;
		int xi=rg.IRandom(0,nx-1);
		int yi=rg.IRandom(0,ny-1);
		apv.x=dx*rg.Random();
		apv.y=dy*rg.Random();
		cell.Feed[xi][yi]++;
		indiv.Feed[xi][yi].push_back(apv);
		to.FeedSites++;
		UpdateHabHab(xi,yi,cell.Feed[xi][yi]-1,'b');
	    return;};


	void FeedDestroy()
	      {
		int* ii=pick2D(cell.Feed,to.FeedSites);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind=rg.IRandom(0,cell.Feed[xi][yi]-1);
		UpdateHabHab(xi,yi,cell.Feed[xi][yi]-1,'d');
		indiv.Feed[xi][yi].erase(indiv.Feed[xi][yi].begin()+ind);
		cell.Feed[xi][yi]--;
		to.FeedSites--;
	    return;};

	void BreedCreate()
	      {
		BreedSite apl; //Create a breeding site called 'apl'. That stores information about the location of it. Along with numbers of individuals around it.
		int xi,yi;
		if(pa.sigmaC>0)//pa.sigmaC measures the turnover of sample points. It seems like when there is turnover it is necessary
            //to create breeding sites according to house densities. Otherwise just allocate them randomly.
			{

            // Pick a large square at random, although bias towards those squares which have the highest house density. This returns a pointer to a 2D array which has the nx and ny indices of the large square
			int* ii=pick2Ddub(cell.house_dense,to.house_dense); //cell.house_dense is an array with two indices - nx and ny - which holds the house density in that square.
			//Get the value of the nx coordinate of the large square
			xi=*ii;
			//Get the value of the ny coordinate of the large square (which is one memory position ahead of it)
			yi=*(ii+1);
			delete[] ii; //Delete the pointer
			int ind;
			int test=0;

			while(test==0)
				{
				    //Select a random sample from the list of all samples from within the selected large square
				ind=rg.IRandom(0,cell.samples[xi][yi]-1);

                // If the sum of the house density within a large square (multiplied by a random (0,1) number) is less than the house density of a particularly randomly drawn
                // sample's house density (where the sample is drawn from those within the large square), then make test = 1.
				if(rg.Random()*cell.house_dense[xi][yi]<indiv.sa[xi][yi][ind].house_dense)test=1;
				};
			apl.x = indiv.sa[xi][yi][ind].x;
			apl.y = indiv.sa[xi][yi][ind].y;
			cell.house_dense[xi][yi]-=indiv.sa[xi][yi][ind].house_dense;
			to.house_dense-=indiv.sa[xi][yi][ind].house_dense;
			indiv.sa[xi][yi].erase(indiv.sa[xi][yi].begin()+ind);
			cell.samples[xi][yi]--;
			to.samples--;
			if(cell.samples[xi][yi]==0)
				{
				cell.house_dense[xi][yi]=0;
				};
			sampCreate();
			}
		else // Randomly select a large square, and coordinates within that large square
			{
            //Large square selection
			xi=rg.IRandom(0,nx-1);
			yi=rg.IRandom(0,ny-1);

			//Random location from within that large square. 'apv' is an instance of a 'Breedsite' and contains information
			// about its location, along with the numbers of individuals in it.
			apl.x=dx*rg.Random();
			apl.y=dy*rg.Random();
			};

        // Initialise all the numbers of individuals within the breeding site to be zero.
		apl.comp=0;
		apl.juvX=0;
		apl.juvY=0;
		apl.maleW=0;
		apl.maleY=0;
		apl.mate_W_rate=0;
		apl.mate_Y_rate=0;
		apl.juvW=0;
		apl.status='e';
		apl.unmated_females=0;

		//Increment the count of the number of breed sites within that large square by 1.
		cell.Breed[xi][yi]++;

		//Add this breedsite to the list of breedsites for this particular large square
		indiv.Breed[xi][yi].push_back(apl);

		//Increment totals by one. Not sure what the difference between breed_w and breed_e is
		to.Breed_w++;
		to.Breed_e++;

		//Update the ovipositers after the breedsite has been created.
		UpdateHabHab(xi,yi,cell.Breed[xi][yi]-1,'b');
	    return;};

	void BreedDestroy()
	      {
		int xi,yi,ind;
		int numX,numY,numW;
		int test =0;
		while (test==0)
			{
			int* ii=pick2D(cell.Breed,to.Breed_d+to.Breed_w);
			xi=*ii;
			yi=*(ii+1);
			delete[] ii;
			ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
			if(indiv.Breed[xi][yi][ind].status!='d')test=1;
			};
		to.Breed_w--;
		if(indiv.Breed[xi][yi][ind].status=='e')to.Breed_e--;
		UpdateHabHab(xi,yi,ind,'d');
		if(indiv.Breed[xi][yi][ind].maleY+indiv.Breed[xi][yi][ind].maleW+indiv.Breed[xi][yi][ind].unmated_females==0)
                    {
                        numX=indiv.Breed[xi][yi][ind].juvX;
                        numY=indiv.Breed[xi][yi][ind].juvY;
			numW=indiv.Breed[xi][yi][ind].juvW;
			indiv.Breed[xi][yi].erase(indiv.Breed[xi][yi].begin()+ind);
			cell.Breed[xi][yi]--;
                        cell.Juv[xi][yi]-=numX+numY+numW;
                        to.J-=numX+numY+numW;
                        cell.J_comp[xi][yi]-=(numX+numY+numW)*(numX+numY+numW);
                        to.comp-=(numX+numY+numW)*(numX+numY+numW);
                    }
                else
                    {
			indiv.Breed[xi][yi][ind].status='d';to.Breed_d++;
                        numX=indiv.Breed[xi][yi][ind].juvX;
                        numY=indiv.Breed[xi][yi][ind].juvY;
			numW=indiv.Breed[xi][yi][ind].juvW;
                        indiv.Breed[xi][yi][ind].juvX=0;
                        indiv.Breed[xi][yi][ind].juvY=0;
			indiv.Breed[xi][yi][ind].juvW=0;
                        cell.Juv[xi][yi]-=(numX+numY+numW);
                        to.J-=numX+numY+numW;
                        indiv.Breed[xi][yi][ind].comp=0;
                        cell.J_comp[xi][yi]-=(numX+numY+numW)*(numX+numY+numW);
                        to.comp-=(numX+numY+numW)*(numX+numY+numW);
                    };
	   return;};


	void sampCreate()
	      {
		sample apv; //This is an example of a struct 'sample' which holds the (x,y) and a variable called 'house_dense'.

		// First select a large square at random via its nx and ny coordinates.
		int xi=rand() % nx;
		int yi=rand() % ny;

        //Generate a sampling point at a random position. Generate a random position within the large square. Note this is not an integer.
		apv.x=dx*rg.Random();//dx is the width of a large square region
		apv.y=dy*rg.Random();
		apv.house_dense=1;

        //A record is kept of all the information used as a component of an 'indiv' struct, in the 'sample' component of that.
		indiv.sa[xi][yi].push_back(apv);

		//Add one onto the totals component corresponding to samples for this large square.
		cell.samples[xi][yi]++;

		//Add one on to the total samples for all space
		to.samples++;


		UpdateSample(xi,yi,cell.samples[xi][yi]-1);
	    return;};


	void sampDestroy()
	      {
		int* ii=pick2D(cell.samples,to.samples);
		int xi=*ii;
		int yi=*(ii+1);
		delete[] ii;
		int ind=rg.IRandom(0,cell.samples[xi][yi]-1);
		cell.house_dense[xi][yi]-=indiv.sa[xi][yi][ind].house_dense;
		to.house_dense-=indiv.sa[xi][yi][ind].house_dense;
		indiv.sa[xi][yi].erase(indiv.sa[xi][yi].begin()+ind);
		cell.samples[xi][yi]--;
		to.samples--;
		if(cell.samples[xi][yi]==0)
		{
			cell.house_dense[xi][yi]=0;
		};
	    return;};

    // Function to update local ovipositers after a breedsite is created or destroyed.
    // nxx and nyy are indices of the particular large square being picked. index is the number of breedsites within that large
    // square. ev is a char which is 'b' if the site is created, and 'd' if it is destroyed.
	void UpdateHabHab(int nxx,int nyy,int index,char ev)//if a breedsite is created (ev='b') or destroyed (ev='d'), update local ovipositers
	{

		int xi,yi;
		int indexB;
		int q;
		double dx1,dx2,dy1,dy2;
		if(ev=='b')q=1;//Site created
		if(ev=='d')q=-1;//Site destroyed
		for(int k=0;k<3;k++)
		{
			for(int kk=0;kk<3;kk++)
			{
            // Need to figure out what is happening here. Think it is some sort of selection of the large square dependent on k
			if(k==0){xi=modulo(nxx-1,'X'); dx1=0;dx2=dx;};
			if(k==1){xi=nxx;dx1=0;dx2=0;};
			if(k==2){xi=modulo(nxx+1,'X');dx1=dx;dx2=0;};
			if(kk==0){yi=modulo(nyy-1,'Y');dy1=0;dy2=dy;};
			if(kk==1){yi=nyy;dy1=0;dy2=0;};
			if(kk==2){yi=modulo(nyy+1,'Y');dy1=dy;dy2=0;};

            // Go through each of the individual Ovipositers within the large square. 'Cell.Ov[xi][yi] holds the total number of ovipositers in that large square
			for(indexB=0;indexB<cell.Ov[xi][yi];indexB++)
				{
                //If the distance between the particular ovipositer and the breeding site is less than the breedsite detection radius then so some sort of egg laying (not sure on the specifics here)
				if(dist(dx1+indiv.Ov[xi][yi][indexB].x,dy1+indiv.Ov[xi][yi][indexB].y, dx2+indiv.Breed[nxx][nyy][index].x,dy2+indiv.Breed[nxx][nyy][index].y)<pa.LB)
					{
						indiv.Ov[xi][yi][indexB].larv_hab+=q;
						cell.O_ovi[xi][yi]+=q;
						to.Oovi+=q;
						cell.O_move[xi][yi]+=indiv.Ov[xi][yi][indexB].jump_rate*(pow(pa.betaO,q)-1);
						to.Omove+=indiv.Ov[xi][yi][indexB].jump_rate*(pow(pa.betaO,q)-1);
						indiv.Ov[xi][yi][indexB].jump_rate*=pow(pa.betaO,q);
					};
				};
			};
		};
		return;};

	void UpdateHabInd(int nxx,int nyy,int index,char horo)//Set spatial variables for new hostseeker (horo='h') or ovipositer ('o')
		{
		int xi,yi;
		int indexB;
		double xx,yy;
		if(horo=='h'){xx=indiv.Ho[nxx][nyy][index].x;yy=indiv.Ho[nxx][nyy][index].y;}
		else {xx=indiv.Ov[nxx][nyy][index].x;yy=indiv.Ov[nxx][nyy][index].y;};
		double dx1,dx2,dy1,dy2;
		for(int k=0;k<3;k++)
		{
			for(int kk=0;kk<3;kk++)
			{
			if(k==0){xi=modulo(nxx-1,'X'); dx1=0;dx2=dx;};
			if(k==1){xi=nxx;dx1=0;dx2=0;};
			if(k==2){xi=modulo(nxx+1,'X');dx1=dx;dx2=0;};
			if(kk==0){yi=modulo(nyy-1,'Y');dy1=0;dy2=dy;};
			if(kk==1){yi=nyy;dy1=0;dy2=0;};
			if(kk==2){yi=modulo(nyy+1,'Y');dy1=dy;dy2=0;};
			if(horo=='h')
			{
			for(indexB=0;indexB<cell.Feed[xi][yi];indexB++)
				{
				if(dist(dx1+indiv.Feed[xi][yi][indexB].x,dy1+indiv.Feed[xi][yi][indexB].y, dx2+xx,dy2+yy)<pa.LA)
					{
						indiv.Ho[nxx][nyy][index].hum_hab++;
						indiv.Ho[nxx][nyy][index].jump_rate*=pa.betaH;
					};
				};
			};
			if(horo=='o')
			{
				for(indexB=0;indexB<cell.Breed[xi][yi];indexB++)
				{
				  if(indiv.Breed[xi][yi][indexB].status!='d')
				  {
				    if(dist(dx1+indiv.Breed[xi][yi][indexB].x,dy1+indiv.Breed[xi][yi][indexB].y, dx2+xx,dy2+yy)<pa.LB)
					{
						indiv.Ov[nxx][nyy][index].larv_hab++;
						indiv.Ov[nxx][nyy][index].jump_rate*=pa.betaO;
					};
				  };
				};
			};
			};
		};
		if(horo=='h')
			{
			cell.H_move[nxx][nyy]+=indiv.Ho[nxx][nyy][index].jump_rate;
			to.Hmove+=indiv.Ho[nxx][nyy][index].jump_rate;
			cell.H_gam[nxx][nyy]+=indiv.Ho[nxx][nyy][index].hum_hab;
			to.Hfeed+=indiv.Ho[nxx][nyy][index].hum_hab;}
		else
			{cell.O_move[nxx][nyy]+=indiv.Ov[nxx][nyy][index].jump_rate;
			to.Omove+=indiv.Ov[nxx][nyy][index].jump_rate;
			cell.O_ovi[nxx][nyy]+=indiv.Ov[nxx][nyy][index].larv_hab;
			to.Oovi+=indiv.Ov[nxx][nyy][index].larv_hab;};

	return;};




	void UpdateMateU(int nxx,int nyy,int index,char ev)//following emergence or death/mating of an unmated female, update her breedsite based on local males
		{
		      int xi,yi;
		      int indexB;
		      double xx,yy;
		      xx=indiv.Breed[nxx][nyy][index].x;
		      yy=indiv.Breed[nxx][nyy][index].y;
		      int q;
		      if(ev=='b')q=1;
		      else q=-1;
		      double dx1,dx2,dy1,dy2;
		      for(int k=0;k<3;k++)
		      {
			      for(int kk=0;kk<3;kk++)
			      {
				if(k==0){xi=modulo(nxx-1,'X'); dx1=0;dx2=dx;};
				if(k==1){xi=nxx;dx1=0;dx2=0;};
				if(k==2){xi=modulo(nxx+1,'X');dx1=dx;dx2=0;};
				if(kk==0){yi=modulo(nyy-1,'Y');dy1=0;dy2=dy;};
				if(kk==1){yi=nyy;dy1=0;dy2=0;};
				if(kk==2){yi=modulo(nyy+1,'Y');dy1=dy;dy2=0;};
				for(indexB=0;indexB<cell.Breed[xi][yi];indexB++)
					      {
						      if(dist(dx1+indiv.Breed[xi][yi][indexB].x,dy1+indiv.Breed[xi][yi][indexB].y,dx2+xx,dy2+yy)<pa.LM)
						      {
							      indiv.Breed[nxx][nyy][index].mate_W_rate+=q*indiv.Breed[xi][yi][indexB].maleW;//+=q
							      indiv.Breed[nxx][nyy][index].mate_Y_rate+=q*indiv.Breed[xi][yi][indexB].maleY;
							      cell.U_mate[nxx][nyy]+=q*(indiv.Breed[xi][yi][indexB].maleW+indiv.Breed[xi][yi][indexB].maleY);
							      to.mate+=q*(indiv.Breed[xi][yi][indexB].maleW+indiv.Breed[xi][yi][indexB].maleY);
						      };
					      };
			      };
		      };
	      return;};
	void UpdateMateM(int nxx,int nyy,int index,char ev,char wory)//following emergence or death of male, update mating rates
		{
		      int xi,yi;
		      int indexB;
		      double xx,yy;
		      int q;
		      if(ev=='b')q=1;
		      else q=-1;
		      xx=indiv.Breed[nxx][nyy][index].x;yy=indiv.Breed[nxx][nyy][index].y;
		      double dx1,dx2,dy1,dy2;
		      for(int k=0;k<3;k++)
		      {
			      for(int kk=0;kk<3;kk++)
			      {
				if(k==0){xi=modulo(nxx-1,'X'); dx1=0;dx2=dx;};
				if(k==1){xi=nxx;dx1=0;dx2=0;};
				if(k==2){xi=modulo(nxx+1,'X');dx1=dx;dx2=0;};
				if(kk==0){yi=modulo(nyy-1,'Y');dy1=0;dy2=dy;};
				if(kk==1){yi=nyy;dy1=0;dy2=0;};
				if(kk==2){yi=modulo(nyy+1,'Y');dy1=dy;dy2=0;};
				      for(indexB=0;indexB<cell.Breed[xi][yi];indexB++)
					      {
						     if(dist(dx1+indiv.Breed[xi][yi][indexB].x,dy1+indiv.Breed[xi][yi][indexB].y,
							      dx2+xx,dy2+yy)<pa.LM)
						      {
							if(wory=='W')
							  indiv.Breed[xi][yi][indexB].mate_W_rate+=q*indiv.Breed[xi][yi][indexB].unmated_females;
							else indiv.Breed[xi][yi][indexB].mate_Y_rate+=q*indiv.Breed[xi][yi][indexB].unmated_females;
							cell.U_mate[xi][yi]+=q*indiv.Breed[xi][yi][indexB].unmated_females;
							to.mate+=q*indiv.Breed[xi][yi][indexB].unmated_females;
						      };
					      };
			      };
		      };
      return;};


	void UpdateSample(int nxx,int nyy,int index)//following creation of sample point, update its house density
		{
		      int xi,yi;
		      int indexB;
		      double xx,yy;
		      xx=indiv.sa[nxx][nyy][index].x; //xx is the x coordinate of the sample point given by the index
		      yy=indiv.sa[nxx][nyy][index].y; //yy is the y coordinate of the sample point given by the index
		      double dx1,dx2,dy1,dy2;
		      for(int k=0;k<3;k++)
		      {
			      for(int kk=0;kk<3;kk++)
			      {
				if(k==0){xi=modulo(nxx-1,'X'); dx1=0;dx2=dx;};
				if(k==1){xi=nxx;dx1=0;dx2=0;};
				if(k==2){xi=modulo(nxx+1,'X');dx1=dx;dx2=0;};
				if(kk==0){yi=modulo(nyy-1,'Y');dy1=0;dy2=dy;};
				if(kk==1){yi=nyy;dy1=0;dy2=0;};
				if(kk==2){yi=modulo(nyy+1,'Y');dy1=dy;dy2=0;};
				for(indexB=0;indexB<cell.Feed[xi][yi];indexB++)
				      {
					      if(dist(dx1+indiv.Feed[xi][yi][indexB].x,dy1+indiv.Feed[xi][yi][indexB].y, dx2+xx,dy2+yy)<pa.Lrho)//pa.Lrho is the distance from a patch to a house (measures spatial scale of covariance between breeding sites and feeding
					      {
						      indiv.sa[nxx][nyy][index].house_dense*=pa.rho;//+=q //This updates the house density according to the covariance between breeding and feeding sites
					      };
					};
			      };
		      };
		      cell.house_dense[nxx][nyy]+=indiv.sa[nxx][nyy][index].house_dense;
		      to.house_dense+=indiv.sa[nxx][nyy][index].house_dense;
	      return;};

    // Need to figure out what the point of this is!
	int modulo(int i,char XorY)
		{
		int res;
		if(XorY=='X'){res=(i % nx +nx)%nx;} else {res=(i % ny +ny)%ny;};
		return res;};

	double dmodulo(double i, double n)
		{ return fmod((fmod(i,n)+n),n); };

	int pick (double* list,int len,double sum)//A function which takes a list of the propensities for each of the reactions, and chooses
	//a reaction on the basis of that propensity. Not sure what exact flavour of Gillespie this is?
	//Sum here is the sum of all the propensities. Len is the number of the reactions
		{
			int test=0;
			int i;
			while(test==0)
			{i=rg.IRandom(0,len);
				if(rg.Random()<list[i]/sum)test=1;
			};
		return i;};

    // This is a function which selects a large square at random, but biases the selection towards those squares which have a higher house density.
	int* pick2Ddub (double list[][ny],double sum)//list in this case is a 2D array which holds the house densities in each large square. sum is the total house density.
	{
		int *ii = new int[2];
		int i1;
		int i2;
		int test=0;
		while(test==0)
		{
		    //Pick a large square at random
			i1=rg.IRandom(0,nx-1);
			i2=rg.IRandom(0,ny-1);
			//If a random number is less than the % of total house density represented by that particular square, then stop the iteration.
			//Hence the bigger the house density is the more likely it will be that we stop the iteration and select that large square.
			if(rg.Random()<list[i1][i2]/sum)test=1;
		};

		//These are simply the chosen indices of the large square
		ii[0]=i1;
		ii[1]=i2;
	return ii;};

	int* pick2D (int list[][ny],int sum)
		{
			int *ii = new int[2];
			int i1=0;
			int i2=0;
			int test=0;
	while(test==0)
		{
			i1=rg.IRandom(0,nx-1);
			i2=rg.IRandom(0,ny-1);
			if(rg.Random()<(double) list[i1][i2]/sum)test=1;
		};
		ii[0]=i1;
		ii[1]=i2;
	return ii;};

	void PutHeg (char dist)// update system for heg release
	      {
		int num;
		int xi,yi,ind;
		int test = 0;
		if(dist=='u')
		{
		num=in.heg;
		for(int index=0;index<num;index++)
			{
			  while (test==0)
			    {
				int* ii=pick2D(cell.Breed,to.Breed_d+to.Breed_w);
				xi=*ii;
				yi=*(ii+1);
				delete[] ii;
				ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
				if(indiv.Breed[xi][yi][ind].status=='w')test=1;
			    };
			indiv.Breed[xi][yi][ind].maleY++;
			cell.Ma[xi][yi]++;
			to.M++;
			UpdateMateM(xi,yi,ind,'b','Y');
			};
			to.HegM+=num;
		};
		if(dist=='p')
		{
			for(int ii=0;ii<in.num_sites;ii++)
			{
			num=int(in.heg/(double) in.num_sites);
			   while (test==0)
			    {
				int* ii=pick2D(cell.Breed,to.Breed_d+to.Breed_w);
				xi=*ii;
				yi=*(ii+1);
				delete[] ii;
				ind=rg.IRandom(0,cell.Breed[xi][yi]-1);
				if(indiv.Breed[xi][yi][ind].status=='w')test=1;
			    };
			indiv.Breed[xi][yi][ind].maleY+=num;
			cell.Ma[xi][yi]+=num;
			to.M+=num;
			for(int index=0;index<num;index++)UpdateMateM(xi,yi,ind,'b','Y');
			to.HegM+=num;
			};
		};
			return;}


	int random_poisson(double landa)
	{
	double p=exp(-landa);
	double g=p;
	double u=rg.Random()*0.9999999;
	int k=0;
	while (u>g)
	    {
	    p*=(landa/(double)(++k));
		g+=p;
	    };
	return k;
	};



	double random_exp(double lamda)
	{double dd= rg.Random()*0.999999;
	return (-log(1.0-dd)/(double)lamda);
	};

	double dist (double x1, double y1, double x2, double y2)
	{
		return double(sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
	};



	void record(int T,Individuals& indiv,PerCell& cell)//make data file with breedsite information
	{
	ostringstream os;
	ofstream logfile;
	os<<"Par"<<pa.set<<"Time"<<T<<".txt";
	cout<<"Making log file...\n";
	logfile.open(os.str().c_str());
	for(int nxx=0;nxx<nx;nxx++)
			{
				for(int nyy=0;nyy<ny;nyy++)
				{
					for(int index=0;index<cell.Breed[nxx][nyy];index++)
					{
						logfile<<dx*nxx+indiv.Breed[nxx][nyy][index].x<<"     "
							<<dy*nyy+indiv.Breed[nxx][nyy][index].y<<"     "
							<<indiv.Breed[nxx][nyy][index].juvX<<"     "
							<<indiv.Breed[nxx][nyy][index].juvW<<"     "
							<<indiv.Breed[nxx][nyy][index].juvY<<"     "
							<<indiv.Breed[nxx][nyy][index].unmated_females<<"     "
							<<indiv.Breed[nxx][nyy][index].maleW<<"     "
							<<indiv.Breed[nxx][nyy][index].maleY<<"     "
							<<indiv.Breed[nxx][nyy][index].mate_W_rate<<"     "
							<<indiv.Breed[nxx][nyy][index].mate_Y_rate<<"     "
							<<indiv.Breed[nxx][nyy][index].status<<endl;
					};

				};
			};
	os.str("");
	logfile.close();

	return;};


	void testfunc(char caller,int i)// debugging function, only needed if there is a problem!
	      {
		int cj,cc,cm,cu,ccb,cma,hg;
		int cjt=0;
		int cct=0;
		int cmt=0;
		int cut=0;
		int pbt=0;
		int cmat=0;
		int hgam=0;
		int oovi=0;
		for(int nxx=0;nxx<nx;nxx++)
			{
			for(int nyy=0;nyy<ny;nyy++)
				{
				cj=0;cc=0;cm=0;cu=0;ccb=0;cma=0;hg=0;
				//if(cell.Breed[nxx][nyy]!=indiv.Breed[nxx][nyy].size())cout<<"testfunc  "<<caller<<"  ev    "<<i<<"    "<<cell.Breed[nxx][nyy]<<"      "<<indiv.Breed[nxx][nyy].size();
				for (int k=0; k<cell.Breed[nxx][nyy];k++)
					{
					cj+=indiv.Breed[nxx][nyy][k].juvX+indiv.Breed[nxx][nyy][k].juvY+indiv.Breed[nxx][nyy][k].juvW;
					ccb+=(indiv.Breed[nxx][nyy][k].juvX+indiv.Breed[nxx][nyy][k].juvY+indiv.Breed[nxx][nyy][k].juvW)*
					    (indiv.Breed[nxx][nyy][k].juvX+indiv.Breed[nxx][nyy][k].juvY+indiv.Breed[nxx][nyy][k].juvW);
				      cc+=indiv.Breed[nxx][nyy][k].comp;
				      cm+=indiv.Breed[nxx][nyy][k].maleW+indiv.Breed[nxx][nyy][k].maleY;
				      cu+=indiv.Breed[nxx][nyy][k].unmated_females;
				      cma+=indiv.Breed[nxx][nyy][k].mate_Y_rate+indiv.Breed[nxx][nyy][k].mate_W_rate;
				      if(indiv.Breed[nxx][nyy][k].status=='d' && indiv.Breed[nxx][nyy][k].juvX+indiv.Breed[nxx][nyy][k].juvY+indiv.Breed[nxx][nyy][k].juvW>0)
				      { cout<<"breed dry "<<indiv.Breed[nxx][nyy][k].juvX+indiv.Breed[nxx][nyy][k].juvY+indiv.Breed[nxx][nyy][k].juvW<<"  caller  "<<i<<endl; exit(1);};
				    };
				for (int kk=0; kk<cell.Ho[nxx][nyy];kk++)
				{hg+=indiv.Ho[nxx][nyy][kk].hum_hab; };
				  if(cj!=cell.Juv[nxx][nyy])
				  {cout<<caller<<"    cj alert    "<<i<<"   cj  "<<cj <<"  ps   "<<cell.Juv[nxx][nyy]<<"  x "<<nxx<<"  y "<<nyy<<endl; exit(1);};

				  if(cc!=cell.J_comp[nxx][nyy])
				  {cout<<caller<<"    cc alert    "<<i<<"  cc   "<<cc<<"   ps  " <<cell.J_comp[nxx][nyy]<<" x  "<<nxx<<"   "<<nyy<<endl; exit(1);};

				   if(ccb!=cell.J_comp[nxx][nyy])
				  {cout<<caller<<"   ccb alert   "<<i<<"  ccb  "<<ccb<<"  cc  "<<cc<<"   ps  " <<cell.J_comp[nxx][nyy]<<"   juv  " <<cell.Juv[nxx][nyy]<<" x  "<<nxx<<"   "<<nyy<<endl; exit(1);};


				  if(cm!=cell.Ma[nxx][nyy])
				  {cout<<caller<<"    cm alert    "<<i<<" cm    "<<cm<<"  ps   " <<cell.Ma[nxx][nyy]<<" x  "<<nxx<<"  y "<<nyy<<endl; exit(1);};
				  if(cu!=cell.Un[nxx][nyy])
				  {cout<<caller<<"    cu alert    "<<i<<"  cu   "<<cu<<"  ps   "
				  <<cell.Un[nxx][nyy]<<" x  "<<nxx<<" y  "<<nyy<<endl; exit(1);};
				  if(cma!=cell.U_mate[nxx][nyy])
				  {cout<<caller<<"    cma alert    "<<i<<"  cma   "<<cma<<"  ps   " <<cell.U_mate[nxx][nyy]<<" x  "<<nxx<<" y  "<<nyy<<endl; exit(1);};
				  if(hg!=cell.H_gam[nxx][nyy])
				  {cout<<caller<<"   HG  alert    "<<i<<"  hg   "<<hg<<"  ps   " <<cell.H_gam[nxx][nyy]<<" x  "<<nxx<<" y  "<<nyy<<endl; exit(1);};
				  cjt+=cj;
				  cct+=cc;
				  cmt+=cm;
				  cut+=cu;
				  cmat+=cma;
				  pbt+=cell.Breed[nxx][nyy];
				  hgam+=cell.H_gam[nxx][nyy];
				  oovi+=cell.O_ovi[nxx][nyy];
				 };
			};
		if(cjt!=to.J) {cout<<caller<<"    cjt alert    "<<i<<"  cjt   "<<cjt<<"   to  " <<to.J<<endl; exit(1);};
		if(cct!=to.comp) {cout<<caller<<"    cct alert    "<<i<<"  cc   "<<cct<<"   to  " <<to.J<<endl; exit(1);};
		if(cmt!=to.M) {cout<<caller<<"    cmt alert    "<<i<<" cm    "<<cmt<<"  to   " <<to.M<<endl; exit(1);};
		if(cut!=to.Un) {cout<<caller<<"    cut alert    "<<i<<"  cu   "<<cut<<"  to   " <<to.Un<<endl;exit(1);};
		if(pbt!=to.Breed_d+to.Breed_w) {cout<<caller<<"    pbt alert    "<<i<<"  pb   "<<pbt<<"  to   " <<to.Breed_d<<endl;};
		if(cmat!=to.mate) {cout<<caller<<"    cmat alert    "<<i<<" cma    "<<cmat<<"  to   " <<to.mate<<endl; exit(1);};
		if(hgam!=to.Hfeed) {cout<<caller<<"    hgam alert    "<<i<<" hgam    "<<hgam<<"  to   " <<to.Hfeed<<endl; exit(1);};
		if(oovi!=to.Oovi) {cout<<caller<<"    oovi alert    "<<i<<" oovi    "<<oovi<<"  to   " <<to.Oovi<<endl; exit(1);};
	      return;};


//Below is code for the random number generator---------------------------------------------------------------------------------------------------------------------------------



void CRandomMersenne::Init0(uint32 seed) {
   // Detect computer architecture
   union {float f; uint32 i[2];} convert;
   convert.f = 1.0;
   if (convert.i[1] == 0x3FF00000) Architecture = LITTLE_ENDIAN1;
   else if (convert.i[0] == 0x3FF00000) Architecture = BIG_ENDIAN1;
   else Architecture = NONIEEE;

   // Seed generator
   mt[0]= seed;
   for (mti=1; mti < MERS_N; mti++) {
      mt[mti] = (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
   }
}

void CRandomMersenne::RandomInit(uint32 seed) {
   // Initialize and seed
   Init0(seed);

   // Randomize some more
   for (int i = 0; i < 37; i++) BRandom();
}

uint32 CRandomMersenne::BRandom() {// Generate 32 random bits

   uint32 y;

   if (mti >= MERS_N) {
      // Generate MERS_N words at one time
      const uint32 LOWER_MASK = (1LU << MERS_R) - 1;       // Lower MERS_R bits
      const uint32 UPPER_MASK = 0xFFFFFFFF << MERS_R;      // Upper (32 - MERS_R) bits
      static const uint32 mag01[2] = {0, MERS_A};

      int kk;
      for (kk=0; kk < MERS_N-MERS_M; kk++) {
         y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
         mt[kk] = mt[kk+MERS_M] ^ (y >> 1) ^ mag01[y & 1];}

      for (; kk < MERS_N-1; kk++) {
         y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
         mt[kk] = mt[kk+(MERS_M-MERS_N)] ^ (y >> 1) ^ mag01[y & 1];}

      y = (mt[MERS_N-1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
      mt[MERS_N-1] = mt[MERS_M-1] ^ (y >> 1) ^ mag01[y & 1];
      mti = 0;
   }

   y = mt[mti++];

#if 1
   // Tempering (May be omitted):
   y ^=  y >> MERS_U;
   y ^= (y << MERS_S) & MERS_B;
   y ^= (y << MERS_T) & MERS_C;
   y ^=  y >> MERS_L;
#endif

   return y;
}


double CRandomMersenne::Random() {
   // Output random float number in the interval 0 <= x < 1
   union {float f; uint32 i[2];} convert; //Union allows one portion of the memory to be accessed as different data types.
   double ra=1.1;
	while(ra>=1)
	{
   uint32 r = BRandom();               // Get 32 random bits
   // The fastest way to convert random bits to floating point is as follows:
   // Set the binary exponent of a floating point number to 1+bias and set
   // the mantissa to random bits. This will give a random number in the
   // interval [1,2). Then subtract 1.0 to get a random number in the interval
   // [0,1). This procedure requires that we know how floating point numbers
   // are stored. The storing method is tested in function RandomInit and saved
   // in the variable Architecture.

   // This shortcut allows the compiler to optimize away the following switch
   // statement for the most common architectures:
#if defined(_M_IX86) || defined(_M_X64) || defined(__LITTLE_ENDIAN__)
   Architecture = LITTLE_ENDIAN1;
#elif defined(__BIG_ENDIAN__)
   Architecture = BIG_ENDIAN1;
#endif

   switch (Architecture) {
   case LITTLE_ENDIAN1:
      convert.i[0] =  r << 20;
      convert.i[1] = (r >> 12) | 0x3FF00000;
      return convert.f - 1.0;
   case BIG_ENDIAN1:
      convert.i[1] =  r << 20;
      convert.i[0] = (r >> 12) | 0x3FF00000;
      return convert.f - 1.0;
   case NONIEEE: default: ;
   }
   // This somewhat slower method works for all architectures, including
   // non-IEEE floating point representation:
   //return 0.0000005 +0.999999*(double)r * (1./((double)(uint32)(-1L)+1.));
   ra= (double)r * (1./((double)(uint32)(-1L)+1.));
	};
   return ra;
}


int CRandomMersenne::IRandom(int min, int max) {
   // Output random integer in the interval min <= x <= max
   // Relative error on frequencies < 2^-32
   if (max <= min) {
      if (max == min) return min; else return 0x80000000;
   }
   // Multiply interval with random and truncate
   int r = int((max - min + 1) * Random()) + min;
   if (r > max) r = max;
   return r;
}

double OrsteinUhlenbeck(double dt, double theta) // A function which increments theta using the exponential of the OrnsteinUhlenbeck process
{
    double x, c_norm, c_r1, c_r2, dW;

    // Generate a normal random variable using the Box Muller transform
    c_r1 = rg.Random();
    c_r2 = rg.Random();
    c_norm = sqrt(-2 * log(c_r1)) * cos(2 * PI * c_r2);
    dW = sqrt(dt) * c_norm;

    // Get x from theta
    theta = theta*(1/pa.thetaB_mean);
    x = log(theta) + (pa.etaB*pa.etaB)/(4*pa.chiB);

    // Now use old x to get new x using Ornstein Uhlenbeck
    x = x - pa.chiB * x * dt + pa.etaB * dW;


    // Now get theta from x
    theta = exp(x)/exp((pa.etaB*pa.etaB)/(4*pa.chiB));
    theta = theta*pa.thetaB_mean;

    return theta;
}

// A function which outputs the various txt files which contain parameter values for the simulation
void parameter_txt_generator()
{
    int i_nchi, i_neta;
    i_nchi = 8;
    i_neta = 8;

    vector<double> v_chiB(i_nchi);
    vector<double> v_etaB(i_neta);

    for(int i = 1; i<i_nchi+1; i++)
    {
        v_chiB[i-1] = 0.01*pow(10,0.25*i-0.25);
    }

    for(int i = 1; i<i_neta+1; i++)
    {
        v_etaB[i-1] = 0.01*pow(10,0.25*i-0.25);
    }


int k = 1;
    for(int i = 0; i<i_nchi; i++)
    {
        for(int j = 0; j<i_neta; j++)
        {
            string a = "parameters";
            string c = ".txt";

            string final;
            final = make_filename(a,k,c);

            ofstream myfile;

            myfile.open( final.c_str());
            if (myfile.is_open())
            {
                myfile<< v_chiB[i]<<"\n";
                myfile<< v_etaB[j]<<"\n";
                myfile.close();
            }
            k = k + 1;
        }
    }

}

// A function which makes a file name in a format which can be used dynamically to create parameter files
string make_filename( const string& basename, int index, const string& ext )
  {
  ostringstream result;
  result << basename << index << ext;
  return result.str();
  }
