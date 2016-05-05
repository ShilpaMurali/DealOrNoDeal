#include "dealornodeal.h"
int dealornodeal::_count;
dealornodeal::dealornodeal(int suitcaseSize){
	for (int i = 0; i < suitcaseSize; i++){
		_suitcaseNumber[i] = i+1;
		_suitcaseNumber2[i] = 0;
	}
	for (int i= 0, j =6; i <9; i++){
		_caseCount[i] = j;
		if(j >1){
			j--;
		}
	}
	_randomArray = new int[suitcaseSize];
}
dealornodeal::~dealornodeal(){
	
	delete [] _randomArray;
}
bool dealornodeal::game(int option)
{
	int index=0,startIndex=0,i=-1,j=0,loopIndex=0;
	bool findAnother=false;
	int _previousOffers[10]={0};
	_countOfOffers=0;
	int _suitcase[]={0.01,1,5,10,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,200000,300000,400000,500000,750000,1000000};
	int size_suitcase=sizeof(_suitcase)/sizeof(int);
	int size_caseCount=sizeof(_caseCount)/sizeof(int);
	int size_suitcaseNumber=sizeof(_suitcaseNumber)/sizeof(int);
	while(j<size_suitcase)
	{
		_randomArray[j]=_suitcase[j];
		j++;
	}
	_displayInitialSuitcases(_suitcase,size_suitcase);
	_randomnumber(_suitcase,size_suitcase,_randomArray);
	cout<<"Welcome to Deal or No Deal!  Select a briefcase and we'll get started."<<endl;
	if(option==2||option==3||option==4)
	{
		startIndex=rand()%(size_suitcase)+1;
	}
	else
	{
		cin>>startIndex;
	}
	_suitcaseNumber2[loopIndex]=startIndex;
	loopIndex++;
	cout<<startIndex<<" is your suitcase"<<endl;
	_suitcaseNumber[startIndex-1]=-999;
	do
	{
		i++;
		cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		_displayModifiedSuitcases(_suitcase,size_suitcase,size_suitcaseNumber);
		for(int ind=_caseCount[i];ind>0;ind--)
		{
			cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"Please select "<<ind<<" cases to be removed"<<endl;
			do
				{
					findAnother=false;
					int k=0;
					if(option==2||option==3||option==4)
					{
						index=rand()%size_suitcase+1;
					}
					else
					{
						cin>>index;
					}
					k=loopIndex-1;
					while(k>=0)
					{
						if(index<=0||index>26)
						{
							findAnother=true;
							cout<<"You have chosen an invalid suitcase.Select a suitcase from the list given"<<endl;
							break;
						}
						else if(_suitcaseNumber2[k]==index)
						{
							findAnother=true;
							if(option==1)
							{
								cout<<"The suitcase you have requested for is already selected. Select a suitcase from the list given"<<endl;
							}
							break;
						}
						k--;
					}
					if(findAnother==false)
					{
						cout<<"Suitcase selected is "<<index<<endl;
						_suitcaseNumber2[loopIndex]=index;
						loopIndex++;
						break;
					}
				}while(findAnother);
			cout<<"Amount present in the suitcase you selected = $"<<_randomArray[index-1];
			_suitcaseNumber[index-1]=-999;
			int k=0;
			while(k<size_suitcase)
			{
				if(_randomArray[index-1]==_suitcase[k])
				{
					_suitcase[k]=-999;
				}
				k++;
			}
			cout<<endl<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
			_displayModifiedSuitcases(_suitcase,size_suitcase,size_suitcaseNumber);
		}
		_bankerDealCalculation(_suitcase,size_suitcase,_previousOffers,_countOfOffers,option);
		if(_choice)
		{
			cout<<"Let's see what's in the case:"<<endl<<"Your Deal: Your Case has $"<<_randomArray[startIndex-1]<<" amount"<<endl<<"Thank you for playing!"<<endl<<endl;
			cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
		}
		if(!_choice && i==size_caseCount-1)
		{
			if(option==1||option==2)
			{
				cout<<"Let's see what's in the case:"<<endl<<"Your Deal: Your Case has $"<<_randomArray[startIndex-1]<<" amount"<<endl<<"Thank you for playing!"<<endl;
				cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
				break;
			}
			if(option==3)
			{
					cout<<"Let's see what's in the case:"<<endl<<"Your Deal: Your Case has $"<<_randomArray[startIndex-1]<<" amount"<<endl;
					if(_randomArray[startIndex-1]==1000000)
					{
						cout<<"Thank you for playing!"<<endl;
						cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
						break;
					}
					else
					{
						cout<<"The case does not contain One Million $. Restarting the game"<<endl;
						return false;	
					}
			}
			if(option==4)
			{
				cout<<"Let's see what's in the case:"<<endl<<"Your Deal: Your Case has $"<<_randomArray[startIndex-1]<<" amount"<<endl;
				if(_randomArray[startIndex-1]==0)
					{
						cout<<"Thank you for playing!"<<endl;
						break;
					}
					else
					{
						cout<<"You are still not bankrupt. Restarting the game"<<endl;
						return false;
					}
			}
		}
	}while(!_choice && i<size_caseCount);
	return true;
}
void dealornodeal::_displayInitialSuitcases(int* v,int n)
{
	cout<<endl<<"***** Deal or No Deal ! *****"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"Amount present"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<"   ";
	}
	cout<<endl<<endl;
	cout<<"Briefcases present"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"  ";
	}
	cout<<endl<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
}
void dealornodeal::_randomnumber(int* v,int n,int* randomPtr)
{

	srand(time(NULL)); 
	int temp = 0;
	int ridx = n-1;

	for(int j=(n-1); j>1; j--)
	{
		ridx = rand()%j;
		temp = randomPtr[ridx];
		randomPtr[ridx] = randomPtr[j];
		randomPtr[j] = temp;
	}
	/*cout<<endl<<"Random Array"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<randomPtr[i]<<" ";
	}
	cout<<endl;*/
}
void dealornodeal::_displayModifiedSuitcases(int* v,int n,int m)
{
	cout<<endl<<"Amount still in game"<<endl;
	for(int i=0;i<n;i++)
	{
		if(v[i]!=-999)
		{
			cout<<v[i]<<"   ";
		}
	}
	cout<<endl;
	cout<<"Cases present"<<endl;
	for(int i=0;i<m;i++)
	{
		if(_suitcaseNumber[i]!=-999)
		{
			cout<<i+1<<"  ";
		}
	}
	cout<<endl;
}
void dealornodeal::_bankerDealCalculation(int* v,int n,int* w,int& m,int& option )
{
	int amount=0,index=0,indexOffer=0,i=0;
	char choice[100];
	char yes[]="y";
	char no[]="n";
	bool choiceAnother;
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"It's the banker."<<endl<<"He is making you an offer of...."<<endl;
	for(int i=0;i<n;i++)
	{
		if(v[i]!=-999)
		{
			index++;
			amount+=v[i];
		}
	}
	amount/=index;
	w[m]=amount;
	cout<<"$"<<amount<<endl;
	cout<<"Do you accept this offer?"<<endl;
	cout<<"Previous offers:"<<endl;
	if(m==0)
	{
		cout<<"None";
	}
	while(m!=0 && i<m)
	{
			cout<<w[i]<<endl;
			i++;
	}
	cout<<endl<<"Deal or No deal."<<"Select (y) for Deal and (n) for No Deal"<<endl;
	if(option==2||option==3||option==4)
	{
		strcpy(choice,"n");
		_choice=false;
		cout<<"Choice is "<<choice<<endl;
	}
	else
	{
		do
		{
			choiceAnother=false;
			cin>>choice;
			if(!(strcmp(choice,yes) && strcmp(choice,no)))
			{
				choiceAnother=false;
			}
			else
			{
				cout<<"Enter the correct choice.Select (y) for Deal and (n) for No Deal"<<endl;
				choiceAnother=true;
			}
		}while(choiceAnother);
	}
	m++;
	if(!(strcmp(choice,yes)))
	{
		_choice=true;
		cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"You have won $"<<amount<<endl;
		cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	}
	else
	{
		_choice=false;
	}
}
