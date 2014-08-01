// Homework4.cpp : 定義主控台應用程式的進入點。
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


//產生亂數陣列
/*
template <class NumberType,class ArrType>
void GetRandomArray(ArrType* arr, NumberType N)
{
	ArrType temp;
	NumberType a, b;

	//依序填值
	for(NumberType i=0;i<N;i++) arr[i]=i;
	
	//隨機調換位置
	//srand();//亂數種子，只要使用亂數前執行一次就可以了
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

	//產生亂數陣列
	template <typename NumberType,typename ArrType>
	void GetRandomArray1(ArrType* arr, NumberType N)
	{
		for(NumberType i=0;i<N;i++) arr[i]=rand();
	}



// 暫停畫面等待輸入
void pause()
{
   std::cin.sync(); // Flush The Input Buffer Just In Case
   std::cin.ignore(); // There's No Need To Actually Store The Users Input
}

template<typename NumberType,typename ArrType>
double CreateArrayAndSort(NumberType n, SortType type)
{
	// 建立亂數陣列
	ArrType* ptrA=new (nothrow) ArrType[n];
	//給MergeSort用 最後一個 address
    //ArrType* ptrA_end=ptrA+sizeof ptrA/sizeof(ArrType);

	//沒分配到記憶體
	if(ptrA==0)
	{
		cout << "記憶體空間不足" ;
		//throw 1;
		return 0;
	}
	std::fill(ptrA, ptrA + n, 0);				//將陣列填零
	//for(NumberType i=0;i<n;i++) ptrA[i]=rand(); //設定亂數

	GetRandomArray1<NumberType, ArrType>(ptrA, n); //設定亂數
	

	//顯示陣列內容
	//for(int i=0;i<n;i++) cout<<ptrA[i]<<endl;

	LARGE_INTEGER startTime,endTime,fre;
    double times;
        //doing something

	switch(type)
	{
	case SortType::CustomQuickSort:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用自製快速排序
		QuickSort<NumberType, ArrType>(ptrA,0,n-1);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;


	case SortType::CustomQuickSortNoSplit:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用自製快速排序 NoSplit
		QuickSort2<NumberType, ArrType>(ptrA,0,n-1);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;


	case SortType::ShellSort:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用ShellSort排序
		shellSort(ptrA, n);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;


	case SortType::HeapSort:
		std::make_heap( ptrA, ptrA+n );
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用C++內建HeapSort排序
		//heapsort(ptrA, ptrA+n);
		std::sort_heap(ptrA, ptrA+n);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;


	case SortType::Sort:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用C++內建排序
		sort(ptrA,ptrA + n);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;


	case SortType::MergeSort:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用C++內建排序
		mergesort(ptrA, n);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;


	case SortType::MergeSort2:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用網路找的排序
		mergesort2(ptrA,n);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;

	case SortType::StableSort:
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用C++內建排序
		std::stable_sort(ptrA, ptrA+n);
		//std::partial_sort();
		//std::partial_sort_copy();
		
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;

	case SortType::MergeSortVector:
		//std::vector<ArrType> v(n);
		//for(NumberType i=0;i<n;i++)
		//	v[i]=ptrA[i];
		QueryPerformanceFrequency(&fre); //取得CPU頻率
		QueryPerformanceCounter(&startTime); //取得開機到現在經過幾個CPU Cycle
		//使用C++內建排序
		//mergesort1(v.begin(), v.end());
		//mergesort(ptrA, ptrA+n);
		mergesort2(ptrA,n);
		QueryPerformanceCounter(&endTime); //取得開機到程式執行完成經過幾個CPU Cycle
		break;
	default:
		break;
	}
	
	//doing something
    times=((double)endTime.QuadPart-(double)startTime.QuadPart)/fre.QuadPart;
    //cout << fixed << setprecision(10) << times << "s" << endl;
	//cout << fixed << setprecision(10) << times * 1000 << "ms" << endl;
	//cout << fixed << setprecision(10) << times * 1000000 << "μs" << endl;
	//cout << fixed << setprecision(10) << times * 1000000000 << "ns" << endl;

	//顯示陣列內容
	//for(int i=0;i<n;i++) cout<<ptrA[i]<<endl;

	//檢查陣列排序結果
	for(NumberType i=1;i<n;i++)
	{
		if(ptrA[i-1]>ptrA[i]) 
		{
			cout<< "排序結果不正確"<<endl;
			cout<< ptrA[i-1] << " " << ptrA[i] << endl;
			if(i>10)
			throw 1;
		}
	}

	delete ptrA;
	return times;
}


//程式進入點
int _tmain(int argc, _TCHAR* argv[])
{
	cout<<"排序 10的 n 次方陣列，0 < n <13。"<< endl;
	cout<< "請輸入 n值:" ;
	int n;
	cin >> n;
	double times;
	for(int i=1;i<=n;i++)
	{
		try { 


			//cout << fixed << setprecision(10) << times << "s" << endl;
			//cout << fixed << setprecision(10) << times * 1000 << "ms" << endl;
			//cout << fixed << setprecision(10) << times * 1000000 << "μs" << endl;
			//cout << fixed << setprecision(10) << times * 1000000000 << "ns" << endl;
			int w=30;
			cout<<"=======   n=10^" << i << "=============================="<<endl;
			
			times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::CustomQuickSort);
			cout <<setw(w)<<left<< "自製 QuickSort(pivot last)"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::CustomQuickSortNoSplit);
			cout <<setw(w)<<left<< "自製 QuickSort(pivot avg)"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::Sort);
			cout <<setw(w)<<left<< "內建 Sort"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<long long,short>(pow(10.0,i),SortType::MergeSort2);
			//cout <<setw(w)<<left<< "找的 MergeSort2"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<int,int>(pow(10.0,i),SortType::StableSort);
			//cout <<setw(w)<<left<< "內建 StableSort"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<int,int>(pow(10.0,i),SortType::HeapSort);
			//cout <<setw(w)<<left<< "內建 HeapSort"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<int,int>(pow(10.0,i),SortType::MergeSort);
			//cout <<setw(w)<<left<< "找的 MergeSort"<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<long long,int>(pow(10.0,i),SortType::ShellSort);
			//cout <<setw(w)<<left<< "找的 ShellSort2"<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			
			//times=CreateArrayAndSort<long long,int>(pow(10.0,i),SortType::MergeSort);
			//cout <<setw(w)<< "找的 MergeSortVector   "<<right<< fixed << setprecision(10) << times * 1000 << "ms" << endl;
			//pause();
		}
		catch(...)
		{
			//cerr<<"發生錯誤: " << endl;
			break;
		}
	}

	//MyRandom rnd(10000000);
	//for(int i=0;i<100;i++)
	//	cout<< rnd.Random3() << "  " ;

	//sort<unsigned _int64>(10);
	cout<<"程式結束"<<endl;

	pause();
	return 0;
};

