#include "PetriNet.h"



PetriNet::PetriNet()
{
	//init
}


PetriNet::~PetriNet()
{
}

//bool PetriNet::correctNet() {
//	for (short int p=0;p<sizeP-1;p++)
//		for (short int t=0; t<sizeT;t++)
//		if(net[p][t] !=0)
//}

bool PetriNet::transPossibility(short int p1, short int p2) //����������� ��������
{
	short int T = findT(p1, p2);
	if (T > -1 && M[p1] > 0) {
		return true;
	}
	return false;
}

short int PetriNet::findT(short int p1, short int p2) //���� �������
{
	for (auto t : net[p1])
		if (net[p2].at(t.first) > 0)
			return t.first;
	return -1;

}

void PetriNet::jump(short int T) //���������� �������
{
	bool marker;
	for (int p = 0; p < M.size(); p++) {  //��������� �������
		if (net[p][T] != 0) {
			if (net[p][T] < 0 && M[p]>0) {
				M[p]--; marker = true;
			}
			if (net[p][T] > 0 && marker==1) {
				M[p]++; 
			}

		}
	}
}

