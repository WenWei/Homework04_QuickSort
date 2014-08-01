// Homework4.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <iomanip>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "mergesort.h"
#include "mergesort2.h"
#include "ShellSort.h"
#include "quicksort.h"

using namespace std;



enum SortType{
	CustomQuickSort,
	CustomQuickSortNoSplit,
	Sort,
	StableSort,
	HeapSort,
	ShellSort,
	MergeSort,
	MergeSort2,
	MergeSortVector
};


//���Ͷüư}�C
/*
template <class NumberType,class ArrType>
void GetRandomArray(ArrType* arr, NumberType N)
{
	ArrType temp;
	NumberType a, b;

	//�̧Ƕ��
	for(NumberType i=0;i<N;i++) arr[i]=i;
	
	//�H���մ���m
	//srand();//�üƺؤl�A�u�n�ϥζüƫe����@���N�i�H�F
	cout<<RAND_MAX<<endl;
	for(NumberType i=0;i<N;i++)
	{
		a=rand() % n;
		b=rand() % n;

		temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;

		//arr[i]=rand();
		//cout << ptr[i] << endl;
	}
}
*/

	//���Ͷüư}�C
	template <typename NumberType,typename ArrType>
	void GetRandomArray1(ArrType* arr, NumberType N)
	{
		for(NumberType i=0;i<N;i++) arr[i]=rand();
	}



// �Ȱ��e�����ݿ�J
void pause()
{
   std::cin.sync(); // Flush The Input Buffer Just In Case
   std::cin.ignore(); // There's No Need To Actually Store The Users Input
}

template<typename NumberType,typename ArrType>
double CreateArrayAndSort(NumberType n, SortType type)
{
	// �إ߶üư}�C
	ArrType* ptrA=new (nothrow) ArrType[n];
	//��MergeSort�� �̫�@�� address
    //ArrType* ptrA_end=ptrA+sizeof ptrA/sizeof(ArrType);

	//�S���t��O����
	if(ptrA==0)
	{
		cout << "�O����Ŷ�����" ;
		//throw 1;
		return 0;
	}
	std::fill(ptrA, ptrA + n, 0);				//�N�}�C��s
	//for(NumberType i=0;i<n;i++) ptrA[i]=rand(); //�]�w�ü�

	GetRandomArray1<NumberType, ArrType>(ptrA, n); //�]�w�ü�
	

	//��ܰ}�C���e
	//for(int i=0;i<n;i++) cout<<ptrA[i]<<endl;

	LARGE_INTEGER startTime,endTime,fre;
    double times;
        //doing something

	switch(type)
	{
	case SortType::CustomQuickSort:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥΦۻs�ֳt�Ƨ�
		QuickSort<NumberType, ArrType>(ptrA,0,n-1);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;


	case SortType::CustomQuickSortNoSplit:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥΦۻs�ֳt�Ƨ� NoSplit
		QuickSort2<NumberType, ArrType>(ptrA,0,n-1);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;


	case SortType::ShellSort:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥ�ShellSort�Ƨ�
		shellSort(ptrA, n);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;


	case SortType::HeapSort:
		std::make_heap( ptrA, ptrA+n );
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥ�C++����HeapSort�Ƨ�
		//heapsort(ptrA, ptrA+n);
		std::sort_heap(ptrA, ptrA+n);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;


	case SortType::Sort:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥ�C++���رƧ�
		sort(ptrA,ptrA + n);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;


	case SortType::MergeSort:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥ�C++���رƧ�
		mergesort(ptrA, n);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;


	case SortType::MergeSort2:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥκ����䪺�Ƨ�
		mergesort2(ptrA,n);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;

	case SortType::StableSort:
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥ�C++���رƧ�
		std::stable_sort(ptrA, ptrA+n);
		//std::partial_sort();
		//std::partial_sort_copy();
		
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;

	case SortType::MergeSortVector:
		//std::vector<ArrType> v(n);
		//for(NumberType i=0;i<n;i++)
		//	v[i]=ptrA[i];
		QueryPerformanceFrequency(&fre); //���oCPU�W�v
		QueryPerformanceCounter(&startTime); //���o�}����{�b�g�L�X��CPU Cycle
		//�ϥ�C++���رƧ�
		//mergesort1(v.begin(), v.end());
		//mergesort(ptrA, ptrA+n);
		mergesort2(ptrA,n);
		QueryPerformanceCounter(&endTime); //���o�}����{�����槹���g�L�X��CPU Cycle
		break;
	default:
		break;
	}
	
	//doing something
    times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
    //cout << fixed << setprecision(10) << times << "s" << endl;
	//cout << fixed << setprecision(10) << times * 1000 << "ms" << endl;
	//cout << fixed << setprecision(10) << times * 1000000 << "�gs" << endl;
	//cout << fixed << setprecision(10) << times * 1000000000 << "ns" << endl;

	//��ܰ}�C���e
	//for(int i=0;i<n;i++) cout<<ptrA[i]<<endl;

	//�ˬd�}�C�Ƨǵ��G
	for(NumberType i=1;i<n;i++)
	{
		if(ptrA[i-1]>ptrA[i]) 
		{
			cout<< "�Ƨǵ��G�����T"<<endl;
			cout<< ptrA[i-1] << " " << ptrA[i] << endl;
			if(i>10)
			throw 1;
		}
	}

	delete ptrA;
	return times;
}


//�{���i�J�I
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"�Ƨ� 10�� n ����}�C�A0 < n <13�C"<< endl;
	cout<< "�п�J n��:" ;
	int n;
	cin >> n;
	double times;
	for(int i=1;i<=n;i++)
	{
		try { 


			//cout << fixed << setprecision(10) << times << "s" << endl;
			//cout << fixed << setprecision(10) << times * 1000 << "ms" << endl;
			//cout << fixed << setprecision(10) << times * 1000000 << "�gs" << endl;
			//cout << fixed << setprecision(10) << times * 1000000000 << "ns" << endl;
			int w=30;
			cout<<"=======   n=10^" << i << "=============================="<<endl;
			
			times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::CustomQuickSort);
			cout <<setw(w)<<left<< "�ۻs QuickSort(pivot last)"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::CustomQuickSortNoSplit);
			cout <<setw(w)<<left<< "�ۻs QuickSort(pivot avg)"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::Sort);
			cout <<setw(w)<<left<< "���� Sort"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::MergeSort2);
			//cout <<setw(w)<<left<< "�䪺 MergeSort2"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<int,int>(pow(10.0,i),SortType::StableSort);
			//cout <<setw(w)<<left<< "���� StableSort"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<int,int>(pow(10.0,i),SortType::HeapSort);
			//cout <<setw(w)<<left<< "���� HeapSort"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<int,int>(pow(10.0,i),SortType::MergeSort);
			//cout <<setw(w)<<left<< "�䪺 MergeSort"<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<long long,int>(pow(10.0,i),SortType::ShellSort);
			//cout <<setw(w)<<left<< "�䪺 ShellSort2"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<long long,int>(pow(10.0,i),SortType::MergeSort);
			//cout <<setw(w)<< "�䪺 MergeSortVector   "<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			//pause();
		}
		catch(...)
		{
			//cerr<<"�o�Ϳ��~: " << endl;
			break;
		}
	}

	//MyRandom rnd(10000000);
	//for(int i=0;i<100;i++)
	//	cout<< rnd.Random3() << "  " ;

	//sort<unsigned _int64>(10);
	cout<<"�{������"<<endl;

	pause();
	return 0;
};

