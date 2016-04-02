#include "../util/util.h"
class dealornodeal
{
	private:
		int _caseCount[9];
		int _previousOffers[6];
		int _countOfOffers;
		int _suitcaseNumber[26];
		int _suitcaseNumber2[26];
		int* _randomArray; 
		static int _count;
		void suitcase_select_prompt(int*);
		void _displayInitialSuitcases(int*,int);
		void _displayModifiedSuitcases(int*,int,int);
		void _randomnumber(int*,int,int*);
		void _bankerDealCalculation(int*,int,int*,int&,int&);
		bool _choice;
	public:
		dealornodeal(int suitcaseSize=26);
		~dealornodeal();
		bool game(int);
};
